//TC : O(1)
//SC : O(1)
#include <iostream>
using namespace std;
class stack
{
public:
    // properties
    int *arr;
    int top;
    int size;
    // behaviour
    stack(int size) // parameterised constructor
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size-top>1)
        {
            top++; // pehle -1 se 0 index pe leke aaoo top ko and then push the element at 0th index
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int currentSize()
    {  if(top>=0)
        {cout<<"Current size of stack : "<<top+1<<endl;}
        else
        {cout<<"Stack is empty"<<endl;
        return -1;} 
    }
};
int main()
{
    stack st(5); // 5=>size of stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << "Top element : " << st.peek() << endl;
    st.currentSize();
    st.pop();
    cout << "Top element : " << st.peek() << endl;
    st.currentSize();
    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}