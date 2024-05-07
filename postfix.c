//To evaluate the given expression into postfix expression
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int item){
	if(top=MAX-1){
		printf("stack overflow");
		getc();
		exit(0);
	}
	stack[++top]=item;
}
int pop(){
	int item;
	if(top==-1){
		printf("stack underflow");
		getch();
		exit(0);
	}
	item=stack[top];
	top--;
	return item;
}
int isEmpty(){
	if(top==-1)
		return 1;
	else 
		return 0;
}
int isOperand(char ch){
	if(ch>='0'&&ch<='9')
		return 1;
	else
		return 0;
}
int main(){
	char postfix[20],ch;
	int op1,op2,i,r;
	printf("Enter the postfix expression:");
	scanf("%c",&postfix);
	for(i=0;postfix[i]!='\0';i++){
		ch=postfix[i];
		if(isOperand(ch))
			push(ch '0')
		else{
			op2=pop();
			op1=pop();
			switch(ch){
			case'+':r=op1+op2;
				break;
			case'-':r=op1-op2;
				break;
			case'*':r=op1*op2;
				break;
			case'%':r=op1%op2;
				break;
			case'/':r=op1/op2;
				break;
			}
		push(r);
	}
	r=pop();
	if(!isEmpty())
		printf("INVALID POSTFIX EXPRESSION");
	else
		printf("result=%d",r);
	return 0;
	}
}
	
