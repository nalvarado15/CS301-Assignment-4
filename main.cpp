#include <iostream>
#include "factorial.h"
using namespace std;

// Driver code
int main()
{
    int number;

    cout << "Enter a number 1-500: ";
    cin >> number;

    while (number > 500 || number < 1) {
        cout << "Number out of range. Enter again: ";
        cin >> number;
    }

    // A new linked list is created. We initialize it with 1 node, with a value 1
    NodeType* head = new NodeType();
    head->info = 1;
    head->next = NULL;

    FactorialList numList;

    for (int i = 2; i <= number; i++) {
        numList.Multiply(head, i);
    }

    cout << "Factorial of " << number << " is:" << endl;
    numList.print(head);

    return 0;
}
