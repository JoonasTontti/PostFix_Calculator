#include "Utility.h"
#include "stack.h"

Error_code Stack::push(const Stack_entry& item)
/*
Pre:  None.
Post: If the Extended_stack is not full, item is added to the top
      of the Extended_stack.  If the Extended_stack is full,
      an Error_code of overflow is returned and the Extended_stack is left unchanged.
*/

{
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Extended_stack is not empty, the top of
      the Extended_stack is removed.  If the Extended_stack
      is empty, an Error_code of underflow is returned.
*/

{
    Error_code outcome = success;
    if (count <= 0)
        outcome = underflow;
    else --count;
    return outcome;
}


Error_code Stack::top(Stack_entry& item) const
/*
Pre:  None.
Post: If the Extended_stack is not empty, the top of
      the Extended_stack is returned in item.  If the Extended_stack
      is empty an Error_code of underflow is returned.
*/

{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Extended_stack is empty, true is returned.
      Otherwise false is returned.
*/

{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}


Stack::Stack()
/*
Pre:  None.
Post: The Extended_stack is initialized to be empty.
*/
{
    count = 0;
}

/*
void Extended_stack::print_contents()
{
    cout << "Tee tama !!!!" << endl;
}*/

void Stack::clear() // Reset the stack to be empty.
{
    count = 0;
}

bool Stack::full() const  // If the stack is full, return true; else return false.
{
    return count == maxstack;
}

int Stack::size() const // Return the number of entries in the stack.
{
    return count;
}

