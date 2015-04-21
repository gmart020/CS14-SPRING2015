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
        stack<T> stack1;
        stack<T> stack2;
        int sz;
        T *array = NULL;
        int partition;
        int top1;
        int top2;
        
    public:
    // if maxtop < 0; array = stack2;
    // if maxtop >= size; arr = stack1;
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
            top1 = 0;
            top2 = sz - 1;
        }
        
        void pushStack1(T value)
        {
            if (top1 == partition)
            {
                cout << "Stack overflow" << endl;
                exit(0);
            }
            array[top1] = value;
            ++top1;
        }
        
        void pushStack2(T value)
        {
            if (top2 < partition)
            {
                cout << "Stack overflow" << endl;
                exit(0);
            }
            array[top2] = value;
            --top2;
        }
        
        void display()
        {
            for (int i = 0; i < sz; ++i)
            {
                if (i >= top1 && i <= top2)
                {
                    cout << " " << endl;
                }
                cout << array[i] << " ";
            }
            cout << endl;
        }
        
        
};

#endif