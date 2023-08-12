//
// Created by Jae Choi on 2023-08-12.
//

#ifndef IMAGE_PROCESSING_VIEWER2D_H
#define IMAGE_PROCESSING_VIEWER2D_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>

class Viewer2d: public QGraphicsView{
public:
    explicit Viewer2d(QWidget *parent = nullptr);
    ~Viewer2d() override;

    [[nodiscard]] QPixmap pixmap() const;
    void setPixmap(const QPixmap &newPixmap);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGraphicsPixmapItem *m_pixmapItem;
};

#endif //IMAGE_PROCESSING_VIEWER2D_H
