#include<iostream>
using namespace std;
 void Q(int z)  //value passed in z=7
    {
        z += z;//z=7+7=14
        cout<<z << " ";
    }

    void P(int *y) //in this function x(main wala nhi h),so *y iss function k 'x' ko nhi point kr rha h
    { //cout<<*y<<endl;
        int x = *y + 2; //x=5+2=7
        Q(x);//iss function m no change
        *y = x - 1; //*y=7-1=6 i.e main wala x =6
       // cout<<*y<<endl;
        cout<<x << " ";  //x=7
    }

    int main()
    {
        int x = 5;
        P(&x);
       cout<<x;
        return 0;
    }

