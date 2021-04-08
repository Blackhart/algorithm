#include <vector>

using namespace std;

// Complexity:
//
// Space: O(1)
// Time:
//    - best case: O(n) -> sorted array
//    - worst case: O(n^2) -> unsorted array
//
vector<int> bubbleSort(vector<int> array) {
  bool isSorted = false;
  size_t sortedAtTheHead = 0;

  while (!isSorted) {
    isSorted = true;

    for (size_t i = 0; i < array.size() - 1 - sortedAtTheHead; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        isSorted = false;
      }
    }

    sortedAtTheHead++;
  }

  return array;
}
