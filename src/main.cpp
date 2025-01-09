#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
     int image_width = 256;
     int image_height = 256;

     // P3 * ASCII
     // 256 256 * Col Row
     // R G B * this 256 columns * 256 rows
     std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

     for (int row = 0; row < image_height; row++) {
          std::clog << "\rScanlines remaining: " << (image_height - row) << ' ' << std::flush;

          for (int col = 0; col < image_width; col++) {
               auto pixel_color = color{double(col) / (image_width-1), 0, double(row) / (image_height-1)};
               write_color(std::cout, pixel_color);
          }
     }
     std::clog << "\rDone.                 \n";
}
