//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: Gerardo Martinez
/// SID: 861169126
/// Date: April 20, 2015
///
/// This header file contains the code for a class List 
/// which uses a struct Node. Templates are used so the 
/// functions can be utilized for lists of any types. The
/// elementSwap function swaps the position of two Nodes
/// by adjusting pointers only.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
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
        if (pos < 0 || pos >= sz)
        {
            cout << "Out of bounds." << endl;
            return *this;
        }
        if (sz < 2)
        {
            return *this;
        }
        Node<Type> *cur = head;
        Node<Type> *temp = cur->next;
        if (pos == 0)
        {
            Node<Type> *temp2 = temp->next;
            head = temp;
            head->next = cur;
            cur->next = temp2;
            return *this;
        }
        if (pos == sz - 1)
        {
            return *this;
        }
        int loc = 1;
        while (loc != pos)
        {
            cur = cur->next;
            temp = temp->next;
            ++loc;
        }
        Node<Type> *temp2 = temp->next;
        cur->next = temp->next;
        temp->next = temp2->next;
        temp2->next = temp;
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

