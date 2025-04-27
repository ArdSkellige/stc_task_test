#include "main_wgt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWgt_t w;
    w.show();
    return a.exec();
}
