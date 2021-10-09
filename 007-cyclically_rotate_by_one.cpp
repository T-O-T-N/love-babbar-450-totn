#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 007: Cyclically Rotate an Array/Vector by 1. 

    Input  : {1, 3, 4, 5, 7}
    Output : {7, 1, 3, 4, 5} 

    Input : {10, 20, 30, 40}
    Output: {40, 10, 20, 30} 
*/

// Pass the vector by reference here (use the & symbol!) 
void rotateVectorByOne(vector<int> &elements) {
    // Declare a temp variable which can store our last element. 
    // So that it doesn't get lost when we shift all the previous 
    // elements by one position to the right. 
    int temp = elements.back(); 

    // Now shift all the previous elements to the right side. 
    // By previous here I mean that shift all the element from 0 
    // uptil the 2nd last element to the right. 
    // We start the loop from 2nd last element and move towards 0 to
    // shift them to right. 
    for (int i = elements.size() - 1; i > 0; i--) {
        // Shift the (i - 1)th element to ith position! 
        elements[i] = elements[i - 1]; 
    }
    // Now the 0th position needs to be occupied with the element 
    // that we stored in our temp variable. 
    elements[0] = temp; 

    // That's it! 
}

void printVector(vector<int> &elements) {
    for (int element : elements) {
        cout << element << " "; 
    }
    cout << endl; 
}

int main() {
    // Cool! So this problem is pretty simple here. 
    // To solve this problem we simply need to store the last element
    // in a temporary variable called temp or whatever you wanna call it. 
    // We shift all the element to the right side. 
    // And then the first place we fill in our temp element.
    
    // Let's declare the vector first.
    vector<int> elements = {};

    cout << "Vector Before Rotation is : " << endl; 
    printVector(elements); 

    // Here our rotation logic should come in! 
    rotateVectorByOne(elements); 

    cout << "Vector After Rotation is : " << endl;
    printVector(elements); 
}

// Let's run to see our program! 
// That's it. Thanks for watching. 
// Wait for 008. :P 