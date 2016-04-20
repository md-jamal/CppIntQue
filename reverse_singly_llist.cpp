// Q36. Reversing singly linked list
//
// List can be reversed in many ways.
// Here two methods are demonstrated -
// 1. Iterate through list in a loop and change
//    next node to prev, prev to current and 
//    current to next.
//
// 2. Recursive method
//    - Divide list into two parts first node and rest of list
//    - Call reverse() for rest of list
//    - Link rest to first
//    - change head
//
// Complexity O(n) for both methods
//
// Author - Prashant Kothawade
// Date - 20-04-2016

#include <iostream>
using namespace std;

// Singly linked list node structure
struct node {
	int num;
	node* next;
} *head; // pointer to head of list

// Function to reverse linked list - Iteration Method
int reverse_list()
{
	int no_of_iterations = 0;

	node* current = head;
	node* prev = NULL;
	node* next = NULL;
	while(current!=NULL){
		// Next node
		next = current->next;
		// Next to prev
		current->next = prev;
		// Prev to current
		prev = current;
		// Current to next
		current = next;

		++no_of_iterations;
	}
	head = prev;

	return no_of_iterations;
}

// Function to reverse linked list - Recursion Method
int recursive_rev(node** head) {
	static int no_of_iterations = 0;
	no_of_iterations += 1;

	// First node
	node* first = *head;
	// Rest of list
	node* rest = first->next;
	// If done then return
	if(rest==NULL) return no_of_iterations;
	// Call reverse() on rest of list
	recursive_rev(&rest);
	// Link rest to first
	first->next->next = first;
	first->next = NULL;
	// Change head
	*head = rest;

	return no_of_iterations;
}

int main()
{
	// Input number of nodes
	int num_nodes = 0;
	cout<<"Enter number of nodes :";
	cin>>num_nodes;

	// Input of node values to add in list
	cout<<endl<<"Enter node values : ";
	node* it = NULL;
	for(int i=0; i<num_nodes; i++) {
		node* nnode = new node();
		cin>>nnode->num;
		if(!head) head = it = nnode;
		it->next = nnode;
		it = nnode;
	}

	// Reverse the list in either method
	int num_iter = reverse_list();
	//int num_iter = recursive_rev(&head);

	// Print reversed list
	cout<<endl<<"Reversed list: ";
	it = head;
	do {
		cout<<it->num<<" ";
	} while(it=it->next);

	cout<<endl<<endl<<"No if iterations :"<<num_iter;

	return 0;
}
