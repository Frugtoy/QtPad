#include "qtpad.h"
#include "ui_qtpad.h"
#include "Visualsetter.h"
#include <qfiledialog.h>
#include <qstring.h>
#include <QColorDialog>
#include <QInputDialog>
#include <QTextCodec>
QtPad::QtPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtPad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    file_manager = new FileManager();
    setter = new VisualSetter(ui->textEdit);
    compiler = new Compiler;
    connect(ui->openFile, &QAction::triggered,this, &QtPad::openFileSlot);
    connect(ui->saveFile, &QAction::triggered,this,&QtPad::saveFileSlot);
    connect(ui->newFile, &QAction::triggered,this,&QtPad::createFileSlot);
    connect(ui->setTextSize,&QAction::triggered,this,&QtPad::changeFontSizeSlot);
    connect(ui->setTextFont,&QAction::triggered,this,&QtPad::changeFontStyleSlot);
    connect(ui->setTextColor,&QAction::triggered,this,&QtPad::changeFontColorSlot);
    connect(ui->setBackgroundColor,&QAction::triggered,this,&QtPad::changeBgColorSlot);
    connect(ui->setTextBackgroundColor,&QAction::triggered,this,&QtPad::changeTextBgSlot);
    connect(ui->compile,&QAction::triggered,this,&QtPad::compileSlot);
    connect(ui->copy,&QAction::triggered,this,&QtPad::copySlot);
    connect(ui->paste,&QAction::triggered,this,&QtPad::pasteSlot);
    connect(ui->cut,&QAction::triggered,this,&QtPad::cutSlot);
    connect(ui->undo,&QAction::triggered,this,&QtPad::undoSlot);
    connect(ui->redo,&QAction::triggered,this,&QtPad::redoSlot);
}

QtPad::~QtPad()
{
    delete ui;
    delete file_manager;
    delete setter;
}


void QtPad::createFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this,tr ("create file"),"/home",tr(""));
    file_manager->_filepath = path;
    file_manager->createFile(path);
}

void QtPad::saveFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this,tr("save file"),"/home",tr(""));
    if(path!="")
    {
        QString text = ui->textEdit->toPlainText();
        file_manager->saveFile(path,text);
    }
}
void QtPad::openFileSlot()
{
    QStringList file_codec_list;
    file_codec_list<<tr("UTF-8")<<tr("UTF-16")<<tr("UTF-32")<<("Win_1251")<<("KOI-8R");
    bool check;
    QString file_codec = QInputDialog::getItem(this,tr("choose codec: "),tr("codec"),file_codec_list,0,false,&check);
    if(check)
    {
        QTextCodec* text_codec = QTextCodec::codecForName(file_codec.toStdString().c_str());
        QString path = QFileDialog::getOpenFileName(this,tr("open file"),"/home",tr(""));
        if(path!="")
        {
            QString text = file_manager->openFile(path,text_codec);
            ui->textEdit->setPlainText(text);
        }
    }
}

void QtPad::changeFontColorSlot()
{
    setter->setFontColor(QColorDialog::getColor(setter->fontColor,this));
}


void QtPad::changeFontStyleSlot()
{
    QStringList styles;
    styles<<tr("TimesNewRoman")<<tr("Ubuntu")<<tr("Bitestream Cyberbit");
    const QString font_style = QInputDialog::getItem(this,tr("Set Font style"),tr("font list"),styles,0,false);
    setter->setFontStyle(font_style);
}

void QtPad::changeFontSizeSlot()
{
    setter->setFontSize(QInputDialog::getInt(this,tr("Size of font"),nullptr,100,1));
}

void QtPad::changeBgColorSlot()
{
    setter->setBgColor(QColorDialog::getColor(setter->bgColor,this));
}

void QtPad::changeTextBgSlot()
{
    setter->setTextBgColor(QColorDialog::getColor(setter->textBgColor,this));
}

void QtPad::compileSlot()
{
    compiler->compile(file_manager->_filepath);
}

void QtPad::copySlot()
{
    ui->textEdit->copy();
}
void QtPad::pasteSlot()
{
    ui->textEdit->paste();
}
void QtPad::cutSlot()
{
    ui->textEdit->cut();
}
void QtPad::undoSlot()
{
    ui->textEdit->undo();
}
void QtPad::redoSlot()
{
    ui->textEdit->redo();
}
