#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int A[N];
int n, m;
bool test(int v) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += max(0, A[i] - (i / v));
    if (cnt >= m) {
      return true;
    }
  }
  return false;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n, greater<int>());
  int l = 1, h = n;
  while (l <= h) {
    int mid = (l + h) >> 1;
    if (test(mid)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  h++;
  cout << (h > n ? -1 : h) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}