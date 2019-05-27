#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int a, t, i;
} A[N], C[N];
int n, T;
int sol[N];
bool comp1(const node &x, const node &y) { return x.a < y.a; }
bool comp2(const node &x, const node &y) { return x.t < y.t; }
bool test(int v) {
  int i = lower_bound(A, A + n, node{v, 0, 0}, comp1) - A;
  if (n - i < v) return false;
  copy(A + i, A + n, C);
  sort(C, C + n - i, comp2);
  int t = 0;
  for (int j = 0; j < v; j++) {
    t += C[j].t;
  }
  if (t <= T) {
    for (int j = 0; j < v; j++) {
      sol[j] = C[j].i;
    }
  }
  return t <= T;
}
void solve() {
  cin >> n >> T;
  int a, t;
  for (int i = 0; i < n; i++) {
    cin >> a >> t;
    A[i] = {a, t, i + 1};
  }
  sort(A, A + n, comp1);
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (test(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  l--;
  cout << l << "\n" << l << "\n";
  for (int i = 0; i < l; i++) {
    cout << sol[i] << " \n"[i == l - 1];
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}