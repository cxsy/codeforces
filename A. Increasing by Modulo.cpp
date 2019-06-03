#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int A[N];
int n, m;
bool test(int v) {
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (l > A[i] + v) {
      return false;
    }
    if (A[i] + v < m || (A[i] + v) % m < l) {
      l = max(A[i], l);
    } 
  }
  return true;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int l = 0, h = m;
  while (l <= h) {
    int mid = (l + h) >> 1;
    if (test(mid)) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  h++;
  cout << h << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}