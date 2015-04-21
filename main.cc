#include "lab3.h"

int main()
{
    TwoStackFixed<int> l1 = TwoStackFixed<int>(6,3);
    l1.pushStack1(3);
    //l1.display();
    l1.pushStack1(4);
    //l1.display();
    l1.pushStack1(5);
    //l1.display();
    l1.pushStack2(6);
    //l1.display();
    l1.pushStack2(7);
    //l1.display();
    l1.pushStack2(8);
    l1.display();
    return 0;
}