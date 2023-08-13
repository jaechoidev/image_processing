//
// Created by Jae Choi on 2023-08-12.
//

#ifndef IMAGE_PROCESSING_IMAGEPROCESS_H
#define IMAGE_PROCESSING_IMAGEPROCESS_H

#include <OpenImageIO/imageio.h>

class ImageProcess {
public:
    ImageProcess();
    ~ImageProcess();

    void grayscale(std::unique_ptr<unsigned char[]> data);

};


#endif //IMAGE_PROCESSING_IMAGEPROCESS_H
