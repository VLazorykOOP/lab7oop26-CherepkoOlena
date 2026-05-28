// OOPLab7T.cpp 
//

#include <iostream>
#include <clocale>

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

int main()
{
    std::cout << "Lab 7" << std::endl;
    std::cout << "Choose the task: " << std::endl;

    int choice = 0;
    std::cin >> choice;

    if (choice == 1) {
        task1();
    }
    if (choice == 2) {
        task2();
    }
    if (choice == 3) {
        task3();
    }
    if (choice == 4) {
        task4();
    }
    return 0;
}


