//
// Created by Tom Breza on 2018-12-26.
//

#include "data_record_TB.h"

data_record_TB::~data_record_TB() {}

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
