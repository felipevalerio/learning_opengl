#include <vector>
#include <fstream>
#include <stdint.h>
#include <iostream>

void create_ppm(int img_width, int img_height, std::vector<uint8_t>& framebuffer) {

	for (int j = 0; j < img_height; j++) {
		for (int i = 0; i < img_width; i++) {

			auto r = double(i) / (img_width - 1);
			auto g = double(j) / (img_height - 1);
			auto b = 0.0;

			int ir = int(255.999 * r);
			int ig = int(255.999 * g);
			int ib = int(255.999 * b);

			int idx = (j * img_width + i) * 4;
			framebuffer[idx + 0] = ir;
			framebuffer[idx + 1] = ig;
			framebuffer[idx + 2] = ib;
			framebuffer[idx + 3] = 255;
		}
	}
}

void save_ppm(const std::string& filename, int width, int height, const std::vector<uint8_t>& framebuffer) {

    std::ofstream file(filename, std::ios::binary);

    if (!file) {
        std::cout << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    // Cabeçalho PPM (P6 = binário, RGB)
    file << "P6\n" << width << " " << height << "\n255\n";

    for (int i = 0; i < width * height; i++) {
        int idx = i * 4; // pula o canal alpha
        file.write(reinterpret_cast<const char*>(&framebuffer[idx]), 3); // R, G, B
    }

    file.close();
}