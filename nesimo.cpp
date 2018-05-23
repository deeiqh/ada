#include <iostream>

using namespace std;

int particiona(int A[], int p, int r);
int nesimo(int B[], int tam, int pos, int p, int r);

int main()
{
	int n = 10;
	int A[n] = {99,33,55,77,11,22,88,66,33,44};			
    cout << A[particiona(A,0,n-1)] << '\n';
    
    n = 13;
    int B[n] = {15,10,12,4,6,13,1,5,2,9,10,7,8};    
    cout << nesimo(B,n,2,0,n-1) << '\n';
    //APLICAR A UVA 10041 Y VER LA COMPLEJIDAD DE NESIMO
    
	return 0;
}

int nesimo(int B[], int tam, int pos, int p, int r)
{
    int pos_p = particiona(B,p,r);cout << "pos_p = " <<pos_p << "\n";
    if( pos_p == pos){
        return B[pos_p];
    }
    if(pos < pos_p)
        nesimo(B,pos_p, pos,0,pos_p-1);
    else
        nesimo(B,tam-pos_p-1, pos, pos_p+1, tam-1);
}

int particiona(int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    int t;
    for(int j=p; j<=r-1;j++){
        if(A[j] <= x){
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i+1;
}


















