#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;

};
struct node *reversell(struct node *head){
struct node *cur = head,*prev=NULL,*nextnode = NULL;
    while(cur!=NULL){
        nextnode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextnode;
    }
    return prev;

}
struct node* createnode(int data){ // Return type name()
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node)); // sizeof is operator and (typecast)
    if (p==NULL){
        printf("Allocation error");

    }
    else{
        p->data = data;
        p->next = NULL;
    }
    return p;
}
void traversing(struct node *head){
     struct node *t = head;
    if (head==NULL)
        printf("Empty Link list");
    else{
        while(t!=NULL){
            printf("%d ",t->data);
            t=t->next;
        }
    }
}
int main(){
    struct node *p1,*p2,*head;
    int data,i,n;
    printf("Enter no of nodes you want to create: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter data for node: ");
        scanf("%d",&data);
        p1 = createnode(data);
        if(i==1){
            head = p1;
            p2=p1;

        }
        else{
            p2->next = p1;
            p2=p1;
        }
    }traversing(head);
    reversell(head);
    return 0;
}
