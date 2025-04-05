// Tarea semana 8.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> // Incluye la biblioteca para entrada y salida de datos

using namespace std; // Permite usar los elementos del espacio de nombres estándar sin especificarlo cada vez

// Definición de la estructura NodoDoble para la lista doblemente enlazada
struct NodoDoble {
    int dato; // Dato almacenado en el nodo
    NodoDoble* siguiente; // Puntero al siguiente nodo
    NodoDoble* anterior; // Puntero al nodo anterior
};

// Definición de la clase ListaDoble
class ListaDoble {
private:
    NodoDoble* cabeza; // Puntero al primer nodo de la lista
public:
    // Constructor que inicializa la cabeza de la lista en nullptr (lista vacía)
    ListaDoble() : cabeza(nullptr) {}

    // Método para insertar un nuevo nodo al inicio de la lista
    void insertarInicio(int valor) {
        NodoDoble* nuevo = new NodoDoble; // Crea un nuevo nodo en memoria dinámica
        nuevo->dato = valor; // Asigna el valor al nodo
        nuevo->siguiente = cabeza; // El nuevo nodo apunta al antiguo primer nodo
        nuevo->anterior = nullptr; // Como es el primer nodo, no tiene anterior

        // Si la lista no está vacía, se actualiza el puntero anterior del nodo cabeza
        if (cabeza != nullptr) {
            cabeza->anterior = nuevo;
        }
        cabeza = nuevo; // Se actualiza la cabeza de la lista al nuevo nodo
    }

    // Método para imprimir la lista desde el inicio hasta el final
    void imprimirAdelante() {
        NodoDoble* actual = cabeza; // Se inicializa un puntero en la cabeza
        cout << "Lista (adelante): ";
        while (actual != nullptr) { // Se recorre la lista mientras el nodo actual no sea nulo
            cout << actual->dato << " <-> "; // Imprime el valor del nodo
            actual = actual->siguiente; // Avanza al siguiente nodo
        }
        cout << "NULL" << endl; // Indica el final de la lista
    }

    // Método para imprimir la lista desde el final hasta el inicio
    void imprimirAtras() {
        NodoDoble* actual = cabeza; // Se inicializa el puntero en la cabeza
        if (actual == nullptr) return; // Si la lista está vacía, se sale del método

        // Se mueve el puntero hasta el último nodo
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        cout << "Lista (atras): ";
        while (actual != nullptr) { // Se recorre la lista hacia atrás
            cout << actual->dato << " <-> "; // Imprime el valor del nodo
            actual = actual->anterior; // Retrocede al nodo anterior
        }
        cout << "NULL" << endl; // Indica el inicio de la lista
    }

    // Método para eliminar el primer nodo que contenga el valor dado
    void eliminar(int valor) {
        NodoDoble* actual = cabeza; // Se inicializa un puntero en la cabeza

        // Se busca el nodo que contiene el valor
        while (actual != nullptr && actual->dato != valor) {
            actual = actual->siguiente;
        }

        // Si no se encontró el valor, se informa al usuario
        if (actual == nullptr) {
            cout << "Valor no encontrado." << endl;
            return;
        }

        // Se ajusta el puntero del nodo anterior al nodo siguiente
        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        }
        else {
            // Si se elimina la cabeza, se actualiza la cabeza de la lista
            cabeza = actual->siguiente;
        }

        // Se ajusta el puntero del nodo siguiente al nodo anterior
        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual; // Se libera la memoria del nodo eliminado
        cout << "Valor eliminado: " << valor << endl;
    }

    // Destructor para liberar la memoria de todos los nodos de la lista
    ~ListaDoble() {
        NodoDoble* actual = cabeza; // Se inicializa el puntero en la cabeza
        while (actual != nullptr) { // Se recorre la lista
            NodoDoble* siguiente = actual->siguiente; // Se guarda el siguiente nodo antes de eliminar
            delete actual; // Se elimina el nodo actual
            actual = siguiente; // Se mueve al siguiente nodo
        }
    }
};

// Función principal del programa
int main() {
    ListaDoble lista; // Se crea una instancia de la lista doblemente enlazada

    // Se insertan elementos en la lista
    lista.insertarInicio(200);
    lista.insertarInicio(300);
    lista.insertarInicio(400);

    // Se imprime la lista en ambas direcciones
    cout << "Lista doblemente encadenada:" << endl;
    lista.imprimirAdelante();
    lista.imprimirAtras();

    // Se elimina un nodo con el valor 30
    lista.eliminar(30);
    cout << "Despues de eliminar 30:" << endl;

    // Se vuelve a imprimir la lista
    lista.imprimirAdelante();
    lista.imprimirAtras();

    return 0; // Fin del programa
}
