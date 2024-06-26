//---------------------------------------------------------------------
// Arquivo      : BST.h
// Conteudo     : Implementacao dos metodos da Arvore Binaria de Pesquisa
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#include "BST.h"

BST::BST(){
    root = NULL;
};

/*inserir email na Arvore Binaria de Pesquisa*/
void BST::Insert(Email email){
    _Insert(root,email);

}

void BST::_Insert(Node* &p, Email email){
    if(p==NULL){    /*insere nó em um nó folha */
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

/*pesquisar email na Arvore Binaria de Pesquisa*/
Email BST::Search(int id,int user_id){
    return _Search(root,id,user_id);
}

Email BST::_Search(Node* node, int id,int user_id){
    Email aux;

    if(node == NULL){
        aux.setID(-1); /*flag para email não encontrado*/
        return aux;
    }
    if(id < node->email.getID())
        return _Search(node->left,id,user_id);
    else if(id > node->email.getID())
        return _Search(node->right,id,user_id);
    else{
        if(node->email.getUserID() == user_id) /*verificar se email pertence ao usuario*/
            return node->email;
        else{
            aux.setID(-1);
            return aux;
        }
    }
    

}

/*remover email da Arvore Binaria de Pesquisa*/
bool BST::Remove(int id,int user_id) {
    return _Remove(root,id,user_id);
}

bool BST::_Remove(Node* &node, int id,int user_id){
    Node *aux;
    if (node == NULL) {
        return false; /*email nao encontrado*/
    }
    if (id < node->email.getID())
        return _Remove(node->left, id,user_id);
    else if (id>node->email.getID())
        return _Remove(node->right, id,user_id);
    else {
        if (node->right == NULL) { /*no so tem filho da esquerda*/
            if(user_id == node->email.getUserID()){
                aux = node;
                node = node->left;
                free(aux);
                return true;
            }
            else
                return false;
        }
        else if(node->left == NULL) { /*no so tem filho da direita*/
            if(user_id == node->email.getUserID()){
                aux = node;
                node = node->right;
                free(aux);
                return true;
            }
            else
                return false;
        }
        else /*no tem dois filhos*/
        if(user_id == node->email.getUserID()){
            _Ancestor(node, node->left);
            return true;
        }
        else
            return false;
    }
}

/*auxilia na remocao de nó com dois filhos*/
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

