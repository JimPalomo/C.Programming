// Gets max value of link list

int setMaxes(Node* myNode) {
    int max = myNode->value;
    
    Node* currNode = myNode;
    
    while(currNode->next != NULL) {
        if(currNode-> value > max) {
            max = currNode-> value;
       
        } 
        currNode = currNode-> next;
       
    }
    return max;
}
