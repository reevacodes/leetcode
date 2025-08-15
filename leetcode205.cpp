#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
  unordered_map<char, char> st; // s -> t
  unordered_map<char, char> ts; // t -> s

  for (int i = 0; i < s.size(); i++)
  {
    char sc = s[i];
    char tc = t[i];

    if (st.count(sc) && st[sc] != tc)
      return false;
    if (ts.count(tc) && ts[tc] != sc)
      return false;

    st[sc] = tc;
    ts[tc] = sc;

    // Optional: print maps for dry run
    cout << "i = " << i << "\n";
    cout << "st: ";
    for (auto &p : st)
      cout << p.first << "->" << p.second << " ";
    cout << "\nts: ";
    for (auto &p : ts)
      cout << p.first << "->" << p.second << " ";
    cout << "\n\n";
  }
  return true;
}

int main()
{
  string s, t;
  cout << "Enter first string: ";
  cin >> s;
  cout << "Enter second string: ";
  cin >> t;

  if (isIsomorphic(s, t))
  {
    cout << s << " and " << t << " are isomorphic.\n";
  }
  else
  {
    cout << s << " and " << t << " are NOT isomorphic.\n";
  }

  return 0;
}
