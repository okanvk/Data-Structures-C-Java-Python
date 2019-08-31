#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	
	int data;
	Node* left;
	Node* right;
		
};


Node* root= NULL;


Node* Add(Node* root,int data){
		
	
	if(root==NULL){
		
		Node* agac=(Node*)malloc(sizeof(struct Node));
		agac->data=data;
		agac->left=NULL;
		agac->right=NULL;
		return agac;	
	}

		
	if(root->data>data){
		
		root->left=Add(root->left,data);
		return root;
	}

	root->right=Add(root->right,data);
		return root;

	
	
}
void PreOrder(Node* root){
	
	
	if(root==NULL){
		return;
	}
	
	Node* iter=root;
	
	printf("Data is %d \n",iter->data);
	PreOrder(iter->left);
	PreOrder(iter->right);	
		

}
void InOrder(Node* root){
	
	if(root==NULL){
		return;
	}
	
		Node* iter=root;
	
	InOrder(iter->left);
	printf("Data is %d \n",iter->data);
	InOrder(iter->right);
	
	
}
void PostOrder(Node* root){
	
		if(root==NULL){
		return;
		}
			Node* iter=root;
	
	
	PostOrder(iter->left);
	PostOrder(iter->right);
	printf("Data is %d \n",iter->data);
	
	
	
}
int FindMin(Node* root){
	
	if(root->left==NULL){
		
		return root->data;
	}
	else{
		
		return FindMin(root->left);
	}

}
int FindMax(Node* root){
	
	if(root->right==NULL){
		
		return root->data;
	}
	
	return FindMax(root->right);
	
}
int Search(Node* root,int data){
	
	if(root==NULL){
		
		printf("Data bulunamadi");
		return -1;
		
		
	}
	
	if(root->data==data){
		
		printf("Data bulundu");
		return 1;
	}
	else{
		
		if(root->data>data){
		return		Search(root->left,data);
		}
		else{
		return	Search(root->right,data);
		}
		
		
	}
	
}	


int main(){
	

}
