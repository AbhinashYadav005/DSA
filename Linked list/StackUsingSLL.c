#include<stdio.h>
#include<stdlib.h>

struct DynamicStack{
    int data;
    struct DynamicStack *next;
};
struct DynamicStack *top = NULL;

void PUSH(int element){
    struct DynamicStack *NewNode;
    NewNode = (struct DynamicStack*) malloc(sizeof(struct DynamicStack));
    if(NewNode == NULL){
        printf("Memory Allocation Failed!!\n");
        return;
    }
    else{
        NewNode->data = element;
        NewNode->next = NULL;
        if(top == NULL)
            top = NewNode;
        else{
            NewNode->next = top;
            top = NewNode;
        }
    }
    printf("%d is pushed into the stack\n",NewNode->data);
}

void POP(){
    struct DynamicStack *temp;

    if(top == NULL){
        printf("Stack underflows!!\n");
        return;
    }
    else if(top->next == NULL){ //stack has single element
        temp = top;
        top = NULL;
        free(temp);
    }
    else{
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("Popped from the stack!\n");
}
void Display(){
    struct DynamicStack *temp;
    temp = top;
    while (temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice,value;
    while(1){
       printf("1. PUSH INTO THE STACK\n2. POP FROM THE STACK\n3. SHOW STACK ELEMENTS\n4. EXIT THE PROGRAM\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice){
        case 1:
            printf("Enter the value you want to push: ");
            scanf("%d",&value);
            PUSH(value);
            break;
        case 2:
            POP();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Exiting...");
            exit(0);

        default:
            printf("Invalid input!!\n");
       }
    }
    return 0;
}