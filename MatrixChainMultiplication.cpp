#include<bits/stdc++.h>

using namespace std;

int Matrix(int v[], int n)
{
    int arr[n][n];

    for(int i =0 ; i<n ; i++)
    {
            arr[i][i]=0;
    }
    int j;

    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            j=i+l;
            for(int k=0;k<j;k++)
            {
                int q=arr[i][k]+arr[k+1][j]+v[i]*v[k]*v[j];
                if(q<arr[i][j])
                arr[i][j]=q;
            }
        }
    }

    return arr[1][n-1];
}

int main() 
{ 
    int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d ", 
                       MatrixChainOrder(arr, size)); 
   
    return 0; 
} 
