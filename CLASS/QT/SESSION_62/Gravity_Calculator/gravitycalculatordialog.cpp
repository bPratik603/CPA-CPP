#include "gravitycalculatordialog.h"


GravityCalculatorDialog::GravityCalculatorDialog(QWidget* parent) : QDialog(parent)
{
    pLabelMass1 = new QLabel(tr("Enter mass of first object:"));
    pLabelMass2 = new QLabel(tr("Enter mass of second object:"));
    pLabelDistance = new QLabel(tr("Enter distance between masses:"));
    pLabelOutput = new QLabel(tr(""));

    pTextBoxForMass1 = new QLineEdit;
    pTextBoxForMass2 = new QLineEdit;
    pTextBoxForDistance = new QLineEdit;

    pLabelMass1->setBuddy(pTextBoxForMass1);
    pLabelMass2->setBuddy(pTextBoxForMass2);
    pLabelDistance->setBuddy(pTextBoxForDistance);

    pComputeButton = new QPushButton(tr("Compute"));
    pClearButton = new QPushButton(tr("Clear"));
    pExitButton = new QPushButton(tr("Exit"));

    connect(pTextBoxForMass1,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(getMass1(QString))
            );

    connect(pTextBoxForMass2,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(getMass2(QString))
            );

    connect(pTextBoxForDistance,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(getDistance(QString))
            );

    connect(pComputeButton,
            SIGNAL(clicked()),
            this,
            SLOT(doCompute())
            );

    connect(pClearButton,
            SIGNAL(clicked()),
            this,
            SLOT(doClear())
            );

    connect(pExitButton,
            SIGNAL(clicked()),
            this,
            SLOT(close())
            );

    pEntry1 = new QHBoxLayout;
    pEntry1->addWidget(pLabelMass1);
    pEntry1->addWidget(pTextBoxForMass1);

    pEntry2 = new QHBoxLayout;
    pEntry2->addWidget(pLabelMass2);
    pEntry2->addWidget(pTextBoxForMass2);

    pEntry3 = new QHBoxLayout;
    pEntry3->addWidget(pLabelDistance);
    pEntry3->addWidget(pTextBoxForDistance);

    pLeftLayout = new QVBoxLayout;
    pLeftLayout->addLayout(pEntry1);
    pLeftLayout->addLayout(pEntry2);
    pLeftLayout->addLayout(pEntry3);
    pLeftLayout->addWidget(pLabelOutput);

    pRightLayout = new QVBoxLayout;
    pRightLayout->addWidget(pComputeButton);
    pRightLayout->addWidget(pClearButton);
    pRightLayout->addWidget(pExitButton);

    pDialogLayout = new QHBoxLayout;
    pDialogLayout->addLayout(pLeftLayout);
    pDialogLayout->addLayout(pRightLayout);

    setLayout(pDialogLayout);
    setWindowTitle("Gravity Calculator");
}

void GravityCalculatorDialog::getMass1(const QString& strMass1)
{
    m1 = strMass1.toDouble();

}

void GravityCalculatorDialog::getMass2(const QString& strMass2)
{
    m2 = strMass2.toDouble();
}

void GravityCalculatorDialog::getDistance(const QString& strDistance)
{
    r = strDistance.toDouble();
}

void GravityCalculatorDialog::doCompute()
{
    double G = 6.67e-11;
    double F = (G*m1*m2)/(r*r);
    QString forceStr;
    forceStr.setNum(F, 'g', 12);
    pLabelOutput->setText(QString(tr("Gravitation force is:")) + forceStr);
}

void GravityCalculatorDialog::doClear()
{
    pTextBoxForMass1->clear();
    pTextBoxForMass2->clear();
    pTextBoxForDistance->clear();
    pLabelOutput->clear();
}
