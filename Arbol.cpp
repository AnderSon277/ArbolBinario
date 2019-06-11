#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;

};

Nodo *crearNodoPadreHijos(int n);

Nodo *arbolBinario=NULL;

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n);

void mostrarArbolBinario(Nodo *&arbolBinario, int separador);

void preOrden(Nodo *arbolBinario);

void inOrden(Nodo *arbolBinario);

void posOrden(Nodo *arbolBinario);

void menu();

void todo();

int main(){
	menu();
	todo();
    return 0;
}

void menu(){
	cout<<"\t ARBOL BINARIO"<<endl;
	cout<<"1. Insertar nodos en el arbol"<<endl;
	cout<<"2. Mostrar arbol completo"<<endl;
	cout<<"3. Recorrido Pre-Orden"<<endl;
	cout<<"4. Recorrido In-Orden"<<endl;
	cout<<"5. Recorrido Pos-Orden"<<endl;
	cout<<"0. Para salir"<<endl<<endl;
}

void todo(){
	int op,n,nodos;
	do{
		cout<<"Ingrese una la opciona a realizar:"<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Ingrese la cantidad de elementos en su arbol binario ";
    			cin>>nodos;
				for(int i=0;i<nodos;i++){
	        		cout<<"INSERTAR ELEMENTO => ";
	        		cin>>n;
	        		insertarNodosEnArbolBinario(arbolBinario,n);
	    		}
	    	break;
	    	case 2:
	    		cout<<"El arbol completo es:"<<endl;
	    		mostrarArbolBinario(arbolBinario,0);
	    	break;
	    	case 3:
	    		cout<<"Recorrido en Pre-Orden: "<<endl;
    			preOrden(arbolBinario);
    			cout<<endl;
    		break;
    		case 4:
	    		cout<<"Recorrido en In-Orden: "<<endl;
    			inOrden(arbolBinario);
    			cout<<endl;
    		break;
    		case 5:
	    		cout<<"Recorrido en Pos-Orden: "<<endl;
    			posOrden(arbolBinario);
    			cout<<endl;
    		break;
	    		
		}
	}while(op!=0);
}

Nodo *crearNodoPadreHijos(int n){
    Nodo *nuevo = new Nodo();
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;
    
    return nuevo;
}

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n){
    if(arbolBinario==NULL)
    {
        Nodo *nuevo =crearNodoPadreHijos(n);
        arbolBinario=nuevo;
    }
    else{
        int datoRaiz=arbolBinario->dato;
        if(n<datoRaiz)
        {
            insertarNodosEnArbolBinario(arbolBinario->izquierdo, n);
        }
        else
        {
            insertarNodosEnArbolBinario(arbolBinario->derecho, n);
        }
    }

}

void mostrarArbolBinario(Nodo *&arbolBinario, int separador){
    if(arbolBinario==NULL)
    {
        return;
    }
    else
    {
        mostrarArbolBinario(arbolBinario->derecho, separador+1);
        for(int i=0;i<=separador;i++)
        {
            cout<<"   ";
        }
        cout<<arbolBinario->dato<<endl;
        mostrarArbolBinario(arbolBinario->izquierdo, separador+1);
    }
}

void preOrden(Nodo *arbolBinario){
	if(arbolBinario==NULL){
		return;
	}
	else{
		cout<<arbolBinario->dato<<"-";
		preOrden(arbolBinario->izquierdo);
		preOrden(arbolBinario->derecho);
	}
}

void inOrden(Nodo *arbolBinario){
	if(arbolBinario==NULL){
		return;
	}
	else{
		inOrden(arbolBinario->izquierdo);
		cout<<arbolBinario->dato<<"-";
		inOrden(arbolBinario->derecho);
	}
}

void posOrden(Nodo *arbolBinario){
	if(arbolBinario==NULL){
		return;
	}
	else{
		posOrden(arbolBinario->izquierdo);
		posOrden(arbolBinario->derecho);
		cout<<arbolBinario->dato<<"-";
	}
}
