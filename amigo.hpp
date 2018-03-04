#ifndef AMIGO_H
#define AMIGO_H
#include <iostream>
#include <cstdlib>

using namespace std;

class amigo
{
public:
    
    amigo();
    amigo(string name);
    string getName() const;
    double getCash() const;
    int getDeadRound() const;
    void dockMoney(int time);
    bool outOfMoney();
    void setDeadRound(int roundNum);
    void setCash(double cash_amount);
    void setpercent(double Percent);
    virtual ~amigo();
    friend inline bool operator==(const amigo &lhs, const amigo &rhs)
    {
        return(lhs.getName()==rhs.getName());
    }
    void print();
    
protected:
    
private:
    string _name;
    double _money;
    double _percent;
    int deadRound;
    
};

#endif // AMIGO_H
