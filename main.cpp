#include "data_record_TB.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
// this solution returns 105071 square inches

bool read_file_string(std::vector<std::string> &import_file);
void data_processing_stage1(std::vector<std::string> &coordinates_from_file,
                            std::vector<int> &raw_co);
void setting_up_coordinates(const std::vector<int> &raw,
                            std::vector<data_record_TB> &ready_data_for_use);
void read_data_from_grid(std::vector<std::vector<int>> &The_grid,
                         std::vector<data_record_TB> &The_data);
void set_grid_right(std::vector<std::vector<int>> &The_grid,
                    std::vector<data_record_TB> &The_data);
int counter_result(std::vector<data_record_TB> &counter_stuff);
void save_result(int result);

int main() {

  std::vector<std::string> data_from_file{}; // file contain raw info from file
  std::vector<int> raw_coordinates{};        //
  std::vector<data_record_TB> my_data_class{}; // vector of my type files

  auto test = read_file_string(data_from_file); // double checking if file was read correctly plus
                       // playing with bool expression to get comfortable with
                       // us of it

  if (test) {
    std::cout << "test is success" << '\n';
  } else {
    std::cout << "test failed" << '\n';
  }

  std::vector<std::vector<int>> garment_max(1000, std::vector<int>(1000, 0)); // it is used now

  data_processing_stage1(data_from_file, raw_coordinates); // reading file and saving it as string

  setting_up_coordinates(raw_coordinates,my_data_class); // converting data to my format

  set_grid_right(garment_max,my_data_class); // setting up coordinates on the grid for later retrieval

  read_data_from_grid(garment_max,my_data_class); // updating counter in my class with the
                                      // answers I get from set_grid_right

  std::cout << "value of counter:: " << counter_result(my_data_class)
            << '\n'; // printing result of the counter function.

  save_result(counter_result(my_data_class));


  std::cout << "test";

  return 0;
}
void save_result(int result){

  std::ofstream my_file_result("result.txt");
  my_file_result.is_open() ? my_file_result << "value of counter:: " << result : std::cout << "Unable to open file to save results\n";
  my_file_result.close();

}


int counter_result(std::vector<data_record_TB> &counter_stuff) {
  int tmp_counter = 0;

  for (auto a : counter_stuff) {

    tmp_counter += a.counter;
  }

  return tmp_counter;
}

void setting_up_coordinates(const std::vector<int> &raw,
                            std::vector<data_record_TB> &ready_data_for_use) {
  int i = 0;
  for (; i < raw.size(); i += 5) {

    data_record_TB one(raw.at(i), raw.at(i + 1),
                       (raw.at(i + 1) + raw.at(i + 3)), raw.at(i + 2),
                       (raw.at(i + 2) + raw.at(i + 4)));
    ready_data_for_use.push_back(one);
  }
}

bool read_file_string(std::vector<std::string> &import_file) {
  std::ifstream file("day3.txt");
  std::string data;
  if (!file.is_open()) {
    return false;
  } else {
    while (std::getline(file, data))

      import_file.push_back(data);
    std::cout << "Success" << '\n';
  }
  return true;
}

void data_processing_stage1(std::vector<std::string> &coordinates_from_file, std::vector<int> &raw_co) { // converting from file to string to vector of ints
  std::string value_to_keep_string{};
  std::vector<std::string> values{};

  for (auto a : coordinates_from_file) {
    std::string test{};
    for (auto b : a) {
      if (isdigit(b)) {
        if (b) {
          test.insert(0, 1, b);
          value_to_keep_string.append(test);
          test = "";
        }
      } else {
        if (!value_to_keep_string.empty()) {
          values.push_back(value_to_keep_string);
        }
        value_to_keep_string = "";
      }
    }
    if (!value_to_keep_string.empty()) {
      values.push_back(value_to_keep_string);
      value_to_keep_string = "";
    }
    std::string separator{"000000000"};
  }
  std::cout << "test\n";

  for (int i = 0; i < values.size(); i++) {
    raw_co.push_back(std::stoi(values.at(i)));
  }
}

void read_data_from_grid(std::vector<std::vector<int>> &The_grid,std::vector<data_record_TB> &The_data) {

  std::ofstream my_file("Out_put_TB_read_data_from_grid.txt");
  if (my_file.is_open()) {

    for (int k = 0; k != The_data.size(); k++) {
      for (int w = The_data.at(k).w_begin; w < The_data.at(k).w_end; w++) {

        for (int h = The_data.at(k).h_begin; h != The_data.at(k).h_end; h++) {

          if (The_grid.at(w).at(h) > 1) {
            my_file << "-----------------------------\n";
            my_file  << "The_grid.at(" << w << ").at(" << h << ")" << " is " << The_grid.at(w).at(h) << '\n';
            The_data.at(k).counter++;
            The_grid.at(w).at(h) = 1;
          } else {
              my_file << "xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
              continue;
          }
        }
      }
    }
  } else {
    std::cout << "Unable to open this file!\n";
  }
  my_file.close();
}

void set_grid_right(std::vector<std::vector<int>> &The_grid,
                    std::vector<data_record_TB> &The_data) {

  std::ofstream my_file("Out_put_TB_Set_grid_right.txt");

  if (my_file.is_open()) {
    for (int k = 0; k != The_data.size(); k++) {
      for (int w = The_data.at(k).w_begin; w < The_data.at(k).w_end; w++) {

        for (int h = The_data.at(k).h_begin; h != The_data.at(k).h_end; h++) {
            my_file << "The_grid.at(" << w << ").at(" << h << ")" << " is " << The_grid.at(w).at(h) << '\n';
            The_grid.at(w).at(h) += 1;
        }
      }
    }
  } else {
    std::cout << "Unable to open this file\n";
  }
  my_file.close();
}
