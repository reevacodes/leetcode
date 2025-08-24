// LARGEST RECTANGLE IN HISTOGRAM

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
  stack<int> st;
  int n = heights.size();
  int maxArea = 0;
  int el, nse, pse;

  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && heights[st.top()] > heights[i])
    {
      el = st.top();
      st.pop();
      nse = i;
      pse = st.empty() ? -1 : st.top();
      maxArea = max(heights[el] * (nse - pse - 1), maxArea);
    }
    st.push(i);
  }

  while (!st.empty())
  {
    el = st.top();
    st.pop();
    nse = n;
    pse = st.empty() ? -1 : st.top();
    maxArea = max(heights[el] * (nse - pse - 1), maxArea);
  }

  return maxArea;
}

int main()
{
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
  return 0;
}
