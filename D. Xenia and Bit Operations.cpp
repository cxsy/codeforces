#include <bits/stdc++.h>
using namespace std;

const int NMAX = (1 << 18) + 5;

int st[NMAX];
int getMid(int l, int r) { return (r - l) / 2 + l; }
void update(int l, int r, int p, int val, int si, int flag) {
  if (p < l || p > r) {
    return;
  } else if (l == r) {
    st[si] = val;
    return;
  }
  int mid = getMid(l, r);
  update(l, mid, p, val, 2 * si + 1, 1 ^ flag);
  update(mid + 1, r, p, val, 2 * si + 2, 1 ^ flag);
  st[si] = flag == 1 ? st[2 * si + 1] | st[2 * si + 2]
                     : st[2 * si + 1] ^ st[2 * si + 2];
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int tmp;
  for (int i = 0; i < 1 << n; i++) {
    cin >> tmp;
    update(0, (1 << n) - 1, i, tmp, 0, n % 2);
  }
  int p, b;
  for (int i = 0; i < m; i++) {
    cin >> p >> b;
    update(0, (1 << n) - 1, p - 1, b, 0, n % 2);
    cout << st[0] << "\n";
  }
  return 0;
}