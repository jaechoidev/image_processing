#include "headers/Viewer2d.h"
#include "headers/Image.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Image img = Image("../grid-overscan.exr");
    //img.grayscale();
    //img.grade(1,1,0.5,0.5);

    qsizetype bytes_per_line = img.width * img.nChannels;
    QImage image(&img.data[0], img.width, img.height, bytes_per_line, QImage::Format_RGBA8888);
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap.scaled(pixmap.size(), Qt::KeepAspectRatio);

    Viewer2d v;
    v.resize(640,480);
    v.setPixmap(pixmap);
    v.show();
    return a.exec();
}
