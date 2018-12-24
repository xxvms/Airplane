#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <map>

bool read_file_string(std::vector<std::string>&import_file);
void garment(std::vector<int>& garment, const std::vector<std::string>& coordinates);


int main() {

    std::vector<std::string>file{};

    auto test = read_file_string(file);

    if (test){
        std::cout << "test is success" << '\n';
    }else {
        std::cout << "test failed" << '\n';
    }

    for (auto a : file){

        std::cout << "reading a: " << a << '\n';

    }
    std::vector<int> garment_max(1000000,0);

    garment(garment_max, file);

    std::cout << "test";
    return 0;
}

bool read_file_string(std::vector<std::string>&import_file){



    std::ifstream file("day3test.txt");
    std::string data;
    if (!file.is_open()){
        return false;
    } else {
        while (std::getline(file, data))

            import_file.push_back(data);
        std::cout << "Success" << '\n';
    }
        return true;
}

void garment(std::vector<int>& garment, const std::vector<std::string>& coordinates){

        //#1 @ 306,433: 16x11

        std::string looking_for = "@";
        auto first = std::find(std::begin(coordinates), std::end(coordinates), looking_for);

        if (first != std::end(coordinates)){

            std::cout << "what will it print? " << *first <<  " blach " << '\n';

        } else {
            std::cout << "Does not contains what I am looking for " << '\n';
        }



        /*
         * maybe i should use for_each ? with range first last?
         * Function for_each(InputIterator first, InputIterator last, Function fn)
            {
              while (first!=last) {
              fn (*first);
              ++first;
              }
         */

        while (*first != ",")
        {
            //int one = *first;
            //garment.push_back(one);
            std::cout << "First " << *first << "<-" << '\n';
            *first++;
        }
        std::cout << "test";

}

