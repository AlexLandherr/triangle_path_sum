#include "include/functions.h"
#include <iostream>
#include <vector>
#include <string>

/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

    3
   7 4
  2 4 6
 8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below (shown in 'prob18_image.png').
*/

int main() {
    std::vector<std::vector<int>> triangle_vec = func::txt_file_to_vector("num_triangle.txt");
    //Printing out the triangle; row by row without any formatting to shape output into a triangle as in example above.
    for (std::vector<int> row : triangle_vec) {
        std::string row_str;
        for (int i : row) {
            if (i < 10) {
                row_str += "0" + std::to_string(i) + " ";
            } else {
                row_str += std::to_string(i) + " ";
            }
        }
        std::cout << row_str << '\n';
    }

    return 0;
}