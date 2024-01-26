#include "AVLTree.h"
#include <chrono>
#include <iostream>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;

double benchmark(const int items, const int iterations) {
  double average;
  for (int iteration = 0; iteration < iterations; iteration++) {
    AVLTree tree(0);
    if (iteration % (iterations / 1000) == 0) {
      std::cerr << "\33[2K\r" << (iteration * 1000 / iterations) / 10.0 << "%";
    }
    auto start = high_resolution_clock::now();
    for (int i = 0; i < items; i++) {
      tree.addValue(i);
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop - start);
    average += time.count();
  }
  std::cerr << "\n";
  return average / iterations;
}

int main() {
  for (int items = 50; items <= 5000; items *= 10) {
    std::cout << "Testing " << items << " items 1000000 times..." << '\n';
    double average = benchmark(items, 1000000);
    std::cout << "Average: " << average << " microseconds.\n\n";
  }
  return 0;
}
