/*
Given a binary search tree and a target node K. The task is to find the node
with minimum absolute difference with given target value K.
*/

#include <cstdlib>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;
};

// Complexity:
//
// Space: O(1)
// Time: O(log(n))
//
int findClosestValueInBst(BST *tree, int target) {
  int closest = tree->value;

  while (tree != nullptr) {
    if (abs(target - tree->value) < abs(target - closest))
      closest = tree->value;

    if (tree->value > target)
      tree = tree->left;
    else if (tree->value < target)
      tree = tree->right;
    else
      break;
  }

  return closest;
}