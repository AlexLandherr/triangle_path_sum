#include "include/functions.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

    3
   7 4
  2 4 6
 8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below (shown in 'prob18_image.png').
*/

namespace func {
    std::vector<std::vector<int>> txt_file_to_vector(std::string file_path) {
        std::vector<std::vector<int>> triangle;
        std::fstream triangle_file(file_path);
        std::string single_line;

        while (std::getline(triangle_file, single_line)) {
            std::vector<int> triangle_row;

            //Remove irrelevant chars from line.
            single_line.erase(std::remove(single_line.begin(), single_line.end(), ' '), single_line.cend());
            single_line.erase(std::remove(single_line.begin(), single_line.end(), '\n'), single_line.cend());

            //Extract digit pair/number, turn into int and then add to triangle_row vector.
            for (int i = 0; i < static_cast<int>(single_line.length()); i+=2) {
                triangle_row.push_back(std::stoi(single_line.substr(i, 2)));
            }

            //Add triangle_row to grid vector.
            triangle.push_back(triangle_row);
        }

        return triangle;
    }
}