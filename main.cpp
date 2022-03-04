#include<iostream>

//#include<string.h>

#include"stack.h"
#include"Utility.h"
#include"PostFixFunctions.h"


int main(int argc,char* argv[])
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Stack stored_numbers;
    bool promptActive = false;
    
    if (argc > 1) {

        for (int i = 1; i < argc; i++) {
            char* prompt = argv[i];
            for (int j = 1; j < strlen(prompt); j++) {
                if (prompt[0] == '-' && prompt[j] == 'p') {
                    promptActive = true;
                }
            }
        }
    }
    if (promptActive) {
        introduction();
        instructions();
        while (do_command(get_command(), stored_numbers));

    }
    else {
        commandless(stored_numbers);
    }
    
    return 0;
}
