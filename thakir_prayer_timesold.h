#ifndef THAKIR_PRAYER_TIMES_H
#define THAKIR_PRAYER_TIMES_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class thakir_prayer_times;
}
QT_END_NAMESPACE

class thakir_prayer_times : public QMainWindow
{
    Q_OBJECT

public:
    thakir_prayer_times(QWidget *parent = nullptr);
    ~thakir_prayer_times();

private:
    Ui::thakir_prayer_times *ui;
};
#endif // THAKIR_PRAYER_TIMES_H
