#include "PostFixFunctions.h"



void sumAll(Stack& numbers) {
    double a, b;
    if (numbers.top(a) == underflow)
        cout << "Stack empty" << endl;
    else {
        numbers.pop();
        if (numbers.top(b) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(a);
        }

        else {
            while (!numbers.empty()) {
                numbers.top(b);
                a = a + b;
                numbers.pop();
            }
            if (numbers.push(a) == overflow)
                cout << "Warning: Stack full, lost result" << endl;
        }
    }
}

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>: ";

    while (waiting) {
        cin >> command;
        cin.clear();
        cin.ignore(1000, '\n');
        command = tolower(command);
        if (command == 'p')
            command = '=';
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'a' || command == 'v' || command == '^' ||
            command == '_' || command == '%' || command == 'c')
            waiting = false;


        else {
            cout << "Please enter a valid command:" << endl;
            instructions();
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
    double p, q;
    switch (command) {
    case '?':
        cout << "Enter a real number: " << flush;
        cin >> p;
        cin.clear();

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
                if (numbers.push(q + p) == overflow)
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
                if (numbers.push(q / p) == overflow)
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
                if (numbers.push(q * p) == overflow)
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
                if (numbers.push(q - p) == overflow)
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
    case 's':
        sumAll(numbers);
        break;
    case 'a':
        int size;
        size = numbers.size();
        sumAll(numbers);
        if (size > 1) {
            numbers.top(p);
            if (numbers.push(p / size) == overflow) {
                cout << "Warning: Stack full, lost result" << endl;

            }
        }
        break;
    case 'v':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            p = sqrt(p);

            if (numbers.push(p) == overflow)
                cout << "Warning: Stack full, lost result" << endl;
        }
        break;
    case '^':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                double temp;
                numbers.pop();
                temp = pow(q, p);
                if (numbers.push(temp) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
    case '%':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                double temp;
                numbers.pop();
                temp = fmod(q, p);
                if (numbers.push(temp) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
    case '_':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            q = -p;
            if (numbers.push(q) == overflow)
                cout << "Warning: Stack full, lost result" << endl;
        }
        break;
    case 'c':
        numbers.clear();
        break;
    case 'q':
        
       // cout << "Calculation finished.\n"; // removed from use for cleaner look in commandless
        
        cout << endl;
        return false;
    }
    return true;
}

bool check_number(string& input) {
    for (char const& c : input) {
        if (isdigit(c) == 0)return false;
    }
    return true;
}

void introduction() {
    cout << "This is a postfix calculator." << endl;
}

void instructions() {

    cout << "[?] push to stack   [p] and [=] print top" << endl
        << "[+] [-] [*] [/]   are arithmetic operations" << endl
        << "[x] changes places of 2 last numbers" << endl
        << "[s] sums all already given numbers together" << endl
        << "[%] remainder of second to top divided with top" << endl
        << "[v] takes square root from top" << endl
        << "[a] gives average of all numbers in stack" << endl
        << "[^] raises second from top to power of the top" << endl
        << "[_] turn top from negative to positive or positive to negative" << endl
        << "[c] clears all numbers from memory" << endl
        << "[Q]uit." << endl;
}


/*

//version 1 where top of stack is printed after each line after enter input
// and you need to clear numbers using c command
void commandless(Stack& numbers) {
    double number;
    bool runCalc = true;
    string input;
    string temp;

    while (runCalc) {
        char command;

        input.clear();
        temp.clear();

        cin.clear();
        getline(cin, input);
        stringstream ss(input);

        if (!input.empty()) {
            while (!ss.eof()) {

                ss >> temp;

                if (check_number(temp)) {
                    number = strtod(temp.c_str(), NULL);
                    numbers.push(number);
                }
                else {

                    for (int i = 0; i < temp.size(); i++) {
                        command = temp[i];
                        command = tolower(command);
                        if (command == 'p')
                            command = '=';

                        if (command == '?' || command == '=' || command == '+' ||
                            command == '-' || command == '*' || command == '/' ||
                            command == 'q' || command == 'x' || command == 's' ||
                            command == 'a' || command == 'v' || command == '^' ||
                            command == '_' || command == '%' || command == 'c') {

                            runCalc = do_command(command, numbers);

                        }

                    }

                }

            }
        }
        if(!numbers.empty() && command != 'q')
            do_command('=', numbers);
    }

}
*/


//version 2 where top of stack is printed after each line after enter input
// and you numbers are cleared before nnew line of commands are given
void commandless(Stack& numbers) {
    double number;
    bool runCalc = true;

    string input;
    string temp;

    while (runCalc) {

        input.clear();
        temp.clear();

        cin.clear();
        getline(cin, input);
        stringstream ss(input);

        numbers.clear();

        if (!input.empty()) {
            while (!ss.eof()) {

                ss >> temp;

                if (check_number(temp)) {
                    number = strtod(temp.c_str(), NULL);
                    numbers.push(number);
                }
                else {

                    for (int i = 0; i < temp.size(); i++) {
                        char command = temp[i];
                        command = tolower(command);
                        if (command == 'p')
                            command = '=';

                        if (command == '?' || command == '=' || command == '+' ||
                            command == '-' || command == '*' || command == '/' ||
                            command == 'q' || command == 'x' || command == 's' ||
                            command == 'a' || command == 'v' || command == '^' ||
                            command == '_' || command == '%' || command == 'c') {

                            runCalc = do_command(command, numbers);

                        }

                    }

                }

            }
        }
        if (!numbers.empty())
            do_command('=', numbers);
    }

}
