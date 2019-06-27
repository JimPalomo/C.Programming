// Gets max value[i] of link list

int setMaxes(Node* myNode) {
    int max = 0;
    
    Node* currNode = myNode;
    
    while(currNode->next != NULL) {
        
        for(int i = 0; i < 5; i++) {
            if(currNode-> value[i] > max) {
                max = currNode-> value[i]; 
            } 
            currNode = currNode-> next;
        }
    }
    return max;
}
