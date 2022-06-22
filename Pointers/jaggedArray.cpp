//https://www.geeksforgeeks.org/jagged-array-or-array-of-arrays-in-c-with-examples/
#include<iostream>
using namespace std;
int main(){
int row0[4]={1,2,3,4};//row0 of jagged array
int row1[2]={5,6};   //row1 of jagged array
int *jaggedArray[2]={row0,row1}; //creating jagged array
int arraySize[2]={4,2}; //size of jagged array
int k=0;
for(int i=0;i<2;i++)
{
    int *p=jaggedArray[i];
    
    for(int j=0;j<arraySize[k];j++)
    {
        cout<<*p<<" ";
        *p++;
    }
    cout<<endl;
    k++;
    jaggedArray[i]++;
}

return 0;
}