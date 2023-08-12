//
// Created by Jae Choi on 2023-08-12.
//

#include "../headers/Image.h"

Image::Image(std::string _filePath)
{
    auto inp = OIIO::ImageInput::open(_filePath);
    // need to handle if (! inp)
    auto &spec = inp->spec();
    this->width = spec.width;
    this->height = spec.height;
    this->nchannels = spec.nchannels;
    this->data = std::unique_ptr<unsigned char[]>(new unsigned char[width * height * nchannels]);
    inp->read_image(0, 0, 0, nchannels, OIIO::TypeDesc::UINT8, &data[0]);
    inp->close();
}

Image::~Image()
{
}
/*
 *

    std::cout << nchannels << std::endl;
    for (int i = 0; i < (xres * yres * nchannels-1); i+=nchannels){
        pixels[i] *= 0.2126;
        pixels[i+1] *= 0.7152;
        pixels[i+2] *= 0.0722;
        pixels[i+3] *= 1;
    }

    const char *filename = "test_gray.jpg";
    const int channels = 3;  // RGB
    std::unique_ptr<ImageOutput> out = ImageOutput::create (filename);
    if (! out)
        return 0;
    out->open (filename, spec);
    out->write_image (TypeDesc::UINT8, &pixels[0]);
    out->close ();
    return 0;
 */