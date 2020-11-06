#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Анкета");
    Hlay->addWidget(sBox);
    Hlay->addWidget(tEdit);
    this->setLayout(Hlay);
    Hlay->addWidget(cBox);
    Hlay->addWidget(But);
    cBox->addItem("1");
    cBox->addItem("2");
    cBox->addItem("3");
    But->setText("Сохранить");
    QObject::connect(But, SIGNAL(clicked()), this, SLOT(Wrf()));
}

MyDialog::~MyDialog()
{
}


void MyDialog::Wrf()
{
    // Блок обработки исключительных ситуаций
    try
    {
        // Выводим диалог выбора файла для сохранения
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Notebook As Text"), QString(), "Text file (*.txt)");
        QSaveFile outf(fileName);
        // Открываем файл только для записи
        outf.open(QIODevice::WriteOnly);
        // Привязываем к файлу поток, позволяющий выводить объекты Qt
        QTextStream ost(&outf);

        ost << "Combo box state: " << cBox->itemText(cBox->currentIndex()) << Qt::endl;
        ost << "Spin box state: " << sBox->value() << Qt::endl;
        ost << "Text field: " << Qt::endl << tEdit->toPlainText() << Qt::endl;

        // Если пользователь не выбрал файл, возвращаем false
        if (fileName.isEmpty())
        {
            return;
        }
        // Сохраняем записную книжку в выбранный файл
        if (!outf.commit())
        {
            throw std::runtime_error(tr("Unable to commit the save").toStdString());
        }
    }
    catch (const std::exception &e)
    {
        // Если при сохранении файла возникла исключительная ситуация, сообщить пользователю
        QMessageBox *MB = new QMessageBox;
        MB->setIcon(QMessageBox::Critical);
        MB->setText("File Error");
        MB->exec();
    }
}

