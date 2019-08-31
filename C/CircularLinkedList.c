#include <stdio.h>
#include <stdlib.h>

 struct Node{
	
	int data;
	struct Node* link;
	
};

struct Node* head=NULL;

struct Node* AddData(int data,struct Node* ll){
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* hold=ll;
	temp->data=data;
	temp->link=ll;

	if(ll==NULL){
		temp->link=temp;
	}
	else{
		
		while(hold->link!=ll){
			hold=hold->link;
		}
		hold->link=temp;

			
	}
	ll=temp;
	return ll;
}
void Traverse(struct Node *head){
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        while (temp != head);
    }
}
int LengthOfLinkedList(struct Node* head){
	
	int count=0;
	struct Node* iter=head;
	if(iter!=NULL){
		
		do{
			count++;
			iter=iter->link;				
		}
		while(iter!=head);
		
	}
	return count;
	
	
	
}
void DivideLinkedList(struct Node* head){
	
	if(LengthOfLinkedList(head)%2==0){
		
		int	middle=LengthOfLinkedList(head)/2;
		int state=0;
		
		struct Node* new1=NULL;
			struct Node* new2=NULL;
		
		while(state!=middle){
			
			new1=AddData(head->data,new1);
			head=head->link;
			state++;
			
		}
		while(state!=LengthOfLinkedList(head)){
			
			new2=AddData(head->data,new2);
			head=head->link;
			state++;
			
		}
		
		Traverse(new1);
		Traverse(new2);
		
		
		
	}
	else{
	int	middle=LengthOfLinkedList(head)/2;
		int state=0;
		
		struct Node* new1=NULL;
			struct Node* new2=NULL;
		
		while(state!=middle){
			
			new1=AddData(head->data,new1);
			head=head->link;
			state++;
			
		}
		while(state!=LengthOfLinkedList(head)){
			
			new2=AddData(head->data,new2);
			head=head->link;
			state++;
			
		}
		
		Traverse(new1);
		Traverse(new2);
		
	}
	
	
	
	
	
}
void SortedLinkedList(struct Node* head){
	
	if(head==NULL)
	return;
	
	struct Node* iter1=head;
	iter1=iter1->link;
	while(iter1!=head){
		
		
		
		struct Node* iter2=iter1;
		iter2=iter2->link;
		while(iter2!=iter1){
			if(iter1->data>iter2->link->data){
				
				swap(iter1,iter2->link);
			}
			
			
			
			iter2=iter2->link;
			
		}
		
		
			iter1=iter1->link;
		
		
		
	
		
	}
	head=iter1;
	
	
	
}
void swap(struct Node* big,struct Node* small){
	
	int data=big->data;
	big->data=small->data;
	small->data=data;
	
}
int isCircularLinkedList(struct Node* ll){
	
	struct Node* iter=ll;
	
	while(iter->link!=NULL && iter!=ll){
		
		iter=iter->link;
		
	}	

	if(iter==ll)
	return 1;
	else
	return -1;
	
	
	
}
struct Node* DeleteingFromLinkedList(struct Node* ll,int data){
	
	
	if(ll==NULL)
	return;
	
	if(ll->data==data){
		
		struct Node* temp=ll->link;
		struct Node* iter=ll;
		while(iter->link!=ll){
			iter=iter->link;
		}
		iter->link=temp;
		
		
		return iter;
		
	}
	struct Node* iter2=ll->link;
	while(ll!=iter2){
		
		if(iter2->link->data==data){
			break;
		}
		
		iter2=iter2->link;
		
		
		
	}	
	if(iter2==ll){
		ll=iter2;
		return;
	}
	else{
		

		iter2->link=iter2->link->link;
	
				
	}
	

}
struct Node* AddDataNthNode(int n,int data,struct Node* ll){
	
	if(LengthOfLinkedList(head)<n)
	return NULL;
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link=NULL;
	if(ll==NULL){
		ll=temp;
	}
	else{
		int i=1;
		
		while(n!=i){
			
			ll=ll->link;
			i++;
			
			
		}
		struct Node* geriye=ll->link;
		ll->link=temp;
		temp->link=geriye;
		return temp;
		
		
		
		
		
		
	}
	
	
	
	
	
}

int main(){
	

}
