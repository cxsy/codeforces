#include <iostream>
#include <string>
using namespace std;
const int MAXLEN = 2005;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  uint64_t sum = 0, dp[MAXLEN];
  for (int i = 1; i <= s.length; i++) {
    int count = 0;
    for (int j = 1; j <= i; j++) {
      if (isPalindrome(s.substr(j - 1, i - j + 1))) {
        sum += dp[j - 1];
        count++;
      }
    }
    dp[i] = dp[i - 1] + count;
  }
  cout << sum;
  return 0;
}

bool isPalindrome(string s) {
  int left = 0, right = s.length - 1;
  while (left < right && s.at(left) == s.at(right)) {
    left++;
    right--;
  }
  return left >= right;
}
