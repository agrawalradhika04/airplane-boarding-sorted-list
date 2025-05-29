#include <string>
#include <iostream>

using namespace std;

class Passenger{
 public:
  // Constructor- name becomes "", position becomes 1,000,000
  Passenger();

  // accessor functions
  string Get_Name() const;
  int Get_Position() const;

  // mutator functions
  void Set_Name(string new_name);
  void Set_Position(int new_pos);
  void Set(string new_name, int new_pos);

  // comparison operator, comparing positions  I only wrote < here, but
  // hopefully if you need others you can expand this
  bool operator<(const Passenger& other) const;

  // comparison operators seeing if two items are equal.  This compares names
  // It feels weird that different comparison operators are comparing different
  // things.
  bool operator==(const Passenger& other) const;
  bool operator!=(const Passenger& other) const;
 
  
 private:
  string name;
  int position;
};

// << operator for calls to cout.  This will let print_list work
ostream& operator<< (ostream& out, const Passenger& p);


