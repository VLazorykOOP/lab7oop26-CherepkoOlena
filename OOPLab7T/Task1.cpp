//
// Created by acer_ on 28.05.2026.
//
#include "Task1.h"
#include <iostream>

using namespace std;

template<typename t> void swap(t* arr, int n) {
    t max;
    int maxID = -1;
    t min;
    int minID = -1;

    for (int i = 0; i < n; ++i) {
        char val = arr[i];
        if ((maxID == -1 || minID == -1) && val > max) {
            max = val;
            maxID = i;
        }
        if (minID == -1 && val < min && val != max) {
            min = val;
            minID = i;
        }
    }

    cout << "Max found: " << max << endl;
    cout << "Min found: " << min << endl;

    arr[minID] = max;
    arr[maxID] = min;

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << " : " << arr[i] << endl;
    }
}

template<> void swap(char* arr, int n) {
    char max = 'a';
    int maxID = -1;
    char min = 'z';
    int minID = -1;

    for (int i = 0; i < n; ++i) {
        char val = arr[i];
        if ((maxID == -1 || minID == -1) && val > max) {
            max = val;
            maxID = i;
        }
        if (minID == -1 && val < min && val != max) {
            min = val;
            minID = i;
        }
    }

    cout << "Max found: " << max << endl;
    cout << "Min found: " << min << endl;

    arr[minID] = max;
    arr[maxID] = min;

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << " : " << arr[i] << endl;
    }
}

void task1() {
    int n;
    cout << "Input how many elements you want to write: " << endl;
    cin >> n;

    cout << "Input your elements: " << endl;
    char arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    swap(arr, n);
}