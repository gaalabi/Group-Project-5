#include "amigo.h"

amigo::amigo()
{
    _name = " ";
    _money = 0.0;
    _percent = 0.0;
}
amigo::amigo(string name)
{
    _name = name;
    _money = (rand()%900) + 100;
    _percent = _money*0.15;
}
string amigo::getName() const
{
    return _name;
}
double amigo::getCash() const
{
    return _money;
}
void amigo::dockMoney(int time)
{
    _money = _money-(_percent*time);
}
bool amigo::outOfMoney()
{
    return (_money <= 0);
}
void amigo::print()
{
    cout << "Name: " <<_name<< ", Money: " << _money<<endl;
}
amigo::~amigo()
{
    //dtor
}
