#include <stdio.h>
#include <stdlib.h>

#include "../inc/utils/vector.h"
#include "../inc/vm.h"

int main(int argc, char* argv[]) {
  vector* vect = vector_new(5);
  const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
  };

    


  vector_free(vect);

  return EXIT_SUCCESS;
}