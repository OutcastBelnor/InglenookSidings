			 =================================
			||				 ||
			|| Inglenook Sidings README file ||
			||				 ||
			 =================================
  
  1. Project contents...........................................................
  2. Building the program.......................................................
  3. Input files................................................................
  
================================================================================

  1. Project contents
  	
  	This project contains actually two projects which run separately. The
  server is written in C and the client is in C++.
  	
  	
  	The server project contains three files. The first one is main which is 
  responsible for initializing the initial state of the sidings based on 
  provided information and then is responsible for managing the sidings:
  	- maintaining the number of wagons on each siding
  	- moving wagons
  	- changings switches
  	- sending status after each action
  	
  	Other files are commands.c which contains the command function
responsible for carrying out certain commands. The last one is the header file
that contains declarations of global variables and command functions.


	The client is more complex. The main.cpp file contains main method in
which everything is carried out. It can read files, create sidings and wagons
objects and move them from siding to siding. The other files are the classes:
vehicle (which is not to be edited), wagon (inherits from vehicle), siding.

================================================================================

  2. Building the program
  
  	For the c side you need following libraries:
  	- <stdio.h>
	- <stdlib.h>
	- <strings.h>
	For standard operations and:
	- <errno.h>
	- <sys/types.h>
	- <sys/socket.h>
	- <netinet/in.h>
	- <netdb.h>
	- <unistd.h>
	For TCP connection. You also need to compile it in C99 standard.
	
	C++ client needs the following:
	- <cstdlib>
	- <iostream>
	- <vector>
	- <fstream>
	- <sstream>
	- <exception>
	Libraries cstdlib and iostream are standard (iostream for taking the 
input and displaying it on the screen). Vector for vector arrays, fstream for
reading the files, sstream for printing the objects and exception for handling
exceptions.
	You also need following Boost libraries for TCP connection reading data
from the server and splitting strings:
	- <boost/array.hpp>
	- <boost/asio.hpp>
	- <boost/tokenizer.hpp>
	- <boost/algorithm/string.hpp>
	
================================================================================

  3. Input files
  
	a) Wagon data
	Has to be in the following format:

<wagon number>, <owner>, <cargo>

	b) Sidings info
	In the format:
	
<max capacity>		<current number of wagons> 
<max capacity>		<current number of wagons> <wagon> <wagon> <wagon>

	There are files included in this project in SLP folder for further
reference.
