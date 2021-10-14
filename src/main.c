#include <stdio.h>
#include <stdlib.h>

#include "../inc/utils/vector.h"

int main(int argc, char* argv[]) {
  vector* vect = vector_new(5);
  
  for (int i = 0; i < 16; i++) {
    printf("Adding %d\n", i+1);
    vector_add(vect, i+1);
  }

  vector_print(vect);

  vector_free(vect);

  return EXIT_SUCCESS;
}