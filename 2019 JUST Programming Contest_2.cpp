#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define mp make_pair
const int M = 1e5 + 5;
ii A[M];
int T, n, m, q, l, r, k;
int R;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n >> m >> q;
    for (int j = 0; j < n; j++) {
      cin >> l >> r;
      A[j] = mp(l, r);
    }
    sort(A, A + n);
  }
  return 0;
}