/*
Given two strings s and t, check if s is a subsequence of t.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).
*/

#include <string>

using namespace std;

// Complexity:
//
// Space: O(1)
// Time: O(n)
//
bool isSubsequence(string s, string t) {
  size_t si = 0;

  for (size_t ti = 0; ti < t.size() && si < s.size(); ti++) {
    if (t[ti] == s[si])
      si++;
  }

  return si == s.size();
}