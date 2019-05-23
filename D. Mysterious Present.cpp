#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
struct env {
  int w, h, id;
} A[N];
int n, w, h, dp[N], p[N];
void build() {
  cin >> n >> w >> h;
  int ww, hh, cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> ww >> hh;
    if (ww <= w || hh <= h) continue;
    A[++cnt] = {ww, hh, i};
  }
  n = cnt;
}
void solve() {
  sort(A, A + n + 1,
       [](const env &a, const env &b) -> bool { return a.w < b.w; });
  int sol = 0, e = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 1; j--) {
      if (A[i].w > A[j].w && A[i].h > A[j].h) {
        if (dp[j] + 1 > dp[i]) {
          p[i] = j;
          dp[i] = dp[j] + 1;
        }
      }
    }
    if (dp[i] > sol) {
      e = i;
      sol = dp[i];
    }
  }
  if (sol == 0) {
    cout << "0\n";
  } else {
    cout << sol << "\n";
    vector<int> res;
    while (e) {
      res.emplace_back(e);
      e = p[e];
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      cout << A[res[i]].id << " \n"[i == res.size() - 1];
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}