#include <iostream>
#include <iomanip>
#include "Pilha.h"
using namespace std;

no *iniTorre1(no *p, int x){

    for(int i = x; i>=1; i--){
        p = PUSH(p, i);
    }
    return (p);

}

void situacaoTorres(no *p1, no *p2, no *p3){

    no *a1, *a2, *a3;
	a1 = p1;
    a2 = p2;
    a3 = p3;	
	
    cout << "Torre 1 \t Torre 2 \t Torre 3" << endl;
	while(a1 != NULL || a2 != NULL || a3 != NULL) {

        if(a1!=NULL){
            cout << setw(4) << a1->info << " \t ";
            a1 = a1->link; 
        }
        else{
            cout << "\t ";
        }
        if(a2!=NULL){
            cout << "\t " << setw(4) << a2->info << " \t ";
            a2 = a2->link;
        }
        else{
            cout <<  " \t " <<  " \t ";
        }
        if(a3!=NULL){
            cout << " \t " << setw(4) << a3->info;
            a3 = a3->link;
        }
        else{
            cout << " \t " << " \t ";
        }
        cout << endl;

	}
}

bool venceu(no *p, int x){

    int i = 0;
    no * aux;
    aux = p;
    while(aux!=NULL){
        i++;
        aux = aux->link;
    }
    if(i==x) return true;
    else return false;

}

int main(){

    cout << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "------------------------------ TORRE DE HANOI ------------------------------" << endl;
    cout << endl;

    no *torres[3];
    int discos, torreIni, torreFini, aux, movimentos = 0;

    torres[0] = inicializaPilha(torres[0]);
    torres[1] = inicializaPilha(torres[1]);
    torres[2] = inicializaPilha(torres[2]);

    cout << "Digite a quantidade de discos: ";
    cin >> discos;
    cout << "QUE OS JOGOS COMECEM!!" << endl;
    cout << endl;
    torres[0] = iniTorre1(torres[0], discos);

    while(1){

        cout << "Estado das torres: " << endl;
        cout << endl;
        situacaoTorres(torres[0], torres[1], torres[2]);
        cout << endl;

        cout << "Selecione a torre da qual deseja mover o disco(1, 2 ou 3): ";
        cin >> torreIni;
        cout << "Selecione a torre para qual deseja mover o disco(1, 2 ou 3): ";
        cin >> torreFini;
        cout << endl;

        if(torres[torreIni-1]!=NULL && torres[torreFini-1]!=NULL){

            if(torres[torreFini-1]->info<torres[torreIni-1]->info){
                cout << "Movimento invalido!" << endl;
                movimentos--;
            }

            else{
                torres[torreIni-1] = POP(torres[torreIni-1], &aux);
                torres[torreFini-1] = PUSH(torres[torreFini-1], aux);
            }

        }
        else{

            torres[torreIni-1] = POP(torres[torreIni-1], &aux);
            if(aux==0){
                cout << "Erro, torre vazia!" << endl;
                movimentos--;
            }
            else torres[torreFini-1] = PUSH(torres[torreFini-1], aux);

        }

        movimentos++;
        cout << "MOVIMENTOS: " << movimentos << endl;
        cout << endl;

        if(venceu(torres[2], discos) || venceu(torres[1], discos)){

            cout << "----------------------- PARABENS, VOCE VENCEU ----------------------" << endl;
            cout << "Jogo vencido em: " << movimentos << " movimentos!" << endl;
            cout << "Estado final das torres: " << endl;
            situacaoTorres(torres[0], torres[1], torres[2]);
            break;
            
        }

    }
}