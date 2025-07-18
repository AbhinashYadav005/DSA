#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};
struct Queue *FRONT,*REAR = NULL;

void Enqueue(int element){
    struct Queue *NewNode;
    NewNode = (struct Queue*) malloc(sizeof(struct Queue));
    if(NewNode == NULL){
       printf("Memory Allocation Failed!!\n");
       return;
    }
    else{
        NewNode->data = element;
        NewNode->next = NULL;
        if(FRONT == NULL){
            FRONT = REAR = NewNode;
        }
        else{
            REAR->next = NewNode;
            REAR = NewNode;
        }
    }
    printf("%d is enqueued into the queue\n",NewNode->data);
}

void Dequeue(){
    struct Queue *temp;
    if(FRONT == NULL){
       printf("Empty Queue!\n");
       return;
    }
    else if(FRONT->next == NULL){
        temp = FRONT;
        FRONT = REAR = NULL;
        free(temp);
    }
    else{
        temp = FRONT;
        FRONT = FRONT->next;
        free(temp);
    }
    printf("Dequeued from queue.\n");
}

void Show(){
    struct Queue *temp;
    temp = FRONT;
    while (temp != NULL)
    {
        printf("%d - ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); 
}

int main(){
    int choice,value;
    while(1){
       printf("1. Enqueue in queue\n2. Dequeue in queue\n3. Show the queue\n4. Exit the program\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice){
        case 1:
            printf("Enter the value you want to enqueue: ");
            scanf("%d",&value);
            Enqueue(value);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Show();
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