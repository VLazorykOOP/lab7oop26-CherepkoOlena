//
// Created by acer_ on 28.05.2026.
//

#include "Task4.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}


        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

void task4()
{
    LinkedList<int> myList;

    cout << "Input amount of elements" << endl;
    int n;
    cin >> n;

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        myList.push_back(element);
    }

    cout << "Iterator result:" << std::endl;
    for (LinkedList<int>::Iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}