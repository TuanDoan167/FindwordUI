#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <iostream>
#include <fstream>  // Notice the required library for file handling
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileLineEdit_editingFinished();

    void on_keyLineEdit_editingFinished();

    void resultShown();

private:
    Ui::MainWindow *ui;
    std::string filename_;
    std::string searchkey_;
};
#endif // MAINWINDOW_HH
