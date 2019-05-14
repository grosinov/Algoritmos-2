#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}

#endif

#if EJ >= 5

TEST(diccionario, ej5_borrar) {
    Diccionario d;
    d.definir(1,4);
    d.definir(2,5);
    d.definir(3,6);
    d.definir(4,7);
    d.borrar(2);
    d.borrar(5);
    ASSERT_FALSE(d.def(2));
    ASSERT_EQ(d.obtener(1), 4);
    ASSERT_EQ(d.obtener(3), 6);
    ASSERT_EQ(d.obtener(4), 7);

}

#endif

#if EJ >= 6

TEST(diccionario, ej6_claves) {
    Diccionario d;
    d.definir(1,4);
    d.definir(2,5);
    d.definir(3,6);
    d.definir(4,7);
    set<Clave> verClaves;
    verClaves.insert(3);
    verClaves.insert(2);
    verClaves.insert(4);
    verClaves.insert(1);
    ASSERT_TRUE(d.claves()==verClaves);
    verClaves.insert(5);
    ASSERT_FALSE(d.claves()==verClaves);
}

#endif

#if EJ >= 7
TEST(diccionario, ej7_igualdad){
    Diccionario d;
    d.definir(1,4);
    d.definir(2,5);
    d.definir(3,6);
    d.definir(4,7);
    Diccionario d2;
    d2.definir(1,4);
    d2.definir(2,5);
    d2.definir(3,6);
    d2.definir(4,7);
    ASSERT_TRUE(d == d2);
    d2.borrar(4);
    ASSERT_FALSE(d == d2);
    d2.definir(4, 6);
    ASSERT_FALSE(d == d2);
}

#endif

#if EJ >= 8

TEST(diccionario, ej8_unionEInterseccion) {
    Diccionario d;
    d.definir(1,4);
    d.definir(2,5);
    d.definir(3,6);
    d.definir(4,7);
    Diccionario d2;
    d2.definir(1,4);
    d2.definir(6,5);
    d2.definir(3,8);
    d2.definir(5,7);
    Diccionario d3 = d || d2;
    Diccionario dPrueba;
    dPrueba.definir(1,4);
    dPrueba.definir(2,5);
    dPrueba.definir(3,6);
    dPrueba.definir(4,7);
    dPrueba.definir(5,7);
    dPrueba.definir(6,5);
    ASSERT_TRUE(d3 == dPrueba);
    d3 = d && d2;
    dPrueba.borrar(2);
    dPrueba.borrar(4);
    dPrueba.borrar(5);
    dPrueba.borrar(6);
    ASSERT_TRUE(d3 == dPrueba);

}

#endif

