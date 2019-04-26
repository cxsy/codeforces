#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> x;
unordered_map<int, int> y;
unordered_map<int, unordered_map<int, int>> rec;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    ans += x[yy] + y[xx] - rec[xx][yy];
    rec[xx][yy]++;
    x[yy]++;
    y[xx]++;
  }
  cout << ans << "\n";
  return 0;
}