#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
const int N = 305;
int A[N], B[N][N];
ii S[N];
int n, m;
int sol, mi = -1;
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  int l, r;
  for (int j = 1; j <= m; j++) {
    cin >> l >> r;
    S[j] = {l, r};
    for (int i = l; i <= r; i++) {
      B[i][j] = 1;
    }
  }
  sol = *max_element(A + 1, A + n + 1) - *min_element(A + 1, A + n + 1);
  for (int i = 1; i <= n; i++) {
    int maxx = A[i];
    int cnt[N]{};
    for (int j = 1; j <= m; j++) {
      if (B[i][j]) continue;
      for (int t = S[j].first; t <= S[j].second; t++) {
        cnt[t]--;
      }
    }
    int minn = maxx;
    for (int i = 1; i <= n; i++) {
      minn = min(minn, cnt[i] + A[i]);
    }
    if (sol < maxx - minn) {
      sol = maxx - minn;
      mi = i;
    }
  }
  if (mi > 0) {
    cout << sol << "\n";
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (B[mi][j]) cnt++;
    }
    cout << m - cnt << "\n";
    for (int j = 1; j <= m; j++) {
      if (!B[mi][j]) {
        cout << j << " ";
      }
    }
    cout << "\n";
  } else {
    cout << sol << "\n";
    cout << 0 << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0; 
}