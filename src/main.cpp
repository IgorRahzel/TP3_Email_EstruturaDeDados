//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : arquivo principal do projeto
// Autor        : Igor Rahzel Colares Galdino (igorrahzel@ufmg.br)
//---------------------------------------------------------------------

#include "Hash.h"
#include <fstream>
#include <getopt.h>

int main(int argc,char **argv){

    fstream file; /*ler arquivo de entrada*/
    fstream file2; /*escrever no arquivo de saida*/

    string input_file; /*nome do arquivo de entrada*/
    string output_file; /*nome do arquivo de saida*/
    
    string input; /*ler dados do arquivo*/
    string input_aux; /*ler partes da mensagem enviada*/

    int option_val; /*utilizado para ler parametros da linha de comando*/

    int size; /*tamanho da tabela Hash*/
    Hash hash; 

    Email aux; /*utilizado para inserir email na tabela Hash*/
    Email check; /*verificar se email existe*/
    int user_id;
    int mail_id;
    int msg_size;

    bool msg_deleted;

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


    file2.open(output_file,ios::out); /*abre arquivo de saida*/
    

    file.open(input_file,ios::in); /*abre arquivo de entrada*/
    if(file.is_open() && file2.is_open()){
        file >> size;
        hash.Build(size);
        while(file >> input){
            if (input.compare("ENTREGA")==0) /*insere email na tabela*/
            {
                file >> user_id >> mail_id >> msg_size;
                aux.setUserID(user_id);
                aux.setID(mail_id);

                for (int i = 0; i < msg_size; i++) /*ler palavras da mensagem*/
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
            else if (input.compare("CONSULTA")==0) /*pesquisa email na tabela*/
            {
                file >> user_id >> mail_id;
                check = hash.Search(user_id,mail_id);
                if(check.getID() == -1){
                    file2 << "CONSULTA " << user_id << " " << mail_id <<": MENSAGEM INEXISTENTE" << endl;
                }
                else{
                    file2 << "CONSULTA " << user_id << " "<<mail_id << ": " << check.getMSG() << endl;
                }
            }
            else if (input.compare("APAGA")==0) /*remove email da tabela*/
            {
                file >> user_id >> mail_id;
                msg_deleted = hash.Remove(user_id,mail_id);
                if(msg_deleted == true){
                    file2 << "OK: MENSAGEM APAGADA" << endl;
                }
                else{
                    file2 << "ERRO: MENSAGEM INEXISTENTE" << endl;
                }
            }
            
        }
    }
    file.close();

    return 0;
}
