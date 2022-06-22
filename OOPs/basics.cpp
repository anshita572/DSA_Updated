#include <iostream>
//#include"hero.cpp"
using namespace std;
class hero
{ // properties of hero class
private:
    int health;

public:
    char level;
    hero()    //Default constructor
    {
        cout<<"Constructor called"<<endl;
    }
    hero(int health) //Parameterised constructor
    {
        this->health=health;
        cout<<"this -> "<<this<<endl;
    }
    hero(hero& temp)
    {
        this->health=temp.health;
        this->level=temp.level;
        cout<<"Copy constructor called"<<endl;
    }
    int getHealth() // getter
    {
        return health;
    }
    void setHealth(int h) // setter
    {
        health = h;
    }
    void print()
    {
        cout<<"Level : "<<this->level<<endl;
    }
};
int main()
{
    hero ironMan; // object(ironMan)of hero class (Static Allocation)
    cout << "Size of object ironMan : " << sizeof(ironMan) << endl;
    ironMan.setHealth(80);
    ironMan.level = 'A';
    cout << "Health of ironMan is : " << ironMan.getHealth() << endl;
    cout << "Level of ironMan is : " << ironMan.level << endl;
    ironMan.print();
    // Dynamic allocation
    hero *spiderMan = new hero;
    spiderMan->level='D';
  //OR  (*spiderMan).level='D';
    cout << "Level of spiderMan: " << (*spiderMan).level << endl;
    // OR
    cout << "Level of spiderMan: " << spiderMan->level << endl;
    spiderMan->setHealth(100);
   //OR (*spiderMan).setHealth(100);
    cout<<"Health of spiderMan : "<<spiderMan->getHealth()<<endl;
    hero ninja(45);
    cout<<"Address of ninja : "<<&ninja<<endl;
    hero superman(ironMan);//copy constructor
    //copies health and level of ironMan in superman
    cout<<"Health of superman : "<<superman.getHealth()<<endl;
    superman.print();
  

    return 0;
}