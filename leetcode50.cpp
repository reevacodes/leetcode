#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mod = 1e9 + 7;

  // Fast exponentiation modulo mod
  long long modPow(long long x, long long n)
  {
    long long result = 1;
    while (n > 0)
    {
      if (n % 2 == 1)
        result = (result * x) % mod; // multiply if odd
      x = (x * x) % mod;             // square x
      n /= 2;                        // halve n
    }
    return result;
  }

  int countGoodNumbers(long long n)
  {
    long long even_pos = (n + 1) / 2; // ceil(n/2)
    long long odd_pos = n / 2;        // floor(n/2)
    long long res = (modPow(5, even_pos) * modPow(4, odd_pos)) % mod;
    return (int)res;
  }
};

int main()
{
  Solution sol;
  long long n;
  cout << "Enter n: ";
  cin >> n;

  int ans = sol.countGoodNumbers(n);
  cout << "Count of good numbers = " << ans << endl;

  return 0;
}
