#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <QWidget>
#include <QLabel>

class AbstractCell : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractCell(QWidget *parent = 0);
    virtual void enterEvent(QEvent* event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
signals:
    mouseClicked();
    mouseClickedMineButton();
    mouseClickReleased();
    mouseHovered();
    mouseReleased();
public slots:

protected:
    void updateGrpahic(const QString& name);
    void resizeCell(int toSize);
private:
    QLabel mGraphic;
};

#endif // ABSTRACTCELL_H
