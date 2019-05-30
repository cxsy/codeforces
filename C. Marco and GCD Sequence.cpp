#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int M[N], sol[N];
int m, g;
void solve() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> M[i];
    if (i == 0) g = M[i];
    if (M[i] % g) {
      cout << "-1\n";
      exit(0);
    }
  }
  cout << 2 * m - 1 << "\n" << M[0];
  for (int i = 1; i < m; i++) {
    cout << " " << g << " " << M[i];
  }
  cout << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}