#include <bits/stdc++.h>
using namespace std;
const int LEN = 5005;
char arr[LEN];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> arr;
  int ans = 0;
  for (int i = 0; arr[i]; i++) {
    int counter = 0, score = 0;
    for (int j = i; arr[j]; j++) {
      if (arr[j] == '?') {
        counter++;
      } else if (arr[j] == '(') {
        score++;
      } else {
        score--;
      }
      if (score < 0) break;
      if (counter > score) {
        counter--;
        score++;
      }
      
      if ((j - i) % 2 && counter >= score) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}