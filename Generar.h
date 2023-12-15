#ifndef GENERAR_H
#define GENERAR_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

namespace nombreCaso {
    const std::string trazabilidadObjetos = "Trazabilidad Objetos"; 
    const std::string eventosEscenario = "Eventos de Cada Escenario"; 
    const std::string colaEspera = "Cola de Espera"; 
};

enum Area {
    trazabilidadObjetos,
    eventosEscenario,
    colaEspera
};

const static int MIN_AREA_COLA_ESPERA = 100000; 
const static int MAX_AREA_COLA_ESPERA = 110000;

const static int MIN_AREA_TRAZABILIDAD_OBJETOS = 1000; 
const static int MAX_AREA_TRAZABILIDAD_OBJETOS = 1500; 
const static int VARIANTE_AREA_TRAZABILIDAD_OBJETOS = 15; 

const static int MIN_AREA_EVENTO_ESCENARIO = 60000; 
const static int MAX_AREA_EVENTO_ESCENARIO = 80000; 

//  retorna un random segun un rango
int obtenerRandom(const int min, const int max);

//  retorna un random segune el rango de cada area(carrera)
int obtenerRandomArea(Area area); 

//  Generacion de listas con dupicados, sin duplicados, ordenadas e inversas

//  No obtiene un vector dado que es la primera funcion en llamarse para generar un vector que sirva a las demas funciones de generar vecotores.   
std::vector<int> obtenerOrdenado(Area Area);

//  Recibe el vector ordenado. 
std::vector<int> obtenerInversamenteOrdenado(const std::vector<int>& data);  

//  Recibe el vector sin duplicados para usar las mismas posiciones aleatorias de ese vector. 
std::vector<int> obtenerDuplicado(const std::vector<int>& data);

//  Recibe el vector ordenado. Llena un vecotor con las posiciones ya retornadas por 'obtenrRandom' para recorrerlo y comprobar que no se repitan. Se TRATA
//  de ayudar a la funcion 'obtenrRandom' con las funciones 'cambiarMaximo' y 'cambiarMinimo' para disminuir el rando de busqueda para un numero distinto.  
std::vector<int> obtenerSinDuplicado(const std::vector<int>& data);

//  Usada en 'obtenerSinDuplicado' para cambiar el maximo en el rango del numero random. Lo que hace es disminuir el maximo a medida que comprueba que ya 
//  no existan valores mayores que maximo que se deban agregar.  
bool cambiarMaximo(size_t n, const std::vector<int>& posiciones, int posicion); 

//  Usada en 'obrtenerSinDuplicado' para cambiar el minimo en el rango del numero random. Aumenta el minimo a medida que comprueba que ya no existan 
//  valores menores que minimo que se deban agregar. 
bool cambiarMinimo(size_t n, const std::vector<int>& posiciones,int posicion, int minimo); 

#endif