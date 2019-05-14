#ifndef MAPA_H
#define MAPA_H

typedef int Direccion;

#define NORTE   0
#define ESTE    1
#define SUR     2
#define OESTE   3

template <class T>
class Mapa {
public:
	// Constructor:
	// Crea un mapa de las dimensiones indicadas.
	// Cada coordenada del mapa almacena un valor de tipo T.
	// Cada coordenada del mapa se inicializa utilizando el constructor
	// por defecto de T.
	//
	// Las coordenadas son de la forma (x, y)
	// donde 0 <= x < ancho
	//       0 <= y < alto.
	//
	// El cursor empieza ubicado sobre la coordenada (0, 0).
	//
	// Precondición: ancho > 0 && alto > 0
	Mapa(int ancho, int alto, const T& def);

	// Devuelve el ancho del mapa.
	int ancho() const;

	// Devuelve el alto del mapa.
	int alto() const;

	// Devuelve una referencia al valor ubicado en la
	// posición del cursor.
	T& valor();

	// Mueve el cursor hacia la dirección indicada.
	// El resultado es el de aplicar el siguiente desplazamiento
	// a la posición actual del cursor:
	//   norte --> (0, +1)
	//   este  --> (+1, 0)
	//   sur   --> (0, -1)
	//   oeste --> (-1, 0)
	// Si la coordenada queda fuera de los límites del mapa, se
	// ajusta utilizando aritmética modular.
	//
	// P.ej. si el tablero es de 100x100
	// la coordenada al este de (99, 3) es (0, 3).
	void mover(Direccion direccion);

	// Constructor por copia
	Mapa(const Mapa& otro);

	// Destructor
	~Mapa();

	// Operador de asignación
	Mapa& operator=(const Mapa& otro);
private:
	// NOTA:
	// En este ejercicio no está permitido usar vector ni
	// otras clases de la STL. El objetivo es hacerlo a mano
	// usando punteros.

	int _ancho;
	int _alto;
    T** grilla;
    int x,y;
};

template <class T>
Mapa<T>::Mapa(int ancho, int alto, const T& def) {

    _ancho = ancho;
    _alto = alto;
    x = 0;
    y = 0;

    grilla = new T*[ancho];

	for(int i = 0; i < ancho; i++) {
	    T* columna = new T[alto];
	    for(int j = 0; j< alto; j++) {
	        columna[j] = def;
	    }
	    grilla[i] = columna;
	}
}

template <class T>
int Mapa<T>::ancho() const {
	return _ancho;
}

template <class T>
int Mapa<T>::alto() const {
	return _alto;
}

template <class T>
T& Mapa<T>::valor() {
    return grilla[x][y];
}

template <class T>
void Mapa<T>::mover(Direccion direccion) {
	switch (direccion) {
        case 0:
            y = (y+1) % _alto;
            break;
        case 1:
            x = (x+1) % _ancho;
            break;
        case 2:
            y = (y-1+_alto) % _alto;
            break;
        case 3:
            x = (x-1+_ancho) % _ancho;
            break;
    }
}


template <class T>
Mapa<T>::Mapa(const Mapa<T>& otro) {

    _alto = otro.alto();
    _ancho = otro.ancho();
    x = otro.x;
    y = otro.y;

    grilla = new T*[otro._ancho];

    for(int i = 0; i < otro._ancho; i++) {
        T* columna = new T[otro._alto];
        for(int j = 0; j< otro._alto; j++) {
            columna[j] = otro.grilla[i][j];
        }
        grilla[i] = columna;
    }
}

template <class T>
Mapa<T>::~Mapa() {
	for(int i = 0; i < _ancho; i++) {
        delete[] grilla[i];
	}
    delete[] grilla;
}

template <class T>
Mapa<T>& Mapa<T>::operator=(const Mapa<T>& otro) {
    for(int i = 0; i < _ancho; i++) {
        delete[] grilla[i];
    }
    delete[] grilla;

    _alto = otro.alto();
    _ancho = otro.ancho();
    x = otro.x;
    y = otro.y;

    grilla = new T*[otro._ancho];

    for(int i = 0; i < otro._ancho; i++) {
        T* columna = new T[otro._alto];
        for(int j = 0; j< otro._alto; j++) {
            columna[j] = otro.grilla[i][j];
        }
        grilla[i] = columna;
    }
}

#endif
