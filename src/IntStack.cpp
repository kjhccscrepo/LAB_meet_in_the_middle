#include "IntStack.hpp"

void IntStack::populate_array() {
   if (my_file_stream->is_open()) {
      std::stringstream input;
      std::string line;
      while (std::getline(*my_file_stream, line, ',')) {
         my_max++;
         input << line;
         input << " ";
      }
      try {
         arr = new int[my_max];
      } catch (std::bad_alloc& e) {
         throw std::string ("Memory allocation failed");
      }
      iteration_pos = arr;
      start_pos = arr;
      int t = 0;
      int i = 0;
      while (std::getline(input, line, ' ')) {
         t = std::stoi(line);
         arr[i] = t;
         i++;
         if (arr[0] != 1) {
            throw std::string ("Increment size failed");
         }
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
   double made_mean = 0;
   for (int i = 0 ; i < my_max ; i++) {
      made_mean += arr[i];
   }
   made_mean = made_mean / my_max;
   return made_mean;
}

double IntStack::makeMedian() const {
   double made_median = 0;
   if (my_max % 2 == 0) { // median is even!
      made_median = (arr[my_max / 2] + arr[(my_max / 2) - 1]);
      made_median = made_median / 2;
   } else { // median is odd
      made_median = arr[my_max / 2];
   }
   return made_median;
}


IntStack::IntStack(std::ifstream *file_stream) {
   try {
      arr = nullptr;
      my_file_stream = file_stream;
      if (!my_file_stream->is_open()) {
         throw std::string ("File is not open");
      }
      my_max = 0;
      populate_array();
      my_bubble_sort();
      median = makeMedian();
      mean = makeMean();
      my_file_stream->close();
   }
   catch (const std::string &msg) {
      std::cerr << msg << std::endl;
   }
   catch (...) {
      std::cerr << "Unknown Error!" << std::endl;
   }
}

std::string IntStack::getMean() const {
   return "The Mean of the file is " + std::to_string(mean) + ".\n";
}

std::string IntStack::getMedian() const {
   return "The Median of the file is " + std::to_string(median) + ".\n";
}
