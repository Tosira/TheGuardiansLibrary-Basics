#include "Generar.h"

int obtenerRandom(int min, int max) {    
    std::random_device rd; 
    std::mt19937 generador(rd()); 
    std::uniform_int_distribution<int> distribucion(min, max);
    
    return  distribucion(generador); 
}

int obtenerRandomArea(Area area) {        
    if (area == trazabilidadObjetos) {
        return obtenerRandom(MIN_AREA_TRAZABILIDAD_OBJETOS, MAX_AREA_TRAZABILIDAD_OBJETOS);     
    } 
    else if (area == eventosEscenario) {
        return obtenerRandom(MIN_AREA_EVENTO_ESCENARIO, MAX_AREA_EVENTO_ESCENARIO); 
    } 
    else {
        return obtenerRandom(MIN_AREA_COLA_ESPERA, MAX_AREA_COLA_ESPERA);                 
    }              
}

std::vector<int> obtenerDuplicado(Area area) {
    size_t n = obtenerRandomArea(area);
    std::vector<int> data; 

    for (int i = 0; i < n; ++i) 
        data.push_back(obtenerRandom(0,n));    
        
    return data;
}