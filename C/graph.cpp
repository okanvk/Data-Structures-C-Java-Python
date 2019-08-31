//Okan Çiftçi - Uðurcan Kök
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAX 10



int stack[MAX]; 
int top = -1; 
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
int vertexCount = 0;
int adjMatrix[MAX][MAX];



//Vertex Struct For hold data like label explosive value
struct Vertex {
   char label;
   int visited;
   int  expvalue;
};
struct Vertex* lstVertices[MAX];



//My randomvalue function generate random value


//Queue process
void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}
int removeData() {
   queueItemCount--;
   return queue[front++]; 
}
int isQueueEmpty() {
   return queueItemCount == 0;
}

//Stack Process
void push(int item) { 
   stack[++top] = item; 
} 
int pop() { 
   return stack[top--]; 
} 
int peek() {
   return stack[top];
}
int isStackEmpty() {
   return top == -1;
}

//Graph functions add vertex,display vertex,add edge
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
   printf("%c explosive value is : %d \n",lstVertices[vertexIndex]->label,lstVertices[vertexIndex]->expvalue);
}       
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = 0;     
   lstVertices[vertexCount++] = vertex;
}
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == 0) {
         return i;
      }
   }
         
   return -1;
}

int  randomvalue(){
	int value = ( rand() % (2 + 1 - 0)) + 0;
	return value;
}
//Search algorithms
void depthFirstSearch() {
   int i;
   lstVertices[0]->visited = 1;
   int random =randomvalue();
   lstVertices[0]->expvalue=random;
   displayVertex(0);   

   push(0);
   
   while(!isStackEmpty()) {
      int unvisitedVertex = getAdjUnvisitedVertex(peek());


      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = 1;
         random=randomvalue();
         lstVertices[unvisitedVertex]->expvalue=random;   
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = 0;     
	     }      
}
int breadthFirstSearch() {
   int i;

   lstVertices[0]->visited = 1;

   displayVertex(0);   

   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      int tempVertex = removeData();   

      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {    
         lstVertices[unvisitedVertex]->visited = 1;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);               
      }
		
   }   

   int sumexplosivevalue=0;      
   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = 0;
   	  sumexplosivevalue+=lstVertices[i]->expvalue;	
   }    
  	return sumexplosivevalue;
}
int main(){

 int i, j;

   for(i = 0; i<MAX; i++){ 
      for(j = 0; j<MAX; j++) 
         adjMatrix[i][j] = 0;
   }
   srand(time(NULL));
	//I Prepare my graph
    addVertex('A');
   addVertex('B');
   addVertex('C');
   addVertex('H');
   addVertex('E');
   addVertex('G');
   addVertex('F');
   addVertex('D');
   
   addEdge(0,1);
   addEdge(1,2);
   addEdge(1,3);
   addEdge(2,4);
   addEdge(2,7);
   addEdge(3,4);
   addEdge(4,5);
   addEdge(4,6);

   
	//Finally I determine explosive value
	int finalvalue;

	printf("Depth Search \n");
    depthFirstSearch(); 
	
	printf("--------------\n");
	
	printf("Breadth First Search \n");
	finalvalue=breadthFirstSearch();

	printf("\n --- Final Explosive value is : %d ---",finalvalue);

		
}


