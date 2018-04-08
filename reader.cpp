#include "reader.hpp"
#include "ui_reader.h"
#include <unistd.h>
#include <QFont>

Reader::Reader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);

    position = ui->reader_position->value();
    QFont afont;
    afont.setStyleHint(QFont::Monospace);
    //afont.setStyleHint(QFont::TypeWriter);
    afont.setPixelSize(30);

    QFontMetrics font(afont);
    ui->word->setFont(afont);
    //ui->label_2->setFont(afont);
}

Reader::~Reader()
{
    delete ui;
}

void pause(int dur){
    usleep(dur);
}


void Reader::on_start_clicked()
{
    bool dot = false;
    bool dot1 = false;
    position = ui->reader_position->value();
    pause1 = false;

    for(std::size_t i = 0;p == true, i< words.count();++i) {
        if(i>=position){
            QString temp = words.at(position);
            int k;
            ui->word->setText("");
            if(temp.size()%2 != 0){
                k = 0;
            } else k = 1;

            for(std::size_t pos = 0; pos < temp.size();++pos){
                if(temp.at(pos) == QChar('.') ||temp.at(pos) == QChar('!')||temp.at(pos) == QChar('?')) dot = true;
                if(temp.at(pos) == QChar(',') ||temp.at(pos) == QChar(';')) dot1 = true;
                if (pos == temp.size()/2-k){
                    ui->word->setTextColor(QColor(Qt::red));
                    ui->word->insertPlainText(temp.at(pos));
                    ui->word->setTextColor(QColor(Qt::black));
                } else
                    ui->word->insertPlainText(temp.at(pos));
            }
            ui->word->setAlignment(Qt::AlignCenter);
            position = i;
            ui->reader_position->setValue(position);
            if(dot != false){
                pause((ui->speed->value()+10000)*10);
                dot = false;
            }else pause(ui->speed->value()*10);
            if(dot1 != false){
                pause((ui->speed->value()+1000)*10);
                dot1 = false;
            }else pause(ui->speed->value()*10);
        } else {
            ui->word->setText("please wait");
            ui->word->setAlignment(Qt::AlignCenter);
        }
            ui->progress->setValue(i);
            QApplication::processEvents();
            ui->reader_position->setValue(position);
            if (pause1 == true) break;

    }
}

void Reader::on_open_clicked()
{
    ui->progress->setValue(0);
    QString filename = QFileDialog::getOpenFileName(this,tr("Chose"),"",tr("*.txt"));
if(filename != nullptr){
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString content = file.readAll();
    file.close();
    p = true; //загружено
    words = content.split(" ");
    ui->word->setText("click start");
    ui->word->setAlignment(Qt::AlignCenter);
    position = 0;
    ui->progress->setMaximum(words.count());
    ui->reader_position->setMaximum(words.count());
}
}



void Reader::on_pause_clicked(){
    pause1 = true;
}
