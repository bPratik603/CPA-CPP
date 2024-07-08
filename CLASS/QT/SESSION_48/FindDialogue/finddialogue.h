#ifndef FINDDIALOGUE_H
#define FINDDIALOGUE_H

#include <QObject>
#include <QWidget>
#include <QString>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

#include <QHBoxLayout>
#include <QVBoxLayout>

class FindDialogue : public QWidget
{
    Q_OBJECT
public:
    explicit FindDialogue(QWidget *parent = nullptr);

signals:
    void findNext(const QString& str, Qt::CaseSensitivity cs);
    void findPrevious(const QString& str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString& text);

private:
    QLabel* label;
    QLineEdit* lineEdit;
    QCheckBox* caseCheckBox;
    QCheckBox* backwardCheckBox;
    QPushButton* findButton;
    QPushButton* closeButton; 
};

#endif // FINDDIALOGUE_H
