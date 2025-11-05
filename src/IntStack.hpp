#pragma once
#include <fstream>
#include <sstream>
#include <functional>
#include <iostream>

class IntStack {
private:
    int my_max;
    int *arr;
    int *iteration_pos;
    int *start_pos;
    std::ifstream *my_file_stream;
    void incrementSize();
    void populateArray() const;
    void my_bubble_sort() const;
    double makeMean() const;
    double makeMedian() const;
    int howManyVar() const;
    int makeMode() const;

public:
    explicit IntStack(std::ifstream file_stream);
    explicit IntStack();
    std::string getMean() const;
    std::string getMedian() const;
    std::string getMode() const;


    bool isEmpty() const;
    bool isFull() const;
    void push(int element);
    void pop();
};

