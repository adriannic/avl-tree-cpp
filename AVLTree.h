#include <memory>
#include <vector>

class AVLTree {
  std::unique_ptr<AVLTree> left = nullptr;
  std::unique_ptr<AVLTree> right = nullptr;
  int height = 0;
  int value;

  void balance(const int);
  void leftRotate();
  void rightRotate();
  void updateHeight();
  void getValuesAux(std::vector<int> &) const;

public:
  explicit AVLTree(int value);
  void addValue(int value);
  std::vector<int> getValues() const;
  int getHeight() const;
};
