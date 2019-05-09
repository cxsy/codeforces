#include <bits/stdc++.h>
using namespace std;

#define mt make_tuple
#define state tuple<int, int>

const int N = 1e5 + 5;
int n, a, x, y;
int cnt[N], steps[N], vis[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    queue<state> que({mt(a, 0)});
    while (!que.empty()) {
      tie(x, y) = que.front();
      que.pop();
      if (x == 0 || x > N || vis[x] == i) continue;
      vis[x] = i;
      steps[x] += y;
      cnt[x]++;
      que.emplace(mt(x * 2, y + 1));
      que.emplace(mt(x / 2, y + 1));
    }
  }
  int sol = INT32_MAX;
  for (int t = 0; t < N; t++) {
    if (cnt[t] == n) sol = min(sol, steps[t]);
  }
  cout << sol << "\n";
  return 0;
}