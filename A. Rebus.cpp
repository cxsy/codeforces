#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char A[N];
void solve() {
  int np = 1, nm = 0;
  char c;
  cin >> c;
  int op = 0;
  while (cin >> c && c != '=') {
    A[op] = c;
    if (c == '+') np++;
    if (c == '-') nm++;
    op++;
    cin >> c;
  }
  int n;
  cin >> n;
  int minn = np - nm * n, maxx = np * n - nm;
  if (minn > n || maxx < n) {
    cout << "Impossible\n";
    exit(0);
  }
  vector<int> pv(np), mv(nm);
  for (int i = 0; i < np; i++) {
    pv[i] = 1;
  }
  for (int i = 0; i < nm; i++) {
    mv[i] = 1;
  }
  cout << "Possible\n";
  int ex = np - nm, i = 0;
  while (ex > n) {
    ex -= n - 1;
    mv[i] = n;
    i++;
  }
  if (i && ex < n) {
    mv[i - 1] = ex;
    ex = n;
  }
  i = 0;
  while (ex < n) {
    ex += n - 1;
    pv[i] = n;
    i++;
  }
  if (i && ex > n) {
    pv[i - 1] = n - (ex - n);
    ex = n;
  }
  cout << pv[0];
  for (int i = 0, pi = 1, mi = 0; i < op; i++) {
    cout << " " << A[i] << " ";
    if (A[i] == '+') {
      cout << pv[pi++];
    } else {
      cout << mv[mi++];
    }
  }
  cout << " = " << n << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}