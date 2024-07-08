#include "finddialogue.h"

FindDialogue::FindDialogue(QWidget *parent)
    : QWidget{parent}
{
    label = new QLabel("Find &What:");
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    QObject::connect(
                        lineEdit,
                        SIGNAL(textChanged(const QString&)),
                        this,
                        SLOT(enableFindButton(const QString&))
                     );

    QObject::connect(
                    findButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(findClicked())
                );


    QObject::connect(
                    closeButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(close())
                );

    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);
}
