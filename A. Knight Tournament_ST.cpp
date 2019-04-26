#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1 << 20;
int st[MAXSIZE];
int ans[MAXSIZE];
void update(int lb, int rb, int l, int r, int x, int si) {
  if (lb > rb || l > r || l > rb || r < lb) {
    return;
  }
  if (l <= lb && rb <= r) {
    if (st[si] == 0) {
      st[si] = rb - lb + 1;
      for (int i = lb; i <= rb; i++) {
        ans[i] = x;
      }
    }
    return;
  }
  if (st[si] != rb - lb + 1) {
    int mid = (rb - lb) / 2 + lb;
    update(lb, mid, l, r, x, 2 * si + 1);
    update(mid + 1, rb, l, r, x, 2 * si + 2);
    st[si] = st[2 * si + 1] + st[2 * si + 2];
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    update(1, n, l, x - 1, x, 0);
    update(1, n, x + 1, r, x, 0);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
  return 0;
}