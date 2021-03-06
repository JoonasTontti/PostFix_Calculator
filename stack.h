#ifndef _STACK_H
#define _STACK_H

#include "Utility.h"


typedef double Stack_entry;

const int maxstack = 10;   //  small value for testing

class Stack {
public:
	Stack();
	Error_code pop();
	Error_code push(const Stack_entry& item);
	Error_code top(Stack_entry& item) const;

	bool empty() const;
	void clear(); // Reset the stack to be empty.
	bool full() const; // If the stack is full, return true; else return false.
	int size() const; // Return the number of entries in the stack.


private:
	int count;
	Stack_entry entry[maxstack];
};

#endif