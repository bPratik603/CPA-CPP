#ifndef GRAVITYCALCULATORDIALOG_H
#define GRAVITYCALCULATORDIALOG_H

#include <QObject>
#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include <QDialog>

#include <QHBoxLayout>
#include <QVBoxLayout>

class GravityCalculatorDialog : public QDialog
{
    Q_OBJECT
public:
    GravityCalculatorDialog(QWidget* parent = nullptr);
public slots:
    void getMass1(const QString& strMass1);
    void getMass2(const QString& strMass2);
    void getDistance(const QString& strDistance);
    void doCompute();
    void doClear();

private:
    QLabel* pLabelMass1;
    QLabel* pLabelMass2;
    QLabel* pLabelDistance;
    QLabel* pLabelOutput;

    QLineEdit* pTextBoxForMass1;
    QLineEdit* pTextBoxForMass2;
    QLineEdit* pTextBoxForDistance;

    QPushButton* pComputeButton;
    QPushButton* pClearButton;
    QPushButton* pExitButton;

    QHBoxLayout* pEntry1;
    QHBoxLayout* pEntry2;
    QHBoxLayout* pEntry3;

    QVBoxLayout* pLeftLayout;

    QVBoxLayout* pRightLayout;
    QHBoxLayout* pDialogLayout;

    double m1, m2, r;

};

#endif // GRAVITYCALCULATORDIALOG_H
