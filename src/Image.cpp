//
// Created by Jae Choi on 2023-08-12.
//

#include "../headers/Image.h"

Image::Image(const std::string& _filePath) {
    auto inp = OIIO::ImageInput::open(_filePath);
    // need to handle if (! inp)
    auto &spec = inp->spec();
    this->width = spec.width;
    this->height = spec.height;
    this->nChannels = spec.nchannels;
    for (int i = 0; i < spec.nchannels; ++i){
        std::cout << "Channel " << i << " is " << spec.channelnames[i] << std::endl;
        channelNames.push_back(spec.channelnames[i]);
    }

    this->data = std::unique_ptr<unsigned char[]>(new unsigned char[width * height * nChannels]);
    inp->read_image(0, 0, 0, nChannels, OIIO::TypeDesc::UINT8, &data[0]);
    inp->close();

}

Image::~Image()
{
}

void Image::grayscale() const {
    for (int i = 0; i < (width * height * nChannels - 1); i+=nChannels){
        double gray = (data[i] + data[i+1] + data[i+2])/3;
        double lum = data[i]*0.0722 + data[i+1]*0.7152 + data[i+2]*0.2126;
        data[i] = gray;
        data[i+1] = gray;
        data[i+2] = gray;
        data[i+3] *= 1;
    }
}

void Image::grade(double r, double g, double b, double a) {
//    std::cout << "r : " << r << std::endl;
//    std::cout << "g : " << g << std::endl;
//    std::cout << "b : " << b << std::endl;
//    std::cout << "data[i] : " << double(data[0]) << std::endl;
//    std::cout << "data[i+1] : " << double(data[1]) << std::endl;
//    std::cout << "data[i+2] : " << double(data[2]) << std::endl;
//    std::cout << "data[i+3] : " << double(data[3]) << std::endl;
    for (int i = 0; i < (width * height * nChannels); i+=nChannels){
        data[i] = double(data[i]) * r;
        data[i+1] = double(data[i+1]) * g;
        data[i+2] = double(data[i+2]) * b;
        data[i+3] = double(data[i+3]) * a;
    }
//    std::cout << "data[i] : " << double(data[0]) << std::endl;
//    std::cout << "data[i+1] : " << double(data[1]) << std::endl;
//    std::cout << "data[i+2] : " << double(data[2]) << std::endl;
//    std::cout << "data[i+3] : " << double(data[3]) << std::endl;
}

void Image::grade(double f) {
    for (int i = 0; i < (width * height * nChannels - 1); i+=nChannels){
        data[i] *= f;
        data[i+1] *= f;
        data[i+2] *= f;
        data[i+3] *= 1;
    }
}


/*
 *

    std::cout << nChannels << std::endl;
    for (int i = 0; i < (xres * yres * nChannels-1); i+=nChannels){
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