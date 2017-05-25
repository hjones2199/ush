The C++ source file contained in this folder is for the ush command line shell for Unix.
Ush is a lightweight command line shell utility for unix, the entire
program is contained in a single source file. It acts as a minimalistic alternative
to shells like bash, zsh, sh and so on.

Program depends on the libedit's **readline()** functionality. This is its only external dependency at this
point in time.

To compile and run this code on a Unix system will require that a c++11 compliant compiler is present on the system.
On newer linux installs simply typing **"g++ ush.cpp -o ush -ledit"** will be sufficient to compile the code. On older systems
that still are compliant with C++11, there are two possible ways to compile the code, which one works will depend on just
how dated the server/pc is. The first is **"g++ -std=c++11 ush.cpp -o ush -ledit"**, the second is **"g++ -std=c++0x ush.cpp -o ush -ledit"**.

Running the shell is as simple as **"./ush"** (or whatever else you decide to name the executable upon compiling). You will
be greeted by the ush command line immediately. Usage of the shell is relatively straightforward for anyone whose used bash.
you type the command followed by the arguments, then hit enter. The program will automatically resolve the path to your binary folders
using the PATH environmental variable. To close ush, type "exit".
