#include <iostream>
#include <cstdlib>

using namespace std;

int nesimo(int B[], int pos, int p, int r);
int main()
{
    int cases;
    cin >> cases;
    int r, nesimo_, suma = 0;
    for (int i=1; i<=cases; i++){
        cin >> r;
        int B[r];
        for(int j=1; j <= r; j++){
            cin >> B[j-1]; 
        }
        nesimo_ = nesimo(B,r/2, 0,r-1);
        for(int k=0; k <=r-1; k++){
            suma += abs(B[k]-nesimo_);
        }
        cout << suma << '\n';
        suma = 0;
    };
    
    return 0;
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

int nesimo(int B[], int pos, int p, int r)
{
    int pos_p = particiona(B,p,r);
    /*
    cout << "pos_p=" <<pos_p << " p=" <<p<< " r="<<r<<  "\n";
    for (int i = 0; i<= 12; i++)
        cout << B[i] << " ";
    cout << '\n' << '\n';
    */
    
    if( pos_p == pos){
        return B[pos_p];
    }
    if(pos < pos_p)
        nesimo(B,pos,0,pos_p-1);
    else
        nesimo(B,pos, pos_p+1, r);
}
