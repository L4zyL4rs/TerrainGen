#include "TerrainGen.h"

int main() {
  TerrainGenSettings settings{};
  settings.height = 100;
  settings.width = 200;

  generateHeightmap(settings);
}
