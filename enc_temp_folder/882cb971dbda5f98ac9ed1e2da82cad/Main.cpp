/*
 Johnny Vo
    CMPR 121 - Spring 2022
    5/14/23

    Lab 9

    Collaboration: Susana Becerra, Sebastian Cabera

*/

#include <iostream>
#include "DArray.h"

void printMenu() {
    std::cout << "1. Add an element to the array" << std::endl;
    std::cout << "2. Get the number of elements" << std::endl;
    std::cout << "3. Get the capacity of the array" << std::endl;
    std::cout << "4. Print the array" << std::endl;
    std::cout << "5. Replace an element at a given index" << std::endl;
    std::cout << "6. Compare arrays" << std::endl;
    std::cout << "7. Change the capacity of the array" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    int capacity = 0;
    int element = 0;
    int index = 0;
    bool exit = false;
    DArray arr;
    DArray otherArray;

    while (!exit) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the element to add: ";
            std::cin >> element;
            arr.addElement(element);
            break;
        case 2:
            std::cout << "Number of elements: " << arr.getNumberOfElements() << std::endl;
            break;
        case 3:
            std::cout << "Capacity of the array: " << arr.getCapacity() << std::endl;
            break;
        case 4:
            std::cout << "Array elements: ";
            arr.print();
            break;
        case 5:
            std::cout << "Enter the index to replace: ";
            std::cin >> index;
            std::cout << "Enter the new element: ";
            std::cin >> element;
            arr.insetElementAtIndex(element, index);
            break;
        case 6:
      
            otherArray.addElement(10);
            otherArray.addElement(20);
            otherArray.addElement(30);
            if (arr.compareArrays(otherArray)) {
                std::cout << "Arrays are equal." << std::endl;
            }
            else {
                std::cout << "Arrays are not equal." << std::endl;
            }
            break;
        case 7:
            std::cout << "Enter the new capacity: ";
            std::cin >> capacity;
            arr.setCapacity(capacity);
            break;
        case 8:
            exit = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}
