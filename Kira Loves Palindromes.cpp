#include <bits/stdc++.h>
using namespace std;

struct node {
  vector<int> v1;
  vector<int> v2;
  node* child[26];
};

void addWord(node* root, const char* word, int start);
int searchWord(node* root, const char* word, int end);
const int LENMAX = 1001;
bool p[LENMAX][LENMAX];
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char* s = new char[LENMAX];
  cin >> s;
  int len = strlen(s);
  for (int d = 0; d < len; d++) {
    for (int i = 0; i + d < len; i++) {
      int j = i + d;
      p[i][j] = s[i] == s[j] && (i + 1 > j - 1 || p[i + 1][j - 1]);
    }
  }
  node* trie = new node();
  long ans = 0;
  for (int i = 0; i < len; i++) {
    addWord(trie, s, i);
  }
  for (int i = len - 1; i >= 0; i--) {
    ans += searchWord(trie, s, i);
  }
  cout << ans << "\n";
  return 0;
}

void addWord(node* root, const char* word, int start) {
  node* cur = root;
  for (int i = start; word[i]; i++) {
    char ch = word[i];
    if (cur->child[ch - 'a'] == NULL) {
      cur->child[ch - 'a'] = new node();
    }
    cur = cur->child[ch - 'a'];
    for (int j = i + 1; word[j]; j++) {
      if (p[i + 1][j]) {
        cur->v2.push_back(j);
      }
    }
    cur->v1.push_back(i);
  }
};
int searchWord(node* root, const char* word, int end) {
  int ans = 0;
  node* cur = root;
  for (int i = end; i >= 0; i--) {
    char ch = word[i];
    if (cur->child[ch - 'a'] == NULL) {
      return ans;
    }
    cur = cur->child[ch - 'a'];
    for (int j = i; j >= 0; j--) {
      if (j == i || p[j][i - 1]) {
        ans += lower_bound(cur->v1.begin(), cur->v1.end(), j) - cur->v1.begin();
      }
    }
    for (int p : cur->v2) {
      if (p < i) {
        ans++;
      }
    }
  }
  return ans;
};