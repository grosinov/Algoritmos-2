#include "Diccionario.hpp"

template<class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x);
    bool operator<=(Multiconjunto<T> otro) const;
private:
    Diccionario<T, int> d;
};

template<class T>
Multiconjunto<T>::Multiconjunto() {}

template<class T>
void Multiconjunto<T>::agregar(T x) {
    if(!d.def(x)) {
        d.definir(x, 1);
    } else {
        d.definir(x, d.obtener(x) + 1);
    }
}

template <class T>
int Multiconjunto<T>::ocurrencias(T x) {
    if(!d.def(x)) {
        return 0;
    } else {
        return d.obtener(x);
    }
}
template <class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const {
    if(d.claves() == otro.d.claves()) {
        for (int i = 0; i < d.claves().size(); ++i) {
            if(d.obtener(d.claves()[i]) > otro.d.obtener(d.claves()[i])) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}