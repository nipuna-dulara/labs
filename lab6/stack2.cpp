// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
class Stack
{
public:
    node *head = nullptr;
    node *top = nullptr;

    bool isEmpty()
    {
        if (top == nullptr)
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
        node *newNode = new node;

        newNode->data = data;
        if (isEmpty())
        {

            head = newNode;
            top = newNode;
        }
        else
        {
            top->next = newNode;
            top = newNode;
        }
    }
    int pop()
    {
        int x = top->data;
        if (top == head)
        {
            top = nullptr;
            head = nullptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != top)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            top = temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
};

int main()
{
    clock_t start, end;
    start = clock();
    Stack s1;
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