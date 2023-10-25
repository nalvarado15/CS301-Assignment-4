#pragma once
#include <iostream>
using namespace std;

//* Node Class
struct NodeType {
    int info;
    NodeType* next;
    NodeType* prev = NULL;
};

class FactorialList {
public:
    FactorialList() {
        thousand = 0;
        tempValue = 0;
    }

    void Multiply(NodeType* topPtr, int i){
        // Pre: We have a linked list with the previous number and node.
        //      If starting, the linked list is simply 1 node, with value 1.
        // Post: Linked list will be multiplied by int i.
        //       A new node will be made if needed to hold more digits.
        
        // Create new nodes that serve as our location for where we are
        // temp is current position, prevPtr is just behind once temp becomes null.
        NodeType* location = topPtr,
                * prevLocation = topPtr;

        // Get our product after multiplying.
        // Set as the new value
        // Find amount over 1000 after multiplying.
        // Shift location to next in linked list.
        // Continue until our temp is done looping through the list
        thousand = 0;
        while (location != NULL) {
            tempValue = (location->info * i) + thousand;
            location->info = tempValue % 1000;
            thousand = tempValue / 1000;
            prevLocation = location;
            location = location->next;
        }

        // Once entire list is multiplied, there is chance for an extra carry with no more links.
        // Create a new node that proceeds the last link. Set as the new last link.
        newNode(thousand, prevLocation);
    }

    void newNode(int value, NodeType* lastPtr) {
        // Pre: Final value is found to put in new node. lastPtr is last link in the list
        // Post: Value is added to a new link at the end, or length of list does not need to change.
        while (value != 0) {
            lastPtr->next = new NodeType();
            lastPtr->next->info = value;
            value /= 1000;
            lastPtr->prev = lastPtr->next;
            lastPtr = lastPtr->next;
        }
    }

    void print(NodeType* topPtr) {
        // Pre: Entire linked list is complete after multiplying
        // Post: Entire linked list is printed in reverse order, commas included.
        if (topPtr == NULL) {
            return;
        }
        print(topPtr->next);
        // Only the head->prev is NULL. Therefore, no commas or extra 0's will be printed for the first node.
        if (topPtr->prev != NULL) {
            cout << ",";
        }
        if (topPtr->prev != NULL && topPtr->info > 100) {
        }
        else if (topPtr->prev != NULL && topPtr->info > 10) {
            cout << "0";
        }
        else if (topPtr->prev != NULL) {
            cout << "00";
        }
        cout << topPtr->info;
    }

private:
    int thousand;
    int tempValue;
};
