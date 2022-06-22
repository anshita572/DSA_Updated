#include <iostream>
using namespace std;
int main()
{
    char st[] = "ABCD";
    for (int i = 0; st[i] != '\0'; i++)
    {
        cout <<"First : "<< st[i] << endl;
        cout <<"Second : "<< *(st) + i << endl;
        cout <<"Third : "<< *(i + st) << endl;
        cout <<"Fourth : "<< i[st] << endl;
    }
    return 0;
}