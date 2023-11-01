#include "include/functions.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

namespace func {
    std::vector<std::vector<func::num_and_path>> txt_file_to_vector(std::string file_path) {
        std::vector<std::vector<func::num_and_path>> triangle;
        std::fstream triangle_file(file_path);
        std::string single_line;

        while (std::getline(triangle_file, single_line)) {
            //std::vector that hold a single row of the triangle.
            std::vector<func::num_and_path> triangle_row;

            //Variable to hold each extracted token from a single line of the text file.
            std::string token;

            //Constructing std::stringstream from single_line std::string.
            std::stringstream s_stream(single_line);

            /*Read the std::stringstream and split it when ' ' char is encountered,
            then put the split-off string in token, convert token to int and put it in triangle_row.*/
            while (getline(s_stream, token, ' ')) {
                func::num_and_path temp_result = {.number = std::stoi(token)};
                triangle_row.push_back(temp_result);
            }

            //Put triangle_row into triangle.
            triangle.push_back(triangle_row);
        }

        return triangle;
    }

    std::string max_triangle_path_sum(std::vector<std::vector<func::num_and_path>> triangle) {
        for (int row = (static_cast<int>(triangle.size() - 2)); row >= 0; row--) {
            for (int col = 0; col < static_cast<int>(triangle[row].size()); col++) {
                int num_left = triangle[row + 1][col].number;
                int num_right = triangle[row + 1][col + 1].number;
                int c = triangle[row][col].number;
                if (num_left + c > num_right + c) {
                    triangle[row][col].number = num_left + c;
                    std::string temp_str = "L" + triangle[row + 1][col].path;
                    triangle[row][col].path.insert(0, temp_str);
                } else {
                    triangle[row][col].number = num_right + c;
                    std::string temp_str = "R" + triangle[row + 1][col + 1].path;
                    triangle[row][col].path.insert(0, temp_str);
                }
            }
        }

        return std::to_string(triangle[0][0].number) + triangle[0][0].path;
    }
}