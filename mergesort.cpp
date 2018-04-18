#include<iostream>
#include<cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}


void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    for(int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

void intercala(int *A, int p, int q, int r)
{
	int B[r-p+1], i, j;
	for(i=p; i!=q+1; i++)
		B[i] = A[i];
	for(j=q+1; j!=r+1; j++)
		B[r+q+1-j] = A[j];
	i = p;
	j = r;
	for(int k = p; k != r+1; k++){
		if(B[i] <= B[j]){
			A[k] = B[i];
			i++;
		}
		else{
			A[k] = B[j];
			j--;
		}
	}
}

void mergesort(int *I, int p, int r)
{
	int q;
	if(p<r){
		q = ceil((p+r)/2);
		mergesort(I,p,q-1);
		mergesort(I,q+1,r);
		intercala(I,p,q,r);
	}
}

int *gen(int n)
{
	int *arr = new int[n];
	for(int i=0; i!=n; i++){
		arr[i] = rand() % n;
	} 
	return arr;
}

int main()
{
	int n = 100;
	int *I;
	I = gen(n);	
	int O[n];	
	time_t t_ini, t_fin;
   	t_ini = clock();
	TopDownMergeSort(I,O,n);
	t_fin = clock();
   	cout <<"wiki: "<< static_cast<double>(t_fin - t_ini)<< '|';
	
	
	for(int i = 0; i != n; i++)
		cout << I[i] << ' ';
	cout << '\n';
	//------------------------------------
	int *I2;
	I2 = gen(n);
   	t_ini = clock();
	mergesort(I2,0,n-1);
	t_fin = clock();
   	cout <<"clase: "<< static_cast<double>(t_fin - t_ini)<< '|';
	
	for(int i = 0; i != n; i++)
		cout << I2[i] << ' ';
	cout << '\n';
	
	
	
	
	return 0;//tiempo y n----299, train swapping. 10327 flip sort.
}









