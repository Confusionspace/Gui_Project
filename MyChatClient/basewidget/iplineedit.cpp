#include "iplineedit.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QRegExp>
#include <QRegExpValidator>
#include <QEvent>
#include <QKeyEvent>
IPLineEdit::IPLineEdit(QWidget *parent)
    :QLineEdit(parent)
{
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->setContentsMargins(2,2,2,2);
    QRegExp regExp("(25[0-5]|2[0-4][0-9]|1?[0-9]{1,2})");
    QLabel *labledot[3];
    for(int i=0;i<IP_INPUT_SIZE;i++)
    {
        m_lineEdilt[i]=new QLineEdit(this);
        //在样式表中选择特定样式，条件就是控件的属性property的ip=true
        m_lineEdilt[i]->setProperty("ip",true);
        //保存线条编辑是否使用边框绘制本身
        m_lineEdilt[i]->setFrame(false);
        //输入框的最大长度为3位数
        m_lineEdilt[i]->setMaxLength(3);
        //消除布局中的空隙，居中
        m_lineEdilt[i]->setAlignment(Qt::AlignCenter);
        //保存小部件的默认布局
        m_lineEdilt[i]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

        //添加验证规则
        m_lineEdilt[i]->setValidator(new QRegExpValidator(regExp,this));
        //安装事件过滤器，过滤子控件事件，截获空间按键，鼠标事件
        m_lineEdilt[i]->installEventFilter(this);

        hboxlayout->addWidget(m_lineEdilt[i]);
        if(i<3)
        {
            labledot[i]=new QLabel(this);
            labledot[i]->setText(".");
            labledot[i]->setFixedWidth(2);
            hboxlayout->addWidget(labledot[i]);
        }
        this->setReadOnly(true);
        m_lineEdilt[0]->setFocus();
        m_lineEdilt[0]->selectAll();
    }

}
IPLineEdit::~IPLineEdit()
{

}

QString IPLineEdit::text()
{
    //获取IP地址
    //例如192.168.1.1
    QString ip;
    for(int i=0;i<IP_INPUT_SIZE;i++)
    {
        ip.append(m_lineEdilt[i]->text());
        if(i!=3)
        {
            ip.append(".");
        }
    }
    return ip;
}

bool IPLineEdit::eventFilter(QObject *watched, QEvent *event)
{
    if(children().contains(watched)&&QEvent::KeyPress==event->type())
    {
        QKeyEvent *keyEvent=dynamic_cast<QKeyEvent*>(event);
        QLineEdit *pCurrent=qobject_cast<QLineEdit*>(watched);

        switch(keyEvent->key())
        {
            case Qt::Key_0:
            case Qt::Key_1:
            case Qt::Key_2:
            case Qt::Key_3:
            case Qt::Key_4:
            case Qt::Key_5:
            case Qt::Key_6:
            case Qt::Key_7:
            case Qt::Key_8:
            case Qt::Key_9:
            {
                QString strtext=pCurrent->text();
                if(strtext.length()<=3&&strtext.toInt()*10>255)
                {
                    int index=getIndex(pCurrent);
                    if(index!=-1&&index!=3)
                    {
                        m_lineEdilt[index+1]->setFocus();
                        m_lineEdilt[index+1]->selectAll();
                    }
                }
            }
            break;
            case Qt::Key_Left:
            {
                {
                    if(!pCurrent->cursorPosition())
                    {
                        int index=getIndex(pCurrent);
                        if(index!=-1&&index!=0)
                        {
                            m_lineEdilt[index-1]->setFocus();
                            int length=m_lineEdilt[index-1]->text().length();
                            m_lineEdilt[index-1]->setCursorPosition(length?length:0);
                        }
                    }
                }
                return QLineEdit::eventFilter(watched,event);
            }
            break;
            case Qt::Key_Right:
            {
                if (pCurrent->cursorPosition() == pCurrent->text().length())
                {
                    int index=getIndex(pCurrent);
                    if(index!=-1&&index!=3)
                    {
                        m_lineEdilt[index+1]->setFocus();
                        m_lineEdilt[index+1]->setCursorPosition(0);

                    }
                }
                return QLineEdit::eventFilter(watched,event);
            }
            break;
            case Qt::Key_Backspace: //后退键
            {
                QString strText=pCurrent->text();
                if(strText.isEmpty())
                {
                    int index=getIndex(pCurrent);
                    if(index!=-1&&index!=0)
                    {
                        m_lineEdilt[index-1]->setFocus();
                        int length=m_lineEdilt[index-1]->text().length();
                        m_lineEdilt[index-1]->setCursorPosition(length?length:0);
                    }
                }
                return QLineEdit::eventFilter(watched,event);
            }
            break;
            case Qt::Key_Period:
            {
                int index=getIndex(pCurrent);
                if(index!=-1&&index!=3)
                    {
                    m_lineEdilt[index+1]->setFocus();
                    m_lineEdilt[index+1]->setCursorPosition(0);

                    }

                return QLineEdit::eventFilter(watched,event);

            }
            break;
        }
    }
}

int IPLineEdit::getIndex(QLineEdit *pLineEdit)
{
    int index=-1;
    for(int i=0;i<IP_INPUT_SIZE;i++)
    {
        if(pLineEdit==m_lineEdilt[i])
        {
            index=i;
        }
    }
    return index;
}
