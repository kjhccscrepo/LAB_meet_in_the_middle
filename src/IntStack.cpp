#include "IntStack.hpp"

void IntStack::incrementSize() {
   if (my_file_stream->is_open()) {
      std::string line;
      while (std::getline(*my_file_stream, line, ',')) {
         my_max++;
      }
   } else {
      throw std::string ("File is not open");
   }
}
void IntStack::populateArray() const {
   if (my_file_stream->is_open()) {
      std::string line;
      int i = 0;
      while (std::getline(*my_file_stream, line, ',')) {
         arr[i] = stoi(line);
         i++;
      }
   } else {
      throw std::string ("File is not open");
   }
}

void IntStack::my_bubble_sort() const {
   double temp = 0;
   for (int i = 0; i < my_max; i++) {
      for (int j = 0; j < my_max - i - 1; j++) {
         if(arr[j] > arr[j+1])
         {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
         }
      }
   }
}

double IntStack::makeMean() const {
   double mean = 0;
   for (int i = 0 ; i < my_max ; i++) {
      mean += arr[i];
   }
   mean = mean / my_max;
   return mean;
}

double IntStack::makeMedian() const {
   double median = 0;
   if (my_max % 2 == 0) { // median is even!
      median = (arr[my_max / 2] + arr[(my_max / 2) - 1]);
      median = median / 2;
   } else { // median is odd
      median = arr[my_max / 2];
   }
   return median;
}

int IntStack::howManyVar() const {
   int count = 0;
   for (int i = 0 ; i < my_max ; i++) {
      for (int j = 0 ; j < i ; j++) {
         if (arr[i] == arr[j]) {
            count++;
            break;
         }
      }
   }
   return count;
}

int IntStack::makeMode() const {
   const int mode_distrib = howManyVar();
   int modeArr[mode_distrib][1];
   modeArr[0][0] = arr[0];
   modeArr[0][1] = 1;
   int k = 0;
   for (int i = 1 ; i < my_max ; i++) {
      if (arr[i] == arr[i - 1]) { // same value
         modeArr[k][1] = modeArr[k][1] + 1;
      } else { //not the same
         k++;
         modeArr[k][0] = arr[i];
      }
   }
   int mode = modeArr[k][0];
   for (int i = 1; i < mode_distrib ; i++) {
      if (modeArr[i - 1][1] > modeArr[i][1]) {
         mode = modeArr[i][0];
      }
   }
   return mode;
}

IntStack::IntStack(std::ifstream file_stream) {
   try {
      my_max = 0;
      my_file_stream = &file_stream;
      incrementSize();
      try {
         arr = new int[my_max];
      } catch (std::bad_alloc& e) {
         throw std::string ("Memory allocation failed");
      }
      populateArray();
      iteration_pos = arr;
      start_pos = arr;
      my_file_stream->close();
      my_bubble_sort();
   }
   catch (const std::string &msg) {
      std::cerr << msg << std::endl;
   }
   catch (...) {
      std::cerr << "Unknown Error!" << std::endl;
   }
}

IntStack::IntStack() {
   my_max = 0;
   my_file_stream = nullptr;
   iteration_pos = nullptr;
   start_pos = nullptr;
   arr = nullptr;
}

std::string IntStack::getMean() const {
   return "The Mean of the file is " + std::to_string(makeMean()) + ".\n";
}

std::string IntStack::getMedian() const {
   return "The Median of the file is " + std::to_string(makeMedian()) + ".\n";
}

std::string IntStack::getMode() const {
   return "The Mode of the file is " + std::to_string(makeMedian()) + ".\n";
}


bool IntStack::isEmpty() const {
   return (iteration_pos == start_pos);
}
bool IntStack::isFull() const {
   return (start_pos + my_max == iteration_pos);
}
void IntStack::push(const int element) {
   if (!isFull()) {
      *iteration_pos = element;
      iteration_pos += 1;
   }
}
void IntStack::pop() {
   if (!isEmpty()) {
      iteration_pos--;
   }
}