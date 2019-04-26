#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> l(n);
  int maxL = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && v[i] > v[i - 1]) {
      l[i] = l[i - 1] + 1;
    } else {
      l[i] = 1;
    }
    maxL = max(maxL, l[i]);
  }
  vector<int> r(n);
  int maxR = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1 && v[i] < v[i + 1]) {
      r[i] = r[i + 1] + 1;
    } else {
      r[i] = 1;
    }
    maxR = max(maxR, r[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && i < n - 1 && v[i - 1] + 1 < v[i + 1]) {
      ans = max(ans, 1 + l[i - 1] + r[i + 1]);
    }
  }
  ans = max(ans, 1 + max(maxL, maxR));
  cout << min(n, ans) << "\n";
  return 0;
}