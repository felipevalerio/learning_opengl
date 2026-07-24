#include <vector>
#include <stdint.h>
#include <fstream>
#include <iostream>

#pragma once

void create_ppm(int img_width, int img_height, std::vector<uint8_t>& framebuffer);
void save_ppm(const std::string& filename, int width, int height, const std::vector<uint8_t>& framebuffer);