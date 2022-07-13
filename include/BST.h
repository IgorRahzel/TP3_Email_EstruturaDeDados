#ifndef BST_H
#define BST_H
#include "Email.h"
#include "Node.h"

class BST{
    private:
        void _Insert(Node* &p, Email email);
        Email _Search(Node* p, int id);
        bool _Remove(Node* &p, int id);
        void _Ancestor(Node* q, Node* &r);
        Node* root;
    public:
        BST();
        void Insert(Email email);
        Email Search(int id);
        bool Remove(int id);
        
        
};

#endif