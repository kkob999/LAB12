#include <iostream>
#include <cmath>
#include<cstdlib>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[],int N,double b[]){
    double sum=0,sumSD=0,multi=1,sumHAR,max=a[0],min=a[0];
    for(int i=0; i<N; i++){
        sum += a[i];
        multi *= a[i];
        sumHAR += 1/a[i];
        if(a[i]>max) max = a[i];
        if(a[i]<min) min = a[i];
    }
    b[0]= sum/N;
    for(int i=0; i<N; i++){
        sumSD += pow(a[i],2) - pow(b[0],2);
    }
    b[1]=sqrt(sumSD/N);
    b[2]=pow(multi,1.0/N);
    b[3]=N/sumHAR;
    b[4]=max;
    b[5]=min;
}
