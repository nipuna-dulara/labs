// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int top;
    int *array = new int[size];

    Stack(int sze)
    {
        top = -1;
        size = sze;
    }
    bool isEmpty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top + 1 >= size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int data)
    {
        if (top + 1 >= size)
        {
            cout << "stack overflow";
        }
        else
        {
            top = top + 1;
            array[top] = data;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow";
            return 0;
        }
        else
        {
            top = top - 1;
            return array[top + 1];
        }
    }
    int stackTop()
    {
        return array[top];
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << endl;
        }
    }
};

int main()
{
    clock_t start, end;
    start = clock();
    Stack s1(100);
    s1.push(8);
    s1.push(10);
    s1.push(50);
    s1.push(11);
    s1.push(12);
    s1.push(23);
    s1.push(8);
    s1.push(17);
    s1.push(18);
    s1.push(20);
    s1.display();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.display();
    s1.push(90);
    s1.push(88);
    s1.push(6);
    s1.push(0);
    s1.display();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}