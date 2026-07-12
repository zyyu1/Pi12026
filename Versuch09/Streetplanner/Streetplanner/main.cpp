#include "mainwindow.h"

#include <QApplication>

/**
 * @brief Application entry point.
 *
 * Creates the Qt application object, shows the main window,
 * and starts the event loop.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
