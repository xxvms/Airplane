#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "data_record_TB.h"
//My solution returns 105071 square inches


bool read_file_string(std::vector<std::string>&import_file);
void data_processing_stage1(std::vector<std::string> &coordinates_from_file, std::vector<int> &raw_co);
void setting_up_coordinates(const std::vector<int>& raw, std::vector<data_record_TB>& ready_data_for_use);


int main() {

    std::vector<std::string>data_from_file{};
    std::vector<int>raw_coordinates{};

    auto test = read_file_string(data_from_file);

    if (test){
        std::cout << "test is success" << '\n';
    }else {
        std::cout << "test failed" << '\n';
    }

    std::vector<int> garment_max(1000000,0); // it is used now

    data_processing_stage1(data_from_file, raw_coordinates); // reading file and saving it as string

    std::vector<data_record_TB> my_data_class{}; // vector of my type files

    setting_up_coordinates(raw_coordinates, my_data_class); // converting data to my format

    my_data_class.at(0).set_grid_right(garment_max, my_data_class); // setting up coordinates on the grid for later retrieval

    my_data_class.at(0).read_data_from_grid(garment_max, my_data_class); // updating counter in my class with the answers I get from set_grid_right

    int tmp_counter = 0;

    for (auto a : my_data_class){

           tmp_counter += a.counter;

           std::cout << "value of counter: " << tmp_counter << '\n';

    }

    std::cout << "test";


    return 0;
}

void setting_up_coordinates(const std::vector<int>& raw, std::vector<data_record_TB>& ready_data_for_use){
    int i = 0;
    for ( ;  i < raw.size(); i+=5) {

        data_record_TB one(raw.at(i), raw.at(i + 1), (raw.at(i + 1) +  raw.at(i + 3)),
                           raw.at(i + 2), (raw.at(i + 2) + raw.at(i + 4)));
        ready_data_for_use.push_back(one);

    }
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

void data_processing_stage1(std::vector<std::string> &coordinates_from_file, std::vector<int> &raw_co){ // converting from file to string to vector of ints
        std::string value_to_keep_string{};
        std::vector<std::string>values{};

        for (auto a: coordinates_from_file){
            std::string test{};
            for (auto b: a){
                if (isdigit(b)){
                    if (b){
                        test.insert(0, 1, b);
                        value_to_keep_string.append(test);
                        test = "";
                    }
                }else{
                    if (!value_to_keep_string.empty()){
                        values.push_back(value_to_keep_string);
                    }
                    value_to_keep_string = "";
                }
            }
            if (!value_to_keep_string.empty()){
                values.push_back(value_to_keep_string);
                value_to_keep_string = "";
            }
            std::string separator{"000000000"};
        }
        std::cout << "test\n";

        for (int i =0; i < values.size(); i++){
            raw_co.push_back(std::stoi(values.at(i)));
        }
}

