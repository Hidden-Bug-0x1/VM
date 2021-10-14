#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <memory.h>

typedef struct {
  int* data;
  size_t size;
  size_t max_size;
} vector;

vector* vector_new(size_t size);                // create the vector
void vector_free(vector* vect);                 // delete the vector
int vector_pop(vector* vect);                   // get the first value
int vector_add(vector* vect, int val);          // push a value to the back of the vector
bool vector_resize(vector* vect, size_t size);  // resize the vector
bool vector_shrink(vector* vect);               // shrink the max_size to fit the size
void vector_print(vector* vect);

#endif