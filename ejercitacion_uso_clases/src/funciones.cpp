#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> sinrepe;
    bool repetido;
    for(int i = 0; i < s.size(); i++){
        repetido = false;
        for(int j = i+1; j < s.size() && !repetido; j++){
            if(s[i] == s[j]){
                repetido = true;
            }
        }
        if(!repetido){
            sinrepe.push_back(s[i]);
        }

    }
    return sinrepe;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> sinrepetidos;
    vector<int> sinrepe;
    for(int n : s){
        sinrepetidos.insert(n);
    }
    for(int m : sinrepetidos){
        sinrepe.push_back(m);
    }
    return sinrepe;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> a1 , b1;
    for(int n : a){
        a1.insert(n);
    }
    for(int n : b){
        b1.insert(n);
    }

    return a1 == b1;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> a1 , b1;
    for(int n : a){
        a1.insert(n);
    }
    for(int n : b){
        b1.insert(n);
    }

    return a1 == b1;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    set<int> s1;
    map<int,int> m;
    for(int n : s){
        s1.insert(n);
    }

    int apariciones;
    for(int n : s1){
        apariciones = 0;
        for(int l : s){
            if(l == n){
                apariciones++;
            }
        }
        m[n] = apariciones;
    }

    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    set<int> s1;
    vector<int> res;
    for(int n : s){
        s1.insert(n);
    }

    int apariciones;
    for(int n : s1){
        apariciones = 0;
        for(int l : s){
            if(l == n){
                apariciones++;
            }
        }
        if(apariciones == 1){
            res.push_back(n);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> set_a;
    set<int> res;
    for (int n : a) {
        set_a.insert(n);
    }
    for (int n : b) {
        if (set_a.count(n)) {
            res.insert(n);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> m;
    for(int n : s){
        m[n % 10].insert(n);
    }
    return m;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    res = str;
    for(int j = 0 ; j < str.size(); j++){
        for(int i = 0 ; i < tr.size(); i++){
            if(str[j] == tr[i].first){
                res[j] = tr[i].second;
            }
        }
    }
    return res;
}

// Ejercicio 10
bool buscarRepetidos(Mail s, Mail s1){
    for(LU n : s.libretas()){
        for(LU m : s1.libretas()){
            if(n == m){
                return true;
            }
        }
    }
    return false;
}

bool integrantes_repetidos(vector<Mail> s) {
    bool hayRepe;
    for(int i =0; i<s.size();i++){
        for(int j =i+1; j<s.size();j++){
            if(s[i].libretas() != s[j].libretas()){
                hayRepe = buscarRepetidos(s[i], s[j]);
            }
        }
    }
    return hayRepe;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> m;
    for(int i =0; i<s.size();i++){
        if(s[i].adjunto()){
            m[s[i].libretas()] = s[i];
            for(int j =i+1; j<s.size();j++){
                if(s[j].adjunto() && s[i].libretas() == s[j].libretas()){
                    if(s[i].fecha() < s[j].fecha()){
                        m[s[i].libretas()] = s[j];
                    }
                }
            }
        }
    }
    return m;
}
