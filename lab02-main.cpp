#include "ArrayList.hpp"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main() {
    // call the constructor with a maximum size of 5
    ArrayList<string> myList(5);

    // add elements to the list
    myList.append("Heart");
    myList.insert(0, "Your");
    myList.insert(0, "May");

    // try replacing as an invalid operation
    try {
        myList.replace(-3, "?");
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    } catch (const string& e) {
        cout << e << endl;
    }

    // add another element
    myList.append("Citrus");

    // try inserting as an invalid operation
    try {
        myList.insert(5, "kweh");
    } catch (const std::exception& e) {
            cout << e.what() << '\n';
    } catch (const string& e) {
        cout << e << endl;
    }

    // remove an element
    myList.remove(3);

    // display the state of the list
    cout << myList;

    // get the third element (position 2) from the list
    string word = myList.getElement(2);
    cout << "Element 2: " << word << endl;

    // create a second list using the copy constructor
    ArrayList<string> secondList = myList;

    // modify the second list and display its state
    secondList.append("Beat");
    secondList.replace(2, "Drums");
    cout << secondList;

    // try removing an element as an invalid operation
    try {
        secondList.remove(4);
    } catch (const std::exception& e) {
            cout << e.what() << '\n';
    } catch (const string& e) {
        cout << e << endl;
    }

    // create a third list using the default constructor (max size of 100)
    ArrayList<string> thirdList;

    // display the state of the list, should be empty
    cout << thirdList;

    // copy the first list to the third list using assignment overload
    thirdList = myList;

    // display the length and max size, should match the first list
    cout << "thirdList length: " << thirdList.getLength() << endl;
    cout << "thirdList maximum size: " << thirdList.getMaxSize() << endl;

    // try getting an element as an invalid operation
    try {
        word = thirdList.getElement(-9);
    } catch (const std::exception& e) {
            cout << e.what() << '\n';
    } catch (const string& e) {
        cout << e << endl;
    }

    // add elements to the list
    thirdList.append("Be A");
    thirdList.append("Yellow");

    // try adding elements as invalid operations
    try {
        thirdList.append("Banana");
    } catch (const std::exception& e) {
            cout << e.what() << '\n';
    } catch (const string& e) {
        cout << e << endl;
    }
    try {
        thirdList.insert(0, "Banana");
    } catch (const std::exception& e) {
            cout << e.what() << '\n';
    } catch (const string& e) {
        cout << e << endl;
    }

    // display the state of the list
    cout << thirdList;

    // clear out the list and verify it is now empty
    myList.clear();
    if (myList.isEmpty()) {
        cout << "myList is empty!\n";
    }
    else if (myList.isFull()) {
        cout << "myList is full!\n";
    }

    // terminate
    return 0;
}
