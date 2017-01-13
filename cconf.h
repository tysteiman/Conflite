#ifndef CCONF_LIB
#define CCONF_LIB

#include <stdio.h>

/* We need to be able to change which file is getting parsed. */
extern FILE * yyin;

#define TRUE 1
#define FALSE 0
#define CCONF_FILE_LOOKUP_TABLE 2

/**
 * Main structure for our lookup table. A simple linked list
 * that allows us to enter as many records as we need.
 */
typedef struct Hash {
  char        * key;
  char        * value;
  struct Hash * next;
} hash_t;

typedef struct CConf {
  char   * file;
  hash_t * table;
} cconf_t;

/* Initialize lookup table so we can access it throughout. */
hash_t  * table;
cconf_t   cconf;

/* BEGIN DECLS */
void     cconf_init();
void     cconf_create(char *key, char *value);
void     cconf_print_table();
void     cconf_free(hash_t *table);
hash_t * cconf_find(char *key);
int      cconf_streql(char *str1, char *str2);
int      cconf_assert(char *str);
int      cconf_int(char *key);
int      cconf_match(char *pattern, char *subj);
char   * cconf_value(char *key);
char   * cconf_file();

#endif
