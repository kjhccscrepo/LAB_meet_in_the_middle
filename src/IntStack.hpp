#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
class IntStack {
private:
    int my_max;
    int *arr;
    int *iteration_pos;
    int *start_pos;
    double median;
    double mean;
    int mode;
    std::ifstream *my_file_stream;
    void populate_array();
    void my_bubble_sort() const;
    double makeMean() const;
    double makeMedian() const;
public:
    explicit IntStack(std::ifstream *file_stream);
    std::string getMean() const;
    std::string getMedian() const;

};

