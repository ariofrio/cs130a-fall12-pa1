#include "Quash.h"
#include <iostream>

using namespace std;

bool Quash::empty() const {
  return heap.empty();
}

// Return true if the quash contains the specified value.
bool Quash::contains(int value) const {
  return false;
}

// Return the largest value in the quash.
int Quash::top() const {
  return -1;
}

// Insert an element into the quash. Does nothing if the element was already
// in the quash.
void Quash::push(int value) {

}

void Quash::pop() {

}

bool Quash::erase(int value) {
  return false;
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
  if(hash_table[0].second != -1)
    cout << hash_table[0].first;
  for(int i=1; i < hash_table.size(); i++) {
    if(hash_table[i].second != -1)
      cout << " " << hash_table[i].first;
  }
  cout << endl;
}

// PRIVATE

int Quash::push_heap(int) {
  
}

void Quash::pop_heap() {

}

int Quash::push_hash_table(int) {

}

void Quash::pop_hash_table() {

}

int Quash::hash(int value) const {
  return value % 43;
}

