// LFU CACHE

#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
  struct Node
  {
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
  };

  struct DLList
  {
    Node *head, *tail;
    int size;
    DLList()
    {
      head = new Node(-1, -1);
      tail = new Node(-1, -1);
      head->next = tail;
      tail->prev = head;
      size = 0;
    }
    void addFront(Node *node)
    {
      node->next = head->next;
      node->prev = head;
      head->next->prev = node;
      head->next = node;
      size++;
    }
    void removeNode(Node *node)
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      size--;
    }
    Node *removeLast()
    {
      if (size == 0)
        return nullptr;
      Node *node = tail->prev;
      removeNode(node);
      return node;
    }
  };

  int cap, minFreq, curSize;
  unordered_map<int, Node *> keyTable;    // key → node
  unordered_map<int, DLList *> freqTable; // freq → DLL

public:
  LFUCache(int capacity)
  {
    cap = capacity;
    minFreq = 0;
    curSize = 0;
  }

  int get(int key)
  {
    if (cap == 0 || keyTable.find(key) == keyTable.end())
      return -1;

    Node *node = keyTable[key];
    updateFreq(node);
    return node->val;
  }

  void put(int key, int value)
  {
    if (cap == 0)
      return;

    if (keyTable.find(key) != keyTable.end())
    {
      Node *node = keyTable[key];
      node->val = value; // update value
      updateFreq(node);  // increase frequency
    }
    else
    {
      if (curSize == cap)
      {
        DLList *list = freqTable[minFreq];
        Node *toRemove = list->removeLast();
        keyTable.erase(toRemove->key);
        delete toRemove;
        curSize--;
      }
      Node *newNode = new Node(key, value);
      keyTable[key] = newNode;
      if (freqTable.find(1) == freqTable.end())
      {
        freqTable[1] = new DLList();
      }
      freqTable[1]->addFront(newNode);
      minFreq = 1;
      curSize++;
    }
  }

private:
  void updateFreq(Node *node)
  {
    int oldFreq = node->freq;
    freqTable[oldFreq]->removeNode(node);
    if (oldFreq == minFreq && freqTable[oldFreq]->size == 0)
    {
      minFreq++;
    }
    node->freq++;
    if (freqTable.find(node->freq) == freqTable.end())
    {
      freqTable[node->freq] = new DLList();
    }
    freqTable[node->freq]->addFront(node);
  }
};

// ----------------- Testing in VS Code -----------------
int main()
{
  LFUCache cache(2); // capacity = 2

  cache.put(1, 1);
  cache.put(2, 2);

  cout << cache.get(1) << endl; // returns 1 (freq(1)=2, freq(2)=1)

  cache.put(3, 3); // evicts key 2 (LFU)

  cout << cache.get(2) << endl; // returns -1 (not found)
  cout << cache.get(3) << endl; // returns 3

  cache.put(4, 4); // evicts key 1

  cout << cache.get(1) << endl; // returns -1
  cout << cache.get(3) << endl; // returns 3
  cout << cache.get(4) << endl; // returns 4

  return 0;
}
