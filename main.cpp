#include <QApplication>
#include <OpenImageIO/imageio.h>
using namespace OIIO;

int main() {
    auto inp = ImageInput::open("../grid-overscan.exr");
    if (! inp)
        return 0;
    const ImageSpec &spec = inp->spec();
    int xres = spec.width;
    int yres = spec.height;
    int nchannels = spec.nchannels;
    auto pixels = std::unique_ptr<unsigned char[]>(new unsigned char[xres * yres * nchannels]);
    inp->read_image(0, 0, 0, nchannels, TypeDesc::UINT8, &pixels[0]);
    inp->close();
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
}
