#include <bits/stdc++.h>
using namespace std;

// recursive backtracking: generate subsequences of arr
void genSubseqRec(const vector<int> &arr, int idx, vector<int> &cur, vector<vector<int>> &out)
{
  if (idx == (int)arr.size())
  {
    out.push_back(cur); // store current subsequence
    return;
  }
  // Option 1: exclude arr[idx]
  genSubseqRec(arr, idx + 1, cur, out);

  // Option 2: include arr[idx]
  cur.push_back(arr[idx]);
  genSubseqRec(arr, idx + 1, cur, out);
  cur.pop_back();
}

int main()
{
  vector<int> arr = {1, 2, 3}; // example
  vector<vector<int>> out;
  vector<int> cur;
  genSubseqRec(arr, 0, cur, out);

  cout << "All subsequences (" << out.size() << "):\n";
  for (const auto &sub : out)
  {
    cout << "{ ";
    for (int x : sub)
      cout << x << " ";
    cout << "}\n";
  }
  return 0;
}
