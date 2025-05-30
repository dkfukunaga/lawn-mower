

#include "lawndriver.h"
#include <random>
#include <time.h>
#include <memory>
#include <iostream>
#include <cstdlib>  // For std::stoi
#include <getopt.h> // For getopt
#include <algorithm> // For std::remove


// int main(int argc, char* argv[]) {

//     srand(time(NULL));

//     // default to randomly sized lawn ranging from 7x7 to 22x22
//     int height = rand() % 15 + 7;
//     int width = rand() % 15 + 7;

//     // command line argument code generated by chatgpt
//     int opt;
//     while ((opt = getopt(argc, argv, "w:h:s:")) != -1) {
//         switch (opt) {
//             case 'w':
//                 width = std::stoi(optarg);
//                 break;
//             case 'h':
//                 height = std::stoi(optarg);
//                 break;
//             case 's': {
//                 std::string size(optarg);

//                 // Clean input (remove spaces)
//                 size.erase(remove(size.begin(), size.end(), ' '), size.end());

//                 // Ensure format is strictly "WxH"
//                 size_t x_pos = size.find('x');
//                 if (x_pos != std::string::npos && x_pos > 0 && x_pos < size.length() - 1) {
//                     width = std::stoi(size.substr(0, x_pos));
//                     height = std::stoi(size.substr(x_pos + 1));
//                 } else {
//                     std::cerr << "Invalid size format. Use -s WxH (e.g., -s 12x15)." << std::endl;
//                     return 1;
//                 }
//                 break;
//             }
//             default:
//                 std::cerr << "Usage: " << argv[0] << " [-w width] [-h height] [-s WxH]" << std::endl;
//                 return 1;
//         }
//     }

//     std::unique_ptr<Lawn> lawn = std::make_unique<Lawn>(width, height);
//     std::unique_ptr<Mower> mower = std::make_unique<Mower>(*lawn);
//     std::unique_ptr<LawnDisplay> lawn_display = std::make_unique<LawnDisplay>(*lawn, *mower);

//     lawn_display->draw();

//     // program logic
//     return 0;
//   }



