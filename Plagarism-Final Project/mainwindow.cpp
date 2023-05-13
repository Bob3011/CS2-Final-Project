#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <regex>
#include <iostream>
#include <set>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include<QDebug>
#include <iostream>
#include <fstream>
#include <string>
#include "file_compilation.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_listModel = new QStringListModel(this);
    ui->listOfWords->setModel(m_listModel);
    connect(ui->btCompare, SIGNAL(released()), this, SLOT(compareTexts()));

}

MainWindow::~MainWindow()
{
    delete m_listModel;
    delete ui;
}
int percentageMatch;
File_compilation run;
void MainWindow::compareTexts()
{
      QString text1 = ui->textEdit1->toPlainText().simplified();
      QString text2 = ui->textEdit2->toPlainText().simplified();
    if(ui->radioButton->isChecked()){
      percentageMatch = run.kmpSearch(text2, text1);
    }
    else if(ui->radioButton2->isChecked()){
          percentageMatch = run.rabinKarp(text2,text1);
    }
    else if(ui->radioButton3->isChecked()){
     percentageMatch= run.boyerMoore(text2, text1);
    }
    else if(ui->radioButton4->isChecked()){
       run.search(text2,text1,percentageMatch);
    }
      else if(ui->radioButton5->isChecked()){
        percentageMatch= run.hammingDistance(text2,text1);
    }
   m_listModel->setStringList(run.UniqueWords);
   ui->coincidenceBar->setValue(percentageMatch);
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Could not open file."));
        return;
    }

    QTextStream in(&file);
    ui->textEdit1->setText(in.readAll());
    file.close();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEdit1->clear();
    ui->textEdit2->clear();
    ui->coincidenceBar->setValue(0);
    m_listModel->setStringList(QStringList());
   // percentage=0;
    uniqueWordsCount = 0;
    uniqueElementsCount=0;
   run.UniqueWords.clear();
   percentageMatch=0;
}
