//
// Created by Tom Breza on 2018-12-26.
//

#ifndef AIRPLANE_DATA_RECORD_H
#define AIRPLANE_DATA_RECORD_H

#include <iostream>
#include <vector>


class data_record_TB {

public:
    int ID;         // 1 ID
    int w_begin;    // 2 A value
    int w_end;      // 4 A value
    int h_begin;    // 3 B value
    int h_end;      // 5 B value
    int counter;
public:
    //data_record_TB();
    data_record_TB(int id, int w_beg, int w_en, int h_beg, int h_en): ID(id), w_begin(w_beg), w_end(w_en), h_begin(h_beg), h_end(h_en), counter(0){};
    ~data_record_TB();
    void print();
    void counter_print();
    void set_grid_right(std::vector<int> &The_grid, std::vector<data_record_TB>& The_data);
    void read_data_from_grid(std::vector<int> &The_grid, std::vector<data_record_TB>& The_data);
};


#endif //AIRPLANE_DATA_RECORD_H
