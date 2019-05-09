#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int LEN = 105;

char arr[N][LEN];
vector<vector<int>> adj(26);
vector<int> ans;
int visited[26];

void dfs(int v) {
  visited[v] = 1;
  for (int u : adj[v]) {
    if (visited[u] == 1) {
      cout << "Impossible\n";
      exit(0);
    } else if (visited[u] == 0) {
      dfs(u);
    }
  }
  visited[v] = -1;
  ans.insert(ans.begin(), v);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++) {
    int k = 0;
    for (; arr[i - 1][k] == arr[i][k]; k++);
    if (arr[i - 1][k] && arr[i][k]) {
      adj[arr[i - 1][k] - 'a'].emplace_back(arr[i][k] - 'a');
    } else if (arr[i - 1][k] && !arr[i][k]) {
      cout << "Impossible\n";
      exit(0);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (visited[i] == 0) {
      dfs(i);
    }
  }
  for (int a : ans) {
    cout << (char)('a' + a);
  }
  cout << "\n";
  return 0;
}