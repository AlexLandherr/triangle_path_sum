#include <vector>
#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    struct num_and_path {
        int number;
        std::string path;
    };
    std::vector<std::vector<func::num_and_path>> txt_file_to_vector(std::string file_path);
    std::string max_triangle_path_sum(std::vector<std::vector<func::num_and_path>> triangle);
}

#endif