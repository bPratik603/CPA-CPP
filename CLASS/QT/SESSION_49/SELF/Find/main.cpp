#include <QApplication>

#include "finddialog.h"

int main(int args,char *argv[]){
    QApplication app(argc,argv);
    Finddialog *dialog = new Finddialog;
    dialog->show();
    return app.exec;
}