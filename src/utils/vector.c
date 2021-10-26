#include "../../inc/utils/vector.h"

#include <stdint.h>

/* private methods */
uint most_sig_bit(size_t num) {
  uint place = 0;
  for(int i = 0; i < sizeof(num); i++) {
    if ( (num & (1 << i)) > 0) place = i;
  }
  return place;
}

/* public methods */
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

int vector_pop_back(vector *vect) {
    if (vect->size == 0) return -1;
    
    int val = vect->data[vect->size-1];
    vect->size--;
    return val;
}

int vector_add(vector* vect, int val) {
  if (vect->size + 1 <= vect->max_size)
  {
    vect->data[vect->size++] = val;
    return 1;
  } else {
    if (vector_resize(vect, vect->max_size << 1)) {
      return vector_add(vect, val);
    } else {
      return 0;
    }
  }
  return 0;
}

bool vector_resize(vector* vect, size_t size) {
  int* temp = realloc(vect->data, size);

    if (temp != NULL) {
        vect->data = temp;
        vect->size = size;
        return true;
    }

  return false;
}

bool vector_shrink(vector* vect) {
  return vector_resize(vect, vect->size);
}

void vector_print(vector* vect) {
    printf("<VECTOR>[");
  for(int i = 0; i < vect->size; i++) {
    printf("%d", vect->data[i]);
    if (i < vect->size - 1)
        printf(", ");
  }
  printf("]\n");
}
