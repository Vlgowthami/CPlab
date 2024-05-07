//implementing BST using linked list
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	struct node*lchild;
	struct node*rchild;
};
struct node*insert(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int count_nodes(struct node*);
int main(){
	int choice,item;
	struct node*root=NULL;
	while(1){
		printf("\n******  MENU   *******\n");
		printf("1.INSERT \n");
		printf("2.Inorder\n");
		printf("3.Preorder\n");
		printf("4.Postorder\n");
		printf("5.No.of Nodes\n");
		printf("6.EXIT\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the element :  ");
				scanf("%d",&item);
				root= insert(root,item);
				break;
			case 2: if(root==NULL)
					printf("Tree is empty");
				else{
					printf("Inorder traversal:");
					inorder(root);
				}
				break;
			case 3: if(root==NULL)
					printf("Tree is empty");
				else{
					printf("Preorder traversal:");
					preorder(root);
				}
				break;
			case 4: if(root==NULL)
					printf("Tree is empty");
				else{
					printf("Postorder traversal:");
					postorder(root);
				}
				break;
			case 5: printf("No.of nodes =%d",count_nodes(root));
				break;
			case 6: exit(0);
				break;
			default:printf("INVALID NUMBER");
		}
	}
}
struct node *insert(struct node *root,int item){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=item;
		root->rchild=root->lchild=NULL;
	}
	else if(item<root->data)
			root->lchild=insert(root->lchild,item);
	else
			root->rchild=insert(root->rchild,item);
	return root;
}
void inorder(struct node*root){
	if(root!=NULL){
		inorder(root->lchild);
		printf("%4d",root->data);
		inorder(root->rchild);
	}
}
void preorder(struct node*root){
	if(root!=NULL){
		printf("%4d",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void postorder(struct node*root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%4d",root->data);
	}
}
int count_nodes(struct node*root){
	if(root==NULL)
		return 0;
	else
		return(count_nodes(root->rchild)+count_nodes(root->lchild)+1);
}
		
		

