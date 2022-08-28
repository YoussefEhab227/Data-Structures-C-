#include <iostream>
#include<stdlib.h>
using namespace std;
template <class T>
class node
{
public:
    T data;
    node<T>* nxt;
    node<T>* prvs;
    node()
    {
        nxt = NULL;
        prvs = NULL;
    }
};
template <class T>
class List
{
     node<T>* head;
    node<T>* tail;
public:
    class Iterator
    {
        friend class List;
    private:
        node<T>* current;
        Iterator(node<T>* curr)
        {
            current = curr;
        }
    public:
        Iterator()
        {
            current = NULL;
        }
        void operator ++ ()
        {
            current = current->nxt;
        }
        void operator -- ()
        {
            current = current->prvs;
        }
        T& operator * ()
        {
            return current->data;
        }
        bool operator == (const Iterator & it)
        {
            if(this->current == it->current)
            {
                return true;
            }else{
                return false;
            }
        }

    };
/// constructor and functions for linked list class
    List();
    List(T value,int initial_size);
    ~List();
    int Get_Size();
    void Insert(T value, Iterator position);
    Iterator Erase(Iterator position);
    void operator = (List<T> & another_list);
    Iterator Begin();
    Iterator End();
    void push(T value);
    void print();

};
template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}
template <class T>
void List<T>::push(T value)
{
        node<T>* new_node = new node <T>();
        new_node->data = value;
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }else{
            new_node->prvs = tail;
            tail->nxt = new_node;
            tail = new_node;
        }

}
template <class T>
List<T>::List(T value,int initial_size)
{

    head = NULL;
    tail = NULL;
    for(int i = 0; i < initial_size; i++)
    {
        node<T>* new_node = new node <T>();
        new_node->data = value;
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }else{
            new_node->prvs = tail;
            tail->nxt = new_node;
            tail = new_node;
        }
    }
}
template <class T>
List<T>::~List()
{
    while(head->nxt != NULL)
    {
        node<T>* new_node = head;
        head = head->nxt;
        delete new_node;
    }
    delete head;
}
template <class T>
int List<T>::Get_Size()
{
    node<T>* new_node = head;
    int Size = 0;
    while(new_node != NULL)
    {
        new_node = new_node->nxt;
        Size++;
    }
    return Size;
}
template <class T>
void List<T>::Insert(T value, Iterator position)
{
    if(position.current == NULL)
    {
        cout << "cannot add at this position !" << endl;
        return;
    }
    node<T>* new_node = new node <T> ();
    new_node->data = value;
    new_node->prvs = position.current->prvs;
    position.current->prvs = new_node;
    new_node->nxt = position.current;
    if(new_node->prvs != NULL)
    {
        new_node->prvs->nxt = new_node;
    }else{
        head = new_node;
    }
}

template <class T>
class List<T>::Iterator List<T>::Erase(Iterator position)
{
    if(position.current->nxt == NULL)
    {
        cout << "This is the last element in the list." << endl;
       // exit(EXIT_FAILURE);
    }
    if(head == position.current)
    {
        head = position.current->nxt;
        free(position.current);
        return Iterator(head);
    }else{
        node<T>* new_node = position.current;
        new_node->data = position.current->nxt->data;
        new_node->nxt = position.current->nxt->nxt;
        position.current = new_node;
        return position;
    }

}
template <class T>
void List<T>::operator = (List<T> & another_list)
{
    int copy_size = another_list.Get_Size();
    List::Iterator it = another_list.Begin();

    for(int i = 0; i < copy_size ; i++)
    {
        if(i == copy_size-1)
        {
            push(*it);
            break;
        }
        push(*it);
        ++it;
    }

}
template <class T>
class List<T>::Iterator List<T>::Begin()
{
    Iterator it(head);
    return it;
};
template <class T>
class List<T>::Iterator List<T>::End()
{
    Iterator it(tail);
    return it;
};
template <class T>
void List<T>::print()
{
    int i = 1;
    node<T>* p = head;
    while(p != NULL)
    {
        cout << "Data " << i << " : " << p->data << endl;
        p = p->nxt;
        i++;

    }
}

int main()
{
    List <float> L1;
    L1.push(2.5);
    L1.push(3.5);
    L1.push(6.9);
    L1.push(8.9);
    L1.push(1.5);
    L1.push(3.2);
    cout<<"Pushing -----------------------------"<<endl;
    L1.print();
    cout<<"-------------------------------------"<<endl;
    List<float>::Iterator it;
    it = L1.Begin();
    ++it;
    ++it;

    cout << "The iterator contain: " << *it << endl;

    L1.Insert(1.8,it);
    cout << "after add: " << endl;
    L1.print();
    cout<<"-------------------------------------------"<<endl;
    cout<<"after erase"<<endl;
    ++it;
    L1.Erase(it);
    L1.print();

    cout << "Size is: " ;
    cout << L1.Get_Size()<<endl;



    cout << "--------------------------------------------------"<<endl;

    cout << "After copy: " << endl;
    List<float> y;
    y = L1;


    y.print();

    cout << endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<endl<<"Trying initial size construction"<<endl;
    List<int> i(2,5);

    i.print();
    cout<<"-------------------------------------------------------"<<endl;

    return 0;
}
