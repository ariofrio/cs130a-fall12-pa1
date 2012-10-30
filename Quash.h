#ifndef QUASH_H
#define QUASH_H

#include <vector>

using namespace std;

/*
 * A combination between a hash set and a maximum priority queue.
 * Behaves as a set (no repeated elements, no ordering) with the
 * ability to act on the largest integer stored on the quash.
 */
class Quash {
public:
  Quash() : hash_table(43, make_pair(0, -1)) {
    heap.reserve(43);
  }
  
  // Capacity
  bool empty() const;

  // Element access
  bool contains(int) const; 
  int top() const;

  // Modifiers
  void push(int);
  void pop();
  bool erase(int);

  // Debugging
  void print_heap() const;
  void print_hash_table() const;

private:
  // Heap of (element, hash_table_index)
  vector<pair<int, int> > heap;
  int push_heap(int);
  void pop_heap();

  // Hash table of (element, heap_index)
  // Empty or deleted slots have heap_index == -1
  vector<pair<int, int> > hash_table;
  int push_hash_table(int);
  void pop_hash_table();

  int hash(int) const;
};

#endif

