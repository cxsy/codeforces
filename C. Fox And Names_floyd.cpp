#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int LEN = 105;
char arr[N][LEN];
char ret[26];
int e[26][26];
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
    for (; arr[i - 1][k] == arr[i][k]; k++)
      ;
    if (arr[i - 1][k] && arr[i][k]) {
      e[arr[i - 1][k] - 'a'][arr[i][k] - 'a'] = 1;
    } else if (arr[i - 1][k] && !arr[i][k]) {
      cout << "Impossible\n";
      exit(0);
    }
  }
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        e[i][j] |= (e[i][k] & e[k][j]);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (e[i][i]) {
      cout << "Impossible\n";
      exit(0);
    }
  }
  for (int i = 0; i < 26; i++) {
    ret[i] = char(i + 'a');
  }
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      if (e[ret[j] - 'a'][ret[i] - 'a']) {
        swap(ret[i], ret[j]);
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << ret[i];
  }
  cout << "\n";
  return 0;
}