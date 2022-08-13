#include <stdio.h> 
#include <stdlib.h> 

typedef struct stack {
    int size;
    int capacity; 
    int sz; 
    int* head; 
    int* begin; 
} stack;  

void initialize_stack(stack* s) {
    s -> capacity = (1 << 3); 
    s -> head = (int*)malloc((s -> capacity)*((int)sizeof(int))); 
    s -> size = 0; 
    s -> begin = s -> head; 
} 

void push(stack* s, int n) {
    if (s -> size + 1 == s -> capacity) {
        s -> capacity <<= 1; 
        s -> begin = realloc(s -> begin, (s -> capacity)*(int)(sizeof(int))); 
        s -> head = s -> begin + s -> size; 
    } 
    s -> head++; 
    s -> size++; 
    *(s -> head) = n; 
} 

void print(stack* s) {
    int* it = s -> head; 
    it -= s -> size - 1; 
    for (int i = 0; i < s -> size; i++) {
        printf("%d ", it[i]); 
    } 
    printf("\n"); 
} 

int pop(stack* s) {
    int n = *(s -> head); 
    if (s -> size < 0) {
        // how to throw error 
        printf("error, tried popping empty stack \n"); 
        return -1; 
    } 
    else {
        s -> head--; 
        s -> size--; 
        if (s -> size <= (s -> capacity >> 2)) {
            s -> capacity >>= 1; 
            s -> begin = realloc(s -> begin, (s -> capacity)*(int)sizeof(int)); 
            s -> head = s -> begin + s -> size; 
        } 
        return n; 
    } 
} 

int main() {
    stack s; 
    initialize_stack(&s); 
    push(&s, 1); push(&s, 2); push(&s, 3); push(&s, 4); push(&s, 5); 
    printf("Stack before pops: "); 
    print(&s); 
    pop(&s); pop(&s);  
    printf("Stack after pops: "); 
    print(&s); 

    return 0; 
} 
