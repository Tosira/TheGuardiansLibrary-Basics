#include "Flujo.h"

void descartar_datos() {
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
}

//  Verifica la entrada del usuario para que ingrese solo tipos de dato int. 
//  OBS: No considdera el ingreso de datos int con caracteres. 
int input_entero(const std::string txt) {
    int numero = 0;
    bool cin_fail = false; 
    do{           
        if (cin_fail){
            std::cout << "Dato incorrecto. Vuelva a intentarlo\n";   
            std::cin.clear(); 
            descartar_datos();                      
        }      
        std::cout << txt; 
        std::cin >> numero;         
        cin_fail = std::cin.fail();             
    }while(cin_fail == true); 
    
    return numero; 
}