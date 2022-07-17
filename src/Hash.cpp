//---------------------------------------------------------------------
// Arquivo      : Hash.cpp
// Conteudo     : Implementacao dos metodos da Tabela Hash
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#include "Hash.h"

Hash::Hash(){

}

/*aloca vetor de Arvores Binarias de Pesquisa*/
void Hash::Build(int size){
    array = new BST[size];
    this->size = size;
}

/*pesquisa mensagem*/
Email Hash::Search(int user_id,int mail_id){

    int pos;
    Email email;

    pos = Hash_function(user_id);
    email = array[pos].Search(mail_id,user_id);
    return email;
}

/*insere email*/
void Hash::Insert(Email email){
    Email aux;
    int pos;

    aux = Search(email.getUserID(),email.getID());
    if(!aux.isEmpty())
    throw("Erro: Item já está presente");

    pos = Hash_function(email.getUserID());
    array[pos].Insert(email);

    
}
/*deleta email*/
bool Hash::Remove(int user_id,int mail_id){
    bool aux;

    int pos =  Hash_function(user_id);
    aux = array[pos].Remove(mail_id,user_id);

    return aux;
}
/*mapeia os emails para posicoes na tabela Hash*/
int Hash::Hash_function(int id){

    return id % size;
}