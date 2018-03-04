#include <iostream>
#include "clist.hpp"
#include "amigo.hpp"

using namespace std;

int fib(int n);

int main()
{
    clist<amigo> n;
    int len;
    
    cout << "Enter the number of rounds: " << endl;
    cin >> len;
    
    int rounds[len];
    
    for(int i = 0; i < len; i++)
    {
        rounds[i] = fib(i+1);
        cout << rounds[i] << " ";
    }
    
    cout << endl;
    
    amigo am1("Jack");
    amigo am2("Bob");
    amigo am3("Sam");
    amigo am4("Mike");
    amigo am5("Am");
    
    n.insert_END(am1);
    n.insert_END(am2);
    n.insert_END(am3);
    n.insert_END(am4);
    n.insert_END(am5);
    
    
    
    cout<<endl<<endl<<endl;
    cout<<"Before the game:"<<endl;
    n.print();
    
    for(int i = 0; i < len; i++)
    {
        cout<<endl<<endl<<endl;
        cout<<"After Round: "<<i+1<<endl;
        n.Vegas(rounds, len,i);
        n.print();
    }
    
    
    
    return 0;
}












int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    
    return fib(n-1)+fib(n-2);
}
