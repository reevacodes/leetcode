#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string curr, vector<string> &res)
{
  if (open == 0 && close == 0)
  {
    res.push_back(curr);
    return;
  }
  if (open > 0)
    solve(open - 1, close, curr + "(", res);
  if (close > open)
    solve(open, close - 1, curr + ")", res);
}

int main()
{
  int n = 3;
  vector<string> res;
  solve(n, n, "", res);
  for (string s : res)
    cout << s << "\n";
}
