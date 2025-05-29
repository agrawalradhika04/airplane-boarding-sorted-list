// Sean McCulloch
// 3/25/15
// node.h- defines an template node class for use in a linked list
// (or other dynamic structure)  Defines basic accessor
// and mutator functions
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
	public:
		//default constructor, which will get called when
		// we create a node
  Node(T default_item = T());
		//destructor which will get called when we delete a node
		~Node();
		
		//accessor and mutator for the "item"- the data the
		// node holds
		T get_item() const;
		void set_item(const T& new_item);
		
		//accessor and mutator for the "next"- the pointer to
		// the next node in the list
		Node<T>* get_next() const;
		void set_next(Node<T>* next_item);
		
	private:
	
		Node<T>* Next;
		T item;
};

// constructor- sets the item to a vaule given by a parameter (or a default)
// , and the next to NULL
template <typename T>
Node<T>::Node(T default_item){
	item = default_item;
	Next = NULL; // note that the compiler knows what NULL is,
				 // as long as we include cstdlib
				 
}

//destructor- called when the item is deleted.  
// We could delete the next item in the list, but since we 
//won't always want that behavior, it's better to make that be
// the job of the structure that uses the node
template <typename T>
Node<T>::~Node(){
	Next = NULL; // because I'm really paranoid, and I want to
	             // make sure it's done, in case someone forgets
	
	// there's no need to set item to anything..
}

//Accessor function for the _item_- the value that is stored in 
// the node
// Notice that this function is declared _const_.  That's important, 
// because it means that it can be used by const items.
template <typename T>
T  Node<T>::get_item() const{
  return item;
 }
 
// Mutator function for the item
template <typename T>
void Node<T>::set_item(const T& new_item){
	item = new_item;
}

// now, the accessor and mutator functions for the next field.
// the next field points to the next node in the list, which
// is why it is of type "pointer to a node"
template <typename T>
Node<T>* Node<T>::get_next() const{
	return Next;
}

template <typename T>
void Node<T>::set_next(Node<T>* next_item){
	Next= next_item;
}
#endif
