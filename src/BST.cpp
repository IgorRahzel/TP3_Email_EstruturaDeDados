#include "BST.h"

BST::BST(){
    root = NULL;
};

void BST::Insert(Email email){
    _Insert(root,email);

}

void BST::_Insert(Node* &p, Email email){
    if(p==NULL){
        p = new Node(); 
        p->email = email;
    }
    else{
        if(email.getID() < p->email.getID())
            _Insert(p->left,email);
        else
            _Insert(p->right,email);
    }
}

Email BST::Search(int id){
    return _Search(root,id);
}

Email BST::_Search(Node* node, int id){
    Email aux;

    if(node == NULL){
        aux.setID(-1);
        return aux;
    }
    if(id < node->email.getID())
        return _Search(node->left,id);
    else if(id > node->email.getID())
        return _Search(node->right,id);
    else
        return node->email;

}

void BST::Remove(int id) {
    return _Remove(root,id);
}

void BST::_Remove(Node* &node, int id){
    Node *aux;
    if (node == NULL) {
        throw("Item nao está presente");
    }
    if (id < node->email.getID())
        return _Remove(node->left, id);
    else if (id>node->email.getID())
        return _Remove(node->right, id);
    else {
        if (node->right == NULL) {
            aux = node;
            node = node->left;
            free(aux);
        }
        else if(node->left == NULL) {
            aux = node;
            node = node->right;
            free(aux);
        }
        else
        _Ancestor(node, node->left);
    }
}

void BST::_Ancestor(Node* q, Node* &r){
    if(r->right != NULL) {
        _Ancestor(q, r->right);
        return;
    }
    
    q->email = r->email;
    q = r;
    r = r->left;
    free(q);
}

