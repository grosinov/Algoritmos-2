#include "string_map.h"
#include "stack"

template <typename T>
string_map<T>::string_map(){
    Nodo* nuevo = new Nodo();
    raiz = nuevo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::referencia(string_map<T>::Nodo *a, string_map<T>::Nodo *d) {
    for(int i = 0; i < d->siguientes.size(); i++) {
        if(d->siguientes[i] != NULL) {
            a->siguientes[i] = new Nodo(d->siguientes[i]->definicion);
            referencia(a->siguientes[i], d->siguientes[i]);
        }
    }
}

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    if(d.raiz != NULL) {
        borradoTotal(raiz);
        raiz = new Nodo(d.raiz->definicion);
        referencia(raiz, d.raiz);
    }

}

template <typename T>
void string_map<T>::borradoTotal(string_map<T>::Nodo *a) {
    if(a != NULL) {
        for(int i = 0; i < a->siguientes.size(); i++) {
            if(a->siguientes[i] != NULL){
                borradoTotal(a->siguientes[i]);
                a->siguientes[i] == NULL;
                //si hay problemas de memoria ver esta funcion
            }
        }
        a->definicion == NULL;
        delete a;
    }
}

template <typename T>
string_map<T>::~string_map(){
    borradoTotal(raiz);
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if(count(clave) == 0) {
        Nodo* actual = raiz;
        for(char c : clave) {
            if(actual->siguientes[int(c)] == NULL) {
                actual->siguientes[int(c)] = new Nodo();
            }
            actual = actual->siguientes[int(c)];
        }
        actual->definicion = new T();
        _size++;
        return *(actual->definicion);
    } else {
        return at(clave);
    }
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* actual = raiz;
    if(raiz != NULL) {
        for(char c : clave) {
            if(actual->siguientes[int(c)] == NULL) {
                return 0;
            } else {
                actual = actual->siguientes[int(c)];
            }
        }
    }
    return 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return  *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return  *(actual->definicion);
}

template <typename T>
int string_map<T>::cantHijos(string_map<T>::Nodo *a) {
    int canthijos = 0;
    for(int i = 0; i< a->siguientes.size(); i++) {
        if(a->siguientes[i]!=NULL) {
            canthijos++;
        }
    }
    return canthijos;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    stack<Nodo*> ancestros;
    for(char c : clave) {
        ancestros.push(actual);
        actual = actual->siguientes[int(c)];
    }
    actual->definicion == NULL;
    while (ancestros.size() != 0) {
        if(ancestros.top()->definicion == NULL && cantHijos(ancestros.top()) == 0) {
            delete ancestros.top();
            ancestros.pop();
        } else {
            break;
        }
    }

}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    if(raiz == NULL) {
        return false;
    } else {
        return true;
    }
}