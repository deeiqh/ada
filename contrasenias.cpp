#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>

using namespace std;

int numerifica(string pass);

int main()
{
    //correcciones al enunciado
    //m < 50000
    //maximo 10s
    //longitud de cadena siempre n
    
    fstream out;
    out.open("out.txt",fstream::out);
    
    fstream in;
    in.open("contrasenha.in",fstream::in);
    
    
    int entradas;
    in >> entradas;
    int longitud, cantidad;
    for(int j=1; j<=entradas; j++){
        in >> longitud; in >>cantidad;
        map<int, vector<string>> numeros;
        string pass;
        for(int i=1; i<=cantidad; i++){
            in >> pass;
            numeros[numerifica(pass)].push_back(pass);
        }
        for(auto it=numeros.begin(); it!=numeros.end(); it++){
            for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++){//por si los pass tienen el mismo numero de swaps
                out<<*it2<<'\n';
            }
        }
        out<<'\n';
    }
        in.close();
        out.close();
    return 0;
}

int numerifica(string pass)
{
    string pass_(pass);
    sort(pass.begin(), pass.end());
    int posicion_sort=0;
    int aux[pass.length()]={0};
    bool aux_sort[pass.length()]={true};
    int veces = 0;
    for(int i=0; i<=pass.length()-1; i++){        
        //posicion_sort = distance(lower_bound(pass.begin(), pass.end(),pass[i]),pass.begin());
        for(int x=0; x<pass.length();x++){
            if(pass[x]==pass_[i]){
                posicion_sort=x;cerr<<x<<'\n';
                break;
            }
        }
        while(aux_sort[posicion_sort]==false){
            posicion_sort++;
        }
        aux_sort[posicion_sort] = false;
        veces = posicion_sort - (i+aux[i]); 
        if (veces<=0) break;
        for(int j=1; j<=veces; j++){
            if(i+j<pass.length())
                aux[i+j]--;
        }
    }
}
























