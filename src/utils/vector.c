#include "../../inc/utils/vector.h"

#include <stdint.h>

uint most_sig_bit(size_t num) {
  uint place = 0;
  for(int i = 0; i < sizeof(num); i++) {
    if ( (num & (1 << i)) > 0) place = i;
  }
  return place;
}

vector* vector_new(size_t size) {
  vector* vect = malloc(sizeof(*vect));
  vect->data = malloc(size*sizeof(int));
  vect->size = 0;
  vect->max_size = 1 << (most_sig_bit(size)+1);
  return vect;
}    

void vector_free(vector* vect) {
  free(vect->data);
  free(vect);
}

int vector_pop(vector* vect) {
  if (vect->size == 0) return -1;

  int val = vect->data[0];
  free(&vect->data[0]);
  vect->data = vect->data + 1;
  vect->size--;
  return val;
}

int vector_add(vector* vect, int val) {
  if (vect->size + 1 <= vect->max_size)
  {
    printf("%zu\n", vect->size);
    vect->data[vect->size++] = val;
    return 1;
  } else {
    if (vector_resize(vect, vect->max_size << 1)) {
      vector_add(vect, val);
    } else {
      return 0;
    }
  }
  return 0;
}

bool vector_resize(vector* vect, size_t size) {
  printf("new size: %zu\n", size);
  int* new;
  if ((new = malloc(size*sizeof(int))) == NULL) {
    return false;
  } else {
    memcpy(new, vect->data, vect->size*sizeof(int));
    vect->data = new;
    vect->max_size = size;
    return true;
  }
  return false;
}

bool vector_shrink(vector* vect) {
  return vector_resize(vect, vect->size);
}

void vector_print(vector* vect) {
  for(int i = 0; i < vect->size; i++) {
    printf("%d ", vect->data[i]);
  }
  printf("\n");
}
