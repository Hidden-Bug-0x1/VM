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
    PRT,
    POP,
    HLT
  };
    for (int i = 0; i < 7; i++) {
        vector_add(vect, program[i]);
    }
    context* vm = vm_create_context(vect);
    vm_exec_context(vm);

  vector_free(vect);
  vm_free_context(vm);

  return EXIT_SUCCESS;
}