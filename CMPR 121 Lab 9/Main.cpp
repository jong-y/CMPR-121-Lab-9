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
    std::cout << "9. Lab 10" << std::endl;
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
            try {
                arr.addElement(element);
            }
            catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
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
            std::cout << "Array to Compare: ";
            otherArray.print();

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
        case 9:
            DArray arr1(10);
            arr1.addElement(10);
            arr1.addElement(11);
            arr1.addElement(12);

            DArray arr2(10);
            arr2.addElement(20);
            arr2.addElement(21);

            DArray arr3(arr2); // copy constructor

            arr2 = arr1;       // overloaded assignment operator

            std::cout << arr2 << std::endl;   // using overloaded insertion operator
            std::cout << arr3 << std::endl;   // using overloaded insertion operator

            int index = arr2.findElement(10); // using find element
            if (index != -1)
            {
                std::cout << "Key was found at index: " << index << std::endl;
            }
            else
            {
                std::cout << "Element not found" << std::endl;
            }

            std::cout << std::endl;
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}