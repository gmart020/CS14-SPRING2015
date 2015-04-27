//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: Gerardo Martinez
/// SID: 861169126
/// Date: April 27, 2015
///
/// This file contains the showTowerStates function which
/// solves the Towers of Hanoi puzzle recursively while 
/// printing out every move made. Also contained in this 
/// file is a test harness for the TwoStackFixed and 
/// TwoStackedOptimal classes in the lab3 header file.
//  ================== END ASSESSMENT HEADER ===============


#include "lab3.h"

template <typename T>

void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if (n == 1)
    {
        cout << "Moved " << A.top() << " from peg A to B.\n";
        B.push(A.top());
        A.pop();
    }
    else
    {
        showTowerStates(n - 1, A, C, B);
        cout << "Moved " << A.top() << " from peg A to B.\n";
        B.push(A.top());
        A.pop();
        showTowerStates(n - 1, C, B, A);
    }
}

int main()
{
    stack<int> stack1;
    stack1.push(5);
    stack1.push(4);
    stack1.push(3);
    stack1.push(2);
    stack1.push(1);
    
    stack<int> stackEnd;
    stack<int> stackAux;
    
    showTowerStates(5, stack1, stackEnd, stackAux);
    
    cout << endl << endl;
    while (stackEnd.size() != 0)
    {
        cout << stackEnd.top() << endl;
        stackEnd.pop();
    }

    // TwoStackFixed<int> l1 = TwoStackFixed<int>(6,3);
    // l1.pushStack1(3);
    // l1.display();
    // l1.pushStack1(4);
    // l1.display();
    // l1.pushStack1(5);
    // l1.display();
    // l1.pushStack2(6);
    // l1.display();
    // l1.pushStack2(7);
    // l1.display();
    // l1.pushStack2(8);
    // cout << l1.isFullStack1() << endl;
    // cout << l1.isFullStack2() << endl;
    // cout << l1.isFullStack1() << endl;
    // cout << l1.isFullStack2() << endl;
    // cout << l1.isFullStack1() << endl;
    // cout << l1.isFullStack2() << endl;
    
    // TwoStackFixed<int> l2 = TwoStackFixed<int>(4,2);
    // cout << l2.isEmptyStack1() << endl;
    // l2.pushStack1(4);
    // cout << l2.isEmptyStack1() << endl;
    // cout << l2.isEmptyStack2() << endl;
    // l2.pushStack2(5);
    // cout << l2.isEmptyStack1() << endl;

    
    // TwoStackOptimal<int> list = TwoStackOptimal<int>(20);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack1(4);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    // list.pushFlexStack2(6);
    
    // cout << list.popFlexStack1() << endl;
    // list.popFlexStack1();
    // list.popFlexStack1();
    // list.popFlexStack1();
    // list.popFlexStack1();
    // list.pushFlexStack2(9);
    // list.pushFlexStack2(9);
    // list.pushFlexStack2(9);
    // list.pushFlexStack2(9);



    return 0;
}