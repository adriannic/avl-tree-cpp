#include "AVLTree.h"
#include <vector>
#define MAX(a, b) (((a) <= (b)) ? (b) : (a))

using std::make_unique;
using std::unique_ptr;
using std::vector;

AVLTree::AVLTree(int value) : value(value) {}

void AVLTree::updateHeight() {
  if (left) {
    left->updateHeight();
  }
  if (right) {
    right->updateHeight();
  }
  const int leftHeight = left ? left->height : -1;
  const int rightHeight = right ? right->height : -1;
  height = 1 + MAX(leftHeight, rightHeight);
}

void AVLTree::leftRotate() {
  auto newLeft = make_unique<AVLTree>(value);
  newLeft->left = std::move(left);
  left = std::move(newLeft);
  value = right->value;
  left->right = std::move(right->left);
  right = std::move(right->right);
}

void AVLTree::rightRotate() {
  auto newRight = make_unique<AVLTree>(value);
  newRight->right = std::move(right);
  right = std::move(newRight);
  value = left->value;
  right->left = std::move(left->right);
  left = std::move(left->left);
}

void AVLTree::balance(const int value) {
  const int leftHeight = left ? left->height : -1;
  const int rightHeight = right ? right->height : -1;

  const int balanceFactor = leftHeight - rightHeight;

  if (balanceFactor < -1) {
    if (value <= right->value) {
      right->rightRotate();
    }
    leftRotate();
  } else if (balanceFactor > 1) {
    if (value > left->value) {
      left->leftRotate();
    }
    rightRotate();
  }
  updateHeight();
}

void AVLTree::addValue(const int value) {
  auto &side = (value <= this->value) ? left : right;
  if (side) {
    side->addValue(value);
  } else {
    side = make_unique<AVLTree>(value);
  }

  updateHeight();
  balance(value);
}

void AVLTree::getValuesAux(vector<int> &values) const {
  if (left) {
    left->getValuesAux(values);
  }
  values.push_back(value);
  if (right) {
    right->getValuesAux(values);
  }
}

vector<int> AVLTree::getValues() const {
  vector<int> values{};
  getValuesAux(values);
  return values;
}

int AVLTree::getHeight() const { return height; }
