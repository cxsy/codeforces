#include <bits/stdc++.h>
using namespace std;

int getNext(vector<int> &next, int ch) {
  if (ch == next[ch]) {
      return ch;
  }
  return next[ch] = getNext(next, next[ch]);;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> answer(n + 1);
  vector<int> next(n + 2);
  for (int i = 1; i <= n + 1; i++) {
    next[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l = getNext(next ,l);
    while (l <= r) {
      if (l == x) {
        l++;
      } else {
        answer[l] = x;
        next[l] = l + 1;
      } 
      l = getNext(next, l);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << answer[i] << (i == n ? "\n" : " ");
  }
  return 0;
}