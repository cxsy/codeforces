#include <bits/stdc++.h>
using namespace std;
char seq[100];

string getCol(int c) {
  string res = "";
  while (c > 0) {
    c--;
    res = (char)('A' + c % 26) + res;
    c /= 26;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> seq;
    if (seq[0] == 'R' && isdigit(seq[1])) {
      int r = 0;
      int j = 1;
      for (; isdigit(seq[j]); j++) {
        r = r * 10 + seq[j] - '0';
      }
      if (!seq[j]) {
        cout << "R" << r << "C" << 18 << "\n";
      } else {
        int c = 0;
        for (j = j + 1; isdigit(seq[j]); j++) {
          c = c * 10 + seq[j] - '0';
        }
        cout << getCol(c) << r << "\n";
      }
    } else {
      int c = 0;
      int j = 0;
      for (; !isdigit(seq[j]); j++) {
        c = 26 * c + seq[j] - 'A' + 1;
      }
      int r = 0;
      for (; isdigit(seq[j]); j++) {
        r = r * 10 + seq[j] - '0';
      }
      cout << "R" << r << "C" << c << '\n';
    }
  }
  return 0;
}