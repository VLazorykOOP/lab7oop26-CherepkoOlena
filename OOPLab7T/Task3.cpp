//
// Created by acer_ on 28.05.2026.
//

#include "Task3.h"
#include <iostream>

using namespace std;

template <typename T>
class Queue {
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void push(T value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) return;

        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
    }

    T front() const {
        if (empty()) {
            return T();
        }
        return head->data;
    }
};

void task3() {
    Queue<int> queue;

    cout << "How many elements to add : " << endl;
    int n;
    cin >> n;

    cout << "Input elements: " << endl;
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        queue.push(element);
    }

    cout << "front: " << queue.front() << endl;
    queue.pop();
    cout << "front after pop: " << queue.front() << endl;
}
