#include <QApplication>
#include "notepad.h"
#include "math_utils.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    Notepad window;
    window.show();
    
    int result = add(5, 3);
    qDebug() << "5 + 3 = " << result;  // Debug output
    
    return app.exec();
}
