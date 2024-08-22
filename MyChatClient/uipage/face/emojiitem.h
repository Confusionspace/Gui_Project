#ifndef EMOJIITEM_H
#define EMOJIITEM_H

#include <QLabel>

class EmojiItem : public QLabel
{
    Q_OBJECT
public:
    explicit EmojiItem(const QString &fileName, QWidget *parent = nullptr);
    ~EmojiItem();
signals:
    void sigSelectEmoji(int index);
    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
private:
    int m_emojiIndex;

    // QWidget interface
};




#endif // EMOJIITEM_H
