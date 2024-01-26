#include "AVLTree.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int size = 10;
  if (argc > 1) {
    size = std::atoi(argv[1]);
  }
  AVLTree tree(0);

  for (int i = 1; i < size; i++) {
    tree.addValue(i);
  }

  std::cout << "[ ";
  for (const auto &v : tree.getValues()) {
    std::cout << v << " ";
  }
  std::cout << "]\n";

  std::cout << tree.getHeight() << std::endl;

  return 0;
}
