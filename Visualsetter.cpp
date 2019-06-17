#include "Visualsetter.h"
#include <QPalette>
#define DEFAULT_SIZE 12
#define DEFAULT_TEXT_COLOR black
#define DEFAULT_BG_COLOR white


VisualSetter::VisualSetter(QTextEdit*text)
{
   setter = text;
   fontSize = DEFAULT_SIZE;
   bgColor = Qt::DEFAULT_BG_COLOR;
   fontColor = Qt::DEFAULT_TEXT_COLOR;
}

void VisualSetter::setFontStyle(const QString style)
{
   this->fontStyle = style;
   setter->setFontFamily(this->fontStyle);
}

void VisualSetter::setFontColor(const QColor color)
{
   this->fontColor=color;
   setter->setTextColor(this->fontColor);
}

void VisualSetter::setBgColor(const QColor bg_color)
{
   QPalette col = setter->palette();
   col.setColor(QPalette::Base,bg_color);
   setter->setPalette(col);
}

void VisualSetter::setFontSize(int font_size)
{
   this->fontSize = font_size;
   setter->setFontPointSize(this->fontSize);
}

void VisualSetter::setTextBgColor(const QColor text_bg_color)
{
   this->textBgColor = text_bg_color;
   setter->setTextBackgroundColor(this->textBgColor);
}

VisualSetter::~VisualSetter(){}
