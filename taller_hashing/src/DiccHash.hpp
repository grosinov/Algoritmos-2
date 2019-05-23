#include "DiccHash.h"

/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash() : _tabla(vector<list<Asociacion>>(TAM_INICIAL)), _tam(TAM_INICIAL), _cant_claves(0) {}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {}

/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string &clav) const {
    for (Asociacion a : _tabla[fn_hash(clav)]) {
        if (a.clave == clav) {
            return true;
        }
    }
    return false;
}

/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 *
 * Pasos a seguir para redimensionar la tabla:
 * - Crear una tabla del doble de tamaño de la original.
 * - Insertar todas las claves de la tabla original en la tabla nueva.
 * - Liberar la memoria reservada para la tabla original.
 */
template<class V>
void DiccHash<V>::definir(const string &clav, const V &sig) {
    if(definido(clav)) {
        for(Asociacion a : _tabla[fn_hash(clav)]) {
            if(a.clave == clav) {
                a.valor = sig;
            }
        }
    } else {
        _tabla[fn_hash(clav)].push_back(Asociacion(clav, sig));
        _cant_claves++;

        if(factorCarga() > UMBRAL_FC) {
            _tam = 2*_tam;
            vector<list<Asociacion>> tabla(_tam);
            for(list<Asociacion> l : _tabla) {
                for(Asociacion a : l) {
                    l.push_back(a);
                }
            }
            _tabla = tabla;
        }
    }
}

/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V &DiccHash<V>::significado(const string &clav) {
    for(Asociacion &a : _tabla[fn_hash(clav)]) {
        if(a.clave == clav) {
            return a.valor;
        }
    }
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string &clav) {
    for (auto it = _tabla[fn_hash(clav)].begin(); it != _tabla[fn_hash(clav)].end(); it++) {
        if( it->clave == clav) {
            _tabla[fn_hash(clav)].erase(it);
        }
    }
//    for(Asociacion a : _tabla[fn_hash(clav)]) {
//        if(a.clave == clav) {
//            _tabla[fn_hash(clav)].remove();
//        }
//    }
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
    return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
    set<string> claves;
    for(list<Asociacion> l : _tabla) {
        for(Asociacion a : l) {
            claves.insert(a.clave);
        }
    }
    return claves;
}

/* SÓLO PARA TESTING
 *
 * Devuelve el factor de carga de la tabla de hash.
 * Factor de carga : cantidad de claves definidas / tamaño de la tabla.
 */
template<class V>
float DiccHash<V>::factorCarga() const {
    return _cant_claves / _tam;
}

/* SÓLO PARA TESTING
 * Devuelve la cantidad de colisiones que tiene el diccionario.
 *
 * Observación: si en una celda de la tabla conviven n elementos,
 * hay n * (n - 1) / 2 colisiones en esa celda.
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
    unsigned int suma = 0;
    for (int i = 0; i < _tam; i++) {
        suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
    }
    return suma;
}

/* Función de hash.
 * Recordar usar "hash = hash % _tam".
 * (El operador "%" calcula el resto en la división o "módulo").
 * Devuelve la posición de la tabla asociada a la clave dada.
 */
template<class V>
unsigned int DiccHash<V>::fn_hash(const string &str) const {
    int i;
    for( i=0; i<str.length(); i++ ) {
        i = 197*i + int(str[i]);
    }
    return i % _tam;
}

