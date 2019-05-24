#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int A[N], B[N];
int n, p, a, b;
bool test(double t) {
  double t1 = 0.0;
  for (int i = 0; i < n; i++) {
    t1 += max(0.0, A[i] * t - B[i]) / p;
  }
  return t1 < t;
}
void solve() {
  cin >> n >> p;
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    sum += A[i];
  }
  if (sum <= p) {
    cout << "-1\n";
    exit(0);
  }
  double l = 0.0, r = 1e10;
  int time = 0;
  while (time < 200) {
    double mid = (l + r) / 2;
    if (test(mid)) {
      l = mid;
    } else {
      r = mid;
    }
    time++;
  }
  cout.precision(5);
  cout << fixed << l << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}