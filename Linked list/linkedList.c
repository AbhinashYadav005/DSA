// to perform various operations on a singly linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SLL{
    int data;
    struct SLL *next;
};

struct SLL *first=NULL,*last=NULL;

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

void DeletionFromBeg(){

    struct SLL *temp;
    if(first == NULL)
       printf("List is empty.\n");

    else if(first->next == NULL){  //list has single element
       temp=first;
       first=last=NULL;
       free(temp);
    }
    else{
        temp=first;
        first=first->next;
        free(temp);;
    }
    printf("\n%d is deleted from begining",temp->data);
}

 void DeletionFromEnd(){

    struct SLL *temp;
    if(first == NULL)
       printf("List is empty.\n");

    else if(first->next == NULL){  //list has single element
       temp=first;
       first=last=NULL;
       free(temp);
    }
    else{
        temp=first;
        while(temp->next != last){
           temp=temp->next;
        }
        last=temp;
        temp= last->next;
        free(temp);
        last->next=NULL;
    }
    printf("%d is deleted from begining",temp->data);

 }

void DeletionFromPOS(int pos){

    struct SLL *temp,*tempp;
    if(first == NULL)
       printf("List is empty.\n");

    else if(pos == 1){  //list has single element
       DeletionFromBeg();
    }
    else{
        temp=first;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        if(temp->next == last){  //Deletion from end
            DeletionFromEnd();
        }
        else{
            tempp=temp->next;
            temp->next=tempp->next;
            free(tempp);
        }
    }
    printf("\n%dth position is deleted.",pos);

}

void Search(int key){
    
    struct SLL *temp;
    int flag=0;
    temp=first;
    if(first == NULL)
       printf("List is empty.\n");

    else{
        while(temp != NULL){
            if(temp->data == key){
                flag = 1;
            }
            temp=temp->next;
        }
        
    }
    if(flag == 1){
            printf("\n%d is found.\n",key);
    }
    else{
        printf("\n%d is not found !!\n",key);
    }
}


void Traverse(){
    struct SLL *temp;
    temp=first;
    if(first == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("\n\nLinked List : \n");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
 }


int main(){
    
    int choice, data, pos, ins;
    while (1) {
        printf("\n\n\n***VARIOUS OPERATIONS IN SLL***\n\n");
        printf("1. Insertion into the Linked List\n");
        printf("2. Deletion of a Node\n");
        printf("3. Searching in Linked List\n");
        printf("4. Traverse the Linked List\n");
        printf("5. Exit the program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n**YOUR INSERTION CHOICE**\n\n");
                printf("  1. Insertion from beginning\n");
                printf("  2. Insertion from end\n");
                printf("  3. Insertion at specific position\n\n");
                printf("Enter your insertion choice: ");
                scanf("%d", &ins);
                printf("\nEnter the value to insert: ");
                scanf("%d", &data);
                switch (ins) {
                    case 1:
                        InsertionFromBeg(data);
                        break;
                    case 2:
                        InsertionFromEnd(data);
                        break;
                    case 3:
                        printf("\nEnter the position to insert at: ");
                        scanf("%d", &pos);
                        InsertionFromPOS(data, pos);
                        break;
                    default:
                        printf("\nInvalid insertion option!\n");
                }
                break;
            
            case 2:
                printf("\n**YOUR DELETION CHOICE**\n\n");
                printf("  1. Deletion from beginning\n");
                printf("  2. Deletion from end\n");
                printf("  3. Deletion at any position\n");
                printf("\nEnter your Deletion choice: ");
                scanf("%d", &ins);
                
                switch (ins) {
                    case 1:
                        DeletionFromBeg();
                        break;
                    case 2:
                        DeletionFromEnd();
                        break;
                    case 3:
                        printf("\nEnter the position to delete at: ");
                        scanf("%d", &pos);
                        DeletionFromPOS(pos);
                        break;
                    default:
                        printf("\nInvalid Deletion option!\n");
                }
                break;
                
            case 3:
               printf("\nEnter the value you want to search : ");
               scanf("%d",&data);
               Search(data);
               break;

            case 4:
                Traverse();
                break;

            case 5:
                printf("\nExiting...\n\n");
                exit(0);

            default:
                printf("Invalid input!\n");
        }
    }
    return 0;
}