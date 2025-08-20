// MIN STACK

#include <bits/stdc++.h>
using namespace std;

// Global stack and current minimum
stack<long long> st;
long long mini = LLONG_MAX;

// Push operation
void push(int val)
{
  if (st.empty())
  {
    mini = val;
    st.push(val);
  }
  else
  {
    if (val >= mini)
    {
      st.push(val);
    }
    else
    {
      // Store encoded value
      st.push(2LL * val - mini);
      mini = val;
    }
  }
}

// Pop operation
void pop()
{
  if (st.empty())
  {
    cout << "Stack is empty\n";
    return;
  }
  long long x = st.top();
  st.pop();
  if (x < mini)
  {
    // Restore previous minimum
    mini = 2LL * mini - x;
  }
}

// Top operation
int top()
{
  if (st.empty())
  {
    cout << "Stack is empty\n";
    return -1;
  }
  long long x = st.top();
  if (x < mini)
    return (int)mini;
  return (int)x;
}

// Get minimum
int getMin()
{
  if (st.empty())
  {
    cout << "Stack is empty\n";
    return -1;
  }
  return (int)mini;
}

// Driver code
int main()
{
  push(5);
  push(3);
  push(7);
  push(2);

  cout << "Top: " << top() << "\n";    // should print 2
  cout << "Min: " << getMin() << "\n"; // should print 2

  pop();                               // remove 2
  cout << "Top: " << top() << "\n";    // should print 7
  cout << "Min: " << getMin() << "\n"; // should print 3

  pop();                               // remove 7
  cout << "Top: " << top() << "\n";    // should print 3
  cout << "Min: " << getMin() << "\n"; // should print 3

  pop();                               // remove 3
  cout << "Top: " << top() << "\n";    // should print 5
  cout << "Min: " << getMin() << "\n"; // should print 5

  return 0;
}
