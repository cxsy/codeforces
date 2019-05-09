#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int A[N];
int n, k;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i];
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] <= 0 || A[i] < A[k]) break;
    sol++;
  }
  cout << sol << "\n";
  return 0;
}