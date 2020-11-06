#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QSaveFile>
#include <QFileDialog>

class MyDialog : public QDialog
{
    Q_OBJECT

private:
    QSpinBox *sBox = new QSpinBox;
    QTextEdit *tEdit = new QTextEdit;
    QHBoxLayout *Hlay = new QHBoxLayout;
    QComboBox *cBox = new QComboBox;
    QPushButton *But = new QPushButton;

public:
    MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private slots:
    void Wrf();
};
#endif // MYDIALOG_H
