#include<iostream>
#include<vector>
#include<fstream>
#include<map>

using namespace std;
using pii = pair<int,int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

int valor(vvi matriz, int actual_f, int actual_c, int origen_f, int origen_c);

int main()
{
    //--------lectura
    fstream in;
    fstream out;
    in.open("in.txt",fstream::in);
    out.open("out.txt",fstream::out);
	int N;
	in >> N; //entre 1 y 100	
	vector<vector<int>> matriz;
	for(int i=1; i<=N; i++){
		vector<int> fila; 
		int e;
		for(int j=1; j<=N; j++){
			in >> e;		
			fila.push_back(e);
		}
		matriz.push_back(fila);
	}
	in.close();
	/*
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << matriz[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	//--------dinámica
	
	//inicializa estructuras
	map<pii,vvi> matrices;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			vvi matriz;			
			for(int k=i; k<N; k++){
			    vi fila;
			    for(int l=j; l<N; l++){
			        fila.push_back(0);
			    }
			    matriz.push_back(fila);
		    }
		    matrices[pii(i,j)] = matriz;
		}
	}
	
	//procedimiento, parte de (0,0), va generando las demás partidas
	for(int f=0; f<N; f++){
		for(int c=0; c<N; c++){
		    //ejm, en fila 3, jalando para -1(3,0), 8(3,1), 0(3,2), -2(3,3)
		    
		}
	}
	
	
	
	
	out.close();
	return 0;
}

int valor(vvi matriz, int actual_f, int actual_c, int origen_f, int origen_c)
{
    int f = actual_f - origen_f;
    int c = actual_c - origen_c;
    int valor;
    if(f>0 && c>0){
        valor = matriz[f][c-1] + matriz[f-1][c] - matriz[f-1][c-1] + matriz[f][c];        
    }else if(f==0 && c>0){
        valor = matriz[f][c-1] + matriz[f][c];
    }else{
        valor = matriz[f][c];
    }    
    return valor;
}
























