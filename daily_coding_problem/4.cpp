/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear
time and constant space. In other words, find the lowest positive integer that
does not exist in the array. The array can contain duplicates and negative
numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should
give 3.

You can modify the input array in-place.
*/

#include <limits>
#include <vector>

using namespace std;

// Complexity:
//
// Space: O(1)
// Time: O(n)
//
int findMissingPositiveNumber(vector<int> nums) {
  int maxNum = numeric_limits<int>::min();
  int minNum = numeric_limits<int>::max();

  for (int num : nums) {
    if (maxNum < num)
      maxNum = num;
    if (minNum > num)
      minNum = num;
  }

  int flaggedNumToken = maxNum + abs(minNum) + 1;

  for (int num : nums) {
    if (num > maxNum)
      num -= flaggedNumToken;
    if (num < nums.size() && num > 0)
      nums[num] += flaggedNumToken;
  }

  size_t missingNumber = 1;
  for (; missingNumber < nums.size() && nums[missingNumber] > maxNum;
       missingNumber++)
    ;

  return missingNumber;
}
