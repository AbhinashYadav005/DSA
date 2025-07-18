#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int value[MAX];
    int TOS;
}Stack;

// Initialize stack
void Initialize(Stack *s){
    s->TOS = -1;  // Set top of stack to -1 indicating empty stack
}

// Push value onto stack
void Push(Stack *s, int value){
    if (s->TOS == MAX -1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    else{
        s->TOS++;
        s->value[s->TOS]=value; // Increment top of stack and assign value
    }
}

// Pop value from stack
int Pop(Stack *s){
    if(s->TOS == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    else{
        int value = s->value[s->TOS]; // fetch value from top of stack
        s->TOS--; // Decrement top of stack
        return value; // Return popped value
    }
}

// peek value at top of stack
int Peek(Stack *s){
    if(s->TOS == -1){
        printf("Stack is empty\n");
        exit(1);
    }
    else{
        return s->value[s->TOS]; // Return value at top of stack
    }
}

// Check if stack is full
int IsFull(Stack *s){
    return s->TOS == MAX -1; // Return 1 if stack is full, otherwise 0
}

// Check if stack is empty
int IsEmpty(Stack *s){
    return s->TOS == -1; // Return 1 if stack is empty, otherwise 0
}

int main(){
    Stack s;
    Initialize(&s); // Initialize stack
    Push(&s, 5); // Push value 5 onto stack
    Push(&s, 10); // Push value 10 onto stack
    Push(&s, 15); // Push value 15 onto stack

    printf("Top of stack: %d\n", Peek(&s)); // Peek at top value of stack
    printf("Popped value: %d\n", Pop(&s)); // Pop value from stack
    printf("Top of stack after pop: %d\n", Peek(&s)); // Peek at top value after pop
    printf("Is stack empty? %s\n", IsEmpty(&s) ? "Yes" : "No"); // Check if stack is empty
    printf("Is stack full? %s\n", IsFull(&s) ? "Yes" : "No"); // Check if stack is full

    
    return 0; // Exit program
}
