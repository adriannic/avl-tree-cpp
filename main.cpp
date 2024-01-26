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

  std::cout << tree.getValues().back() + 1 << " elements\n";

  std::cout << tree.getHeight() << std::endl;

  return 0;
}
