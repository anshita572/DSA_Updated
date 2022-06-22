#include<iostream>
using namespace std;
void update_address_double_ptr(int **ptr)
{
    ptr=ptr+1;  //no change in main function

}
void update_value_of_single_ptr(int**ptr)   //or address of i
{
    *ptr=*ptr+1;   //value inside p1 will be upated(increse by 4 as it is int) in main
}
void update_value_of_i(int **ptr)
{
    **ptr=**ptr+1;   //value of i will be incremented by 1 in main
}
int main(){
int i = 6;
    int *p1 = &i;
    int **p2 = &p1; //Double pointer
    cout<<"Before : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;
    update_address_double_ptr(p2);
    cout<<endl;
    cout<<"After : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;


/*cout<<"Before : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;
     cout<<"Value stored inside p1"<<*p1<<endl;
    update_value_of_single_ptr(p2);
    cout<<endl;
    cout<<"After : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;
    cout<<"Value stored inside p1"<<*p1<<endl;
    */
cout<<"Before : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;
     cout<<"Value stored inside p1"<<*p1<<endl;
    update_value_of_i(p2);
    cout<<endl;
    cout<<"After : "<<endl;
    cout<<"value of i : " <<i<<endl;
    cout<<"Value of p1(i.e Address of i) : " <<p1<<endl;
    cout<<"Value of p2(i.e. Address of p1) : " <<p2<<endl;
 cout<<"Value stored inside p1"<<*p1<<endl;
return 0;
}