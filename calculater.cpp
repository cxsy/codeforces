#include <bits/stdc++.h>
using namespace std;

const int LENMAX = 100;

char expr[LENMAX];
double num[LENMAX];
char op[LENMAX];

double getNum(int& index);
double getAns(double n1, double n2, char op);

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%s", expr);
  for (int i = 0, ni = 0, oi = 0; expr[i] || oi; i++) {
    if (expr[i] == ' ') continue;
    if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
      double n = getNum(i);
      if (oi && (op[oi - 1] == '*' || op[oi - 1] == '/')) {
        num[ni - 1] = getAns(num[ni - 1], n, op[--oi]);
      } else {
        num[ni++] = n;
      }
    }
    if (!expr[i] || expr[i] == ')' || expr[i] == '-' || expr[i] == '+') {
      if (oi && op[oi - 1] != '(') {
        if (ni >= 2) {
          double n2 = num[--ni], n1 = num[--ni];
          num[ni++] = getAns(n1, n2, op[--oi]);
        }
      }
    }
    if (expr[i] == ')')
      oi--;
    else if (expr[i])
      op[oi++] = expr[i];
  }
  printf("%.1f", num[0]);
  return 0;
}

double getNum(int& index) {
  string s = "";
  do {
    s += expr[index++];
  } while ((expr[index] >= '0' && expr[index] <= '9') || expr[index] == '.');
  return stod(s);
}

double getAns(double n1, double n2, char op) {
  if (op == '+') return n1 + n2;
  if (op == '-') return n1 - n2;
  if (op == '*') return n1 * n2;
  return n1 / n2;
}