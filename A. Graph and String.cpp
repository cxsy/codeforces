#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int graph[N][N];
char sol[N];
int n, m;
void build() {
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= n; i++) {
    sol[i] = '.';
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u][v] = graph[v][u] = 1;
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    bool isb = true;
    for (int j = 1; j < i; j++) {
      if (!graph[j][i]) {
        isb = false;
        if (sol[j] == 'b') {
          cout << "No\n";
          exit(0);
        } else if (sol[j] == 'a' || sol[j] == 'c') {
          if (sol[i] == '.') {
            sol[i] = sol[j] == 'a' ? 'c' : 'a';
          } else if(sol[i] == sol[j]) {
            cout << "No\n";
            exit(0);  
          }
        }
      }
    }
    if (!isb) {
      if (sol[i] == '.') sol[i] = 'a';
      for (int j = 1; j < i; j++) {
        if (!graph[j][i]) {
          sol[j] = sol[i] == 'a' ? 'c' : 'a';
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (graph[i][j] && ((sol[i] == 'a' && sol[j] == 'c') || (sol[i] == 'c' && sol[j] == 'a'))) {
        cout << "No\n";
        exit(0);  
      }
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << (sol[i] == '.' ? 'b' : sol[i]);
  }
  cout << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}