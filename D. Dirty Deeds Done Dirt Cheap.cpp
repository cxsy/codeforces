#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct node {
  int a, b, id;
};
vector<node> in, de;
int n;
bool comp1(const node &x, const node &y) { return x.b < y.b; }
bool comp2(const node &x, const node &y) { return x.b > y.b; }
void solve() {
  cin >> n;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    if (a < b) {
      in.emplace_back(node{a, b, i});
    } else {
      de.emplace_back(node{a, b, i});
    }
  }
  cout << max(in.size(), de.size()) << "\n";
  if (in.size() >= de.size()) {
    sort(in.begin(), in.end(), comp2);
    for (node x : in) {
      cout << x.id << " ";
    }
  } else {
    sort(de.begin(), de.end(), comp1);
    for (node x : de) {
      cout << x.id << " ";
    }
  }
  cout << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}