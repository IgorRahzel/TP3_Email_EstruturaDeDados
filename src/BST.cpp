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

Email BST::Search(int id,int user_id){
    return _Search(root,id,user_id);
}

Email BST::_Search(Node* node, int id,int user_id){
    Email aux;

    if(node == NULL){
        aux.setID(-1);
        return aux;
    }
    if(id < node->email.getID())
        return _Search(node->left,id,user_id);
    else if(id > node->email.getID())
        return _Search(node->right,id,user_id);
    else{
        if(node->email.getUserID() == user_id)
            return node->email;
        else{
            aux.setID(-1);
            return aux;
        }
    }
    

}

bool BST::Remove(int id,int user_id) {
    return _Remove(root,id,user_id);
}

bool BST::_Remove(Node* &node, int id,int user_id){
    Node *aux;
    if (node == NULL) {
        return false;
        throw("Item nao está presente");
    }
    if (id < node->email.getID())
        return _Remove(node->left, id,user_id);
    else if (id>node->email.getID())
        return _Remove(node->right, id,user_id);
    else {
        if (node->right == NULL) {
            if(user_id == node->email.getUserID()){
                aux = node;
                node = node->left;
                free(aux);
                return true;
            }
            else
                return false;
        }
        else if(node->left == NULL) {
            if(user_id == node->email.getUserID()){
                aux = node;
                node = node->right;
                free(aux);
                return true;
            }
            else
                return false;
        }
        else
        if(user_id == node->email.getUserID()){
            _Ancestor(node, node->left);
            return true;
        }
        else
            return false;
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

