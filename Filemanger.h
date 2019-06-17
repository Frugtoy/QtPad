#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFile>
#include <QTextStream>


class FileManager
{
public:
    FileManager();

    void createFile( QString &filepath);
    void saveFile(QString&filepath,QString& text);
    QString openFile(QString filepath,QTextCodec* codec);
    QString _filepath;

    ~FileManager();

};

#endif // FILEMANAGER_H
