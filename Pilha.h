using namespace std;
struct no {
	int info;
	no *link;
};

no *inicializaPilha(no *L) {
	return NULL;
}

void imprimePilha(no *L) {
	no *P;
	P = L;	
	
	while(P != NULL) {
		cout << P->info << " ";
		P = P->link;
	}
	cout << endl;	
}

no *PUSH(no *L, int x) {
	no *N;
	N = new no;
	N->info = x;
    N->link = L;
	L = N;
	return (L);
}


no *POP(no *L, int *n) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		AUX = L;
		L = L->link;
		delete AUX;
	}
	else{
		*n = 0;
	}
	return (L);
}

int TamanhoPilha(no *L){
	no *P;
	int x = 0;
	P = L;
	while(P!=NULL){
		x++;
		P = P->link;
	}
	return x;
}

void imprimeTopo(no *L) {
	
	printf("\n Imprime TOPO: \n");	
	cout << L->info << endl;
}
