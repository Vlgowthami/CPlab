//double linked list
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	int data;
	struct node*prev;
	struct node*next;
};
typedef struct node NODE;
void create();
void insert_front(int );
void delete_front();
void traRL();
NODE*head=NULL;
int main(){
	int choice,item;
	create();
	while(1){
		printf("\n*****MENU*****\n1.Insert front\n2.Delete Front\n3.traverse from right to left\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:	printf("Enter the element :");
				scanf("%d",&item);
				insert_front(item);
				break;
			case 2:	delete_front();
				break;
			case 3:	traRL();
				break;
			case 4:	exit(0);
			default:printf("INVALID POSTION\n");
		}
	}
}
void create(){
	NODE *temp,*cur=head;
	int item;
	char ch;
	do{
		printf("Enter the Element:");
		scanf("%d",&item);
		temp=(NODE*)malloc(sizeof(NODE));
		temp->data=item;
		if(head==NULL)
			temp=head=cur;
		else{
			cur->next=temp;
			cur=temp;
			cur->prev=temp;
		}
		printf("do you want to continue(y/n)");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	cur->next=NULL;
}
void insert_front(int item){
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=head;
	temp->prev=NULL;
	head->prev=temp;
	head=temp; 
}
void delete_front(){
	NODE *temp;
	if(head==NULL)
		printf("List is Empty\n");
	else{
		temp=head;
		head=head->next;
		printf("Deleted element:%d",temp->data);
		free(temp);
		head->prev=NULL;
	}
}
void traRL(){
	NODE *temp,*cur=head;
	if(head=NULL)
		printf("List is Empty");
	else{
		while(cur->next!=NULL)
			cur=cur->next;
		while(cur->prev!=NULL){
			printf("%4d",cur->data);
			cur=cur->prev;
		}
	}
}

				
	
		

