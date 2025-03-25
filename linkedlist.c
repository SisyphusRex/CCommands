#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
} IntNode;

// Constructor
void IntNode_Create
(IntNode* thisNode, int dataInit, IntNode* nextLoc) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = nextLoc;
}

/* Insert newNode after node.
 Before: thisNode -- next
 After:  thisNode -- newNode -- next
 */
void IntNode_InsertAfter
(IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;
   
   tmpNext = thisNode->nextNodePtr; // Remember next
   thisNode->nextNodePtr = newNode; // this -- new -- ?
   newNode->nextNodePtr = tmpNext;  // this -- new -- next
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
   printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

/* ******** New functions ********/

// Return the length of the list
int IntNode_Length(IntNode* firstNode) {
   int length = 0;
   IntNode* currentNode = firstNode;
   while(currentNode != NULL) {
      ++length;
      currentNode = currentNode->nextNodePtr;
   }

   return length;
}

// Return the Nth element of the list. First node is 1.
IntNode* IntNode_GetNth(IntNode* firstNode, int pos) {
   /* Type your code here. */
   int count = 1;
   IntNode* currentNode = firstNode;
   while (count != pos) {
    currentNode = currentNode->nextNodePtr;
    count++;
   }
   return currentNode;
}

// Print the entire list starting at firstNode
void IntNode_PrintList(IntNode* firstNode) {
   /* Type your code here. */
   IntNode* currentNode = firstNode;
   while (currentNode != NULL) {
    printf("%d ", currentNode->dataVal);
    currentNode = currentNode->nextNodePtr;
   }
}

// Sum the numbers in the list
int IntNode_SumList(IntNode* firstNode) {
   /* Type your code here. */
   IntNode* currentNode = firstNode;
   int sum = 0;
   while (currentNode != NULL) {
    sum += currentNode->dataVal;
    currentNode = currentNode->nextNodePtr;
   }
   return sum;
}

int main(void) {
   IntNode* headObj  = NULL; // Create IntNode objects
   IntNode* nodeObj1 = NULL;
   IntNode* nodeObj2 = NULL;
   IntNode* nodeObj3 = NULL;
   IntNode* currObj  = NULL;
   
   // Front of nodes list
   headObj = (IntNode*)malloc(sizeof(IntNode));
   IntNode_Create(headObj, -1, NULL);
   
   // Insert nodes
   nodeObj1 = (IntNode*)malloc(sizeof(IntNode));
   IntNode_Create(nodeObj1, 555, NULL);
   IntNode_InsertAfter(headObj, nodeObj1);
   
   nodeObj2 = (IntNode*)malloc(sizeof(IntNode));
   IntNode_Create(nodeObj2, 999, NULL);
   IntNode_InsertAfter(nodeObj1, nodeObj2);
   
   nodeObj3 = (IntNode*)malloc(sizeof(IntNode));
   IntNode_Create(nodeObj3, 777, NULL);
   IntNode_InsertAfter(nodeObj1, nodeObj3);
   
   // Print linked list
   currObj = headObj;
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }
   
   return 0;
}
