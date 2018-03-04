#ifndef CLIST_H
#define CLIST_H
#include <iostream>

using namespace std;

template <class D>
class clist
{
public:
    
    clist();
    void insert_START(D i);
    void insert_END(D i);
    void delete_START();
    void delete_END();
    void deleteKey(D key);
    void destruct();
    void print();
    
    void Vegas(int *rounds, int roundsNum,int cuRound);
    
    
    bool isEmpty();
    
    
    
    
    virtual ~clist();
    
protected:
    
private:
    
    struct node
    {
        D info;
        
        node *next;
        
    };
    
    node *head , *tail, *curr, *temp;
    int nodeCount;
};

#endif // CLIST_H

template <class D>
clist<D>::clist()
{
    tail = nullptr;
    curr = nullptr;
    temp = nullptr;
    nodeCount = 0;
}
template <class D>
void clist<D>::insert_START(D i)
{
    node *n = new node;
    n->info = i;
    n->next = nullptr;
    
    if(tail == nullptr)
    {
        tail = n;
        n->next = n;
    }
    else
    {
        n->next = tail->next;
        tail->next = n;
        
    }
    nodeCount++;
}
template <class D>
void clist<D>::insert_END(D i)
{
    node *n = new node;
    n->info = i;
    n->next = nullptr;
    
    if(tail == nullptr)
    {
        tail = n;
        n->next = n;
    }
    else
    {
        n->next = tail->next;
        tail ->next = n;
        tail = n;
    }
    
    nodeCount++;
}
template <class D>
void clist<D>::delete_START()
{
    if(!this->isEmpty())
    {
        curr = tail->next;
        tail->next = curr->next;
        
        delete curr;
        
        nodeCount--;
    }
    
    
}
template <class D>
void clist<D>::delete_END()
{
    if(!this->isEmpty())
    {
        temp = tail->next;
        
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        
        curr = tail;
        
        temp->next = curr->next;
        tail = temp;
        
        delete curr;
        
        
        nodeCount--;
        
    }
}
template <class D>
void clist<D>::destruct()
{
    if(!this->isEmpty())
    {
        
        
        while(tail->next != tail)
        {
            
            this->delete_END();
        }
        
        delete tail;
        
        tail = nullptr;
        
    }
    
}
template <class D>
void clist<D>::deleteKey(D key)
{
    if(!isEmpty())
    {
        bool found = false;
        curr = tail->next;
        
        do
        {
            if(curr->info == key)
            {
                found = true;
            }
            
            curr = curr->next;
            
        }while(curr != tail->next);
        
        if(found)
        {
            curr = tail->next;
            
            while(!(curr->next->info == key))
            {
                curr = curr->next;
            }
            
            temp = curr;
            curr = curr->next;
            
            temp->next = curr->next;
            
            delete curr;
            
        }
        else
        {
            cout << "Item not in index" << endl;
        }
        
        
    }
    
    
    
}
template <class D>
void clist<D>::Vegas(int *rounds, int roundsNum,int cuRound)
{
    int TotalRound = 0;
    for(int i = 0; i < cuRound; i++){     TotalRound += rounds[i];    }
    
    for(int i = 0; i < rounds[cuRound]; i++)
    {
        curr = tail->next;
        for(int j = 0; j < 5; j++){
            if (curr->info.getDeadRound() != -1){ //if already out of money
                curr = curr->next;
                continue;
            }
            else{ //if can still play
                curr->info.dockMoney(1);
                curr->info.setpercent(curr->info.getCash()*.15);
                if(curr->info.outOfMoney()){//if out of money
                    curr->info.setDeadRound(TotalRound+i+1);
                    curr->info.setCash(0.0);
                }
            }
            curr = curr->next;
        }
    }
}






template <class D>
bool clist<D>::isEmpty()
{
    return (tail== nullptr);
}
template <class D>
void clist<D>::print()
{
    if(!this->isEmpty())
    {
        curr = tail->next;
        
        do{
            
            curr->info.print(); //prints with print function
            curr = curr->next;
            
        }while(curr != tail->next);
        
    }
}


template <class D>
clist<D>::~clist()
{
    if(!this->isEmpty())
    {
        this->destruct();
        
    }
    
    tail = nullptr;
    curr = nullptr;
    temp = nullptr;
}
