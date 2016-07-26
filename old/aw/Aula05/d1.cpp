#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
//é como se fosse um corredor cheio de sala
//e cada sala tivesse cheia de carteira
//e cada carteira cheia de aluno um em cima do outro
class caixa{
	public:
	int valor;
	caixa *dir;
	caixa *esq;
	caixa();

};
caixa::caixa(){
	valor = 0;
	dir = NULL;
	esq = NULL;
}
class pilha{
	private:
	int qtd;
	caixa *inicio;
	caixa *fim;
	public:
	pilha();
	~pilha();
	int retornaQtd();
	void add(int x);
	void remover();
	void imprimir();
};
pilha::pilha(){
	qtd=0;
	inicio = NULL;
	fim = NULL;
}
int pilha::retornaQtd(){
	return qtd;
}
pilha::~pilha(){
	caixa *aux = fim;
	while(qtd!=0){
		remover();
	}
}
void pilha::add(int x){
	caixa *aux = new caixa();
	aux->valor = x;
	aux->dir=NULL;
	aux->esq=NULL;
	if(qtd==0){
		inicio = aux;
		fim = aux;
	}
	else{
		fim->dir = aux;
		aux->esq = fim;
		fim = aux;
	}
	qtd++;
}
void pilha::remover(){
	//cout<<"cheguei";
	//system("pause");
	caixa *aux = fim;
    if(qtd!=0){
        if(qtd==1){
        	//cout<<"qtd == 1    "<<qtd;
        	//system("pause");
            inicio = NULL;
            fim = NULL;
            //cout<<"aterrei";
            //system("pause");
        }else{
        	//cout<<"qtd!=1";
        	//system("pause");
            fim = fim->esq;
            fim->dir = NULL;
        }
        qtd--;
        //system("pause");
        //cout<<aux->valor;
        delete aux;
        //cout<<"deletei";
        //system("pause");
    }
}
void pilha::imprimir(){
	caixa *aux = fim;
	int i;
	//int i=0;
	cout<<"Pilha "<<endl;
	while(aux!=NULL){

		cout<<aux->valor<<endl;
		aux = aux->esq;
		i--;
	}

}
//pilha normal


class caixaFila{//cria pilhas
	public:
		caixaFila *ant;
		caixaFila *prox;
		class pilha pilha;
		caixaFila();
};
caixaFila::caixaFila(){
	ant = NULL;
	prox = NULL;
}
class fila{
	private:
		int qtd;
		int qtdPilhas;
		caixaFila *primeira;
		caixaFila *ultima;
	public:
		fila();
		~fila();
		void add(int x);
		void remover();
		void imprimir();
		int retornaqtdpilha();
};
int fila::retornaqtdpilha(){
    return qtdPilhas;
}
fila::fila(){
	qtd=0;
	qtdPilhas = 0;
	primeira = NULL;
	ultima = NULL;
}
fila::~fila(){
	caixaFila *aux = primeira;
	while(aux !=NULL){
		primeira->pilha.remover();
	}
}
void fila::remover(){
	if((qtd-1)%7==0){
		//cout<<"entrei 2";
		//system("pause");
        caixaFila *aux = primeira;
	    qtdPilhas--;
        qtd--;
        if(primeira->prox!=NULL){
			primeira=primeira->prox;
       		primeira->ant=NULL;
    	}else{
    		primeira=NULL;
    		ultima=NULL;
		}
        aux->pilha.remover();
        
	}else{
        //senao remove a fila
        if(qtd!=0){
            caixaFila *aux;
            aux=primeira;
            aux->pilha.remover();
            //primeira=aux->prox;
            //delete aux;
            qtd--;
        }else{
            cout<<"SEM ELEMENTOS";//so para evitar bugs, não é necessario essa condção de !=0
        }
	}

}
void fila::add(int x){
	if(qtd==49){
		cout<<"ESTA LOTADA\n";
		system("pause");
	}
	else{

		if(qtd==0){
			caixaFila *aux = new caixaFila();
			qtdPilhas++;
			aux->pilha.add(x);
			primeira = aux;
			ultima = aux;
		}
		else{
			if(qtd%7==0){
				caixaFila *aux = new caixaFila();
				qtdPilhas++;
				aux->pilha.add(x);
				aux->ant = ultima;
				ultima->prox = aux;
				ultima = aux;
			}
			else{
				caixaFila *aux = ultima;
				aux->pilha.add(x);
			}
		}
		qtd++;
	}
}
void fila::imprimir(){
	int i = 0;
	caixaFila *aux = ultima;
	cout<<"Fila "<<endl;
	while(aux!=NULL){


		aux->pilha.imprimir();
		aux = aux->ant;
		i++;
	}

}
//fila


class caixaPilha{//cria filas
	public:
		caixaPilha *Fant;
		caixaPilha *Fprox;
		class fila fila;
		caixaPilha();
};
caixaPilha::caixaPilha(){
	Fant=NULL;
	Fprox=NULL;
}
class pilhaStruct{
	private:
		int qtdF;
		int qtd;
		caixaPilha *ultima;
		caixaPilha *primeira;
		caixaPilha *up;
		caixaPilha *donw;
	public:
		pilhaStruct();
		~pilhaStruct();
		void add(int x);
		void remover();
		void imprimir();
};
pilhaStruct::pilhaStruct(){
    qtdF=0;
    qtd=0;
    ultima=NULL;
    primeira=NULL;
    up=NULL;
    donw=NULL;
}
pilhaStruct::~pilhaStruct(){
    caixaPilha *aux = primeira;
	while(aux !=NULL){
		primeira->fila.remover();
	}

}
void pilhaStruct::imprimir(){
	caixaPilha *aux = ultima;
	//i=qtd;
	//int i = qtdF;
	if(qtd!=0){
		cout<<"Pilha de cima: "<<endl;
		while(aux!=NULL){
			aux->fila.imprimir();
			aux=aux->Fant;
		}
	}else{
		cout<<"VAZIO!";
	}	
}
void pilhaStruct::remover(){
	if((qtd-1)%7*7==0){
        caixaPilha *aux = ultima;
        //cout<<"entrei 1";
        //system("pause");
        //caixaFila *aux2 = ultima;
	    qtdF--;
	    qtd--; 
		if(ultima->Fant!=NULL){
			ultima=ultima->Fant;
			ultima->Fprox=NULL;
		}else{
			ultima=NULL;
			primeira=NULL;
		}

        		
		//cout<<"cheguei aui";
		//system("pause");
        aux->fila.remover();

        //delete aux;
	}else{
        //remove a pilha
        if(qtd!=0){
            caixaPilha *aux;
            aux=ultima;
            aux->fila.remover();

            //ultima=aux->Fant;
            //ultima->Fprox=NULL;
            //delete aux;
            qtd--;
        }else{
            cout<<"SEM ELEMENTOS!";
        }
	}
}
void pilhaStruct::add(int x){
	if(qtd==49*7){
		cout<<"ESTA LOTADA\n";
		system("pause");
	}
	else{

		if(qtd==0){
			caixaPilha *aux = new caixaPilha();
			qtdF++;
			aux->fila.add(x);
			primeira = aux;
			ultima = aux;
		}
		else{
			if(qtd%7==0){
				caixaPilha *aux = new caixaPilha();
				qtdF++;
				aux->fila.add(x);
				aux->Fant = ultima;
				ultima->Fprox = aux;
				ultima = aux;
			}
			else{
				caixaPilha *aux = ultima;
				aux->fila.add(x);
			}
		}

		qtd++;
	}
}


//pilhaStruct




int main(){
    pilhaStruct pilhaStruct;
	fila fila;
	pilha pilha;
	int x = 0;
	int op = 0;
	while(1){
		system("cls");
		cout<<"Digite uma opcao:\n1-Adicionar\n2-Remover\n3-Imprimir\n4-Sair\n";
		cin>>op;
		if(op==1){
		    int x=0;
			cout<<"Digite o valor de entrada: \n";
			cin>>x;
			//int i=1;
			//while(i<50){
				pilhaStruct.add(x);
				//i++;
			//}
			//fila.add(x);

		}
		if(op==2){
			/*
			int i=1;
			while(i<50){
				fila.remover();
				i++;
			}*/

			pilhaStruct.remover();
		}
		if(op==3){
			pilhaStruct.imprimir();
			system("pause");
		}
		if(op==4){
			break;
		}
	}
}

