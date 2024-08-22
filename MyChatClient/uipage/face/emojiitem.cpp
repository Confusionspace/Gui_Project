#include "emojiitem.h"
#include <QMovie>
EmojiItem::EmojiItem(const QString &fileName,QWidget *parent)
    : QLabel(parent)
{
    QMovie *iconMovie=new QMovie;
    iconMovie->setFileName(fileName);
    this->setMovie(iconMovie);
    this->setMargin(4);
    iconMovie->start();
    iconMovie->stop();

    QString suffix=".gif";
    QString lastDiagonal="/";
    int pos1=fileName.indexOf(suffix);
    int pos2=fileName.lastIndexOf(lastDiagonal)+1;
    QString emojiIndex=fileName.mid(pos2,pos1-pos2);
    m_emojiIndex=emojiIndex.toInt();
    // this->setPixmap(QString(fileName));
}

EmojiItem::~EmojiItem()
{

}
void EmojiItem::enterEvent(QEvent *event)
{
    QMovie *iconMovie=this->movie();
    iconMovie->start();
    return QLabel::enterEvent(event);
}

void EmojiItem::leaveEvent(QEvent *event)
{
    QMovie *iconMovie=this->movie();
    iconMovie->jumpToFrame(0);
    iconMovie->stop();
    return QLabel::leaveEvent(event);
}
void EmojiItem::mousePressEvent(QMouseEvent *event)
{
    emit sigSelectEmoji(m_emojiIndex);
}
