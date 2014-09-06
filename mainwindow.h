#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QValidator>

#include "VideoProcessor.hpp"
#include "FGSegmentation.hpp"
#include "FaceDetection.hpp"

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
    VideoProcessor *VP;
    FaceDetection FD;
    FGSegmentation *FGS;
    std::vector<cv::Rect> ROIs,faces;
    cv::Mat tmpFace;
    int faceId;
    QImage img;
    bool isProcessing,isAbort;
    QIntValidator *jumpVal, *sizeVal;
};

#endif // MAINWINDOW_H
