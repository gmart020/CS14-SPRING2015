//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: Gerardo Martinez
/// SID: 861169126
/// Date: April 20, 2015
///
/// This file contains the generic templates for two 
/// forward_list functions, printLots and listCopy, as
/// well as a function, primeCount, which uses another 
/// function isPrime to count the number of prime numbers
/// in a list recursively.
//  ================== END ASSESSMENT HEADER ===============

#include "lab2.H"
#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;

bool isPrime(int i)
{
    if (i < 2) return false;
    for (int j = 2; j < i; ++j)
    {
        if (i % j == 0) return false;
    }
    return true;
}



int primeCountSearch(forward_list<int> lst)
{
    forward_list<int> copy(lst);
    if (copy.empty()) return 0;
    if (!isPrime(copy.front()))
    {
        copy.pop_front();
        return primeCountSearch(copy);
    }
    copy.pop_front();
    return 1 + primeCountSearch(copy);
}

template <typename Type>
void listCopy(forward_list<Type> list1, forward_list <Type> &list2)
{
    typename forward_list<Type>::iterator it;
    typename forward_list<Type>::iterator that;
    forward_list<Type> temp = list2;
    temp.reverse();
    list2.clear();
    for (it = list1.begin(); it != list1.end(); ++it)
    {
        list2.push_front(*it);
    }
    for (that = temp.begin(); that != temp.end(); ++that)
    {
        list2.push_front(*that);
    }
}

template <typename Type>
void printLots (forward_list <Type> L, forward_list <int> P)
{
    typename forward_list<Type>::iterator i;
    for (auto it = P.begin(); it != P.end(); ++it)
    {
        int pos = 0;
        i = L.begin();
        while (pos <*it)
        {
            if (i == L.end() && pos < *it) return;
            ++pos;
            ++i;
        }
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    // cout << "printLots test" << endl;
    // forward_list<int> test = {2,3,4,5,6,7,8,9,13,19,17,23,31};
    // forward_list<int> sec = {101,201,301};
    // forward_list<int> pos = {3,6,7,8};
    // printLots(test,pos);
    
    // cout << "isPrime test" << endl;
    // cout << isPrime(2) << endl;
    // cout << isPrime(3) << endl;
    // cout << isPrime(4) << endl;
    // cout << isPrime(5) << endl;
    // cout << isPrime(6) << endl;
    // cout << isPrime(7) << endl;
    // cout << isPrime(8) << endl;
    
    // cout << "primeCountSearch and listCopy test" << endl;
    // cout << primeCountSearch(test) << endl;
    // listCopy(sec,test);
    // for (auto it = test.begin(); it != test.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    
    // cout << "elementSwap test" << endl;
    // List<int> l1;
    // l1.push_back(3);
    // l1.push_back(4);
    // l1.push_back(5);
    // l1.push_back(6);
    // l1.push_back(7);
    // l1.display();
    // cout << l1.size();
    // cout << endl;
    // l1.elementSwap(1);
    // l1.display();
    // l1.elementSwap(-1);
    // l1.display();
    // l1.elementSwap(8);
    // l1.display();
    // l1.elementSwap(0);
    // l1.display();
    // l1.elementSwap(2);
    // l1.display();
    // l1.elementSwap(3);
    // l1.display();
    // l1.elementSwap(4);
    // l1.display();
    
    // List<int> l2;
    // l2.push_back(3);
    // l2.push_back(2);
    // l2.push_back(1);
    // l2.elementSwap(0);
    // l2.display();
    // l2.elementSwap(1);
    // l2.display();
    // l2.elementSwap(2);
    // l2.display();
    
    // List<int> l3;
    // l3.push_back(2);
    // l3.push_back(1);
    // l3.elementSwap(0);
    // l3.display();
    // l3.elementSwap(1);
    // l3.display();
    // l3.elementSwap(2);
    // l3.display();
    
    // List<int> l4;
    // l4.push_back(1);
    // l4.elementSwap(0);
    // l4.display();
    // l4.elementSwap(1);
    // l4.display();
    // l4.elementSwap(2);
    // l4.display();
    return 0;
    
    
}