#ifndef VISUALSETTER_H
#define VISUALSETTER_H
#include <QTextEdit>
#include <QColor>

class VisualSetter
{
public:
    VisualSetter(QTextEdit* text);

    void setFontStyle(const QString fontStyle);
    void setFontColor(const QColor fontColor);
    void setBgColor(const QColor bgColor);
    void setFontSize(int size);
    void setTextBgColor(const QColor);
    QColor bgColor;
    QColor fontColor;
    QColor textBgColor;
    QString fontStyle;
    int fontSize;

    ~VisualSetter();
private:
    QTextEdit *setter;

   //QColor bgColor  and also fontColor in private is not provided by a function in mainwindow.cpp


};

#endif // VISUALSETTER_H
