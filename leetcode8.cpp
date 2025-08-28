// STRING TO CACHE

// APPROACH 1 - ITERATIVE

// #include <iostream>
// #include <string>
// #include <climits>
// using namespace std;

// int myAtoi(string s)
// {
//   int i = 0, n = s.length();

//   // 1. Skip leading whitespaces
//   while (i < n && s[i] == ' ')
//     i++;

//   // 2. Check for sign
//   int sign = 1;
//   if (i < n && (s[i] == '+' || s[i] == '-'))
//   {
//     if (s[i] == '-')
//       sign = -1;
//     i++;
//   }

//   // 3. Read digits and build the number
//   long long result = 0; // use long long to handle overflow while building number
//   while (i < n && isdigit(s[i]))
//   {
//     result = result * 10 + (s[i] - '0');

//     // 4. Check for overflow
//     if (sign * result > INT_MAX)
//       return INT_MAX;
//     if (sign * result < INT_MIN)
//       return INT_MIN;

//     i++;
//   }

//   return (int)(sign * result);
// }

// // Example usage
// int main()
// {
//   string str = "   -42";
//   cout << myAtoi(str) << endl; // Output: -42
//   return 0;
// }

// APPROACH II - RECURSIVE

#include <iostream>
#include <string>
#include <climits>
using namespace std;

long long helper(const string &s, int i, int sign, long long result)
{
  // Base case: end of string or non-digit character
  if (i >= s.size() || !isdigit(s[i]))
    return sign * result;

  // Add current digit
  result = result * 10 + (s[i] - '0');

  // Check for overflow
  if (sign * result > INT_MAX)
    return INT_MAX;
  if (sign * result < INT_MIN)
    return INT_MIN;

  // Recursive call for next character
  return helper(s, i + 1, sign, result);
}

int myAtoi(string s)
{
  int i = 0;

  // 1. Skip leading whitespaces
  while (i < s.size() && s[i] == ' ')
    i++;

  // 2. Check for sign
  int sign = 1;
  if (i < s.size() && (s[i] == '+' || s[i] == '-'))
  {
    if (s[i] == '-')
      sign = -1;
    i++;
  }

  // 3. Start recursion from current index
  return (int)helper(s, i, sign, 0);
}

// Example usage
int main()
{
  string str = "   -91283472332";
  cout << myAtoi(str) << endl; // Output: -2147483648 (clamped)
  return 0;
}
