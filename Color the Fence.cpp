#include <bits/stdc++.h>
using namespace std;

const int AMAX = 1e5 + 5;
int main(int argc, char const *argv[]) {
  int v;
  cin >> v;
  int p[10];
  int minn = AMAX;
  for (int i = 1; i <= 9; i++) {
    cin >> p[i];
    minn = min(minn, p[i]);
  }
  int len = v / minn;
  vector<int> ans;
  while (v > 0 && len > 0) {
    for (int n = 9; n >= 1; n--) {
      if (v >= p[n] && (v - p[n]) / minn == len - 1) {
        ans.push_back(n);
        v -= p[n];
        len--;
        break;
      }
    }
  }
  for (int n : ans) {
    cout << n;
  }
  cout << "\n";
  return 0;
}
