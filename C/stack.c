#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	
	int data;
	struct Node* next;
	
};


struct Node* head=NULL;


struct Node* PrepNode(int data){
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=data;
	return temp;
	
}
struct Node* Push(int data,struct Node* link){
	
	struct Node* temp=PrepNode(data);
	
	if(link==NULL){
		link=temp;
	}
	else{
		
		temp->next=link;
		link=temp;
		
		
	}
	return link;
		
}
int front(struct Node* link){
	
	return link->data;
	
}
struct Node* Pop(struct Node* link){
	
	return link->next;
	
}
void Traverse(struct Node* link){
	
	struct Node* iter=link;
	while(iter!=NULL){
		
		printf("%d \n",iter->data);
		iter=iter->next;
		
	}
	
}
struct Node* ReverseStack(struct Node* stack,struct Node* reversed){
	
	if(stack==NULL)
	return reversed;
	else{
		
		reversed=Push(stack->data,reversed);
		stack=Pop(stack);
		return ReverseStack(stack,reversed);
		
	}

}
void NextGreater(struct Node* link){
	
	struct Node* iter=link;
	
	while(iter!=NULL){
		
		int data=iter->data;
		
		struct Node* iter2=link->next;
		
		while(iter2!=NULL){
			
			if(iter2->data>data){
				data=iter2->data;
			}
						
			iter2=iter2->next;
		}
		
		
		
		
		if(data!=iter->data){
			printf("Data is %d Greater is %d \n",iter->data,data);
		}
		else{
			printf("Data is %d Greater is -1\n",data);;
		}
		
		
		
		iter=iter->next;
	}
	
	
	
	
}
int is_Empty(struct Node* link){
	if(link==NULL)
	return 1;
	else
	return -1;

}

int main(){

}
