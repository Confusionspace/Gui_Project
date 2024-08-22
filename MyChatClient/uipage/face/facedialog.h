#ifndef FACEDIALOG_H
#define FACEDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QList>
#include "emojiitem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FaceDialog;
}
QT_END_NAMESPACE

class FaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FaceDialog(QWidget *parent = nullptr);
    ~FaceDialog();
    void setSelectFaceIndex(int index);
    int selectFaceIndex();
    void moveFaceLocation(QPoint p);
private slots:
    void on_toolButton_clicked();

private:
    int m_preRow;
    int m_preColumn;
    Ui::FaceDialog *ui;
    QList<EmojiItem*> m_emojiList;
    int m_selectFaceIndex;

    void addEmojiItem(const QString &filename);

};
#endif // FACEDIALOG_H
