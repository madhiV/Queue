#include<stdio.h>
int front=-1,rear=-1;
int queue[5];

int isfull()
{
    if(rear>=4 || front>=4){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(){
    if(rear==-1){
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
   if(isfull()==1){
       printf("Queue is full...");
   }
   else if(isempty()==1){
       front++;
       rear++;
       queue[rear]=e;
       printf("Enqueue sucess");
   }
   else{
       queue[++rear]=e;
    //   top++;
       printf("Enqueue sucess");
   }
}
int dequeue(){
    int e;
    if(isempty()==1){
        printf("queue is empty...");
        return -1;
    }
    else{
        e=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
        front++;
        }
        return e;
    }
}
void display()
{
    int y=front,z=rear;
    if(y==-1){
        printf("queue is empty");
    }
    else{
        printf("The elements are : ");
         do{
            printf("%d\t",queue[y]);
            y++;
        }while(y!=z);
        printf("%d\t",queue[y]);
    }
}
void peek()
{
    if(front==-1){
        printf("queue is empty");
    }
    else{
    printf("The peek element is :");
    printf("%d",queue[front]);
    }
}
void peep()
{
    int y;
    int p;
    printf("Enter the position : ");
    scanf("%d",&p);
    y=front;
    while(y==p-1){
        y++;
    }
    printf("The element found at position %d is %d ",p,queue[y]);
}
int size()
{
    int count=0,y=front,z=rear;
    if(front==-1){
        return 0;
    }
    else{
        while(y!=z){
            count++;
            y++;
        }
        count++;
        return count;
    }
}
void main()
{
    int e=1,t;
    while(e==1){
    printf("-----MENU-----\n");
    printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Size\t5.isFull\t6.isEmpty\t7.Exit\nEnter a choice...");
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
            if(isfull()==1){
                printf("The queue is full");
            }
            else{
                printf("queue is not full");
            }
            break;
        case 6:
            if(isempty()==1){
                printf("The queue is empty");
            }
            else{
                printf("queue is not empty");
            }
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
