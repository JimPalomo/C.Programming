// Prints Linklist & counts Nodes

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_struct {
 int values[5];
 int sum;
 int max;
 struct Node_struct* next;
} Node;

int countNodes(Node* myNode){
   // Sets count to 1 with the head node accounted for
   int count = 1;
   
   // Traverses the linked list by starting at the head node 
   Node* currNode = myNode;
   
   // Linked list is traversed and nodes are counted through the use of an increment count variable
   while(currNode->next != NULL) {
      count++;
      currNode = currNode -> next;
   }
   
   return count;
}

void Node_PrintList(Node* myNode){
   Node* currHead = myNode;
    
   while (currHead != NULL){
      printf("%d\n", currHead->sum);
      currHead = currHead->next;
   }
    
   printf("\n");
}


int main() {
 Node* myNode = (Node*)malloc(sizeof(Node));
 myNode->next = (Node*)malloc(sizeof(Node));
 myNode->next->next = (Node*)malloc(sizeof(Node));
 myNode->next->next->next = (Node*)malloc(sizeof(Node));
 myNode->next->next->next->next = NULL;

myNode->next->values[3] = 3;
myNode->sum = 7;
Node_PrintList(myNode);

printf("%d", countNodes(myNode));

 return 0;
}
