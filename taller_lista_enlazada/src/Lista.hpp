#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    prim = NULL;
    ult = NULL;
}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <typename T>
Lista<T>::~Lista() {
    Nodo* posActual = prim;
    while (posActual != NULL) {
        Nodo* siguiente = (*posActual).siguiente;
        (*posActual).anterior = NULL;
        (*posActual).siguiente = NULL;
        delete posActual;
        posActual = siguiente;
    }
    prim = NULL;
    ult = NULL;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
    Nodo* posActual = prim;
    while (posActual != NULL) {
        Nodo* siguiente = (*posActual).siguiente;
        (*posActual).anterior = NULL;
        (*posActual).siguiente = NULL;
        delete posActual;
        posActual = siguiente;
    }
    prim = NULL;
    ult = NULL;

    if(aCopiar.prim == NULL) {
        prim = NULL;
        ult = NULL;
    } else {
        Nodo* iterador = aCopiar.prim;
        Nodo* actual = new Nodo((*iterador).valor, NULL, NULL);
        prim = actual;
        iterador = (*iterador).siguiente;

        while (iterador != NULL) {
            Nodo* nuevo = new Nodo((*iterador).valor, actual, NULL);
            (*actual).siguiente = nuevo;
            actual = nuevo;
            iterador = (*iterador).siguiente;
        }
        ult = actual;
    }
    return *this;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* nuevo = new Nodo(elem, NULL, NULL);

    if (prim == NULL) {
        prim = nuevo;
        ult = nuevo;
    } else {
        Nodo* primPos = prim;
        prim = nuevo;
        (*nuevo).siguiente = primPos;
        (*primPos).anterior = nuevo;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* nuevo = new Nodo(elem, NULL, NULL);

    if (ult == NULL) {
        prim = nuevo;
        ult = nuevo;
    } else {
        Nodo* ultPos = ult;
        ult = nuevo;
        (*nuevo).anterior = ultPos;
        (*ultPos).siguiente = nuevo;
    }
}

template <typename T>
void Lista<T>::eliminar(Nat i) {

    if (longitud() == 1) {
        Nodo* unico = prim;
        prim = NULL;
        (*unico).anterior = NULL;
        (*unico).siguiente = NULL;
        delete unico;
    }else if (i == 0) {
        Nodo* primero = prim;
        Nodo* siguiente = (*primero).siguiente;
        prim = siguiente;
        (*siguiente).anterior = NULL;
        (*primero).siguiente = NULL;
        delete primero;

    } else if (i == longitud()-1) {
        Nodo* ultimo = ult;
        Nodo* anterior = (*ultimo).anterior;
        ult = anterior;
        (*anterior).siguiente = NULL;
        (*ultimo).anterior = NULL;
        delete ultimo;
    } else {
        int iterador = 0;
        Nodo* posActual = prim;
        Nodo* anterior = NULL;
        Nodo* siguiente = (*posActual).siguiente;

        while (iterador != i) {
            anterior = posActual;
            posActual = siguiente;
            siguiente = (*siguiente).siguiente;
            iterador++;
        }

        (*anterior).siguiente = siguiente;
        (*siguiente).anterior = anterior;
        (*posActual).siguiente = NULL;
        (*posActual).anterior = NULL;
        delete posActual;
    }
}

template <typename T>
int Lista<T>::longitud() const {
    int largo = 0;
    Nodo* posActual = prim;
    while (posActual != NULL) {
        largo++;
        posActual = (*posActual).siguiente;
    }
    return largo;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    int iterador = 0;
    Nodo* posActual = prim;
    while (iterador != i) {
        posActual = (*posActual).siguiente;
        iterador++;
    }
    return (*posActual).valor;
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    int iterador = 0;
    Nodo* posActual = prim;
    while (iterador != i) {
        posActual = (*posActual).siguiente;
        iterador++;
    }
    return (*posActual).valor;
}

template <typename T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}