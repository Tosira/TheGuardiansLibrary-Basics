#include <iostream> 
#include <vector>
#include <chrono>
#include <map>
#include "Algoritmo.h"
#include "Generar.h"
#include "Flujo.h"

using namespace std; 
using namespace std::chrono; 

const string ordenado = "Ordenado"; 
const string ordenInverso = "Ordenado Inversamente"; 
const string conDuplicados = "Aleatorio Con duplicados"; 
const string sinDuplicados = "Aleatorio Sin duplicados"; 

struct Historial {
    string caso;
    string entrada;  
    string ganador; 
    size_t size_entrada; 
    map<int, pair<string,double>> tiempos; 
};

//  Busca en el struct Historial el tiempo menor de cada carrera para poder ser mostrado en panatalla con su algoritmo de ordenamiento. 
void identificarAlgoritmoGanador(struct Historial &historial) {
    string algoritmo; 
    double tiempo = 1000; 

    for (auto& par : historial.tiempos) {
        if (par.second.second < tiempo) {
            algoritmo = par.second.first; 
            tiempo = par.second.second; 
        }   
    }

    historial.ganador = algoritmo; 

    cout << "El ganador es: " << historial.ganador << " con un tiempo de " << tiempo << endl; 

    cout << endl;
}

//  Retorna indice del vector de vectores de cualquier tipo de carrera. Ademas, gracias al filtrado se almacena la entrada en el struct historial.  
int obtenerIndiceVector(int opcion, struct Historial &historial) {
    if (opcion == 1) {
        historial.entrada = ordenado; 
        return 0; 
    }
    if (opcion == 2) {
        historial.entrada = ordenInverso; 
        return 1; 
    }
    if (opcion == 3) {
        historial.entrada = conDuplicados; 
        return 2; 
    }
    if (opcion == 4) {
        historial.entrada = sinDuplicados; 
        return 3; 
    }
    return 0; 
}

//  Las funciones 'tomar_tiempo' se encargan de medir el tiempo que demora cada algoritmo de ordenamiento segun 'data'. 
double tomar_tiempo(vector<int> &data, void (*algoritmo)(vector<int>&)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    algoritmo(data);

    high_resolution_clock::time_point fin = high_resolution_clock::now();
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();
}

double tomar_tiempo(vector<int> &data, void (*algoritmo)(vector<int>&, const int low, const int high)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    size_t size = data.size(); 
    algoritmo(data, 0, size-1);

    high_resolution_clock::time_point fin = high_resolution_clock::now();
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();    
}

double tomar_tiempo(vector<int> &data, std::vector<int> (*algoritmo)(vector<int>&)) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    ios_base::sync_with_stdio(false);
    data = algoritmo(data);

    high_resolution_clock::time_point fin = high_resolution_clock::now();    
        //  tipo    formato(suyacente)
    duration<double, milli> tiempo_transcurrido = duration_cast<duration<double, milli>>(fin - inicio);
    return tiempo_transcurrido.count();    
}

//  Llama a cada uno de los algoritmos para la entrada, y elmacena en el historial los timepos resultantes. 
void procesar_entrada(vector<int> &data, struct Historial &historial) {

    cout << endl; 
    cout << "Carrera " << historial.caso << ", Modo " << historial.entrada << endl; 

    map<int, pair<string, double>> tiempos; 

    double tiempo_selectionSort = tomar_tiempo(data, selectionSort)/1000;
    tiempos[1] = make_pair(nombreAlgoritmo::selectionSort, tiempo_selectionSort);  
    
    double tiempo_bubbleSort = tomar_tiempo(data, bubbleSort)/1000;
    tiempos[2] = make_pair(nombreAlgoritmo::bubbleSort, tiempo_bubbleSort);  
    
    double tiempo_insertionSort = tomar_tiempo(data, insertionSort)/1000;
    tiempos[3] = make_pair(nombreAlgoritmo::insertionSort, tiempo_insertionSort);  
    
    double tiempo_shellSort = tomar_tiempo(data, shellSort)/1000;
    tiempos[4] = make_pair(nombreAlgoritmo::shellSort, tiempo_shellSort);  
    
    double tiempo_mergeSort = tomar_tiempo(data, mergeSort)/1000;
    tiempos[5] = make_pair(nombreAlgoritmo::mergeSort, tiempo_mergeSort);  
    
    double tiempo_quickSort = tomar_tiempo(data, quickSort)/1000;
    tiempos[6] = make_pair(nombreAlgoritmo::quickSort, tiempo_quickSort);  
    
    double tiempo_heapSort = tomar_tiempo(data, heapSort)/1000;
    tiempos[7] = make_pair(nombreAlgoritmo::heapSort, tiempo_heapSort);  
    
    historial.tiempos = tiempos;

    cout << nombreAlgoritmo::selectionSort << ", " << tiempo_selectionSort << " s " << endl;   
    cout << nombreAlgoritmo::bubbleSort << ", " << tiempo_bubbleSort <<" s " << endl;   
    cout << nombreAlgoritmo::insertionSort << ", " << tiempo_insertionSort <<" s " << endl;   
    cout << nombreAlgoritmo::shellSort << ", " << tiempo_shellSort <<" s " << endl;   
    cout << nombreAlgoritmo::mergeSort << ", " << tiempo_mergeSort <<" s " << endl;   
    cout << nombreAlgoritmo::quickSort << ", " << tiempo_quickSort <<" s " << endl;   
    cout << nombreAlgoritmo::heapSort << ", " << tiempo_heapSort <<" s " << endl;             
}

void imprimirLista(const vector<int> &data, string tipo) {
    int contador = 0; 
    
    cout << tipo << endl << endl; 
    for (auto valor : data) {
        cout << valor << "(" << contador << ")" << ", ";  
        contador++; 
    }

    cout << endl;     
}

//  Compruba que la entrada sin duplicados no contenga numeros duplicados. 
bool comprobarRepetidos(const vector<int> &data) {
    int contador = 0;  
    size_t n = data.size();

    for (int i = 0; i < n; ++i) {
        for (int e = 0; e < n; ++e) {
            if (data[i] == data[e]){
                //cout << data[i] << " igual que " << data[e] << " en " << e << endl;  
                contador++; 
            }
            if (contador > 1)   
                return false; 
        }
        //cout << "* "; 
        contador = 0; 
    }

    return true; 
}

//  Procesa o carga la entrada segun la opcion del usuario. 
void caso(int opcion_entrada, vector<vector<int>> &data, vector<struct Historial> &historial, size_t &size_data, Area area) {
    if (data.empty()) {
        if (area == colaEspera) {
            cout << "Debido a un problema de diseno, este carga de datos puede tardar varios minutos (mas de 8).\n" <<
                    "Procure no cerrar el programa para no pasar por esta espera nuevamente.\n"; 
        }  
        cout << "Cargando datos... Por favor, espere\n"; 
        data.push_back(obtenerOrdenado(area));
        size_data = data[0].size(); 
        data.push_back(obtenerInversamenteOrdenado(data[0]));   
        data.push_back(obtenerSinDuplicado(data[0]));
        data.push_back(obtenerDuplicado(data[2]));

        if (comprobarRepetidos(data[2])) {
            cout << "Test Completado\n"; 
        }
    }


    cout << "Entrada con tamanno de " << size_data << " elementos." << endl; 
    Historial h = Historial();
    h.caso = nombreCaso::trazabilidadObjetos;  
    h.size_entrada = size_data; 
    vector<int> temp = data[obtenerIndiceVector(opcion_entrada, h)];
    procesar_entrada(temp, h); 
    identificarAlgoritmoGanador(h);
    historial.push_back(h);
}

int main () {

    vector<vector<int>> trazabilidad_objetos;
    vector<vector<int>> eventos_escenario;
    vector<vector<int>> cola_espera;         

    size_t size_trazabilidad_objetos = 0; 
    size_t size_eventos_escenario = 0;      
    size_t size_cola_espera = 0;            

    // imprimirLista(trazabilidad_objetos[0], "Ordenado"); 
    // imprimirLista(trazabilidad_objetos[1], "Inverso"); 
    //  imprimirLista(trazabilidad_objetos[2], "Sin duplicados"); 
    // imprimirLista(trazabilidad_objetos[3], "Con duplicados");

    // imprimirLista(eventos_escenario[0], "Ordenado"); 
    // imprimirLista(eventos_escenario[1], "Inverso"); 
    // imprimirLista(eventos_escenario[2], "Sin duplicados"); 
    // imprimirLista(eventos_escenario[3], "Con duplicados");

    // imprimirLista(cola_espera[0], "Ordenado"); 
    // imprimirLista(cola_espera[1], "Inverso"); 
    // imprimirLista(cola_espera[2], "Sin duplicados"); 
    // imprimirLista(cola_espera[3], "Con duplicados");    

    vector<struct Historial> historial;  

    int opcion = 1; 
    while (opcion != 0) {
        opcion = input_entero("Escoja el modo de carrera:\n"
                    "<1> Trazabilidad de Objetos\n"
                    "<2> Eventos de Cada Escenario\n"
                    "<3> Cola de Espera\n"
                    "<0> Sair\n"
                    "opcion: ");     

        int opcion_entrada = 0; 
        if (opcion != 0) {            
            opcion_entrada = input_entero("Seleccione el tipo de entrada:\n"
                                    "<1> Orden\n"
                                    "<2> Orden inverso\n"
                                    "<3> Con duplicados\n"
                                    "<4> Sin duplicados\n"
                                    "opcion: ");        
        }

        //  Funcion generica para casos 
        switch (opcion)
        {
            case 1:
            {                
                caso(opcion_entrada, trazabilidad_objetos, historial, size_trazabilidad_objetos, trazabilidadObjetos);                                            
                break;
            }
            
            case 2:
            {
                caso(opcion_entrada, eventos_escenario, historial, size_eventos_escenario, eventosEscenario);                                            
                break;
            }

            case 3:
            {
                caso(opcion_entrada, cola_espera, historial, size_cola_espera, colaEspera);            
                break;                
            }

            default:
                break;
        }   //  switch

    }

    cout << endl; 

    cout << "Resultados de los Algoritmos\n"; 
    for (auto& h : historial) {
        cout << "Caso: " << h.caso << endl 
            << "Entrada: " << h.entrada << endl 
            << "Tamanno entrada: " << h.size_entrada << endl
            << "Ganador: " << h.ganador << endl;

        for (auto& par : h.tiempos) {
            cout << par.second.first << ", "
                << par.second.second << " s " << endl;   
        }   

        cout << endl;
    }

    return 0; 
}