#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QLabel* pLabel = new QLabel("Hello, Qt!");
    pLabel->show();
    return app.exec(); 
}

