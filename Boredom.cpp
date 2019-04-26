#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  map<int, int> map;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    map[num]++;
  }
  vector<pair<int, int>> pairs(map.size());
  for (auto &en : map) {
    pairs.push_back(make_pair(en.first, en.second));
  }
  vector<int64_t> dp(pairs.size());
  for (int i = 0; i < pairs.size(); i++) {
    int pr = i - 1;
    if (pr >= 0 && pairs[i].first == 1 + pairs[pr].first) {
      pr--;
    }
    dp[i] = (pr < 0 ? 0 : dp[pr]) + (1LL * pairs[i].first * pairs[i].second);
    dp[i] = max(dp[i], i == 0 ? 0 : dp[i - 1]);
  }
  cout << dp[pairs.size() - 1] << "\n";
  return 0;
}
