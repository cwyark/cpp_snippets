#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a = 0;
  printf("size of a = %lu\n", sizeof(a)); // size of a is 4 bytes (32bits)
  char *s = "12345";
  printf("size of s = %lu\n",
         sizeof(s)); // size of s is 8 bytes (which is equal to sizeof(char*))
  printf("size of char = %lu\n",
         sizeof(char)); // size of char is 1 byte (8bits);
  printf("size of char * = %lu\n",
         sizeof(char *)); // size of char * is 8 bytes, where points to a memory
                          // address (I'm a 64bits CPU);
  printf("size of int = %lu\n", sizeof(int));
  printf("size of int * = %lu\n", sizeof(int *));
  printf("size of void = %lu\n", sizeof(void));
  printf("size of void * = %lu\n", sizeof(void *));
  printf("size of size_t = %lu\n", sizeof(size_t));
  printf("strlen of s is %lu\n", strlen(s));
  char buffer[10];
  for (int i = 0; i < 10; i++) {
    buffer[i] = 30 + i;
  }
  printf("size of buffer = %lu\n", sizeof(buffer));
  printf("strlen of buffer = %lu\n", strlen(buffer));
  char buf_str[] = "12345";
  printf("size of buf_str = %lu\n", sizeof(buf_str));
  printf("strlen of buf_str = %lu\n", strlen(buf_str));
  exit(EXIT_SUCCESS);
}
