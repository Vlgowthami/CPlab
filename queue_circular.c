//implementation of queues in circular
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int);
void delete();
void display();
int main(){
    int choice,item;
    while(1){
        printf("\n******MENU*******\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :printf("Enter the element : ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2 :delete();
                    break;
            case 3 :display();
                    break;
            case 4: exit (0);
            default:printf("invalid number");
        }
    }
}
void insert(int item){
    if((rear+1)%MAX==front)
        printf("Queue is full");
    else{
        rear=(rear+1)%MAX;
        queue[rear]=item;
        if (front==-1)
            front=0;
    }
}
void delete(){
    if(front==-1)
        printf("Queue is empty");
    else{
        printf("Deleted element : %d ",queue[front]);
        if(front==rear)
            front=rear=0;
        front=(front+1)%MAX;
    }
}
void display(){
    int i=front;
    if(front==-1)
        printf("Queue is empty");
    else{
        printf("List content :");
        while(i!=rear){
            printf("%4d",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%4d",queue[rear]);
    }
}
    
    

