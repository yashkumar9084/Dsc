#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;

};
void main(){
    struct Node *head = NULL,*temp = NULL,*new=NULL;
    printf("Enter number of nodes: ");
    int n;
    scanf("%d",&n);
    int i=0;
    do{
        printf("Enter the data of new Node: ");
        new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL){
            head = new;
            temp = head;
        }
        else{
           temp = new;
           temp= temp->next;
     
        }i++;
        
    }while (i<n);
   temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    
    
}
