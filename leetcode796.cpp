// Compare the rotated string

#include <bits/stdc++.h>
using namespace std;

bool isRotationBruteForce(string s1, string s2)
{
  if (s1.size() != s2.size())
    return false;
  int n = s1.size();

  for (int i = 0; i < n; i++)
  {
    // Rotate s1 by i positions
    string rotated = s1.substr(i) + s1.substr(0, i);
    if (rotated == s2)
      return true;
  }
  return false;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  if (isRotationBruteForce(s1, s2))
    cout << s2 << " is a rotation of " << s1 << endl;
  else
    cout << s2 << " is NOT a rotation of " << s1 << endl;

  return 0;
}
