#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>  // Notice the required library for file handling
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->findPushButton, &QPushButton::clicked, this, &MainWindow::resultShown);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fileLineEdit_editingFinished()
{
    QString filename(ui->fileLineEdit->text());
    filename_=filename.toStdString();
}


void MainWindow::on_keyLineEdit_editingFinished()
{
    QString searchkey(ui->keyLineEdit->text());
    searchkey_=searchkey.toStdString();
}

void MainWindow::resultShown()
{
    std::ifstream file_object(filename_);
    if ( not file_object ) {
        QString str = "File not found";
        ui->textBrowser->setText(str);
    }

    else {
        if(searchkey_.size()==0){
            QString str = "File found";
            ui->textBrowser->setText(str);
        }
        else {
            std::string word;
            while ( file_object>>word) {

                if (not ui->matchCheckBox->isChecked()){
                    unsigned int sz = searchkey_.size();
                    unsigned int szword = word.size();
                    if (sz != szword) {
                        continue;}
                    else
                    {
                        std::string newkey="";
                        std::string newword="";
                        for (unsigned int i = 0; i < sz; ++i){
                            newkey+=tolower(searchkey_[i]);
                            newword+=tolower(word[i]);
                        }
                            if (newkey == newword)
                              { QString str = "Word found";
                                ui->textBrowser->setText(str);
                                break;}
                    }
                }

                else if (searchkey_ == word){
                    QString str = "Word found";
                    ui->textBrowser->setText(str);
                    break;
                }
            }

            if(file_object.eof()){
                QString str ="Word not found";
                ui->textBrowser->setText(str);
            }

        }
        file_object.close();
    }
}

