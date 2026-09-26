#pragma once
#include "TerrainGenSettings.h"
#include "TerrainData.h"

void generateHeightmap(TerrainGenSettings settings) {
  TerrainData terrain(settings);

  terrain.write();
}

