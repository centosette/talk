/************************************************************

jparser.h 

parser for json format files

 - Content is always sorroundend by curly braces {}
 - inside the braces there can be one or more objects:
   - other sub-objects {}
   - name : value pairs where:
- name can be a string: even if it is an integer, it will be read as a string.
- value can be:
 - a single value (string or numeric)
 - an array in the form [a, b, ..., n] or (a, b, ..., n)
 - a sub-object {}
 ************************************************************/
#include <malloc.h>
#include <stdio.h>

#ifndef JPARSER
#define JPARSER
#endif

#ifndef ERRORS
#include "errors.h"
#endif

#define LOCAL static

typedef struct
{
  json_t *father;
  json_t ** children;
  pair_t **;
  
} json_t;

typedef struct
{
  char *name;
  void *value;
} pair_t;

int read_file(const char *filename, json_t *result);

void *get_value(char *path_to_name);

char **get_path(char *name);

