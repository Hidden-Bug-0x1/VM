#ifndef VM_H
#define VM_H

#include "./utils/vector.h"
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    PSH,
    POP,
    ADD,
    SET,// not implemented yet (:
    PRT, // print the top of the stack
    HLT
} Instructions;

#define MAX_STACK 256 // 256 int max storage
typedef struct {
    vector* stack;  //memory stack
    vector* program;//instruction stack
    int iindex;        //instruction index
    bool halted;    //information on how to "restart" the context 
} context;

context* vm_create_context(vector* program);  // create a context
void vm_free_context(context* ctx);         // delete the context
void vm_exec_context(context* ctx);         // execute the context

#endif