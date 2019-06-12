
template<class T>
ColaPrior<T>::ColaPrior() : cola(vector<T>()){}

template<class T>
int ColaPrior<T>::tam() const {
	return cola.size();
}

template<class T>
void ColaPrior<T>::swap(vector<T>& vec, int &i, int j) {
    T aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
    i = j;
}

template<class T>
void ColaPrior<T>::encolarEnVec(vector<T> &vec, const T &elem) {
    vec.push_back(elem);
    int i = vec.size()-1;
    while(i >= 0) {
        if(vec[i] > vec[(i-1)/2]) {
            swap(vec, i, (i-1)/2);
        } else {
            break;
        }
    }
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	encolarEnVec(cola, elem);
}

template<class T>
const T& ColaPrior<T>::proximo() const {
    return cola[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	int i = 0;
	cola[0] = cola[cola.size()-1];
	cola.pop_back();
	while (2*i+1 < cola.size()) {
	    if(cola[2*i+1] > cola[i]) {
	        if(2*i+2 < cola.size() && cola[2*i+1] < cola[2*i+2]){
	            swap(cola, i, 2*i+2);
	        } else {
                swap(cola, i, 2*i+1);
	        }
	    } else if(2*i+2 < cola.size() && cola[2*i+2] > cola[i]) {
            swap(cola, i, 2 * i + 2);
        } else {
	        break;
	    }
	}
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    for (int i = 0; i < elems.size(); i++) {
        encolarEnVec(cola, elems[i]);
    }
}

