#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	
	int data;
	struct Node* next;
	
};


struct Node* head=NULL;
struct Node* tail=NULL;


void Traverse(struct Node* queue){
	
	struct Node* iter=queue;
	
	while(iter!=NULL){
		
		printf("%d \n",iter->data);
		iter=iter->next;
	}
	
}
struct Node* PrepNode(int data){
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=data;
	return temp;	
}

struct Node* Enqueue(int data,struct Node* queue){
	
	struct Node* temp=PrepNode(data);
	
	if(head==NULL){
		head=temp;
		tail=temp;
	}
	else{
		
		tail->next=temp;
		tail=temp;		
	}
	
	return head;
	
	
}
struct Node* Dequeue(struct Node* queue){
	
	return queue->next;	
}

int is_Empty(struct Node* queue){
	if(queue==NULL)
	return 1;
	else
	return -1;
}
int Front(struct Node* queue){	
	return queue->data;		
}




int main(){


	
}
