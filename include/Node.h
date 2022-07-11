#ifndef NODE_H
#define NODE_H
#include "Email.h"

class Node{
    private:
        int Node_ID;
        Email email; 
        Node* left;
        Node* right;

        friend class BST;
    
    public:
        Node();

};

#endif 
