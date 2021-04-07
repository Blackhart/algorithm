/*
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the
list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
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