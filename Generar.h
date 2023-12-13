#ifndef GENERAR_H
#define GENERAR_H

#include <iostream>
#include <vector>
#include <random>

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

int obtenerRandom(const int min, const int max);

std::vector<int> obtenerDuplicado(Area area); 

#endif