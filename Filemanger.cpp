#include "Filemanger.h"
#include "QInputDialog"
FileManager::FileManager(){}

FileManager::~FileManager(){}

void FileManager::createFile( QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.close();
}
void FileManager::saveFile(QString&filepath,QString& text)
{
    QFile file (filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::WriteOnly);
    fstream<<text;
    file.flush();
    file.close();
}

QString FileManager::openFile(QString filepath,QTextCodec* codec)
{
    QString file_codec_list;
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::ReadOnly);
    fstream.setCodec(codec);
    QString text = fstream.readAll();
    _filepath = filepath;
    file.close();
return text;
}
