#include "Quash.h"
#include <iostream>

using namespace std;

bool Quash::empty() const {
  return heap.empty();
}

/* Return true if the quash contains the specified value. */
bool Quash::contains(int value) const {
  return contains_hash_table(value);
}

/* Return the largest value in the quash. Undefined behaviour if called when
 * the quash is empty. */
int Quash::top() const { return heap.front().first; }

// Insert an element into the quash. Does nothing if the element was already
// in the quash.
void Quash::push(int value) {
  if(contains(value)) return;

  int hash_index = push_hash_table(value);
  int heap_index = push_heap(value);
  hash_table[hash_index].second = heap_index;
  heap[heap_index].second = hash_index;
}

/* Remove the largest value from the quash. Undefined behaviour if called when
 * the quash is empty. */
void Quash::pop() {
  hash_table[heap.front().second].second = -2;

  heap.front() = heap.back();
  heap.pop_back();
  percolate_down(0);
}

bool Quash::erase(int value) {
  int hash_index = find_hash_table(value);
  if(hash_index == -1) return false;

  int heap_index = hash_table[hash_index].second;
  heap[heap_index] = heap.back();
  heap.pop_back();
  percolate_down(heap_index);

  hash_table[hash_index].second = -2;
}

void Quash::print_heap() const {
  if(!heap.empty()) {
    cout << heap[0].first;
    for(int i=1; i < heap.size(); i++) {
      cout << " " << heap[i].first;
    }
  }
  cout << endl;
}

void Quash::print_hash_table() const {
  bool did_print_a_number = false;
  if(hash_table[0].second >= 0) {
    cout << hash_table[0].first;
    did_print_a_number = true;
  }
  for(int i=1; i < hash_table.size(); i++) {
    if(hash_table[i].second >= 0) {
      if(did_print_a_number) cout << " ";
      cout << hash_table[i].first;
      did_print_a_number = true;
    }
  }
  cout << endl;
}

// PRIVATE

/* Swap heap[i] with the larger of its children until it satisfies the heap
 * property in its new position. */
void Quash::percolate_down(int i) {
  while(true) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left <= heap.size() and heap[left] > heap[largest]) largest = left;
    if(right <= heap.size() and heap[right] > heap[largest]) largest = right;
    if(largest != i) {
      swap(heap[i], heap[largest]);
      hash_table[heap[i].second].second = largest;
      hash_table[heap[largest].second].second = i;
    } else {
      return;
    }
  }
}

/*
 * Insert an element into the heap, updating indexes that become invalid when
 * the heap is rearranged. Returns the index of the new element in the heap.
 *
 * Assumes element does not already exist in the heap.
 */
int Quash::push_heap(int value) {
  heap.push_back(make_pair(value, -1));
  int i;
  for(i = heap.size()-1; heap[i].first < heap[(i-1)/2].first; i = (i-1)/2) {
    swap(heap[i], heap[(i-1)/2]);
    if(heap[i].second != -1)
      hash_table[heap[i].second].second = (i-1)/2;
    if(heap[(i-1)/2].second != -1)
      hash_table[heap[(i-1)/2].second].second = i;
  }
  return i;
}

int Quash::find_hash_table(int value) const {
  int i = hash(value);
  while(i != hash(value)-1) {
    if(hash_table[i].second == -1) break;
    if(hash_table[i].second != -2 and hash_table[i].first == value)
      return i;
    if(++i == 43) i = 0;
  }
  return -1;
}


bool Quash::contains_hash_table(int value) const {
  return find_hash_table(value) != -1;
}

/*
 * Insert an element into the hash table using linear probing. Returns the
 * index of the new element in the hash table.
 *
 * Assumes element does not already exist in the hash table.
 */
int Quash::push_hash_table(int value) {
  int i = hash(value);
  while(i != hash(value)-1) {
    if(hash_table[i].second == -1) break;
    if(hash_table[i].second == -2) break;
    if(++i == 43) i = 0;
  }

  hash_table[i].first = value;
  return i;
}

int Quash::hash(int value) const {
  return (value%43 + 43) % 43; // TODO test -- positive mod
}

