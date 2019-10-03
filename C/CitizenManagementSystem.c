//Okan Ciftci 
//151805041
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#define SIZE 100
typedef struct Family{ //My Struct For Every Family Member
	int id;
	int state;
	int birth_year;
	char name[SIZE];
	char surname[SIZE];
	char relationship[SIZE];
	struct Family* next;	
}Fm;
typedef struct Resident{//My Struct For Every Resident Member
	int id;
	char name[SIZE];
	char surname[SIZE];
	char address[SIZE];	
	struct Resident* next; 
	struct Family* firstFm;
}Rs;
Rs* head=NULL; //My head I can access everything with this pointer
void swap(Rs *a, Rs *b){ //This is my swap function which helps Sort	
	char tempname[20];
    int temp = a->id;
    Fm* rtemp=NULL;
    a->id = b->id;
    b->id = temp;
	strcpy(tempname,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tempname);
    strcpy(tempname,a->surname);
    strcpy(a->surname,b->surname);
    strcpy(b->surname,tempname);
    strcpy(tempname,a->address);
    strcpy(a->address,b->address);
    strcpy(b->address,tempname);
	rtemp=a->firstFm;
	a->firstFm=b->firstFm;
	b->firstFm=rtemp;
}
void bubbleSort(){//This is my sort algorithm
    int swapped, i;
     Rs *ptr1;
     Rs	 *lptr = NULL;
    if (ptr1 == NULL)
        return; 
    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->id > ptr1->next->id)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void AddResident(int data,char name[],char surname[],char address[]){//This function add resident your linked list
	Rs* temp=(Rs*)malloc(sizeof(Rs));
	temp->firstFm=NULL;
	temp->id=data;
	strcpy(temp->name,name);
	strcpy(temp->surname,surname);
	strcpy(temp->address,address);
	temp->next=head;
	head=temp;
	bubbleSort();
}
void AddFamily(int id,int data,int state,int birth,char name[],char surname[],char relationship[]){//This Function add family member your resident
	Rs* iter=head;
	while(iter!=NULL){
		if(iter->id==id){
			break;
		}
		iter=iter->next;
	}
	if(iter==NULL){
		printf("Your entered ID didn't find\n");
		return;
	}
	Fm* family=(Fm*)malloc(sizeof(Fm));
	family->id=data;
	family->state=state;
	family->birth_year=birth;
	strcpy(family->name,name);
    strcpy(family->surname,surname);
    strcpy(family->relationship,relationship);
	if(iter->firstFm==NULL){
		family->next=NULL;
		iter->firstFm=family;
	}
	else{
		family->next=iter->firstFm;
		iter->firstFm=family;
	}		
}
void BringResidentFamilyData(int id){//Display family info which depend resident id
		Rs* iter=head;
	while(iter!=NULL){
		if(iter->id==id){
			break;
		}
		iter=iter->next;
	}
	if(iter==NULL){
		printf("You Entered ID didn't find'\n");
		return;
	}
	Fm *tempf=iter->firstFm;
	while(tempf!=NULL){
	printf("\n----------\n");
		printf("ID - %d -\n",tempf->id);
		printf("Name - %s -\n",tempf->name);
		printf("Surname - %s -\n",tempf->surname);
		printf("Life  - %d -\n",tempf->state);
		printf("Birth - %d -\n",tempf->birth_year);
		printf("Relationship - %s -\n",tempf->relationship);
		printf("----------");	
		tempf=tempf->next;
	}	
}
void DeleteResident(int data){//Delete Resýdent depends on resident id
	Rs *iter=head;				
		if(iter->id==data){
			struct Resident* interim=iter;
			iter=iter->next;
			head=iter;
			free(interim);
			return;
		}
	while(iter->next->id!=data){		
		iter=iter->next;
			if(iter->next==NULL){
			printf("There is no member which you want delete \n");;
			return;
			}				
	}	
	Rs* temp=iter->next;
	if(temp->next!=NULL)
	iter->next=temp->next;
	else{
		iter->next=NULL;
	}
	free(temp->firstFm);
	free(temp);				
}
void Assign(Fm *atanan,Fm *atanacak){	//For My Update Functýon
	strcpy(atanan->relationship,atanacak->relationship);
	strcpy(atanan->name,atanacak->name);
	strcpy(atanan->surname,atanacak->surname);
	atanan->id=atanacak->id;
	atanan->state=atanacak->state;
	atanan->birth_year=atanacak->birth_year;	
}
void Update(int Rid,int Rfm){ //For Update 
			Rs* iter=head;
	while(iter!=NULL){
		if(iter->id==Rid){
			break;
		}
		iter=iter->next;
	}
	if(iter==NULL){
		printf("There is no resident family member which you want to update\n");
		return;
	}
	Fm *choosen=iter->firstFm;	
	Fm *temp1=NULL; 
	int flag=1;
	while(choosen!=NULL){
		
		if(choosen->id==Rfm){
			choosen->state=0;
			flag=0;
		}		
		Fm* ftemp=(Fm*)malloc(sizeof(Fm)); 
		Assign(ftemp,choosen);
		
		if(temp1==NULL){
			temp1=ftemp;
			ftemp->next=NULL;
		}
		else{
			ftemp->next=temp1;
			temp1=ftemp;
		}	
		choosen=choosen->next;
	}
	if(flag==1){
		printf("There is no resident family member which you want to update");
	}		
	Fm *reload=NULL;
	while(temp1!=NULL){		
		Fm* ftemp=(Fm*)malloc(sizeof(Fm)); 
		Assign(ftemp,temp1);		
		if(reload==NULL){
			reload=ftemp;
			ftemp->next=NULL;
		}
		else{
			ftemp->next=reload;
			reload=ftemp;
		}	
		temp1=temp1->next;
	}	
	iter->firstFm=reload;
}
void DisplayResident(){ //Gýve Resýdent Info whých depends on resýdent ýd
	Rs *iter=head;
	while(iter!=NULL){
		printf("----------\n");
		printf("ID - %d -\n",iter->id);
		printf("Name - %s -\n",iter->name);
		printf("Surname - %s -\n",iter->surname);
		printf("Address - %s -\n",iter->address);
		printf("----------");
		iter=iter->next;
	}
}
int Menu(){//Menu for Process
	printf("\n----------\n");
	printf("1-Add Resident \n");
	printf("2-Add Family \n");
	printf("3-Delete Resident \n");
	printf("4-Update Family \n");
	printf("5-Display Resident \n");
	printf("6-Display Family \n");
	printf("7-For Exit\n");
	printf("----------\n");
	int id;
	printf("Enter Process\n");
	scanf("%d",&id);
	return id;	
}
void clrscr()//I use this function for clear console
{
    system("@cls||clear");
}
int main(){	
	int secondid,id,state,birth_Year,open=1;
	char name[SIZE];
	char surname[SIZE];
	char address[SIZE];
	char relationship[SIZE];
	while(open){
	int process=Menu();
		switch(process){		 	
		 	case 1:
		 		printf("Enter ID\n");
		 		scanf("%d",&id);
		 		printf("Enter Name\n");
		 		scanf("%s",name);
		 		printf("Enter Surname\n");
		 		scanf("%s",surname);
		 		printf("Enter Address\n");
		 		scanf("%s",address);
		 		AddResident(id,name,surname,address);
		 	break;
		 	case 2:
		 		printf("Enter Resident ID\n");
		 		scanf("%d",&secondid);
		 		printf("Enter Family ID\n");
		 		scanf("%d",&id);
		 		printf("Enter Birth Year ID\n");
		 		scanf("%d",&birth_Year);
		 		printf("Enter Name\n");
		 		scanf("%s",name);
		 		printf("Enter Surname\n");
		 		scanf("%s",surname);
		 		printf("Enter Relationship\n");
		 		scanf("%s",relationship);
		 		AddFamily(secondid,id,1,birth_Year,name,surname,relationship);
		 	break;
		 	case 3:
		 		if(head==NULL){
		 		printf("Resident List is empty");				 
		 		break;;
		 		}
		 		printf("Enter ID which you want to delete \n");
				 scanf("%d",&id);
				 DeleteResident(id);				 		
		 	break;
		 	case 4:
		 		printf("Enter Resident ID which you want to update \n");
				 scanf("%d",&id);
				 printf("Enter Family ID which you want to update \n");
				 scanf("%d",&secondid);
				 Update(id,secondid);		
		 	break;
		 	case 5:
		 		DisplayResident();
		 	break;
		 	case 6:
		 	printf("Enter resident id which you want to see family info \n");	
			 scanf("%d",&id);
			 BringResidentFamilyData(id);
			 break;
			 case 7:
			 open=0;
			 break;
			 default:
			 printf("Enter Valid Number\n");
			 break;				
		}
		if(open){
		printf("\nEnter a number for continue\n");
		scanf("%d",&secondid);
		clrscr();
		}
	}	
}
