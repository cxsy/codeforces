#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5e3 + 5;
pair<int, int> e[NMAX];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    e[i] = {a, b};
  }
  sort(begin(e), begin(e) + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (e[i].second >= ans) {
      ans = e[i].second;
    } else {
      ans = e[i].first;
    }
  }
  cout << ans << "\n";
  return 0;
}