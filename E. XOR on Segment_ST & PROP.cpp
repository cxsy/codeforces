#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
const int KMAX = 22;
int st[NMAX << 2][KMAX], la[NMAX << 2];

void pushUp(int rt) {
  for (int i = 0; i < KMAX; i++) {
    st[rt][i] = st[rt << 1][i] + st[rt << 1 | 1][i];
  }
};
void build(int rt, int l, int r) {
  if (l == r) {
    int val;
    cin >> val;
    for (int i = 0; i < KMAX; i++) {
      st[rt][i] = (val & (1 << i)) ? 1 : 0;
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushUp(rt);
};
void pushDown(int rt, int l, int r) {
  if (la[rt]) {
    la[rt << 1] ^= la[rt];
    la[rt << 1 | 1] ^= la[rt];
    int mid = (l + r) >> 1;
    for (int i = 0; i < KMAX; i++) {
      if (la[rt] & (1 << i)) {
        st[rt << 1][i] = (mid - l + 1) - st[rt << 1][i];
        st[rt << 1 | 1][i] = (r - mid) - st[rt << 1 | 1][i];
      }
    }
    la[rt] = 0;
  }
};
int64_t query(int rt, int l, int r, int ll, int rr) {
  int64_t ans = 0;
  if (ll <= l && r <= rr) {
    for (int i = 0; i < KMAX; i++) ans += st[rt][i] * (1ll << i);
    return ans;
  }
  pushDown(rt, l, r);
  int m = (l + r) >> 1;
  if (ll <= m) ans += query(rt << 1, l, m, ll, rr);
  if (rr > m) ans += query(rt << 1 | 1, m + 1, r, ll, rr);
  // pushUp(rt);
  return ans;
};
void update(int rt, int l, int r, int ll, int rr, int x) {
  if (ll <= l && r <= rr) {
    la[rt] ^= x;
    for (int i = 0; i < KMAX; i++) {
      if (x & (1 << i)) st[rt][i] = (r - l + 1) - st[rt][i];
    }
    return;
  }
  pushDown(rt, l, r);
  int m = (l + r) >> 1;
  if (ll <= m) update(rt << 1, l, m, ll, rr, x);
  if (rr > m) update(rt << 1 | 1, m + 1, r, ll, rr, x);
  pushUp(rt);
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n;
  build(1, 1, n);
  cin >> m;
  int t, l, r, x;
  for (int i = 0; i < m; i++) {
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << "\n";
    } else {
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x);
    }
  }
  return 0;
}