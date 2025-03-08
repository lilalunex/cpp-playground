#include "notepad.h"

Notepad::Notepad() {
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Open", this, &Notepad::openFile);
    fileMenu->addAction("Save", this, &Notepad::saveFile);
}

Notepad::~Notepad() {
    delete textEdit;
}

void Notepad::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            textEdit->setText(in.readAll());
        }
    }
}

void Notepad::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
        }
    }
}
