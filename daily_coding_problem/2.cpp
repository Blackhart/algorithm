/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i
of the new array is the product of all the numbers in the original array except
the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be
[2, 3, 6].
*/

#include <vector>

using namespace std;

// Complexity:
//
// Space: O(n)
// Time: O(n)
//
vector<int> product(vector<int> nums) {
  vector<int> products;
  int product = 1;

  for (int num : nums)
    product *= num;

  products.reserve(nums.size());

  for (size_t i = 0; i < nums.size(); i++)
    products.push_back(product / nums[i]);

  return products;
}

// ----------------------------------------------------------

/*
Follow-up: what if you can't use division?
*/

#include <vector>

using namespace std;

// Complexity:
//
// Space: O(n)
// Time: O(n*n)
//
vector<int> product(vector<int> nums) {
  vector<int> products(nums.size(), 1);

  for (size_t i = 0; i < nums.size(); i++) {
    for (size_t j = 0; j < products.size(); j++) {
      if (i != j)
        products[j] *= nums[i];
    }
  }

  return products;
}
