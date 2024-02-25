#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * insertStart(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node * insertBetween(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(ptr->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * deleteStart(struct Node * head){
    struct Node * p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node * deleteBetween(struct Node * head, int index){
    struct Node * ptr = head;
    int i = 0;
    while(i!=index-1){
        ptr = ptr->next;
        i++;
    }
    struct Node * p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

struct Node * deleteEnd(struct Node * head){
    struct Node * ptr = head;
    while(ptr->next->next!=NULL){
        ptr = ptr->next;
    }
    struct Node * p = ptr->next;
    ptr->next = NULL;
    free(p);
    return head;
}

void LLTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node * head = NULL;
    int choice, data, index;

    do{
        printf("\nLinked List Operations : \n");
        printf("\n1. Insert at Start");
        printf("\n2. Insert in Between");
        printf("\n3. Insert in the Last");
        printf("\n4. Delete from the Start");
        printf("\n5. Delete from the Between");
        printf("\n6. Delete from the End");
        printf("\n7. Display Linked List");
        printf("\n0. Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);
    
        switch(choice) {
        
            case 1:
            printf("Enter the data you want to insert : ");
            scanf("%d",&data);
            break;

            case 2:
            printf("Enter the data you want to insert : ");
            scanf("%d",&data);
            printf("Enter the index position where you want to enter the data : ");
            scanf("%d",index);
            break;

            case 3:
            printf("Enter the data you want to enter : ");
            scanf("%d",&data);
            break;

            case 4:
            break;

            case 5:
            printf("Enter the index from where you want the data to be deleted : ");
            scanf("%d",&index);
            break;

            case 6:
            break;

            case 7:
            printf("Here is the Linked List : ");
            break;

            case 0:
            printf("Exiting the program : ");
            break;

        }
    } while (choice != 0);
    
    return 0;
}