
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = NULL;
}

template <class T>
void Conjunto<T>::vaciar(Conjunto<T>::Nodo *a) {
    if(a != NULL){
        vaciar(a->izq);
        vaciar(a->der);
        a->izq = NULL;
        a->der = NULL;
        delete a;
    }
}

template <class T>
Conjunto<T>::~Conjunto() { 
    vaciar(_raiz);
}

template <class T>
bool Conjunto<T>::perteneceAux(const T &clave, Conjunto<T>::Nodo *a) const {
    if(a == NULL){
        return false;
    } else {
        if(a->valor == clave) {
            return true;
        } else if(clave > a->valor){
            return perteneceAux(clave, a->der);
        } else {
            return perteneceAux(clave, a->izq);
        }
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    return perteneceAux(clave, _raiz);
}

template <class T>
void Conjunto<T>::insertarAux(const T& clave, Conjunto<T>::Nodo *a) {

    if(clave > a->valor){
        if(a->der == NULL){
            Nodo* nuevo = new Nodo(clave);
            a->der = nuevo;
        } else {
            return insertarAux(clave, a->der);
        }
    } else if (clave < a->valor){
        if(a->izq == NULL) {
            Nodo* nuevo = new Nodo(clave);
            a->izq = nuevo;
        } else {
            return insertarAux(clave, a->izq);
        }
    }
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(_raiz == NULL) {
        Nodo* nuevo = new Nodo(clave);
        _raiz = nuevo;
    } else {
        insertarAux(clave, _raiz);
    }
}

template <class T>
void Conjunto<T>::removerAux(const T& clave, Conjunto<T>::Nodo *a, Conjunto<T>::Nodo* anterior) {
    if(a != NULL){
        if(clave > a->valor && a->der != NULL) {
            removerAux(clave, a->der, a);
        } else if(clave < a->valor && a->izq != NULL){
            removerAux(clave, a->izq, a);
        } else {
            if(a->izq == NULL && a->der != NULL) {
                if(anterior == a) {
                    _raiz = a->der;
                } else if(anterior->der == a) {
                    anterior->der = a->der;
                } else {
                    anterior->izq = a->der;
                }
                a->der = NULL;
                a->izq = NULL;
                delete a;
            } else if (a->izq != NULL && a->der == NULL) {
                if (anterior == a){
                    _raiz = a->izq;
                } else if(anterior->der == a){
                    anterior->der = a->izq;
                } else {
                    anterior->izq = a->izq;
                }
                a->der = NULL;
                a->izq = NULL;
                delete a;
            } else if (a->izq != NULL && a->der != NULL){
                Nodo* reemplazante = a->der;
                Nodo* antReemplazante;
                if(reemplazante->izq == NULL) {
                    reemplazante->izq = a->izq;
                } else {
                    while(reemplazante->izq != NULL) {
                        antReemplazante = reemplazante;
                        reemplazante = reemplazante->izq;
                    }
                    antReemplazante->izq = reemplazante->der;
                    reemplazante->izq = a->izq;
                    reemplazante->der = a->der;
                }

                if(anterior == a) {
                    _raiz = reemplazante;
                } else if(anterior->der == a){
                    anterior->der = reemplazante;
                } else {
                    anterior->izq = reemplazante;
                }
                a->der = NULL;
                a->izq = NULL;
                delete a;
            } else if (a->izq == NULL && a->der == NULL) {
                if(anterior == a) {
                    a->der = NULL;
                    a->izq = NULL;
                    delete a;
                    _raiz = NULL;
                } else if(anterior->der == a){
                    a->der = NULL;
                    a->izq = NULL;
                    delete a;
                    anterior->der = NULL;
                } else {
                    a->der = NULL;
                    a->izq = NULL;
                    delete a;
                    anterior->izq = NULL;
                }
            }

        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (_raiz != NULL) {
        removerAux(clave, _raiz, _raiz);
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    Nodo* anterior;
    while(actual->valor != clave) {
        anterior = actual;
        if(clave > actual->valor) {
            actual = actual->der;
        } else {
            actual = actual->izq;
        }
    }
    if(actual->der == NULL) {
        return anterior->valor;
    } else {
        actual = actual->der;
        while (actual->izq != NULL) {
            actual = actual->izq;
        }
        return actual->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while (actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while (actual->der != NULL) {
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Conjunto<T>::Nodo* a) const{
    if(a->der != NULL && a->izq != NULL) {
        return 1 + cardinalAux(a->izq) + cardinalAux(a->der);
    } else if(a->der == NULL && a->izq != NULL) {
        return 1 + cardinalAux(a->izq);
    } else if(a->der != NULL && a->izq == NULL) {
        return 1 + cardinalAux(a->der);
    } else {
        return 1;
    }
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    if(_raiz == NULL) {
        return 0;
    } else {
        return cardinalAux(_raiz);
    }
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

