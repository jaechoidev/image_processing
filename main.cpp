#include "headers/Viewer2d.h"
#include "headers/Image.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Image img = Image("../dog.jpg");
    //Image img = Image("../grid-overscan.exr");
    //img.grayscale();
    //img.grade(1,1,0.5,0.5);
    img.blur(10, {{1,1,1},{1,1,1},{1,1,1}});

    auto format = img.nChannels == 4 ? QImage::Format_RGBA8888 : QImage::Format_RGB888;
    qsizetype bytes_per_line = img.width * img.nChannels;
    QImage image(&img.data[0], img.width, img.height, bytes_per_line, format);
    QPixmap pixmap = QPixmap::fromImage(image);
    pixmap.scaled(pixmap.size(), Qt::KeepAspectRatio);

    Viewer2d v;
    v.resize(img.width,img.height);
    v.setPixmap(pixmap);
    v.show();
    return a.exec();
}
