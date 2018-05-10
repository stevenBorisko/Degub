#ifndef DEGUB_H
#define DEGUB_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

//----------------------------------------------------------------------------//
// --- Macro Definitions ---
//----------------------------------------------------------------------------//

#define DEGUB_ERROR_ON 1
#define DEGUB_WARN_ON 1
#define DEGUB_INFO_ON 1

//----------------------------------------------------------------------------//
// --- Main Function Declarations ---
//----------------------------------------------------------------------------//

/*
--- error ---

msg (char*)
	- Custom message to be printed out.
code (int)
	- This should be the errno set from the erroneous function call.
	- This function will print the string associated with the errno.

Print an error message to stderr
*/
void error(char* msg, int code);

/*
--- warn --- 

msg (char*)
	- Custom message to be printed out.
code (int)
	- Custom status code to be printed out along with the message.

Print an warning message to stderr
*/
void warn(char* msg, int code);

/*
--- info --- 

msg (char*)
	- Custom message to be printed out.
code (int)
	- Custom status code to be printed out along with the message.

Print an information message to stderr
*/
void info(char* msg, int code);

#endif
