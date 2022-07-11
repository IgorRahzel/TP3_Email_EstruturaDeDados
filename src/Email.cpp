#include "Email.h"

Email::Email(){}

int Email::getID(){
    return id;
}

void Email::setID(int id){
    this->id = id;
}

void Email::setMSG(string msg){
    this->msg = msg;
}

string Email::getMSG(){
    return msg;
}

int Email::getUserID(){
    return user_id;
}

void Email::setUserID(int user_id){
    this->user_id = user_id;
}


bool Email::isEmpty(){
    if(id == -1)
        return true;
    else
        return false;
}