#include <iostream>
#include "List.h"
#include "passenger.h"

using namespace std;

int main(){
    List<Passenger> list;

    cout << "How many passengers? ";
    int num_passengers;
    cin >> num_passengers;

    for(int i = 0; i < num_passengers; i++){
        cout << "Enter the passenger's name: ";
        string name;
        cin >> name;

        cout << "Enter the position in line (positive number): ";
        int pos;
        cin >> pos;

        Passenger passenger;
        passenger.Set(name, pos);
        list.Insert(passenger);
    }

    bool exit = false;

    while(!exit){
        cout << "The current line is: " << endl;

        list.Print_List();

        cout << "Enter 1 to move someone in the list to a new position." << endl;

        cout << "Enter 2 to remove the first person in the list." << endl;

        cout << "Enter 3 to add someone to the list." << endl;

        cout << "Enter 4 to quit." << endl;

        int choice;
        cin >> choice;

        if(choice == 1){
            cout << "Who are we moving? ";
            string name;
            cin >> name;

            cout << "What is their new position? ";
            int pos;
            cin >> pos;

            Passenger passenger;
            passenger.Set(name, pos);
            int index = list.Find_Item(passenger);
                if (index > -1){
                    list.Delete(passenger);
                    list.Insert(passenger);
                }
        }
        else if(choice == 2){
            Passenger passenger;
            list.Find_Item_At_Index(0, passenger);
            string name = passenger.Get_Name();
            cout << name << " has exited the line. ";
            list.Delete(passenger);
        }
        else if(choice == 3){
            cout << "What is the name of the new passenger? ";
            string name;
            cin >> name;

            cout << "Where is their position?";
            int pos;
            cin >> pos;

            Passenger passenger;
            passenger.Set(name, pos);
            list.Insert(passenger);
        }
        else{
            exit = true;
        }
        }

    list.Print_List();

}
