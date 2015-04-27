//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: Gerardo Martinez
/// SID: 861169126
/// Date: April 27, 2015
///
/// TwoStackedFixed objects are composed of two stacked 
/// allocated in a single array. They begin at either end of
/// the array and grow towards the middle. However they may 
/// not exceed the maximum partition which is inputed by the
/// user through the constructor. TwoStacksOptimal is the 
/// same except that the stacks can increase in size up 
/// until they reach the other stack. The tops of both 
/// arrays are stored in integers which are initialized to 
/// -1 for the front array and size for the back array.
//  ================== END ASSESSMENT HEADER ===============

#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

template <typename T>

class TwoStackFixed
{
    private:
        int sz;
        T *array = NULL;
        int partition;
        int top1;
        int top2;
        
    public:   
        TwoStackFixed(int size, int maxtop)
        {
            if (maxtop < 0 || maxtop > size)
            {
                cout << "Partition is out of bounds." << endl;
                exit(0);
            }
            sz = size;
            array = new T[sz];
            partition = maxtop;
            top1 = -1;
            top2 = sz;
        }
        
        void pushStack1(T value)
        {
            if (isFullStack1())
            {
                cout << "Stack overflow" << endl;
                exit(0);
            }
            array[top1] = value;
            display();
        }
        
        void pushStack2(T value)
        {
            if (isFullStack2())
            {
                cout << "Stack overflow" << endl;
                exit(0);
            }
            --top2;
            array[top2] = value;
            display();
        }
        
        T popStack1()
        {
            if (isEmptyStack1())
            {
                cout << "Stack 1 is empty. Nothing to pop.\n";
                exit(0);
            }
            T data = array[top1];
            --top1;
            return data;
        }
        
        T popStack2()
        {
            if (isEmptyStack2())
            {
                cout << "Stack 2 is empty. Nothing to pop.\n";
                exit(0);
            }
            T data = array[top2];
            ++top2;
            return data;
        }
        
        void display()
        {
            for (int i = 0; i < sz; ++i)
            {
                if (i > top1 && i < top2)
                {
                    cout << "  ";
                }
                else
                {
                    cout << array[i] << " ";
                }
            }
            cout << endl;
        }
        
        bool isFullStack1()
        {
            if (++top1 == partition)
            {
                --top1;
                return true;
            }
            return false;
        }
        
        bool isFullStack2()
        {
            return (top2 == partition);
        }
        
        bool isEmptyStack1()
        {
            return (top1 == -1);
        }
        
        bool isEmptyStack2()
        {
            return (top2 == sz);
        }
        
};

template <typename T>

class TwoStackOptimal
{
    private:
        int sz;
        T *array;
        int top1, top2;
        
    public:
        TwoStackOptimal(int size)
        {
            sz = size;
            array = new T[sz];
            top1 = -1;
            top2 = sz;
        }
        
        void pushFlexStack1(T value)
        {
            if (isFullStack1())
            {
                cout << "Stack is full. Unable to push item.\n";
                --top1;
                return;
            }
            array[top1] = value;
            display();
        }
        
        void pushFlexStack2(T value)
        {
            if (isFullStack2())
            {
                cout << "Stack is full. Unable to push item.\n";
                ++top2;
                return;
            }
            array[top2] = value;
            display();
        }
        
        T popFlexStack1()
        {
            if (isEmptyStack1())
            {
                cout << "Stack is empty. Nothing to pop.\n";
                exit(0);
            }
            T data = array[top1];
            --top1;
            return data;
        }
        
        T popFlexStack2()
        {
            if (isEmptyStack2())
            {
                cout << "Stack is empty. Nothing to pop.\n";
                exit(0);
            }
            T data = array[top2];
            ++top2;
            return data;
        }
        
        bool isFullStack1()
        {
            if (++top1 == top2) return true;
            return false;
        }
        
        bool isFullStack2()
        { 
            if (--top2 == top1) return true;
            return false;
        }
        
        bool isEmptyStack1()
        {
            return (top1 == -1);
        }
        
        bool isEmptyStack2()
        {
            return (top2 == sz);
        }
        
        void display()
        {
            for (int i = 0; i < sz; ++i)
            {
                if (i > top1 && i < top2)
                {
                    cout << "  ";
                }
                else
                {
                    cout << array[i] << " ";
                }
            }
            cout << endl;
        }
};
#endif