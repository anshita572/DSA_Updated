#include <iostream>
using namespace std;
void reachHome(int source, int destination)
{ cout<<"Source = "<<source<<" Destination = "<<destination<<endl;
    if (source == destination)
    {
        cout << "Reached" << endl;
        return;
    }
    
    reachHome(source + 1, destination);
}
int main()
{
    int source, destination;
    cout << "Enter source : " << endl;
    cin >> source;
    cout << "Enter detsination : " << endl;
    cin >> destination;
    cout << endl;
    reachHome(source, destination);
}

