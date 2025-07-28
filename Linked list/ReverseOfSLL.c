#include<stdio.h>
#include<stdlib.h>

struct SLL{
    int data;
    struct SLL *next;
};

struct SLL *first,*last = NULL;

void InsertionFromBeg(int value){
    struct SLL *NewNode;
    NewNode = (struct SLL*) malloc(sizeof(struct SLL));
    NewNode->data=value;
    NewNode->next=NULL;

    if ( first == NULL) //list is empty
       first=last=NewNode;
    else{
        NewNode->next=first;
        first=NewNode;
    }
    printf("%d is inserted at beginning\n",first->data);
}

void InsertionFromEnd(int value){
    struct SLL *NewNode;
    NewNode = (struct SLL*) malloc(sizeof(struct SLL));
    NewNode->data=value;
    NewNode->next=NULL;

    if ( first == NULL) //list is empty
       first=last=NewNode;
    else{
        last->next=NewNode;
        last=NewNode;
    }
    printf("\n%d is inserted at the end\n",last->data);
}

void InsertionFromPOS(int value,int pos){
    struct SLL *NewNode;
    NewNode = (struct SLL*) malloc(sizeof(struct SLL));
    NewNode->data=value;
    NewNode->next=NULL;

    if ( first == NULL) //list is empty
       printf("List is empty!!\n");

    struct SLL *temp;
    temp=first;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
        
    if(temp == NULL){
        printf("Position out of range!!\n");
        free(NewNode);
        return;
    }
        
    NewNode->next=temp->next;
    temp->next=NewNode;
    if(NewNode->next==NULL)
        last= NewNode;
    printf("%d is inserted at %dth position\n",value,pos);
}

void ReverseList(){
    struct SLL *prev=NULL, *current = first, *next = NULL;

    while( current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

void Traverse(){
    struct SLL *temp;
    temp = first;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    InsertionFromBeg(4);
    InsertionFromEnd(10);
    InsertionFromBeg(7);
    InsertionFromBeg(22);
    Traverse();
    ReverseList();
    Traverse();
    return 0;
}