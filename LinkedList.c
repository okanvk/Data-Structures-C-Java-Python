#include <stdio.h>
#include <stdlib.h>


 struct Node{

	int data;
	struct Node* next;
	
};


struct Node* head=NULL;
struct Node* tail=NULL;

struct Node* DeleteNthNode(int value,struct Node* ll){
	
	if(ll==NULL)
	return NULL;
	if(LengthOfLinkedList(ll)<value)
	return NULL;
	
	if(value==1){
	return ll->next;
	}
	
	struct Node* iter=ll;
	int count=1;
	while(iter!=NULL){
		
		if(count+1==value)
		break;
		
		
		iter=iter->next;
		count++;
		
	}
	
	if(iter->next->next==NULL){
		iter->next=NULL;
	}
	else{		
		struct Node* temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	}
	return ll;
}	
void Swapping(struct Node*  node1,struct Node*  node2){
	
	int data=node1->data;
	node1->data=node2->data;
	node2->data=data;
		
}	
struct Node* PrepNode(int data){
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
		
}
void AddDataTail(int data){
	
	struct Node* temp=PrepNode(data);
	
	if(tail==NULL){
	
		head=temp;
		tail=temp;
	}
	else
	{	
	tail->next=temp;
	tail=temp;	
	}
	
}
void AddDataHead(int data){

	struct Node* temp=PrepNode(data);
	
	if(head==NULL){

		tail=temp;
		head=temp;

	}
	else{
		
		temp->next=head;
		head=temp;		

	}	
}
int FindData(int data){
	
	
	struct  Node* iter=head;
	
	while(iter!=NULL){
		
		if(iter->data==data){
			return 1;
		}
		iter=iter->next;
	}
	return -1;	
}
int DeleteWithData(int data){
	
	struct Node* Temp;
	struct Node* iter=head;
	
	if(iter->data==data){//Basta olma durumu
	
	head=head->next;
	return 1;
	
	}
	
	while(iter!=NULL){
		
		if(iter->next->data==data){
			
			if(iter->next->data==data && iter->next->next==NULL){
				//Sonda olma durumu
				
				Temp=iter->next;
				tail=iter;
				free(Temp);				
				return 1;
				
			}
			if(iter->next->data==data && iter->next->next!=NULL){
				//Ortada olma durumu
				
				Temp=iter->next;
				iter->next=iter->next->next;
				free(Temp);
				
				return 1;
			}
						
		}
		
		iter=iter->next;
		
	}
	
	if(iter==NULL)//Veri bulunmama
	return -1;
		
}
void Traverse(struct Node* temp){
	
struct	Node* iter=temp;
	while(iter!=NULL){
		
		printf("Data %d \n",iter->data);
		iter=iter->next;
		
	}
	
}
void SchemaTraverse(struct Node* temp){
	
	struct Node* iter=temp;
	
	while(iter!=NULL){
		
		if(iter->next==NULL)
		printf("- %d - |",iter->data);
		else
		printf("- %d -  --> ",iter->data);
		iter=iter->next;
		
	}
		
}
struct Node*  LinkedListSort(struct Node* list){
		
	struct Node* iter=list;
	
	while(iter!=NULL){
				
		struct Node* iter2=iter;
		
		while(iter2!=NULL){
			
			if(iter->data>iter2->data){
			
			Swapping(iter,iter2);
			
			}
			
			iter2=iter2->next;
	
		}
						

		iter=iter->next;
		
	}
	return list;
		
}
int LengthOfLinkedList(struct Node* ll){
	
	int length=0;
	struct Node* iter=ll;
	while(iter!=NULL){
		
		length++;
		iter=iter->next;
	}

	return length;
	
}
struct Node* GetNthNode(int value){
	
	if(LengthOfLinkedList(head)<value)
	return NULL;
	
	if(value<=0)
	return NULL;
	
	struct 	Node* iter=head;
	int n=1;
	
	while(iter!=NULL){
		
		if(n==value)
		return iter;
				
		iter=iter->next;
		n++;
	}

}
int FindMiddle(struct Node* ll){
	
	int middle;
	
	if(LengthOfLinkedList(head)%2==0){
		
		middle=LengthOfLinkedList(ll)/2;
		struct Node* temp=GetNthNode(middle+1);
		return temp->data;			
		
	}
	else{
		
		middle=LengthOfLinkedList(ll)/2;
		struct Node* temp=GetNthNode(middle+1);
		return temp->data;
		
	}
		
}
void NThFromEnd(int value){
	
	struct Node* temp=GetNthNode(value);
	Traverse(temp);
	
}
int Find_Count_Of_GivenData(int data){
	
	struct Node* iter=head;
	int count=0;	
	
	while(iter!=NULL){
		
		if(iter->data==data)
		count++;		
		
		iter=iter->next;		
	}
	return count;			
}
struct Node*  ReverseList(struct Node* ll){
	
	struct Node* reversedlist=NULL;
	
	while(ll!=NULL){
		
		if(reversedlist==NULL){			
			reversedlist=PrepNode(ll->data);									
		}
		else{
			
			struct Node* temp=PrepNode(ll->data);
			temp->next=reversedlist;
			reversedlist=temp;
						
		}
		ll=ll->next;
	}
	
	return  reversedlist;
	
}
struct Node* Move_LastElm_To_First(struct Node* ll){
	
	if(LengthOfLinkedList(ll)<2)
	return;
	
	struct Node* iter=ll;
	while(iter->next->next!=NULL){
		
		iter=iter->next;
		
	}
	
	struct Node* temp=PrepNode(iter->next->data);
	iter->next=NULL;
	temp->next=ll;
	ll=temp;
	return ll;
	
}
void Pairwise_Swapping(struct Node* ll){
	
		struct Node* iter=head;
		
	if(LengthOfLinkedList(ll)%2==0){
		
		while(iter!=NULL){
			
			Swapping(iter,iter->next);
			iter=iter->next;
			iter=iter->next;
			
			
		}
	}
	else{
			while(iter->next!=NULL){
			
			Swapping(iter,iter->next);
			iter=iter->next;
			iter=iter->next;

			
		}
				
	}
			
}
void RemoveDuplicates(struct Node* ll){
		
	struct Node* dup;	
	struct Node* iter=ll;
	while(iter!=NULL){
			
		struct Node* iter2=iter;
		
		while(iter2->next!=NULL){
		
			if(iter2->next->data==iter->data){
				
				dup = iter2->next;
                iter2->next = iter2->next->next;
                free(dup);


			}
			else			
			iter2=iter2->next;
		}
		
		iter=iter->next;
	}

	
	
	
	
}	
struct Node* Intersection_of_two_Sorted_Linked_Lists(struct Node* ll,struct Node* ll2){
	
	struct Node* newlist=NULL;
	
	
	struct Node* ll1t=LinkedListSort(ll);
	struct Node* ll2t=LinkedListSort(ll2);

	
	while(ll1t!=NULL){
		while(ll2t!=NULL){
			if(ll1t->data==ll2t->data){
				
				if(newlist==NULL){
				newlist=PrepNode(ll1t->data);
				}
				else{
					struct Node* temp=PrepNode(ll1t->data);
					temp->next=newlist;
					newlist=temp;
				}
				ll2t=ll2t->next;
				break;
					
								
			}
			ll2t=ll2t->next;
			
		}
		ll2t=LinkedListSort(ll2);
		ll1t=ll1t->next;
	}
	return newlist;

	
}
int Identical(struct Node* ll,struct Node* ll2){
	
	int state=0;
	if(ll==NULL && ll2==NULL)
	return 0;
	
	if(ll!=NULL && ll2!=NULL)
	{

	if(ll->data==ll2->data){
		state=0;
	}
	
	return state+Identical(ll->next,ll2->next);
	}
	else
	return -1;
	
	
}
struct Node* RotateListNthNode(int number,struct Node* ll){//Tamamla
	
	if(LengthOfLinkedList(ll)<number)
	return NULL;
	
	
	struct Node* iter1=ll;
	int state=0;
	int array[number];
	while(state!=number){
	
			
			
		array[state]=ll->data;
		state++;
		ll=ll->next;				
		}
		
		struct Node* iter3=ll;
		while(iter3->next!=NULL){
			iter3=iter3->next;
		}
		
		

			int anth=0;
			while(anth!=state){
				
				iter3->next=PrepNode(array[anth]);
				anth++;
				iter3=iter3->next;
				
				
			}
			
			
	
		
	
		

return iter3;
	
}


int main(){
	


}
