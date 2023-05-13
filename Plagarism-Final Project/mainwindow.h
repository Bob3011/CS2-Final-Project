#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringListModel* m_listModel;
 //   int percentage = 0;
   int uniqueWordsCount;
  int  uniqueElementsCount;

private slots:
    void compareTexts();
    void on_pushButton_clicked();
    void on_pushButtonClear_clicked();
};
#endif // MAINWINDOW_H
