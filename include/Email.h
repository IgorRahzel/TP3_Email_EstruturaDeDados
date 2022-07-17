//---------------------------------------------------------------------
// Arquivo      : Email.h
// Conteudo     : Cabeçalho da classe Email
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#ifndef EMAIL_H
#define EMAIL_H
#include <iostream>
#include <string>

using namespace std;

class Email{
    private:
        int id;
        int user_id;
        string msg;
    public:
        int getID();
        void setID(int id);
        int getUserID();
        void setUserID(int user_id);
        void setMSG(string msg);
        string getMSG();
        bool isEmpty();
        Email();
};
#endif