#include "../inc/vm.h"

/* private methods */
// advance the ip
bool context_advance(context* ctx) {
    if (ctx->halted) return false;

    if (ctx->iindex == ctx->program->size-1) return false;
    
    ctx->iindex++;
    return true;

}

// print the top of the stack
int print(context* ctx) {
    if (ctx->stack->size <= 0) {
        return false;
    }

    printf("value = %d\n", ctx->stack->data[0]);
    return true;
}

// get a number from the stack
int pop(context* ctx) {
    if (ctx->stack->size == 0) return -1;

    int val = vector_pop_back(ctx->stack);
    return val;
}

// add the top two numbers on the stack
int add(context* ctx) {
    int a = pop(ctx);
    int b = pop(ctx);
    
    return vector_add(ctx->stack, a+b);
}

// put a number on the stack
int push(context* ctx) {
    if(context_advance(ctx)) {
        int val = ctx->program->data[ctx->iindex];
        vector_add(ctx->stack, val);
        return true;
    } else {
        return false;
    }
}

// set a register to a value
int set(context* ctx) {
    // unimplemented w/ a stack based VM
    return 0;
}

// unhalt the context
void unhalt(context* ctx) {
    ctx->halted = false;
    ctx->iindex = 0;
}

// set the context to halted
int halt(context* ctx) {
    if (ctx->halted) {
        unhalt(ctx);
        return false;
    } else {
        ctx->halted = true;
        return true;
    }
}

char* cmd_to_str(int cmd) {
    switch(cmd) {
        case 0:
            return "PSH";
        case 1:
            return "POP";
        case 2:
            return "ADD";
        case 3:
            return "SET";
        case 4:
            return "PRT";
        case 5:
            return "HLT";
        default:
            return "Not implemented";
    }
}


/* public methods */

context* vm_create_context(vector* program) {
    context* ctx = malloc(sizeof(*ctx));
    ctx->program = program;
    ctx->iindex = 0;
    ctx->halted = false;
    ctx->stack = vector_new(MAX_STACK);
    return ctx;
}

void vm_free_context(context* ctx) {
    vector_free(ctx->stack);
    free(ctx);
}

void vm_exec_context(context* ctx) {
    int (*instructions[])(context*)= {
        push,
        pop,
        add,
        set,
        print,
        halt
    };

    do {
        printf("Instruction: %s\n", cmd_to_str(ctx->program->data[ctx->iindex]));
        bool result = instructions[ctx->program->data[ctx->iindex]](ctx);
        if (result <= 0) {
            printf("instruction failed: %s w/ code:%d\n", cmd_to_str(ctx->iindex), result);
        }
    }
    while (context_advance(ctx));
}