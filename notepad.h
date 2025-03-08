#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

class Notepad : public QMainWindow {
    Q_OBJECT  // Needed for Qt signal-slot system

public:
    Notepad();
    ~Notepad();

private slots:
    void openFile();
    void saveFile();

private:
    QTextEdit *textEdit;
};

#endif  // NOTEPAD_H
