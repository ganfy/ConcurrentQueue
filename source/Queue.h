#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct node
{
    node(T x)
    {
        value = x;
        next = prev = 0;
    }
    T value;
    node* next, * prev;
};

template <class T>
class Queue
{
public:
    Queue()
    {
        head = tail = 0;
        nelem = 0;
    }
    ~Queue()
    {
        while (tail) {
            pop();
        }
    }

    void push(T x)
    {
        node<T>* n = new node<T>(x);
        if (!nelem)
            head = tail = n;
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        nelem++;
    }

    T pop()
    {
        if (nelem == 0) {
            throw std::out_of_range("The queue is empty");
        }

        T h = head->value;
        node<T>* n = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete n;
        nelem--;
        return h;
    }

    bool empty() {
        return (nelem == 0);
    }

    T& operator[](int i)
    {
        node<T>* n = head;
        for (int k = 0; k != i; k++)
            n = n->next;
        return n->value;
    }

    void print()
    {
        std::cout << "\n";
        for (node<T>* n = head; n != 0; n = n->next)
            std::cout << n->value << " ";
    }
    void print2()
    {
        std::cout << "\n";
        for (int i = 0; i < nelem; i++)
            std::cout << (*this)[i] << " ";
    }

private:
    node<T>* head, * tail;
    int nelem;
};

