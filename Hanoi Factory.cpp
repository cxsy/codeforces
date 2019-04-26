#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int64_t> a, vector<int64_t> b) { return a[1] > b[1]; }
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<vector<int64_t>> v(n, vector<int64_t>(3));
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  sort(v.begin(), v.end(), comp);
  stack<int> opt;
  vector<int64_t> ans(n);
  int64_t ret = 0;
  for (int i = 0; i < n; i++) {
    while (i + 1 < n && v[i][1] == v[i + 1][1]) {
      v[i + 1][2] += v[i][2];
      v[i + 1][0] = min(v[i][0], v[i + 1][0]);
      i++;
    }
    while (!opt.empty() && v[opt.top()][0] >= v[i][1]) {
      opt.pop();
    }
    if (!opt.empty()) {
      ans[i] = ans[opt.top()];
    }
    ans[i] += v[i][2];
    ret = max(ret, ans[i]);
    opt.push(i);
  }
  cout << ret << "\n";
  return 0;
}