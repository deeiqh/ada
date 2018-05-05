#include <iostream>
#include <cstdlib>

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



void TopDownMergeSort(double A[], double B[], int n)
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

int main()
{
        int n = 100;
	double *I;
	I = gen(n);	
	double O[n];		
	time_t t_ini, t_fin;
   	t_ini = clock();
	TopDownMergeSort(I,O,n);
	t_fin = clock();
   	cout <<"wiki: "<< static_cast<double>(t_fin - t_ini)<< '|';
	
	

        
        
        return 0;
}
