#include "Hash.h"

Hash::Hash(){

}

void Hash::Build(int size){
    array = new BST[size];
    this->size = size;
}

Email Hash::Search(int user_id,int mail_id){

    int pos;
    Email email;

    pos = Hash_function(user_id);
    email = array[pos].Search(mail_id);
    return email;
}

void Hash::Insert(Email email){
    Email aux;
    int pos;

    aux = Search(email.getUserID(),email.getID());
    if(!aux.isEmpty())
    throw("Erro: Item já está presente");

    pos = Hash_function(email.getUserID());
    array[pos].Insert(email);

    
}

void Hash::Remove(int user_id,int mail_id){
    
    int pos =  Hash_function(user_id);
    array[pos].Remove(mail_id);

}

int Hash::Hash_function(int id){

    return id % size;
}