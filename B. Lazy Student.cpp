#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
const int N = 1e5 + 5;
struct node {
  int a, b, id;
} A[N];
bool comp(const node &x, const node &y) {
  return x.a != y.a ? x.a < y.a : x.b > y.b;
}
int n, m;
void solve() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    A[i] = {a, b, i};
  }
  sort(A, A + m, comp);
  vector<ii> sol(m);
  int cnt = 1, from = 2, to = 3;
  for (int i = 0; i < m; i++) {
    int b = A[i].b, id = A[i].id;
    if (b == 1) {
      sol[id] = {1, ++cnt};
    } else {
      if (to > cnt) {
        cout << "-1\n";
        exit(0);
      }
      sol[id] = {from++, to};
      if (from == to) {
        from = 2;
        to++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << sol[i].first << " " << sol[i].second << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}