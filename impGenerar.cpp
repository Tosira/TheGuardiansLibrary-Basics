#include "Generar.h"

int obtenerRandom(int min, int max) {    
    std::random_device rd; 
    std::mt19937 generador(rd()); 
    std::uniform_int_distribution<int> distribucion(min, max);
    
    return  distribucion(generador); 
}

int obtenerRandomArea(Area area) {        
    if (area == trazabilidadObjetos) {
        return obtenerRandom(MIN_AREA_TRAZABILIDAD_OBJETOS, MAX_AREA_TRAZABILIDAD_OBJETOS)*VARIANTE_AREA_TRAZABILIDAD_OBJETOS;     
    } 
    else if (area == eventosEscenario) {
        return obtenerRandom(MIN_AREA_EVENTO_ESCENARIO, MAX_AREA_EVENTO_ESCENARIO); 
    } 
    else {
        return obtenerRandom(MIN_AREA_COLA_ESPERA, MAX_AREA_COLA_ESPERA);                 
    }              
}

std::vector<int> obtenerOrdenado(Area area) {
    size_t  n = obtenerRandomArea(area); 
    std::vector<int> data; 

    for (int i = 0; i < n; ++i) 
        data.push_back(i); 

    return data; 
}

std::vector<int> obtenerInversamenteOrdenado(const std::vector<int> &data) {
    size_t n = data.size(); 
    std::vector<int> invertido; 

    for (int i = 0; i < n; ++i) {
        invertido.push_back(data[(n-i)-1]); 
    }

    return invertido; 
}

std::vector<int> obtenerDuplicado(const std::vector<int>& data) {
    size_t n = data.size(); 
    std::vector<int> duplicado; 

    int duplicar = 3, maximo = 10;  

    for (auto valor : data) {
        if (obtenerRandom(0, maximo) <= duplicar && !duplicado.empty()) {
            int posicion = obtenerRandom(0, (duplicado.size()-1)); 
            duplicado.push_back(duplicado[posicion]); 
            continue;   
        } 

        duplicado.push_back(valor); 
    }   //  valor

    return duplicado; 
}

/*  FUNCION INEFICIENTE: 
        Posible solucion: Dividir el n a traves de recursividad y obtener aleatorios por cada sub-vector
*/  
std::vector<int> obtenerSinDuplicado(const std::vector<int> &data) {
    int n = data.size(); 
    std::vector<int> sinDuplicados;     
 
    int minimo = 0, maximo = (n-1);   //  Si minimo y maximo iguales no termina.   
    std::vector<int> posiciones;        

    for (int i = 0; i < n; ++i) {        

        if (minimo == maximo) break;  
            
        int posicion = obtenerRandom(minimo, maximo);                 

        while (posiciones.end() != std::find(posiciones.begin(), posiciones.end(), posicion)) {            
            posicion = obtenerRandom(minimo, maximo);            
        }
        
        posiciones.push_back(posicion);
        sinDuplicados.push_back(posicion);

        if (cambiarMaximo(n, posiciones, posicion)) {             
            std::cout << "maximo cambiado de "<< maximo;  
            maximo = posicion; 
            std::cout << " a " << maximo << std::endl;                     
            continue;
        }

        if (cambiarMinimo(n, posiciones, posicion, minimo)) {
            std::cout << "minimo cambiado de "<< minimo;
            minimo = posicion; 
            std::cout << " a " << minimo << std::endl;             
        }         
    }    

    return sinDuplicados; 
}

bool cambiarMaximo(size_t n, const std::vector<int>& posiciones,int posicion) {
    int cantidad_sucesores = 0;       

    for (auto& valor : posiciones) {
        if (valor >= posicion) {
            ++cantidad_sucesores; 
        }

    }

    if (cantidad_sucesores == (n-posicion)) {
        //std::cout << "Tamanno = " << posiciones.size() << std::endl;         
        //std::cout << "Cantidad de sucesores = " << cantidad_sucesores << " igual que " << n-posicion << std::endl; 
        return true;    
    }        

    return false; 
}

bool cambiarMinimo(size_t n, const std::vector<int>& posiciones,int posicion, int minimo) {
    int cantidad_antecesores = 0;       
    //  si posicion es 0,no se hace cambio. Mantener condicion <= ya hacer cambios con contador >= 1
    if (posicion == 0) return false; 

    for (auto& valor : posiciones) {
        if (valor <= posicion) {
            ++cantidad_antecesores; 
        }

    }
    if (cantidad_antecesores == (posicion+1)) {
        //std::cout << "Tamanno = " << posiciones.size() << std::endl;
        //std::cout << "Cantidad de antecesores = " << cantidad_antecesores << " igual que " << posicion << std::endl;
        return true;    
    }        

    return false; 
}