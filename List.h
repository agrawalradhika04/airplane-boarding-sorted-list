// Sean McCulloch
// File is as provided as part of the coursework.
// 3/25/15
// List.h
// Implementes a sorted linked list using the node class defined in
// node.h and node.cpp.  This class will have member functions
// for insertion, deletion, and printing the list elements out.
// Note that since this list keeps its nodes in sorted order, it's important
// that the type of the nodes be something we can compare with operators like <

#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>

using namespace std;

template <typename T>
class List{
  public:
	// constructor- creates an empty list
	List();
	//destructor- deletes the entire list, freeing every node.
	~List();
	
	// copy constructor- called so that we have a "deep copy"
	// of the list when needed.
	List(const List<T>& L);
	
	// Print the elements of the list
	void Print_List() const;
	
	// other member functions- to be done in lab
	
	// inserts an element into the correct sorted position of
	// the list
	void Insert(const T& new_item);
	
	// deletes an item from the list, if it's there.  Returns
	// true if the item was deleted, false otherwise
	bool Delete(const T& del_item);
	
	//find_item returns the index of the item if it is in
	// the list, -1 otherwise
	int Find_Item(const T& item);
	
	//find_item_at_index returns the item at position index in
	// the reference parameter "value".  Returns true if the index
	// is a valid one, false otherwise
	bool Find_Item_At_Index(int position, T& value);
	
	// this function computes the size of the list.  It will
	// count every node (an O(n) operation).  We could make 
	// this constant time by storing the size in the class, but
	// that would require constant updating in our insert and 
	// delete functions
	int Size() const;
	
  private:
  	//the only data we need in the private section is a pointer to the list
  	Node<T>* theList;
};

// The default constructor creates a list with no elements
template <typename T>
List<T>::List(){
	theList = NULL; // so that we have a consistent way to 
	                // check for an empty list
}

// the list destructor has to delete the whole list, node by node
template <typename T>
List<T>::~List(){
	Node<T>* p = theList;
	Node<T>* kill = theList;
	while(p!= NULL){
		kill = p;
		p = p->get_next();
		delete kill;
	}
	theList = NULL; // just in case
}

// the list copy constructor creates a new list with new nodes,
// all with identical data to those in the list we're copying
// from
template <typename T>
List<T>::List(const List<T>& L){
	Node<T>* orig_list_pos = L.theList; // holds the position of
	                                 // the thing we're copying
	                                 // in L
	if(orig_list_pos == NULL) // then L is empty..
	  theList = NULL; //...and so are we
	else{
	  theList = new Node<T>;
	  theList->set_item(orig_list_pos->get_item());
	  Node<T>* new_list_end= theList; // points to the last item in the
	                      // list we're creating
	  orig_list_pos = orig_list_pos->get_next();

	  // this loop will continually copy items from the original
	  // list (pointed at by "orig_list_pos") to the new list
	  // (whose last item is pointed at by "new_list_end"), until
	  // the oringinal list runs out of elements
	  while(orig_list_pos != NULL) {
	  	// the loop has 2 parts.  First, we create the new node,
	  	// and set it's value
	  	
	  	Node<T>* n = new Node<T>;
	  	n->set_item(orig_list_pos->get_item());
	  	n->set_next(NULL);
	  	new_list_end->set_next(n); // links n into the list
	  	
	  	// now, we set up the next iteration
	  	new_list_end = n; //so it points to the last element in
	  	                   // the new list again
	  	orig_list_pos =orig_list_pos->get_next();
	  }
	  
	  // when we leave the loop, we have a whole new copy, 
	  // pointed at by theList.  The only thing we have to do
	  // is set the last element to point to NULL.
	  new_list_end->set_next(NULL);
	}
}
	  

// the print_list function prints all of the elements in the
// list
template <typename T>
void List<T>::Print_List() const{

	Node<T>* p = theList;
	while(p != NULL){
	  cout << p->get_item() << endl;
	  p = p->get_next();
	 }
}

// Insert inserts an element into the appropriate place in the
// sorted list
template <typename T> 
void List<T>::Insert(const T& new_item){
	Node<T> *p = new Node<T>;
	p->set_item(new_item);

	if (theList == NULL){
		theList = p;
	}
	else{
		if(new_item < theList->get_item()){
			p->set_next(theList);
			theList = p;
		}
		else{
			Node<T> *r ;
			r = theList;
			while(r != NULL){
				if(r -> get_next() == NULL){
					r->set_next(p);
					return;
				}
				if(r->get_next() -> get_item() < p->get_item()){
					r = r->get_next();
				}
				else{
					p->set_next(r->get_next());
					r -> set_next(p);
					return;
				}
			}

		}
	}
}

// Delete removes an item from the list.  returns true if the
// item was successfully deleted, false if it wasn't (becuase
// the item couldn't be found)
template <typename T>
bool List<T>::Delete(const T& del_item){
	if(theList == NULL){
        return false; 
	}

	Node<T> *kill = theList;

	if(del_item == kill->get_item()){
		theList = kill->get_next();
		delete kill;
		return true;
	}
	
	Node<T> * previous = kill;
	kill = kill->get_next();

	while(kill != NULL){
		if(del_item == kill->get_item()){
			previous->set_next(kill->get_next());
			delete kill;
			return true;
		}
		previous = kill;
		kill = kill->get_next();
	}
	return false;
}

//find_item returns the index of the item if it is in the list,
// -1 otherwise.  It uses a sequential search technique
template <typename T>
int List<T>::Find_Item(const T& item){
	Node<T>* p = theList;
	int index = 0;
	while (p != NULL) {
   	 	if (p->get_item() == item) {
       	 	return index;
    	}
    	p = p->get_next();
    	index++;
	}
	return -1;
}

//find_item_at_index returns the item at position index in
// the reference parameter "value".  Returns true if the index
// is a valid one, false otherwise
template <typename T>
bool List<T>::Find_Item_At_Index(int position, T& value){
	if(theList == NULL){
		return false;
	}

	Node<T>* p = theList;
	int index = 0;

	for(int i = 0; i <= position; i++){
		//p = p->get_next();
	
		if(p != NULL && i == position){
			value = p->get_item();
			return true;
		}

		p = p->get_next();
	}

	return false;
}

// this function computes the size of the list.  It will
	// count every node (an O(n) operation).  We could make 
	// this constant time by storing the size in the class, but
	// that would require constant updating in our insert and 
	// delete functions
template <typename T>
int List<T>::Size() const{
	Node<T>* p = theList;
	int count = 0;
	while (p != NULL) {
    	count++;
   	 	p = p->get_next();
	}
	return count;
}

#endif
