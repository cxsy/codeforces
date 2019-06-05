#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 5005;
const int m = 1e9 + 7;
int n;
vector<int> v1, v2;
void solve() {
  cin >> n;
  v1.resize(n + 1);
  v2.resize(n + 1);
  fill(v1.begin(), v1.end(), 1);
  char pre = 's', c;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (pre == 'f') {
      for (int j = 1; j <= n; j++) {
        v2[j] = v1[j - 1];
      }
    } else {
      v2[0] = v1[n];
      for (int j = 1; j <= n; j++) {
        v2[j] = ((v2[j - 1] + v1[n] - v1[j - 1]) % m + m) % m;
      }
    }
    v1 = v2;
    fill(v2.begin(), v2.end(), 0);
    pre = c;
  }
  cout << v1[n] << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}