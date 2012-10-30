#include <iostream>
#include <cstring>
using namespace std;

#include "Quash.h"

bool VERBOSE = false;
void print_message(string);
void print_message(string, int, string);
void print_message(string, int, string, bool);

int main(int argc, char**argv) {
  if(argc > 1) {
    if(strcmp(argv[1], "--verbose") == 0) {
      VERBOSE = true;
    }
  }

  Quash quash;

  while(!cin.eof()) {
    string cmd;
    cin >> cmd;

    if(cmd.compare("insert") == 0) {
      int i;
      cin >> i;
      
      if(quash.contains(i)) {
        print_message("item", i, "already present");
      } else {
        quash.push(i);
        print_message("item", i, "successfully inserted");
      }
    } else if(cmd.compare("lookup") == 0) {
      int i;
      cin >> i;

      if(quash.contains(i)) {
        print_message("item", i, "found");
      } else {
        print_message("item", i, "not found");
      }
    } else if(cmd.compare("deleteMax") == 0) {
        if(quash.empty()) {
          print_message("max item not present since table is empty");
        } else {
          int i = quash.top();
          quash.pop();
          print_message("max item", i, "deleted", true);
        }
        
    } else if(cmd.compare("delete") == 0) {
      int i;
      cin >> i;

      if(quash.erase(i)) { // NOTE: Returns bool, not size_type.
        print_message("item", i, "successfully deleted");
      } else {
        print_message("item", i, "not present in the table");
      }
    } else if(cmd.compare("print") == 0) {
      quash.print_hash_table();
      quash.print_heap();
    }
  }
}

void print_message(string a) {
  cout << a << endl;
}

void print_message(string a, int b, string c) {
  print_message(a, b, c, false);
}

void print_message(string a, int b, string c, bool force) {
  if(VERBOSE or force) {
    cout << a << " " << b << " " << c << endl;
  } else {
    cout << a << " " << c << endl;
  }
}

