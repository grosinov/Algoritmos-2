template <typename T>
string_map<T>::string_map(){
    Nodo* nuevo = new Nodo();
    raiz = nuevo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::borradoTotal(string_map<T>::Nodo *a) {
    if(a != NULL) {
        for(int i = 0; i < a->siguientes; i++) {
            if(a->siguientes[i] != NULL){

            }
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    if(count(clave) == 0) {
        Nodo* actual = raiz;
        for(char c : clave) {
            if(actual->siguientes[int(c)] == NULL) {
                Nodo* nuevo = new Nodo();
                actual->siguientes[int(c)] = nuevo;
                actual = nuevo;
            } else {
                actual = actual->siguientes[int(c)];
            }
        }
        actual->definicion = T();
        return actual->definicion;
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
    return  actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for(char c : clave) {
        actual = actual->siguientes[int(c)];
    }
    return  actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return size;
}

template <typename T>
bool string_map<T>::empty() const{
    if(raiz == NULL) {
        return false;
    } else {
        return true;
    }
}