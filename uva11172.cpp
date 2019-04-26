#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    cout << (a < b ? "<" : (a == b ? "=" : ">")) << "\n";
  }
  return 0;
}