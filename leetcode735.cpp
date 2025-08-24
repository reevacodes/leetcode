// ASTEROID COLLISION

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
  vector<int> st; // stack to simulate collisions

  for (int a : asteroids)
  {
    bool destroyed = false;

    // check for collisions
    while (!st.empty() && a < 0 && st.back() > 0)
    {
      if (st.back() < -a)
      {
        st.pop_back(); // stack asteroid destroyed
        continue;      // keep checking with new top
      }
      else if (st.back() == -a)
      {
        st.pop_back(); // both destroyed
        destroyed = true;
        break;
      }
      else
      { // st.back() > -a
        destroyed = true;
        break;
      }
    }

    if (!destroyed)
    {
      st.push_back(a); // asteroid survives
    }
  }

  return st;
}

int main()
{
  vector<int> asteroids;

  asteroids = {5, 10, -5};
  vector<int> res = asteroidCollision(asteroids);
  cout << "Output: ";
  for (int a : res)
    cout << a << " ";
  cout << endl;

  asteroids = {8, -8};
  res = asteroidCollision(asteroids);
  cout << "Output: ";
  for (int a : res)
    cout << a << " ";
  cout << endl;

  asteroids = {10, 2, -5};
  res = asteroidCollision(asteroids);
  cout << "Output: ";
  for (int a : res)
    cout << a << " ";
  cout << endl;

  return 0;
}
