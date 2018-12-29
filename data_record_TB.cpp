//
// Created by Tom Breza on 2018-12-26.
//

#include "data_record_TB.h"


data_record_TB::~data_record_TB() {}

void data_record_TB::read_data_from_grid(std::vector<int> &The_grid, std::vector<data_record_TB>& The_data){

    for (int k = 0; k != The_data.size(); k++){
        for (int w = The_data.at(k).w_begin; w < The_data.at(k).w_end; w++){

            if (The_grid.at(w) < 1){
                continue;
            }else {
                The_data.at(k).counter++;
            }
        }
    }
}
void data_record_TB::set_grid_right(std::vector<int> &The_grid, std::vector<data_record_TB>& The_data) {


    for (int k = 0; k != The_data.size(); k++) {
        for (int w = The_data.at(k).w_begin; w < The_data.at(k).w_end; w++) {
            The_grid.at(w) += 1;
        }

        for (int h = The_data.at(k).h_begin; h != The_data.at(k).h_end; h++){
            The_grid.at(h) = +1;
        }
    }
}
void data_record_TB::print() {

    std::cout << "ID: " << ID << '\n';
    std::cout << "wide begin: " << w_begin << '\n';
    std::cout << "wide end: " << w_end << '\n';
    std::cout << "high begin: " << h_begin << '\n';
    std::cout << "high end: " << h_end << '\n';
    std::cout << "Counter: " << counter << '\n';
}
void data_record_TB::counter_print() {
    std::cout << "Counter: " << counter << '\n';
}
