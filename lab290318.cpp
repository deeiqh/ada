#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL));

    double esperado[21]{0};
    cout << "Esperado para 10\n--------------------------------------------";
    for(int i=1; i<=10; i++){
        int contador,maximo;
        for(int j=8; j<=20; j++){
            vector<int> v;//de tamaño pow(2,j)
            for(int k=1; k<=pow(2,j)-1; k++){
                v.push_back(rand()%INT_MAX+1);
            }
            contador=0;
            maximo=0;
            for(int l=1; l<=pow(2,j); l++){
                if(v[l]>maximo){
                    maximo = v[l];
                    contador++;
                }
            }
            esperado[j] += contador;
        }
    }
    
    cout << "-------------------------------------------------------\n";
    cout << "esperado para 10: \n";
    for(int i=8; i<=20; i++){
        cout << esperado[i]/12.0 << '\n';
    }
    cout << "-------------------------------------------------------\n";
    
    
    /*
    tarea: será que la cantidad de swaps en el particiona de quicksort 
    también se asemeja a nlgn, nlgn? traer codigo
    
    /*
    esperado = 0;
    esperado2 = 0;    
    for(int i=1; i<=100; i++){
        int contador,maximo;
        for(int j=8; j<=20; j++){
            vector<int> v;//de tamaño pow(2,j)
            for(int k=1; k<=pow(2,j)-1; k++){
                v.push_back(rand()%INT_MAX+1);
            }
            contador=0;
            maximo=0;
            for(int l=1; l<=pow(2,j); l++){
                if(v[l]>maximo){
                    maximo = v[l];
                    contador++;
                }
            }
            esperado += contador;
            cout << "esperado para 2^" << j << "=" << esperado << '\n';
        }
        esperado/=20-8;
        esperado2 += esperado;
    }
    
    cout << "-------------------------------------------------------\n";
    cout << "esperado para 100: " << esperado2/(100) << '\n'; 
    cout << "-------------------------------------------------------\n";
    
    esperado = 0;
    esperado2 = 0;  
    for(int i=1; i<=200; i++){
        int contador,maximo;
        for(int j=8; j<=20; j++){
            vector<int> v;//de tamaño pow(2,j)
            for(int k=1; k<=pow(2,j)-1; k++){
                v.push_back(rand()%INT_MAX+1);
            }
            contador=0;
            maximo=0;
            for(int l=1; l<=pow(2,j); l++){
                if(v[l]>maximo){
                    maximo = v[l];
                    contador++;
                }
            }
            esperado += contador;
            cout << "esperado para 2^" << j << "=" << esperado << '\n';
        }
        esperado/=20-8;
        esperado2 += esperado;
    }
    
    cout << "-------------------------------------------------------\n";
    cout << "esperado para 200: " << esperado2/(200) << '\n'; 
    cout << "-------------------------------------------------------\n";
    */
    return 0;
}
