#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DLL{
    int data;
    struct DLL *prev, *next;
};

struct DLL *first,*last = NULL;

void Insertion_at_begining(int element){
    struct DLL *NewNode;
    NewNode = (struct DLL*) malloc(sizeof(struct DLL));
    NewNode->next = NULL;
    NewNode->data = element;
    NewNode->prev = NULL;
    if(first == NULL)
       first = last = NewNode;
    else{
        NewNode->next = first;
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d was inserted at the front\n",first->data);
}

void Insertion_at_end(int element){
    struct DLL *NewNode;
    NewNode = (struct DLL*) malloc(sizeof(struct DLL));
    NewNode->next = NULL;
    NewNode->data = element;
    NewNode->prev = NULL;
    if(first == NULL)
       first = last = NewNode;
    else{
        NewNode->prev = last;
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d was inserted at the end\n",last->data);
}

void Insertion_at_position(int value,int pos){
    struct DLL *NewNode;
    NewNode = (struct DLL*) malloc(sizeof(struct DLL));
    NewNode->data=value;
    NewNode->next=NULL;

    if ( first == NULL) // list is empty
       printf("List is empty!!\n");

    struct DLL *temp;
    temp = first;

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    if(temp == NULL){
        printf("Position out of range!");
        return;
    }
    else if(temp->prev == NULL || pos == 1)
        Insertion_at_begining(value);

    else if(temp->next == NULL){ //Insertion at end
        Insertion_at_end(value);
    }
    else{
        NewNode->next = temp->next;
        NewNode->prev = temp;
        temp->next=NewNode;
    }
    printf("%d is inserted at %dth position\n",value,pos);
}

void Reverse(){
    struct DLL *temp,*current;
    current = first;
    temp = NULL;
    while ( current != NULL )
    { 
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != NULL)
       first = temp->prev;

    printf("List is reversed successfully.\n");
}

void Display(){
    struct DLL *temp;
    temp = first;
    while(temp != NULL){
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Insertion_at_begining(20);
    Display();
    Insertion_at_begining(10);
    Display();
    Insertion_at_begining(30);
    Display();
    Reverse();
    Display();
    
    return 0;
}