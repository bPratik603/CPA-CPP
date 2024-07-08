#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel* msg = new QLabel;
    msg->setText("Hello, <b><i>Qt</i></b> World!");
    msg->show();
    return app.exec();
}
