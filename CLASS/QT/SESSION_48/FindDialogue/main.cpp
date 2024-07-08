#include <QApplication> 
#include "finddialogue.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv); 
    FindDialogue* findDialogue = new FindDialogue; 
    findDialogue->show(); 
    return app.exec(); 
}