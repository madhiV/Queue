#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*head=NULL,*p,*n,*old;
//is empty
int isempty(){
    if(head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue()
{
   int e;
   printf("Enter the element : ");
   scanf("%d",&e);
   n=(struct node *)malloc(sizeof(struct node));
   n->data=e;
   n->next=NULL;
   if(isempty()==1){
       head=n;
       printf("Enqueue success");
   }
   else{
       p=head;
       if(p->next!=NULL){
       while(p->next!=head){
           p=p->next;
        }
       }
       p->next=n;
       n->next=head;
       printf("Enqueue sucess");
   }
}
int dequeue(){
    int e;
    p=head;
    if(isempty()==1){
        printf("queue is empty...");
        return -1;
    }
    else{
        e=p->data;
        if(p->next==NULL){
            head=NULL;
            return e;
        }
        else{
        while(p->next!=head){
            p=p->next;
        }
        p->next=head->next;
        head=head->next;
        if(head->next==head){
            head->next=NULL;
        }
        }
        return e;
    }
}
void display()
{
    p=head;
    if(isempty()==1){
        printf("queue is empty");
    }
    else if(p->next==NULL){
        printf("The elements are : ");
        printf("%d\t",p->data);
    }
    else{
        printf("The elements are : ");
         do{
            printf("%d\t",p->data);
            p=p->next;
        }while(p!=head);
    }
}
void peek()
{
    if(head==NULL){
        printf("queue is empty");
    }
    else{
    printf("The peek element is :");
    printf("%d",head->data);
    }
}
void peep()
{
    int pos;
    p=head;
    printf("Enter the position : ");
    scanf("%d",&pos);
    int y=pos;
    y--;
    while(y!=0){
        p=p->next;
        y--;
    }
    printf("The element found at position %d is %d ",pos,p->data);
}
int size()
{
    p=head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    else if(p->next==NULL){
        return 1;
    }
    else{
        do{
            count++;
            p=p->next;
        }while(p!=head);
        return count;
    }
}
void main()
{
    int l;
    printf("Enter number of node : ");
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        printf("Enter the element %d : ",i+1);
        n=(struct node*) malloc(sizeof(struct node));
        n->next=NULL;
        scanf("%d",&n->data);
        p=head;
        if(head==NULL){
            head=n;
        }
        else if(p->next==NULL){
            p->next=n;
            n->next=head;
        }
        else{
            while( p->next!=head){
                p=p->next;
            }
            p->next=n;
            n->next=head;
        }
    }
    int e=1,t;
    while(e==1){
    printf("-----MENU-----\n");
    printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Size\t5.isEmpty\t6.Peep\t7.Exit\nEnter a choice...");
    scanf("%d",&t);
    switch(t){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("The size of the queue is %d",size());
            break;
        case 5:
            if(isempty()==1){
                printf("The queue is empty");
            }
            else{
                printf("queue is not empty");
            }
            break;
        case 6:
            peep();
            break;
        case 7:
            e=0;
            break;
        default:
            printf("Invalid choice");
        }
        printf("\n");
    }
}
