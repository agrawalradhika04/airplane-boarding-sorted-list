# airplane-boarding-sorted-list
This is an implementation of an airplane boarding simulation using a sorted linked list. Each Passenger has a name and a boarding position. The program maintains an ordered list of passengers and provides the ability to insert new passengers, remove existing ones, search by name or index, and print the current boarding order.

hw8.cpp
Implements the main menu-driven program. Allows the user to add, remove, search, and print passengers using a sorted linked list. It handles all user interaction and invokes the necessary list operations.

passenger.h
Defines the Passenger class with fields for name and boarding position. Also includes comparison operator overloads to enable sorting and equality checks.

passenger.cpp
Contains implementations for the Passenger class's member functions, including constructors, getters, and operator overloads.

node.h
Declares a generic Node<T> struct for use in the linked list. Each node holds data of type T and a pointer to the next node.

List.h
Implements a templated, sorted singly linked list class List<T>. Includes methods to insert items in sorted order, search by key or position, remove items, check if the list is empty, and print the list contents.
