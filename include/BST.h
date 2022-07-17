//---------------------------------------------------------------------
// Arquivo      : BST.h
// Conteudo     : Cabeçalho da classe de Arvore Binaria de Pesquisa
//                  -Assinatura dos metodos de insercao,pesquisa e remocao
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#ifndef BST_H
#define BST_H
#include "Email.h"
#include "Node.h"

class BST{
    private:
        void _Insert(Node* &p, Email email);
        Email _Search(Node* p, int id,int user_id);
        bool _Remove(Node* &p, int id,int user_id);
        void _Ancestor(Node* q, Node* &r);
        Node* root;
    public:
        BST();
        void Insert(Email email);
        Email Search(int id,int user_id);
        bool Remove(int id,int user_id);
        
        
};

#endif