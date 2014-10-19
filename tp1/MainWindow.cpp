#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QPixmap>

#include "Graphics/GrayscaleImageFactory.h"
#include "Graphics/GrayscaleImage.h"
#include "Graphics/GrayscaleHistogram.h"
#include "Graphics/MatchingFunction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _pImage(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOuvrir_triggered()
{
    QFileDialog fd(this, tr("Ouvrir une image"));
    fd.setFileMode(QFileDialog::ExistingFile);
    fd.setNameFilter(tr("Portable Map (*.pgm)"));
    
    if (fd.exec())
    {
        Graphics::GrayscaleImage* pImage = Graphics::GrayscaleImageFactory::loadFromFile(fd.selectedFiles().first().toUtf8().data());
        if (pImage)
            setImage(pImage);
    }
}

void MainWindow::setImage(Graphics::GrayscaleImage* pImage)
{
    int width = pImage->width();
    int height = pImage->height();
    
    if (_pImage)
        delete (_pImage);
    
    _pImage = pImage;
    QImage *pQimage = new QImage(_pImage->width(), _pImage->height(), QImage::Format_RGB888);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            unsigned short value = _pImage->getIntensityAt(x, y);
            pQimage->setPixel(x, y, qRgb(value, value, value));
        }
    }

    this->ui->label->setPixmap(QPixmap::fromImage(*pQimage));
}

void MainWindow::on_actionSaveHistogram_triggered()
{
    if (_pImage == 0)
        return;

    QString savePath = QFileDialog::getSaveFileName(0, tr("Sauvegarde de l'histogramme sur disque"), QString());
    if (!savePath.isEmpty())
    {
        Graphics::GrayscaleHistogram imgHistogram(*_pImage);
        imgHistogram.save(savePath.toUtf8().data());
    }
}
void MainWindow::on_actionLoadHistogram_triggered()
{
    QFileDialog fd(this, tr("Charger un histogramme"));
    fd.setFileMode(QFileDialog::ExistingFile);

    if (fd.exec())
    {
        Graphics::GrayscaleHistogram histogram(fd.selectedFiles().first().toUtf8().data());
    }
}

void MainWindow::on_actionApplyMatchingFunction_triggered()
{
    QFileDialog fd(this, tr("Sélectionner une fonction de correspondance"));
    fd.setFileMode(QFileDialog::ExistingFile);

    if (fd.exec())
    {
        Graphics::MatchingFunction matchFunc(fd.selectedFiles().first().toUtf8().data());
        setImage(matchFunc.apply(_pImage));
    }
}
