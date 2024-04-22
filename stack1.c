#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int);
void pop();
void display();
int main(){
    int item,choice;
    char ch;
    clrscr();
    while(1){ 
        printf("\n1.PUSH\n2.POP\n3.display\n4.EXIT");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
    switch(choice){
              case 1:printf("Enter the element:");
                     scanf("%d",&item);
                     push(item);
                     break;
              case 2:pop();
                     break;
              case 3:display();
                     break;
              case 4:exit(0);
                     break;
        }
        
    }
}
void push(int item ){
     if(top==MAX-1) 
       printf("Stack overflow");
     else{
        item= stack[++top];
        printf("Element inserted");
     }
}
void pop(){
    if (top==-1) 
        printf("stack underflow");
    else  
       printf("Element deleted %d",stack[top--]);
    
}
void display(){
    int i;
    if(top==-1) 
       printf("stack is empty");
    else{
          printf("Stack content");
          for(i=top;i>=0;i--){
              printf("%d",stack[i]);
        }
    }
}
