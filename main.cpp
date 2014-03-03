#include "rslasexportdialog.h"
#include <QApplication>
//add for test
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RSLasExportDialog w;
    w.show();

    return a.exec();
}
