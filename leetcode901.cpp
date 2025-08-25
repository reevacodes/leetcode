// ONLINE STOCK SPAN

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
  stack<pair<int, int>> st; // {price, span}

  StockSpanner() {}

  int next(int price)
  {
    int span = 1;
    // Pop smaller or equal prices and accumulate their spans
    while (!st.empty() && st.top().first <= price)
    {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};

int main()
{
  StockSpanner stockSpanner;

  vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

  for (int price : prices)
  {
    cout << stockSpanner.next(price) << " ";
  }
  cout << endl;
  return 0;
}
