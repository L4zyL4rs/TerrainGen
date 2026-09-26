#pragma once
#include "TerrainGenSettings.h"
#include <stdlib.h>
#include <fstream>

struct TerrainData {
  TerrainData(TerrainGenSettings settings) : height(settings.height), width(settings.width) {
    initData();
  }
  int height{};
  int width{};

  int& get(int pointHeight, int pointWidth) {
    int offset = (pointHeight - 1) * width + pointWidth - 1;
    return *(data + offset);
  }

  void initData() {
    data = static_cast<int*>(malloc(height * width * sizeof(int)));
    for(int i= 0; i < height * width; i++) {
      *(data + i) = 100;
    }
  }

  void write() {
    std::ofstream ofs("terrain.ppm", std::ios_base::out | std::ios_base::binary);
    ofs << "P6\n" << width << ' ' << height << "\n255\n";

    for(int h{}; h <= height; h++) {
      for(int w{}; w <= width; w++) {

        // I want greyscale so I just write RGB all the same color
        for(int i{}; i < 3; i++) {
          ofs << static_cast<char>(get(h, w));
        }

      }
    }

  }


private:
  // Don't try to write here manually, I will only break things
  int* data{};
};

