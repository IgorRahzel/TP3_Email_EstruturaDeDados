//---------------------------------------------------------------------
// Arquivo      : Hash.h
// Conteudo     : Cabeçalho da classe Hash
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#ifndef HASH_H
#define HASH_H
#include "BST.h"

class Hash{
    private:
        int size;
        BST* array;
        int Hash_function(int id);
    public:
        Hash();
        void Build(int size);
        Email Search(int user_id,int mail_id);
        void Insert(Email email);
        bool Remove(int user_id,int mail_id);
};

#endif
