#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
struct node {
  int L, R, id;
} Q[M];
int n, m;
int A[N], freq[N], sol[M];
int ans = 0, currL = 0, currR = 0, b;
bool comp(const node &x, const node &y) {
  return (x.L / b != y.L / b) ? x.L / b < y.L / b : x.R < y.R;
}
void upd(int v, int a) {
  if (v >= N) return;
  if (freq[v] == v) ans--;
  freq[v] += a;
  if (freq[v] == v) ans++;
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  b = int(sqrt(n));
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> Q[i].L >> Q[i].R;
    Q[i].id = i;
  }
  sort(Q, Q + m, comp);
  for (int i = 0; i < m; i++) {
    int L = Q[i].L - 1, R = Q[i].R;
    while (currL < L) upd(A[++currL], -1);
    while (currL > L) upd(A[currL--], 1);
    while (currR < R) upd(A[++currR], 1);
    while (currR > R) upd(A[currR--], -1);
    sol[Q[i].id] = ans;
  }
  for (int i = 0; i < m; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}