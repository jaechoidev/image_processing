//
// Created by Jae Choi on 2023-08-12.
//

#ifndef IMAGE_PROCESSING_IMAGE_H
#define IMAGE_PROCESSING_IMAGE_H

#include <string>
#include <OpenImageIO/imageio.h>

class Image {
public:
    Image(std::string);
    ~Image();

    void save();
    void saveAs(std::string);

    std::string filePath;
    std::unique_ptr<unsigned char[]> data;
    int width;
    int height;
    int nchannels;
};

#endif //IMAGE_PROCESSING_IMAGE_H
