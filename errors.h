#include "talkconfig.h"

/***********************************************************

errors.h - macro definitions for error handling

ERROR_ macros exit the program
EXCEPTION_ macros provide a return statement
WARN_ macros simply printout a warning message

************************************************************/

//need talkconfig to retrieve the transcoding of the error codes

#ifndef ERRORS
#define ERRORS


#define ERROR_EQUALS(variable, value, exit_code, error_msg)	\
  if((variable)==(value)){				\
    printf("Error occurred, exit code: %d\n", (exit_code));\
    printf(error_msg); printf("\n");		 \
    exit((exit_code));}

#define ERROR_NOT_EQUALS(variable, value, exit_code, error_msg) \
if((variable)!=(value)){				\
    printf("Error occurred, exit code: %d\n", (exit_code));\
    printf(error_msg); printf("\n");		 \
    exit((exit_code));}

#define EXCEPTION_EQUALS(variable, value, error_code, error_msg) \
  if((variable)==(value)){				\
    printf("Exception occurred, error code: %d\n", (error_code));\
    printf(error_msg); printf("\n");		 \
    return((error_code));}

#define EXCEPTION_NOT_EQUALS(variable, value, exit_code, error_msg)\
  if((variable)!=(value)){				\
    printf("Exception occurred, error code: %d\n", (error_code));\
    printf(error_msg); printf("\n");		 \
    return((error_code));}

#define WARN_EQUALS(variable, value, exit_code, error_msg)

#define WARN_NOT_EQUALS(variable, value, exit_code, error_msg)

#define DEBUG(variable, value, exit_code, error_msg)

#define MALLOC_ERROR(variable) ERROR_EQUALS(variable, NULL, 1, "Memory allocation failed.\n")


#endif //ERRORS
