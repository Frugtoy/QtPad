#ifndef QTPAD_H
#define QTPAD_H

#include <QMainWindow>
#include <Filemanger.h>
#include <Visualsetter.h>
#include <compiler.h>

namespace Ui {
class QtPad;
}

class QtPad : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtPad(QWidget *parent = nullptr);
    
    ~QtPad();

private slots:
    void createFileSlot();
    void saveFileSlot();
    void saveFileAsSlot();
    void openFileSlot();
    void changeFontStyleSlot();
    void changeFontColorSlot();
    void changeFontSizeSlot();
    void changeBgColorSlot();
    void changeTextBgSlot();
    //void compileSlot();
    void copySlot();
    void pasteSlot();
    void cutSlot();
    void undoSlot();
    void redoSlot();


private:
    Ui::QtPad *ui;
    FileManager* fileManager;
    VisualSetter* setter;
 //    Compiler* compiler;
};//

#endif // QTPAD_H
