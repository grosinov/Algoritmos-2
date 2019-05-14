#include "Diccionario.h"

Diccionario::Diccionario(){

}

Diccionario::Asociacion::Asociacion(Clave c, Valor v): _clave(c), _valor(v) {}

void Diccionario::definir(Clave k, Valor v) {

    int i;
    for(i =0; i<asociaciones.size();i++){
        if(asociaciones[i]._clave == k){
            asociaciones[i]._valor = v;
            break;
        }
    }
    if(i>=asociaciones.size()){
        Asociacion asoc(k,v);
        asociaciones.push_back(asoc);
    }
}

bool Diccionario::def(Clave k) const {

    for(int i =0; i<asociaciones.size();i++){
        if(asociaciones[i]._clave == k){
            return true;
        }
    }

    return false;
}

Valor Diccionario::obtener(Clave k) const {
    for(int i =0; i<asociaciones.size();i++){
        if(asociaciones[i]._clave == k){
            return asociaciones[i]._valor;
        }
    }
}

void Diccionario::borrar(Clave k) {

    vector<Asociacion> newAsociaciones;
    for(int i =0;i<asociaciones.size();i++){
        if(asociaciones[i]._clave != k){
            newAsociaciones.push_back(asociaciones[i]);
        }
    }
    asociaciones = newAsociaciones;
}

set<Clave> Diccionario::claves() const {
    set<Clave> claves;
    for(int i = 0; i < asociaciones.size(); i++) {
        claves.insert(asociaciones[i]._clave);
    }

    return claves;
}

bool Diccionario::operator==(Diccionario o) {
    if(asociaciones.size() == o.asociaciones.size()){
        int j;
        for(int i = 0; i < asociaciones.size(); i++) {
            for(j = 0; j < o.asociaciones.size(); j++) {
                if(asociaciones[i]._clave == o.asociaciones[j]._clave && asociaciones[i]._valor == o.asociaciones[j]._valor){
                    break;
                }
            }
            if(j >= o.asociaciones.size()){
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

Diccionario Diccionario::operator||(Diccionario o) const {
    Diccionario res;
    res.asociaciones = asociaciones;
    for(int i = 0; i < o.asociaciones.size(); i++) {
        if(!def(o.asociaciones[i]._clave)) {
            res.definir(o.asociaciones[i]._clave, o.asociaciones[i]._valor);
        }
    }
    return res;
}

Diccionario Diccionario::operator&&(Diccionario o) const {
    Diccionario res;
    for(int i = 0; i < asociaciones.size(); i++) {
        if(def(asociaciones[i]._clave) && o.def(asociaciones[i]._clave)) {
            res.definir(asociaciones[i]._clave, asociaciones[i]._valor);
        }
    }
    return res;
}