#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>
#include <set>
using namespace std;

typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;

	void borrar(Clave k);
	set<Clave> claves() const;
	Diccionario operator||(Diccionario o) const;
    Diccionario operator&&(Diccionario o) const;


    bool operator==(Diccionario o);
	
private:

    struct Asociacion {
	    Asociacion(Clave c, Valor v);
        Clave _clave;
        Valor _valor;
    };

	vector<Asociacion> asociaciones;
};

#endif /*__DICCIONARIO_H__*/
