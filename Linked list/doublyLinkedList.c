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

    if ( first == NULL) //list is empty
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

void Deletion_from_beginning(){

    struct DLL *temp;
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
        first->prev = NULL;
        free(temp);;
    }
    printf("%d is deleted from begining\n",temp->data);
}

void Deletion_from_end(){

    struct DLL *temp;
    if(first == NULL)
       printf("List is empty.\n");

    else if(first->next == NULL){  //list has single element
       temp=first;
       first=last=NULL;
       free(temp);
    }
    else{
        temp=last;
        last=last->prev;
        last->next = NULL;
        free(temp);;
    }
    printf("%d is deleted from end\n",temp->data);
}

void Deletion_from_position(int pos){

    struct DLL *temp,*tempp;

    if(first == NULL)
       printf("List is empty.\n");

    else if(pos == 1){  //list has single element
       Deletion_from_beginning();
    }

    else{
        temp=first;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }

        if(temp->next == last){  //Deletion from end
            Deletion_from_end();
        }

        else{
            tempp = temp->next;
            temp->next = tempp->next;
            (tempp->next)->prev = temp;
            free(tempp);
        }
    }
    printf("%dth position is deleted.\n",pos);

}

void Traverse(){
    struct DLL *temp;
    temp = first;
    if(first == NULL)
        printf("List is empty\n");
    else{
        while(temp != NULL){
            printf("%d <-> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void TraverseFromLast(){
    struct DLL *temp;
    temp = last;
    if(first == NULL)
        printf("List is empty\n");
    else{
        while(temp != NULL){
            printf("%d <-> ",temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }
}

void Search(int key){
    
    struct DLL *temp;
    int flag=0;
    temp=first;
    if(first == NULL)
       printf("List is empty.\n");

    else{
        while(temp != NULL){
            if(temp->data == key){
                flag = 1;
                printf("%d is found\n",key);
            }
            temp=temp->next;
        }
        
    }
    if(flag == 0)
        printf("%d is not found.\n",key);
}

// void SearchFromLast(int key){
    
//     struct DLL *temp;
//     int flag=0;
//     temp=last;
//     if(first == NULL)
//        printf("List is empty.\n");

//     else{
//         while(temp != NULL){
//             if(temp->data == key){
//                 flag = 1;
//                 printf("%d is found\n",key);
//             }
//             temp=temp->prev;
//         }
        
//     }
//     if(flag == 0)
//         printf("%d is not found.\n",key);
// }

int main(){
    int choice, data, pos, ins;
    while (1) {
        printf("\n\n\n***VARIOUS OPERATIONS IN DLL***\n\n");
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
                
                switch (ins) {
                    case 1:
                        printf("\nEnter the value to insert: ");
                        scanf("%d", &data);
                        Insertion_at_begining(data);
                        break;
                    case 2:
                        printf("\nEnter the value to insert: ");
                        scanf("%d", &data);
                        Insertion_at_end(data);
                        break;
                    case 3:
                        printf("\nEnter the position to insert at: ");
                        scanf("%d", &pos);
                        printf("\nEnter the value to insert: ");
                        scanf("%d", &data);
                        Insertion_at_position(data, pos);
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
                        Deletion_from_beginning();
                        break;
                    case 2:
                        Deletion_from_end();
                        break;
                    case 3:
                        printf("\nEnter the position to delete at: ");
                        scanf("%d", &pos);
                        Deletion_from_position(pos);
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
                printf("1. Traverse from beginning\n2. Traverse from end\nEnter Your choice: ");
                scanf("%d",&ins);
                switch(ins){
                    case 1: 
                        Traverse();
                        break;
                    case 2:
                        TraverseFromLast();
                        break;
                    default:
                        printf("Wrong choice!");
                }
                
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

/*
1. IMPLEMENT REMAINING OPERATIONS IN DLL
2. IMPLEMENT STACKS USING SLL
3. REVERSE A LINKED LIST(SLL AND DLL)
*/
