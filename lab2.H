#include <iostream>
#include <cassert>
#include <forward_list>
#include <cstdlib>
using namespace std;

template <typename Type>
struct Node
{
    Type data;
    Node *next;
    Node( Type data ) : data(data), next(0) {}
};

template <typename Type>
class List
{
  private:
    Node<Type> *head;
    Node<Type> *tail;
    
  public:
    List<Type>()
    {
        head = 0;
        tail = 0;
    }
  
    List<Type> elementSwap(int pos)
    {
        int sz = size();
        assert(pos >= 0 && pos < sz - 1);
        Node<Type> *cur = head;
        int loc = 0;
        while (loc != pos)
        {
            cur = cur->next;
            ++loc;
        }
        Node<Type> *temp = cur->next;
        Node<Type> *temp2 = temp->next;
        temp->next = cur;
        cur->next = temp2;
        return *this;
    }
    
    void push_back(Type value)
    {
        Node<Type> *temp = new Node<Type>(value);
        if (!head)
        {
            head = temp;
            tail = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    
    void display() const
    {
        for (Node<Type> *cur = head; cur != NULL; cur = cur->next)
        {
            cout << cur->data << " ";
        }
        cout << endl;
    }
    
    int size()
    {
        int size = 0;
        for (Node<Type> *cur = head; cur != 0; cur = cur->next)
        {
            ++size;
        }
        return size;
    }
    
};

