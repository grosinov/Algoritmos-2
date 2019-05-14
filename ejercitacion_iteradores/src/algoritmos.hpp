#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    auto it2 = c.begin();
    for(auto it = c.begin(); it != c.end(); it++){
        if (*it < *it2) {
            it2 = it;
        }
    }
    return *it2;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c) {
    typename Contenedor::value_type prom = 0;
    for(auto& y : c) {
        prom += y;
    }
    prom /= c.size();
    return prom;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta) {
    auto it2 = desde;
    for(auto it = desde; it != hasta; it++) {
        if (*it < *it2) {
            it2 = it;
        }
    }
    return  *it2;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type prom = 0;
    int size = 0;
    for(auto it = desde; it != hasta; it++) {
        prom += *it;
        size++;
    }
    prom /= size;
    return prom;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem) {
    auto it = c.begin();
    while(it !=c.end()) {
        if (*it == elem) {
            it = c.erase(it);
        } else {
            it++;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c) {
    auto it2 = c.begin();
    auto it = it2;
    it2++;
    while (it2 != c.end()) {
        if (*it2 < *it) {
            return false;
        }
        it2++;
        it++;
    }
    return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem) {
    std::pair<Contenedor, Contenedor> par;
    typename Contenedor::iterator its;

    for (auto it = c.begin(); it != c.end(); it++) {
        if (*it < elem) {
            its = par.first.end();
            par.first.insert(its, *it);
        } else {
            its = par.second.end();
            par.second.insert(its, *it);
        }
    }
    return par;
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res) {
    typename Contenedor::const_iterator it1(c1.begin());
    typename Contenedor::const_iterator it2(c2.begin());
    typename Contenedor::iterator itres;

    while(it1 != c1.end() && it2 != c2.end()) {
        itres = res.end();
        if(*it1 < *it2) {
            res.insert(itres, *it1);
            it1++;
        } else {
            res.insert(itres, *it2);
            it2++;
        }
    }
    while(it1 != c1.end()) {
        itres = res.end();
        res.insert(itres, *it1);
        it1++;
    }
    while (it2 != c2.end()) {
        itres = res.end();
        res.insert(itres, *it2);
        it2++;
    }
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
