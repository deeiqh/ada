#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

//merge-sort, pseudocodigo de wikipedia

void CopyArray(double A[], int iBegin, int iEnd, double B[])
{
    for(int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

void TopDownMerge(double A[], int iBegin, int iMiddle, int iEnd, double B[])
{
    int i = iBegin, j = iMiddle;
    for (int k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void TopDownSplitMerge(double B[], int iBegin, int iEnd,double  A[])
{
    if(iEnd - iBegin < 2)                       
        return;                            
    
    int iMiddle = (iEnd + iBegin) / 2;                  
    TopDownSplitMerge(A, iBegin,  iMiddle, B); 
    TopDownSplitMerge(A, iMiddle,    iEnd, B); 
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}



void Merge_normal(double A[], double B[], int n)
{
    CopyArray(A, 0, n, B);           
    TopDownSplitMerge(B, 0, n, A);   
}

double *gen(int n)
{
	double *arr = new double[n];
	for(int i=0; i!=n; i++){
		arr[i] = rand() % n;
	} 
	return arr;
}

void insertion_sort(double I[],double O[], int n){
        for(int i = 0; i < n; ++i){
                for(int j = i; j > 0; --j)
                        if(I[j-1] > I[j]){
                                double aux = I[j];
                                I[j] = I[j-1];
                                I[j-1]=aux;
                        }                             
        }
        for(int i = 0; i != n; i++){
                O[i]=I[i];
        }
 
}

void Merge_insert(double A[], double B[], int n)
{
        if(n<= 64){
                insertion_sort(A,B,n);
        }
        else{
                CopyArray(A, 0, n, B);           
                TopDownSplitMerge(B, 0, n, A);   
        }
}

void Merge_quick(double A[], double B[], int n)
{
        if(n<= 64){
                vector<double> v(A,A+n);
                sort (v.begin(), v.end()); 
                for(int i = 0; i < n; ++i){
                        B[i]=v[i];
                }
        }
        else{
                CopyArray(A, 0, n, B);           
                TopDownSplitMerge(B, 0, n, A);   
        }
}

int main()
{

	
	time_t t_ini, t_fin,t_ini2, t_fin2;
	fstream arch;
   	arch.open("vs.txt",fstream::out);
   	double *I;
   	for(int n=1; n != 500; n++){	    
	    I = gen(n);	
	    double O[n];
       	t_ini = clock();       	
	    Merge_insert(I,O,n);	
	    t_fin = clock();     	
   	    arch << n<< " " << static_cast<double>(t_fin - t_ini)/CLOCKS_PER_SEC << "s\t";
   	    t_ini2 = clock();       	
	    Merge_quick(I,O,n);	
	    t_fin2 = clock();     	
	     arch << static_cast<double>(t_fin2 - t_ini2)/CLOCKS_PER_SEC << "s\n";
   	}   
   	arch.close();
   	

   	cout << '\n';   	
   	
   	
	
	
        
        
        
        return 0;
}
