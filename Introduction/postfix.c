#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for operands
float exp_list[MAX];
int top = -1;

// Push value onto stack
void push(float value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    exp_list[++top] = value;
}

// Pop value from stack
float pop() {
    if (top < 0) {
        printf("Stack Underflow (Insufficient operands)\n");
        exit(1);
    }
    return exp_list[top--];
}

// Function to evaluate postfix expression
float Postfix_Evaluator(char *expression) {
    char *character = strtok(expression, " ");
    
    printf("Tokens: ");
    while (character != NULL) {
        printf("%s ", character);

        if (strcmp(character, "+") == 0 || strcmp(character, "-") == 0 ||
            strcmp(character, "*") == 0 || strcmp(character, "/") == 0) {
            
            float operand2 = pop();
            float operand1 = pop();
            float result;

            if (strcmp(character, "+") == 0)
                result = operand1 + operand2;
            else if (strcmp(character, "-") == 0)
                result = operand1 - operand2;
            else if (strcmp(character, "*") == 0)
                result = operand1 * operand2;
            else if (strcmp(character, "/") == 0) {
                if (operand2 == 0) {
                    printf("\nError: Division by zero\n");
                    exit(1);
                }
                result = operand1 / operand2;
            }

            push(result);
        } else {
            // Convert token to float and push
            push(atof(character));
        }

        character = strtok(NULL, " ");
    }

    if (top != 0) {
        printf("\nError: Invalid postfix expression\n");
        exit(1);
    }

    printf("\n");
    return pop();
}

// Main function
void postfix() {
    char Inp_expression[MAX];

    printf("Enter the postfix expression: ");
    fgets(Inp_expression, MAX, stdin);

    // Remove newline at end if present
    size_t len = strlen(Inp_expression);
    if (Inp_expression[len - 1] == '\n') {
        Inp_expression[len - 1] = '\0';
    }

    float Result = Postfix_Evaluator(Inp_expression);
    printf("The result of the expression is: %.2f\n", Result);
}

int main() {
    postfix();
    return 0;
}
