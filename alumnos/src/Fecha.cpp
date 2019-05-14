//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
    if(anio == 400){
        return true;
    } else {
        if(anio % 4 == 0 && anio % 100 != 0){
            return true;
        } else {
            return false;
        }
    }
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes){
    switch (mes) {
        case 2:
            if(esBisiesto(anio)){
                return 29;
            } else {
                return 28;
            }
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
    }
}
//

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;
  void sumar_periodo(Periodo p);

  // Ejercicio 7: sumar período a fecha

 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia){
    _anio = anio;
    _mes = mes;
    _dia = dia;
}

Anio Fecha::anio() const {
    return _anio;
}

Mes Fecha::mes() const {
    return _mes;
}

Dia Fecha::dia() const {
    return _dia;
}


// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return _anio == o.anio() && _mes == o.mes() && _dia == o.dia();
}

bool Fecha::operator<(Fecha o) const {
    return _anio <= o.anio() && _mes <= o.mes() && _dia <= o.dia();
}

void Fecha::sumar_anios(int anios) {
    _anio += anios;
}

void Fecha::sumar_meses(int meses) {
    _mes += meses;
}

void Fecha::sumar_dias(int dias) {
    _dia += dias;
}


// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
    return f1.anio() != f2.anio() || f1.mes() != f2.mes() || f1.dia() != f2.dia();
}

// Ejercicio 6: clase período
class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios() const;
    int meses() const;
    int dias() const;
private:
    Anio _anios;
    Mes _meses;
    Dia _dias;
};

Periodo::Periodo(int anios, int meses, int dias) : _anios(anios),_meses(meses),_dias(dias){
}


Anio Periodo::anios() const {
    return _anios;
}

Mes Periodo::meses() const {
    return _meses;
}

Dia Periodo::dias() const {
    return _dias;
}

void Fecha::sumar_periodo(Periodo p){
    sumar_dias(p.dias());
    sumar_anios(p.anios());
    sumar_meses(p.meses());
    if(_mes > 12){
        _anio += _mes/12;
        _mes = _mes % 12;
    }
    while(_dia > diasEnMes(_anio,_mes)){
        _dia -= diasEnMes(_anio,_mes);
        _mes++;
        if(_mes > 12){
            _anio += _mes/12;
            _mes = _mes % 12;
        }
    }
}

// Ejercicio 8: clase Intervalo
class Intervalo{
public:
    Intervalo(Fecha desde, Fecha hasta);

    Fecha desde() const;
    Fecha hasta() const;
    int enDias() const;
private:
    Fecha _desde;
    Fecha _hasta;
};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde), _hasta(hasta) {};

Fecha Intervalo::desde() const {
    return _desde;
}

Fecha Intervalo::hasta() const {
    return _hasta;
}

int Intervalo::enDias() const {
    Fecha actual = _desde;
    int dias = 0;
    while (actual != _hasta) {
        dias++;
        actual.sumar_periodo(Periodo(0, 0, 1));
    }
    return dias;
}
