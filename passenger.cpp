#include "passenger.h"


  // Constructor- name becomes "", position becomes 1,000,000
Passenger::Passenger(){
  Set_Name("");
  Set_Position(1000000);
}


  // accessor functions
string Passenger::Get_Name() const{
  return name;
}

int Passenger::Get_Position() const{
  return position;
}


// mutator functions
void Passenger::Set_Name(string new_name){
  name = new_name;
}

void Passenger::Set_Position(int new_pos){
  if(new_pos <= 0)
    cout << "ERROR: Trying to set position to " << new_pos << " when it must be positive" << endl;

  else
    position = new_pos;
}

void Passenger::Set(string new_name, int new_pos){
  Set_Name(new_name);
  Set_Position(new_pos);
}


// comparison operator, comparing positions  I only wrote < here, but
// hopefully if you need others you can expand this
bool Passenger::operator<(const Passenger& other) const{
  if(Get_Position() < other.Get_Position())
    return true;
  else
    return false;
}

// equality operators, comparing names.  Yes, it's weird that different
// comparison operators compare different things
bool Passenger::operator==(const Passenger& other) const{
  if(Get_Name() == other.Get_Name())
    return true;
  else
    return false;
}

bool Passenger::operator!=(const Passenger& other) const{
  if(Get_Name() == other.Get_Name())
    return false;
  else
    return true;
}

// << operator for calls to cout.  This will let print_list work
ostream& operator<< (ostream& out, const Passenger& p)
{
  out << "Name: " << p.Get_Name() << " Position: " << p.Get_Position() << endl;
  return out;
}
