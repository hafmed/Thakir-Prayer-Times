#include "thakir_prayer_times.h"
#include "./ui_thakir_prayer_times.h"

thakir_prayer_times::thakir_prayer_times(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::thakir_prayer_times)
{
    ui->setupUi(this);
}

thakir_prayer_times::~thakir_prayer_times()
{
    delete ui;
}
