#include <stdio.h>
#include <stdlib.h>
#include "c_img.h"
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void change_brightness(struct rgb_img * img, int height, int width, float mult)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            uint8_t rVal = mult * get_pixel(img, y, x, 0);
            uint8_t gVal = mult * get_pixel(img, y, x, 1);
            uint8_t bVal = mult * get_pixel(img, y, x, 2);
            set_pixel(img, y, x, MIN(rVal, 255), MIN(gVal, 255), MIN(bVal, 255));
        }
    }

}

int main(void)
{
    float mults[] = {0.03, 0.5, 1.9, 2.9, 8.9};
    char *files[] = {"f1.bin", "f2.bin", "f3.bin", "f4.bin", "f5.bin"};

    for (int i = 0; i < 5; i++)
    {
        float mult = mults[i];
        struct rgb_img *image;
        read_in_img(&image, "mericgertler.bin"); // og image bin file
        int height = image->height;
        int width = image->width;

        change_brightness(image, height, width, mult);
        write_img(image, files[i]);
        destroy_image(image);
    }
}