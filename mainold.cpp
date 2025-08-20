#include "thakir_prayer_times.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    thakir_prayer_times w;
    w.show();
    return a.exec();
}
