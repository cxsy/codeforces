#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
int const M = 1e5 + 5;
struct q {
  int L, R, id;
} Q[M];
int n, m;
int freq[N];
int A[N], sol[M];
vector<int> v[N];
void upd(int i, int a) {
  for (i = i + 1; i <= n; i += i & (-i)) {
    freq[i] += a;
  }
}
int get(int i) {
  int ret = 0;
  for (i = i + 1; i > 0; i -= i & (-i)) {
    ret += freq[i];
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++) {
    cin >> Q[i].L >> Q[i].R;
    Q[i].L--;
    Q[i].R--;
    Q[i].id = i;
  }
  sort(Q, Q + m, [](const q &a, const q &b) -> bool { return a.R < b.R; });
  int R = 0, t = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > n) continue;
    v[A[i]].emplace_back(i);
    int size = v[A[i]].size();
    if (size >= A[i]) upd(v[A[i]][size - A[i]], 1);
    if (size >= A[i] + 1) upd(v[A[i]][size - A[i] - 1], -2);
    if (size >= A[i] + 2) upd(v[A[i]][size - A[i] - 2], 1);
    while (t < m && Q[t].R == i) {
      sol[Q[t].id] = get(i) - get(Q[t].L - 1);
      t++;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}