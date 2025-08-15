// Valid Anagram

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
  if (s.size() != t.size())
    return false;

  unordered_map<char, int> sMap;
  unordered_map<char, int> tMap;

  for (int i = 0; i < s.size(); i++)
  {
    sMap[s[i]]++; // count characters in s
    tMap[t[i]]++; // count characters in t
  }

  // Compare counts
  for (auto &p : sMap)
  {
    char ch = p.first;
    if (sMap[ch] != tMap[ch]) // compare frequencies
      return false;
  }

  return true;
}

int main()
{
  string s, t;
  cin >> s >> t;

  if (isAnagram(s, t))
    cout << t << " is an anagram of " << s << endl;
  else
    cout << t << " is NOT an anagram of " << s << endl;

  return 0;
}
