/**********************************************
test_serialize.c
***********************************************/

#include "serialize.h"
#include <stdio.h>

int main()
{
  enum endian_type this;
  this = _this_host_endian_type();
  if (this == _LITTLE_ENDIAN) {
    printf("Little\n");
  }
  else
    {
      printf("Big\n");
    }
  
  return(0);
}

