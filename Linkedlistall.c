Singly linked list Implementation (Traversing, Insertion, Deletion)
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *create_node(int data)
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if(p==NULL)
printf("Allocation Error");
else
{
p->data=data;
p->next=NULL;
}
return p;
}
void traversing(struct node *head)
{
struct node *t=head;
if(head==NULL)
printf("Linked list is empty");
else
{
while(t)
{
printf("%d ",t->data);
t=t->next;
}
}
printf("\n");
}
struct node *insert_starting(struct node *head,int data)
{
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
printf("Allocation Error");
else
{
p->data=data;
p->next=NULL;
p->next=head;
head=p;
}
return head;
}
struct node *insert_ending(struct node *head,int data)
{
struct node *p,*t=head;
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
printf("Allocation Error");
else
{
p->data=data;
p->next=NULL;
if(head==NULL)
head=p;
else {
while(t->next!=NULL)
t=t->next;
t->next=p;
}
}
return head;
}
struct node *insert_position(struct node *head,int data,int position)
{
int count=1;
struct node *p,*t=head;
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
printf("Allocation Error");
else
{
p->data=data;
p->next=NULL;
if(position==1){
p->next=head;
head=p;
}
else {
while(count!=(position-1)){
t=t->next;
count++;
}
p->next=t->next;
t->next=p;
}
}
return head;
}
struct node *delete_starting(struct node *head)
{
struct node *d;
if(head==NULL)
printf("Underflow error");
else
{
d=head;
head=head->next;
free(d);
}
return head;
}
struct node *delete_ending(struct node *head)
{
struct node *d,*t=head;
if(head==NULL)
printf("Underflow error");
else if(head->next==NULL)
{
free(head);
head=NULL;
}
else
{
while(t->next->next!=NULL)
t=t->next;
d=t->next;
t->next=NULL;
free(d);
}
return head;
}
struct node *delete_position(struct node *head,int position)
{
int count=1;
struct node *d,*t=head;
if(head==NULL)
printf("Underflow error");
else if(position==1)
{
d=head;
head=head->next;
free(d);
}
else
{
while(count!=(position-1))
{
count++;
t=t->next;
}
d=t->next;
t->next=d->next;
free(d);
}
return head;
}
int main()
{
int i,n,data;
struct node *p1,*p2,*head;
printf("enter the number of node you want to create ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter data for node%d ",i);
scanf("%d",&data);
p1=create_node(data);
if(i==1)
{
head=p1;
p2=p1;
}
else
{
p2->next=p1;
p2=p1;
}
}
printf("Linked List data: ");
traversing(head);
head=insert_starting(head,30);
printf("Linked List data after insert 30 at starting: ");
traversing(head);
head=insert_ending(head,40);
printf("Linked List data after insert 40 at ending: ");
traversing(head);
head=insert_position(head,50,3);
printf("Linked List data after insert 50 at position 3: ");// Note take initial linked list 1 2 3 4 5
traversing(head);
head=delete_starting(head);
printf("Linked List data after deletion at starting: ");
traversing(head);
head=delete_ending(head);
printf("Linked List data after deletion at ending: ");
traversing(head);
head=delete_position(head,2);
printf("Linked List data after deletion at position 2: ");
traversing(head);
return 0;
}
Output￾enter the number of node you want to create 5
Enter data for node1 1
Enter data for node2 2
Enter data for node3 3
Enter data for node4 4
Enter data for node5 5
Linked List data: 1 2 3 4 5
Linked List data after insert 30 at starting: 30 1 2 3 4 5
Linked List data after insert 40 at ending: 30 1 2 3 4 5 40
Linked List data after insert 50 at position 3: 30 1 50 2 3 4 5 40
Linked List data after deletion at starting: 1 50 2 3 4 5 40
Linked List data after deletion at ending: 1 50 2 3 4 5
Linked List data after deletion at position 2: 1 2 3 4 5
