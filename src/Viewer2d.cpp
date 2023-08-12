//
// Created by Jae Choi on 2023-08-12.
//

#include "../headers/Viewer2d.h"

Viewer2d::Viewer2d(QWidget *parent): QGraphicsView(parent){
        setScene(new QGraphicsScene(this));
        m_pixmapItem = scene()->addPixmap(QPixmap());
        setAlignment(Qt::AlignCenter);
}

Viewer2d::~Viewer2d()
= default;

QPixmap Viewer2d::pixmap() const {
    return m_pixmapItem->pixmap();
}

void Viewer2d::setPixmap(const QPixmap &newPixmap) {
    m_pixmapItem->setPixmap(newPixmap);
    fitInView(m_pixmapItem, Qt::KeepAspectRatio);
}

void Viewer2d::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(m_pixmapItem, Qt::KeepAspectRatio);
}
