#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int A[N], t[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  int sol = 0;
  stack<int> ss;
  ss.push(0);
  t[0] = -1;
  for (int i = 1; i < n; i++) {
    t[i] = 0;
    while (!ss.empty() && A[ss.top()] < A[i]) {
      t[i] = max(t[i], t[ss.top()] + 1);
      ss.pop();
    }
    if (ss.empty()) t[i] = -1;
    ss.push(i);
    sol = max(sol, t[i] + 1);
  }
  cout << sol << "\n";
  return 0;
}