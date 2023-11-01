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
    std::vector<std::vector<func::num_and_path>> triangle_vec = func::txt_file_to_vector("num_triangle.txt");
    //Printing out the triangle; row by row without any formatting to shape output into a triangle as in example above.
    /* for (int i = 0; i < static_cast<int>(triangle_vec.size()); i++) {
        std::string row_str;
        for (int j = 0; j < static_cast<int>(triangle_vec[i].size()); j++) {
            row_str += std::to_string(triangle_vec[i][j].number) + " ";
        }
        std::cout << row_str << '\n';
    } */
    std::cout << "The maximum total from top to bottom of the triangle below (shown in 'prob18_image.png') is:" << '\n';
    std::cout << func::max_triangle_path_sum(triangle_vec) << '\n';

    return 0;
}