#include "auth.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
        dg->show();
    return;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    enum {null, monday, tuesday, wednesday, thursday, friday, saturday, sunday};
    int currentGreen = index + 1;
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(currentGreen));
    QTextCharFormat format;
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(currentGreen), format);
    // Делаем обновление цветов таблицы (цикл for, начиная с понедельника, заканчивая воскресеньем)
    for(int i = monday; i <= sunday; i++)
    {
        // Если это не выбранный день недели
        if(i != currentGreen)
        {
            // Если это день в промежутке с понедельника по пятницу - красим в черный
            if(i >= monday && i <= friday)
                format.setForeground(qvariant_cast<QColor>("black"));
            // Иначе если это суббота или воскресенье - красим в красный
            else if(i == saturday || i == sunday)
                format.setForeground(qvariant_cast<QColor>("red"));
            // Устанавливаем цвет по индексу
            ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i), format);
        }
    }

}
