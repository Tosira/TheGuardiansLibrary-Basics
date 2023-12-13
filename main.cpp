#include <iostream> 
#include <vector>
//#include <ctime>
#include <chrono>
#include "Algoritmo.h"
#include "Generar.h"

using namespace std; 
using namespace std::chrono; 

void funcion(vector<int> &data) {

    for (int i = 0; i < 10000000; ++i); 

}

/*double procesar_informacion (vector<int> &data, void (*algortimo)(vector<int>&)) {
    time_t start, end; 
    double time_taken;
    
    time(&start);

    ios_base::sync_with_stdio(false); 
    algortimo(data);     

    time(&end);   

    time_taken = difftime(end, start); 
    return time_taken; 
}*/

double procesar_informacion(vector<int> &data, void (*algoritmo)(vector<int>&)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    algoritmo(data);

    high_resolution_clock::time_point fin = high_resolution_clock::now();
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();
}

double procesar_informacion(vector<int> &data, void (*algoritmo)(vector<int>&, const int low, const int high)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    size_t size = data.size(); 
    algoritmo(data, 0, size-1);

    high_resolution_clock::time_point fin = high_resolution_clock::now();
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();    
}

double procesar_informacion(vector<int> &data, std::vector<int> (*algoritmo)(vector<int>&)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    data = algoritmo(data);

    high_resolution_clock::time_point fin = high_resolution_clock::now();
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();    
}

//  Pasar por referencia y no por valor para no crear copia. 
void imprimirLista(const vector<int> &data) {
    int contador = 0; 
    
    for (auto valor : data) {
        cout << valor << "(" << contador << ")" << ", ";  
        contador++; 
    }

    cout << endl;     
}

int main () {

    vector<vector<int>> trazabilidad_objetos;
    vector<vector<int>> eventos_escenario;
    vector<vector<int>> cola_espera;
    
    trazabilidad_objetos.push_back(obtenerDuplicado(trazabilidadObjetos));     
    
    imprimirLista(trazabilidad_objetos[0]);

    /*
    vector<int> data = {9,0,4,10,1,3,15,13,7}; 
    double tiempo; 

    tiempo = procesar_informacion(data, heapSort);
    
    cout << tiempo << endl;

    imprimirLista(data);
    */

    return 0; 
}