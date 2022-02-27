#include<iostream>
#include"stack.h"
#include"Utility.h"


using namespace std;

char get_command();
bool do_command(char command, Stack& numbers);

void introduction() {
    cout << "This is a postfix calculator."<< endl;
}
void instructions() {

}

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Stack stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));
    return 0;
}


char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting) {
        cin >> command;
        cin.clear();
        cin.ignore(1000,'\n');
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' ||command =='x') waiting = false;


        else {
            cout << "Please enter a valid command:" << endl
                << "[?]push to stack   [=]print top" << endl
                << "[+] [-] [*] [/]   are arithmetic operations" << endl
                << "[Q]uit." << endl;
        }
    }
    return command;
}


bool do_command(char command, Stack& numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double p, q, t;
    switch (command) {
    case '?':
        cout << "Enter a real number: " << flush;
        cin >> p;
        cin.clear();
        cin.ignore(1000, '\n');

        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;

    case '+':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q+p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '/':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q/p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '*':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q*p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
    case '-':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q-p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case 'x':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(p) == overflow || numbers.push(q) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }

        break;
    case 'q':
        cout << "Calculation finished.\n";
        return false;
    }
    return true;
}