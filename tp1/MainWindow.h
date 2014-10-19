#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

namespace Graphics
{
class GrayscaleImage;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    
    void on_actionQuitter_triggered();    
    void on_actionOuvrir_triggered();

    void on_actionLoadHistogram_triggered();
    void on_actionSaveHistogram_triggered();

    void on_actionApplyMatchingFunction_triggered();

private:
    
    Ui::MainWindow *ui;
    Graphics::GrayscaleImage* _pImage;
    
    void setImage(Graphics::GrayscaleImage* pImage);
};

#endif // MAINWINDOW_H
