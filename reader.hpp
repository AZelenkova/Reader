#ifndef READER_HPP
#define READER_HPP

#include <QMainWindow>
#include <QFileDialog>

#include <QMutex>


namespace Ui {
class Reader;
}

class Reader : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reader(QWidget *parent = 0);
    ~Reader();

private slots:


    void on_start_clicked();

    void on_open_clicked();

    void on_pause_clicked();

private:
    QStringList words;
    std::size_t position;

    bool p = false; // индикатор закрузки текста
    bool pause1 = false; // индикатор паузы

    Ui::Reader *ui;
};

#endif // READER_HPP
