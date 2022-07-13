#include "Hash.h"
#include <fstream>
#include <getopt.h>

int main(int argc,char **argv){

    fstream file;
    fstream file2;

    string input_file; 
    string output_file; 
    string input;
    string input_aux;
    int option_val; /*utilizado para ler parametros da linha de comando*/

    int size;
    Hash hash;

    Email aux;
    Email check;
    int user_id;
    int mail_id;
    int msg_size;

    while((option_val = getopt(argc,argv,"i:o:"))!= -1){
        switch (option_val)
        {
        case 'i':
            input_file = optarg;
            break;
        case 'o':
            output_file = optarg;
            break;
        default:
            break;
        }
    }


    file2.open(output_file,ios::out);
    

    

    //cout<< input_file << " " << output_file << endl;
    file.open(input_file,ios::in);
    if(file.is_open() && file2.is_open()){
        file >> size;
        //cout << size << endl;
        hash.Build(size);
        while(file >> input){
            if (input.compare("ENTREGA")==0)
            {
                file >> user_id >> mail_id >> msg_size;
                aux.setUserID(user_id);
                aux.setID(mail_id);

                for (int i = 0; i < msg_size; i++)
                {
                    file >> input;
                    input_aux +=input;
                    if(i<msg_size-1){
                        input_aux += " ";
                    }
                    
                }
                aux.setMSG(input_aux);
                hash.Insert(aux);
                input_aux.clear();
                file2 << "OK: MENSAGEM " << mail_id << " PARA " << user_id  << " ARMAZENADA EM " << user_id % size << endl;
            }
            else if (input.compare("CONSULTA")==0)
            {
                file >> user_id >> mail_id;
                check = hash.Search(user_id,mail_id);
                file2 << "CONSULTA " << user_id << " "<<mail_id << ": " << check.getMSG() << endl;
            }
            else if (input.compare("APAGA")==0)
            {
                file >> user_id >> mail_id;
                hash.Remove(user_id,mail_id);
                file2 << "OK: MENSAGEM APAGADA" << endl;
            }
            
        }
    }
    file.close();

    return 0;
}
