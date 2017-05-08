/************************************************************************************
 * Author: Hunter Jones
 * Date: 04/23/2017
 * File Name: ush.cpp
 * Purpose: ush is a lightweight command line shell utility for unix, the entire
 *  program is contained in this source file. It acts as a minimalistic alternative
 *  to shells like bash, zsh, sh and so on.
 * Notes: This C++ file uses features from the C++11 standard, attempting to compile
 *    against the C++98 libraries will certainly fail. On some older systems, the
 *    C++11 standard is referred to as c++0x.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

using namespace std;

string userPrompt = "ush-> "; //command line prompt, PS1 to use unix terms
void printPrompt();
void setPath(vector<string>& answer);
string findCommand();
bool fileExists(string filename);



int main(int argc, char** argv) {
  /**
   * Main function consists entirely of an infinite while loop. The loop consists of
   * three distinct subroutines (i could have refactored them into seperate functions
   * but decided that this was more readable). The first subroutine is to search the $PATH
   * for a program that matches the user specified command. The second is to combine this
   * generated path to the executable with the args specified by the user. Lastly, the shell
   * forks off a process which runs the program with the specified args.
   */
  while(1) { //Main loop begin
    //Initializer Area
    string current{}; //holds the string just recieved from user input
    char* userArgs[100] = {NULL}; //array contains the 'argv' of the program to be run
    printPrompt();
    
    //Search $PATH for a program matching users selection
    try{
      userArgs[0] = (char* const)findCommand().c_str();
    }
    catch(const char* msg) {
      cerr << msg << endl;
      continue; //so that the user is able to continue using the command line after a bad input.
    }

    //Fill the array of args from user input
    for(int i = 1;;i++) {
      if(cin.peek() == '\n') {
        cin.get();
        break;
      }
      cin >> current;
      userArgs[i] = new char[current.size()+1];
      current.copy(userArgs[i],current.size(),0);
      userArgs[i][current.size()] ='\0';
    } //end array fill loop
        
    //Forking off to run program
    pid_t parent = getpid();
    pid_t pid = fork();
    if(pid > 0) { //Parent runs this
      int statusnum;
      waitpid(pid, &statusnum, 0);
    }
    else { //child runs this
      execv(userArgs[0], userArgs); //execute the program
      exit(-1); //if child reached this something is really amiss.
    }
  } //end of main loop
  return 0;
}

void printPrompt() {
  /**
   * Simply prints the command line prompt to console, could have 
   * just used a variable, but left open for possible setPrompt
   */
  cout << userPrompt;
}

void setPath(vector<string>& answer) {
  /**
   * Converts PATH from a single string to a tokenized vector via ':' delimeter
   */
  string current{};
  stringstream x{getenv("PATH")}; //User binary path
  while(x) {
    getline(x,current,':');
    answer.push_back(string{current});
  }
}

string findCommand() {
  /**
   * Takes users command input, and finds the appropriate executable file to run.
   * Working directory (if program starts with ./), $PATH variable, and missing files
   * are all taken into account
   */
  string command{}; //Stores the command from user input (for example gcc)
  vector<string> path;
  cin >> command;
  if(command == "exit") //Exit command input by user
    exit(0);
  if((command.substr(0,2) == "./") && (fileExists(command))) //Command is selected from current dir
    return command;
  if(command == "cd") { //has to be implemented in shell, no external commands for it.
    cin >> command;
    if(chdir(command.c_str()))
      throw "Error: file not found";
    return string{"cd"};
  }
  setPath(path);
  for(string x : path) { //Iterate through the path looking for matching files
    if(fileExists(x + "/" + command))
       return x + "/" + command;
  }
  throw "Error: File not found"; //No matches found
}

bool fileExists(string filename) {
  /**
   * Checks if the specified file exists, and returns the result of said test
   * as a boolean. Pretty standard really.
   */
  if(fopen(filename.c_str(),"r") == 0)
    return false;
  else
    return true;
}
