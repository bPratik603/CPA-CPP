#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>

class Finddialog : public QObject
{
    Q_OBJECT
public:
    Finddialog(QWidget *parent = nullptr);

signals:
     void findNext(const QString &str,Qt::CaseSensitivity cs);
     void findPrevious(const QString &str,Qt::CaseSensitivity cs);

private slots:
     void findClicked();
     void enableFindButton(const QString &text);

     private:
     QLabel *label;
     QLineEdit *lineEdit;
     QCheckBox *caseCheckBox;
     QCheckBox *backwardCheckBox;
     QPushButton *findButton;
     QPushButton *closeButton;

};

#endif // FINDDIALOG_H
