#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <cassert>
#include <vector>

using namespace std;

template<class Clave, class Valor>
class Diccionario {
public:
    Diccionario();
    void definir(Clave k, Valor v);
    bool def(Clave k) const;
    Valor obtener(Clave k) const;
    vector<Clave> claves() const;
private:

    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };
    vector<Asociacion> _asociaciones;
};

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Diccionario() {}

template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            _asociaciones[i].valor = v;
            return;
        }
    }
    _asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return true;
        }
    }
    return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
    for (unsigned int i = 0; i < _asociaciones.size(); i++) {
        if (_asociaciones[i].clave == k) {
            return _asociaciones[i].valor;
        }
    }
    assert(false);
}

template <class Clave>
vector<Clave> selectionSort(vector<Clave> claves) {
    int min;
    int minPos;
    for(int i = 0; i < claves.size(); i++) {
        min = claves[i];
        minPos = i;
        for(int j = i + 1; j < claves.size(); j++) {
            if(claves[j] < min) {
                min = claves[j];
                minPos = j;
            }
        }
        claves[minPos] = claves[i];
        claves[i] = min;
    }

    return claves;
}

template <class Clave, class Valor>
vector<Clave> Diccionario<Clave, Valor>::claves() const {
    vector<Clave> claves;
    for(int i = 0; i < _asociaciones.size(); i++) {
        claves.push_back(_asociaciones[i].clave);
    }

    claves = selectionSort(claves);
    return claves;
}

#endif /*__DICCIONARIO_H__*/