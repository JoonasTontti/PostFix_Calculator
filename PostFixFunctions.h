#include<iostream>
#include"stack.h"
#include"Utility.h"

#include<sstream>
#include<string>
#include<string.h>
#include<math.h>

using std::string;;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::flush;

void introduction();
void instructions();

char get_command() ;
bool do_command(char command, Stack& numbers);
void sumAll(Stack& numbers);

void commandless(Stack& numbers);
bool check_number(string& input);


