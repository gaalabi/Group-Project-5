#include "amigo.hpp"


amigo::amigo()
{
    _name = " ";
    _money = 0.0;
    _percent = 0.0;
    deadRound = 0;
}
amigo::amigo(string name)
{
    _name = name;
    _money = (rand()%900) + 100;
    _percent = _money*0.15;
    deadRound = -1;
}
string amigo::getName() const
{
    return _name;
}
double amigo::getCash() const
{
    return _money;
}
int amigo::getDeadRound() const
{
    return deadRound;
}
void amigo::dockMoney(int time)
{
    _money -= (_percent*time);
}
void amigo::setDeadRound(int roundNum)
{
    deadRound = roundNum;
}
void amigo::setCash(double cash_amount)
{
    _money = cash_amount;
}
void amigo::setpercent(double Percent)
{
    _percent = Percent;
}

bool amigo::outOfMoney()
{
    return (_money <= 1.0);
}
void amigo::print()
{
    cout << "Name: " <<_name<< ", \tMoney: " << _money<<endl;
    if (deadRound != -1){
        cout<<"bankrupt @ rotation #: "<<deadRound<<endl<<endl;
    }
    else{
        cout<<"not yet bankrupt! "<<endl<<endl;    }
}
amigo::~amigo()
{
    //dtor
}
