// REMOVE K DIGITS

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
  stack<char> st;
  int n = num.size();
  string res = "";

  if (k == n)
    return "0";

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && k > 0 && st.top() > num[i])
    { // direct char comparison works
      st.pop();
      k--;
    }
    st.push(num[i]);
  }

  // Remove remaining digits if k > 0
  while (k > 0 && !st.empty())
  {
    st.pop();
    k--;
  }

  // Build result string from stack
  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }

  // Remove leading zeros (after reversing)
  while (!res.empty() && res.back() == '0')
    res.pop_back();

  if (res.empty())
    return "0";

  reverse(res.begin(), res.end());
  return res;
}

int main()
{
  string num;
  int k;

  // Example 1
  num = "1432219";
  k = 3;
  cout << "Input: " << num << ", k = " << k << endl;
  cout << "Smallest number: " << removeKdigits(num, k) << endl;

  // Example 2
  num = "10200";
  k = 1;
  cout << "Input: " << num << ", k = " << k << endl;
  cout << "Smallest number: " << removeKdigits(num, k) << endl;

  // Example 3
  num = "10";
  k = 2;
  cout << "Input: " << num << ", k = " << k << endl;
  cout << "Smallest number: " << removeKdigits(num, k) << endl;

  return 0;
}
