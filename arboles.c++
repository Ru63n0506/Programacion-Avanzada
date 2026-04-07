#include <iostream>

using namespace std;

struct Nodo 
{
    int dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int dato) 
{
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}   

Nodo* insertar(Nodo* raiz, int dato) 
{
    if(raiz == NULL)
    {
        return crearNodo(dato);
    }

    if(dato < raiz->dato)
    {
        raiz->izq = insertar(raiz->izq, dato);
    }
    else if (dato > raiz->dato)
    {
        raiz->der = insertar(raiz->der, dato);
    }

    return raiz;
}

int buscar(Nodo* raiz, int dato) 
{
    if (raiz == NULL) 
    {
        return 0;
    }

    if (raiz->dato == dato) 
    {
        return 1;
    }

    if (dato < raiz->dato)
    {
        return buscar(raiz->izq, dato);
    }
    else
    {
        return buscar(raiz->der, dato);
    }
}

Nodo* minimo(Nodo* raiz) 
{
    while (raiz->izq != NULL)
    {
        raiz = raiz->izq;
    }
    return raiz;
}

Nodo* eliminar(Nodo* raiz, int dato) 
{
    if (raiz == NULL) 
    {
        return raiz;
    }

    if (dato < raiz->dato)
    {
        raiz->izq = eliminar(raiz->izq, dato);
    }
    else if (dato > raiz->dato)
    {
        raiz->der = eliminar(raiz->der, dato);
    }
    else 
    {
        if(raiz->izq == NULL && raiz->der == NULL) 
        {
            free(raiz);
            return NULL;
        }
        else if(raiz->izq == NULL)
        {
            Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        }
        else if(raiz->der == NULL)
        {
            Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }

        Nodo* temp = minimo(raiz->der);
        raiz->dato = temp->dato;
        raiz->der = eliminar(raiz->der, temp->dato);
    }
    return raiz;
}

Nodo* modificar(Nodo* raiz, int viejo, int nuevo) 
{
    if (buscar(raiz, viejo)) 
    {
        raiz = eliminar(raiz, viejo);
        raiz = insertar(raiz, nuevo);
        cout<<"Elemento modificado correctamente"<<endl;
    }
    else
    {
        cout<<"El elemento no existe"<<endl;
    }
    return raiz;
}

void imprimirArbol(Nodo* raiz) 
{
    if (raiz == NULL)
    {
        return;
    }

    imprimirArbol(raiz->izq);
    cout<<raiz->dato;
    imprimirArbol(raiz->der);
}

int main() 
{
    Nodo* raiz = NULL;
    int opcion, dato, nuevoDato;

    do 
    {
        cout<<"--- MENU ---"<<endl;
        cout<<"1. Insertar"<<endl;
        cout<<"2. Baja (Eliminar)"<<endl;
        cout<<"3. Buscar"<<endl;
        cout<<"4. Imprimir Arbol"<<endl;
        cout<<"5. Modificar"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Seleccione una opcion: "<<endl;
        cin>>opcion;

        switch (opcion) {
            case 1:
                cout<<"Ingrese un numero: "<<endl;
                cin>>dato;
                raiz = insertar(raiz, dato);
                break;
            case 2:
                printf("Ingrese el numero a eliminar: ");
                scanf("%d", &dato);
                raiz = eliminar(raiz, dato);
                break;
            case 3:
                printf("Ingrese el numero a buscar: ");
                scanf("%d", &dato);
                if (buscar(raiz, dato))
                    printf("Elemento encontrado\n");
                else
                    printf("Elemento no encontrado\n");
                break;
            case 4:
                printf("\nEstructura del arbol:\n");
                imprimirArbol(raiz);
                printf("\n");
                break;
            case 5:
                printf("Ingrese el valor a modificar: ");
                scanf("%d", &dato);
                printf("Ingrese el nuevo valor: ");
                scanf("%d", &nuevoDato);
                raiz = modificar(raiz, dato, nuevoDato);
                break;
        }

    } while (opcion != 6);

    return 0;
}
