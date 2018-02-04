#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree{			
	char op[2];
	char name[20];	
	double  kcal;
	struct Tree* left;
	struct Tree* right;	
}Tree;


Tree* repto(struct Tree* root,double data,char* op,char* name){
		if(root==NULL){		
	  root=(Tree*)malloc(sizeof(struct Tree));
		root->left=NULL;
		root->right=NULL;
		root->kcal=data;	
		strcpy(root->op,op);
		strcpy(root->name,name);
		return root;
	}
	return root;
}

double  Sum(struct Tree* root){	

	
	if(root==NULL)
	return 1;	
	if(strcmp(root->op,"/")==0){		
	
		double value=Sum(root->left);	
		double value2=Sum(root->right);
		printf("4 person helva has %.3f calories\n",value+value2);
	 	double final=(value+value2)/4;				
		return final;
	}
	else if(strcmp(root->op,"*")==0){
		double value=Sum(root->left);	
		double value2=Sum(root->right);
		return value=value*value2;	
	}
	else if(strcmp(root->op,"+")==0){
		double value=Sum(root->left);	
		double value2=Sum(root->right);
		return value=value+value2;	
	}	
	else if(strcmp(root->op,"-")==0){
		if(root->kcal<10)
		printf("%s : %.2f X 100\n",root->name,root->kcal);
		else
		printf("%s : %.2f \n",root->name,root->kcal);
		return root->kcal;
	}	
}	

void draw_tree_hor2(struct Tree* tree, int depth, char *path, int right){
    if (tree== NULL)
        return;
    depth++;
    draw_tree_hor2(tree->right, depth, path, 1);
    path[depth-2] = 0;
    if(right)
        path[depth-2] = 1;
    if(tree->left)
        path[depth-1] = 1;
    printf("\n");
    int i;
	for(i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");
      
      int j;
	  for(j=1; j<5; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }
    if(strcmp(tree->op,"/")==0){
    	printf("@/@\n");
	}
else	if(tree->kcal==0){
    printf("@%s@\n",tree->op);
	}
    else{
    printf("%.3f\n" , tree->kcal);
	}
	for(i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");
		int j;
      for(j=1; j<5; j++)
          printf(" ");
    }
    draw_tree_hor2(tree->left, depth, path, 0);
}

void draw_tree_hor(struct Tree* tree){
    char path[255] = {};
    draw_tree_hor2(tree, 0, path, 0);
}

struct Tree * Prep(Tree* root){
Tree* iter=NULL;
root=repto(root,4,"/","Sum Kcal Divided 4 ");
iter=root->left;

iter=repto(iter,0,"*","Finding Flour");
root->left=iter;
iter=root->left->left;

iter=repto(iter,4,"-","Flour Amount");
root->left->left=iter;
iter=root->left->right;

iter=repto(iter,364,"-","Flour Kcal for 100 gr");
root->left->right=iter;
iter=root->right;

iter=repto(iter,0,"+","Butter and sugar");
root->right=iter;
iter=root->right->left;

iter=repto(iter,0,"*","Butter");
root->right->left=iter;
iter=root->right->left->left;

iter=repto(iter,2.5,"-","Butter Amount");
root->right->left->left=iter;
iter=root->right->left->right;

iter=repto(iter,716.8,"-","Butter Kcal For 100 gr");
root->right->left->right=iter;
iter=root->right->right;

iter=repto(iter,0,"*","Sugar");
root->right->right=iter;
iter=root->right->right->left;

iter=repto(iter,4,"-","Sugar Amount");
root->right->right->left=iter;
iter=root->right->right->right;

iter=repto(iter,388.9,"-","Sugar Kcal For 100gr");
root->right->right->right=iter;
return root;
}
int main(){
	
struct Tree* root=NULL;

root = Prep(root); 

double SumCal=Sum(root); 

printf("1 Person of Helva had   %.3f calories\n\n\n",SumCal);

draw_tree_hor(root); 
}
