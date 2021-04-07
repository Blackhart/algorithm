/*
Given an array of integers nums and an integer target, return the two numbers
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.
*/

// -----------------------------------------------------------------------

#include <unordered_set>
#include <vector>

using namespace std;

// Complexity:
//
// Space: O(n)
// Time: O(n)
//
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_set<int> savedNums;

  for (int num : array) {
    if (savedNums.contains(targetSum - num))
      return vector<int>{num, targetSum - num};
    else
      savedNums.insert(num);
  }

  return {};
}

// -----------------------------------------------------------------------

#include <algorithm>
#include <vector>

using namespace std;

// Complexity:
//
// Space: O(1)
// Time: O(nlog(n))
//
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());

  size_t left = 0;
  size_t right = array.size() - 1;

  while (left < right) {
    int currentSum = array[left] + array[right];

    if (currentSum == targetSum)
      return vector<int>{array[left], array[right]};
    else if (currentSum < targetSum)
      left++;
    else
      right--;
  }

  return {};
}