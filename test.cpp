#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
// #define what_is(x) cout << #x << " is " << x << "\n";
// #define rep(i, begin, end)                            \
//   for (__typeof(end) i = (begin) - ((begin) > (end)); \
//        i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

// template <typename T>
// T _max(T a) {
//   return a;
// }
// #define eb emplace_back
// #define mt make_tuple
// template <typename T, typename... Args>
// T _max(T a, Args... args) {
//   return max(a, _max(args...));
// }
// int sum() { return 0; }

// template <typename T, typename... Args>
// T sum(T a, Args... args) {
//   return a + sum(args...);
// }
// long long operator"" _km(unsigned long long literal) { return literal * 1000;
// }
int main(int argc, char const *argv[]) {
  // vector<int> v{7, 2, 3, 5};
  // vector<int> n;
  // for (int a : v) {
  //   n.eb(a + 1);
  // }
  // v = move(n);
  // rep(it, v.begin(), v.end()) cout << *it << " ";
  // rep(it, n.begin(), n.end()) cout << *it << " ";
  // cout << R"(Hello\tWorld\n)"
  //      << "\n";
  // regex email_pattern(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");
  // string valid_email("swift@codeforces.com");
  // if (regex_match(valid_email, email_pattern))
  //   cout << valid_email << " is valid\n";
  // else
  //   cout << valid_email << " is invalid\n";
  // cout << 120_km << "meters \n";
  // tuple<int, int> t{1, 2};
  pair<int, int> p1{1, 2};
  pair<int, int> p2 = p1;
  p2.first = 3;
  cout << p1.first << "\n";
}
