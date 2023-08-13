//
// Created by Jae Choi on 2023-08-12.
//

#ifndef IMAGE_PROCESSING_IMAGE_H
#define IMAGE_PROCESSING_IMAGE_H

#include <string>
#include <OpenImageIO/imageio.h>
#include "ImageProcess.h"

class Image{
public:
    explicit Image(const std::string&);
    ~Image();

    void save();
    void saveAs(std::string);

    void grayscale() const;
    void grade(double, double, double, double);
    void grade(double);

    std::string filePath;
    std::unique_ptr<unsigned char[]> data;
    int width;
    int height;
    int nChannels;
    std::vector<std::string> channelNames;
};

#endif //IMAGE_PROCESSING_IMAGE_H
