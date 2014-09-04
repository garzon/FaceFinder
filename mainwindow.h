#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include "VideoProcessor.hpp"

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void inputFile();
    void outputDir();
    void process();
private:
    Ui::MainWindow *ui;
    VideoProcessor VP;
};

#endif // MAINWINDOW_H
