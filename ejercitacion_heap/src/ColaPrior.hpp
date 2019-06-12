
template<class T>
ColaPrior<T>::ColaPrior() {
	return vector<T>();
}

template<class T>
int ColaPrior<T>::tam() const {
	return cola.size();
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	cola.push_back(elem);
	int i = cola.size()-1;
	while(i >= 0) {
	    if(cola[i] > cola[(i-1)/2]) {
            T aux = cola[i];
            cola[i] = cola[(i - 1) / 2];
            cola[(i - 1) / 2] = aux;
            i = (i - 1) / 2;
        } else {
	        break;
	    }
	}
}

template<class T>
const T& ColaPrior<T>::proximo() const {
    return cola[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	// COMPLETAR
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
	// COMPLETAR
}

