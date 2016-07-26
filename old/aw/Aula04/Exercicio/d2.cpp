#include <iostream>
#include <cstdlib>
using namespace std;
class caixa {
	public:
		int valor;
		caixa *dir;
};
class fila {
	private: 
		int qtd;
		caixa *inicio;
		caixa *fim;
	public:
		fila();
		~fila();
		void add (int x);
		void remover ();
		void print ();		
};
fila::fila(){
	qtd=0;
	inicio=NULL;
	fim=NULL;
}
fila::~fila(){ 
	while(qtd!=0){
		//remover();
	}
}
void fila::add(int x){
	caixa *aux = new caixa();
	aux->valor=x;
	aux->dir=NULL;
	if(qtd==0){
		inicio=aux;
		fim=aux;
	}
	else{
		fim->dir=aux;
		fim=aux;
	}
	qtd++;
}
void fila::print(){
	caixa *aux;
	aux=inicio;
	while(aux!=NULL){
		cout<<aux->valor<<" | ";
		aux=aux->dir;
	}
	cout<<endl;
}
//fila

class no{
	public:
		int valor;
		no *dir;
		no *esq;
		class fila fila;
		no();
};
no::no(){
	valor=0;
	dir=NULL;
	esq=NULL;
}
class arvore{
	private:
		int qtd;
		no *last;
	public:
		no *raiz;
		arvore();
		~arvore();
		void add(int x);
		void remover(int x);
		void print_();
		void print(no *nodo);	
};
arvore::arvore(){
	qtd=0;
	raiz=NULL;
}
arvore::~arvore(){
	
	
}
//arvore


void arvore::add(int x){
	//cout<<qtd;
	//system("pause");
	if(qtd==0 || qtd%7==0){
		//cout<<"\nENTREI\n";
		no *aux=new no;
		last=aux;
		int y=x*7;
		aux->valor=y;
		if(qtd==0){
			raiz=aux;
		}
		else{
			no *anterior=NULL;
			no *aux2=raiz;
			while(aux2!=NULL){
				anterior=aux2;
				if(y>aux2->valor){
					
					aux2=aux->dir;
				}
				else{
					aux2=aux2->esq;
				}
			}
			if(y>anterior->valor){
				//cout<<"\nADD A DIREITA DO "<<anterior->valor<<endl;
				anterior->dir=aux;
			}
			else{
				anterior->esq=aux;
				//cout<<"\nADD A ESQUERDA DO "<<anterior->valor<<endl;
			}	
		}	
	}

	last->fila.add(x);	
	qtd++;	
	//cout<<"qtd: "<<qtd<<endl;
	//system("pause");
}
void arvore::print(no *nodo){
	if(nodo!=NULL){
		//cout<<"entrei";
		print(nodo->esq);
		cout<<nodo->valor<<" -> ";
		//cout<<"fila"<<endl;
		nodo->fila.print();
		print(nodo->dir);
	}
	//system("pause");
}
void arvore::print_(){
	print(raiz);
}


main(){
	arvore arvore;
	int choice=0;
	while(1){
		cout<<"Escolha uma funcao: "<<endl;
		cout<<"1 - Adicionar"<<endl;
		cout<<"2 - Remover (nao tem)"<<endl;
		cout<<"3 - Imprimir"<<endl;
		cout<<"4 - Sair"<<endl;
		fflush(stdin);
		cin>>choice;
		if(choice==1){
			system("cls");
			cout<<"Digite um numero para adicionar: ";
			int x;
			cin>>x;
			arvore.add(x);
			system("cls");
		}else{
			if(choice==2){
				system("cls");
				//arvore.remover();
				system("cls");
			}else{
				if(choice==3){
					system("cls");
					//system("pause");
					arvore.print_();
					system("pause");
					system("cls");
				}else{
					if(choice==4){
						exit(1);
					}else{
						cout<<"Opção invalida";
						system("cls");
					}
				}
			}
		}
		
		
	}
	/*switch(choice){
		case 1:
			system("cls");
			cout<<"Digite um numero para adicionar: ";
			int x;
			cin>>x;
			arvore.add(x);
			system("cls");
			main();
		case 2:
			system("cls");
			//arvore.remover();
			system("cls");
			main();
		case 3:
			system("cls");
			system("pause");
			arvore.print_();
			system("cls");
			main();
		case 4:
			exit(1);
		default:
			system("cls");
			cout<<"Opcao invalida!"<<endl;
			system("cls");
			main();			
	}*/
	
	//system("pause");
}

