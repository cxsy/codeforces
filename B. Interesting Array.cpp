#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t[N << 2], l[N], r[N], q[N], a[N], sol[N];
int n, m;
void build(int tn, int l, int r) {
  if (l + 1 == r) {
    t[tn] = sol[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(tn << 1, l, mid);
  build(tn << 1 | 1, mid, r);
  t[tn] = t[tn << 1] & t[tn << 1 | 1];
}
int query(int tn, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return t[tn];
  }
  int mid = (l + r) >> 1;
  int ret = (1 << 30) - 1;
  if (L < mid) ret &= query(tn << 1, l, mid, L, R);
  if (mid < R) ret &= query(tn << 1 | 1, mid, r, L, R);
  return ret;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    l[i]--;
  }
  for (int b = 0; b < 30; b++) {
    fill(a, a + n, 0);
    for (int i = 0; i < m; i++) {
      if ((q[i] >> b) & 1) {
        a[l[i]]++;
        a[r[i]]--;
      }
    }
    for (int j = 0; j < n; j++) {
      a[j] = j == 0 ? a[j] : a[j - 1] + a[j];
      if (a[j] > 0) sol[j] |= (1 << b);
    }
  }
  build(1, 0, n);
  for (int i = 0; i < m; i++) {
    if (query(1, 0, n, l[i], r[i]) != q[i]) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
  for (int j = 0; j < n; j++) {
    cout << sol[j] << " \n"[j == n - 1];
  }
  return 0;
}