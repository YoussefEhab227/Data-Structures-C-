#include <bits/stdc++.h>

using namespace std;

#define MAXINT 1000000

typedef long long ll  ;

template <class T>

class Stack{
    
    ll top;
    
 public:
    T *a;
    
    Stack<T>(){ top =-1; a= new T[MAXINT];}
    bool push(T x);
    T pop();
    T peek();
    bool isEmpty();
    
    ~Stack<T>(){delete[]a;}
};

template <class T>
bool Stack<T>::push(T x)
{
   if(top>=MAXINT-1){
    size_t newSize = MAXINT+1000;
    
    T * newArr = (T *) realloc(newArr, newSize);    
    delete [] a;
    a = newArr;
    
    a[++top] = x;
    return true;
}
    a[++top] = x;
    return true;
}

template <class T>
T Stack<T>::pop()
{
    T x;
    try 
    {
        if (top<0) throw (top);
        
         x = a[top--];
        
    }
    catch(ll top)
    {
        cout<< "Stack is empty"<<endl;
    }
    return x;
}

template <class T>
T Stack<T>::peek()
{
    T x;
     try 
    {
        if (top<0) throw (top);
        
        x = a[top];
        
    }
    catch(ll top)
    {
        cout<< "Stack is empty"<<endl;
    }
    return x;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top<0);    
}

int main()
{
   class Stack<int> s;
    
    s.peek();
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    
    cout << "Top element is : " << s.peek() << endl;
    
    cout <<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}