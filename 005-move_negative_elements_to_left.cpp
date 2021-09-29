#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 005: Move all the negative numbers to one side of the 
    array. (I am gonna move them to left side!)  

    Approaches I am gonna discuss here are - 
    1. Sort. 
    2. Incremental Swaps
    3. Two Pointer Method 
*/

/*
    What we do here is - We take a pointer called current
    and initialise it to 0. 
    We iterate over the vector vec, and if we encounter any -ve 
    element. Then we swap the element at position current to the 
    element which we just found to be negative. 
    After the swap. We also increment the current variable by 1 so that 
    the next negative element when we find, it occupies the next current 
    position. 
    In this manner we will keep filling the negative elements from 0, 1, 2
    , 3 etc .... filling the left side full of -ve elements. 
*/ 
// Make sure to pass the vector by reference! 
void incrementalSwap(vector<int> &vec) {
    // Declare a position which a negative element needs to occupy! 
    int current = 0; 

    for (int i = 0; i < vec.size(); i++) {
        // Check if the ith element is negative. 
        if (vec[i] < 0) {
            // If it is negative. Then swap it with current position 
            // and increment current by one. 
            swap(vec[i], vec[current]); 
            // Increment it so that next time the negative element 
            // occupies the next place to the negative element we 
            // filled just now. 
            current++; 
        }
    }
}

/*
    Approach - 
    In the two pointer method, as the name suggest we will have 
    two pointers called left and right. 
    left will be assigned to 0 
    and right will be assigned to position (size - 1) where size is the 
    vector size. 

    Now we follow the following - 
    1. If vec[left] and vec[right] both point to a -ve element. Then
       we move only the left by one. 
    2. If vec[left] is positive and vec[right] is -ve element. Then we swap
       vec[left] and vec[right] so that the -ve element on the right now 
       comes to the left side. And the +ve element on left goes to right. 
       We increment left by one and decrement right by one here. 
    3. If vec[left] is positive and vec[right] is +ve. Then we move the right 
       pointer to left by one. 
    4. If vec[left] is -ve and vec[right] is +ve. Then we increment left by one 
       and decrement right by one as both are in their correct positions. 
*/ 
void twoPointerMethod(vector<int> &elements) {
    // Declare the two pointers left and right. 
    int left = 0; 
    int right = elements.size() - 1; 

    // Declare the while loop. 
    while (left <= right) {
        // First condition (-,-) 
        if (elements[left] < 0 and elements[right] < 0) {
            left++; 
        } else if (elements[left] >= 0 and elements[right] < 0) {
            swap(elements[left], elements[right]);
            left++; 
            right--; 
        } else if (elements[left] >= 0 and elements[right] >= 0) {
            right--; 
        } else {
            // Both are at correct positions. 
            left++; 
            right--; 
        }
    }
}

// Function to print the vector! 
void printVector(vector<int> &vec) {
    for (int element : vec) {
        cout << element << " ";
    }
    cout << endl; 
}

// The simplest solution to the problem is using SORTING! 
// All the negative elements (if any) present in the array will come 
// to the left side of the array! 
int main() {
    // Consider we have the following array. 
    // Coz I like vector more. I will use vector. :) 
    vector<int> vec = {1, 2, 3, -1, -123, 3, -4, -123, 19, 32}; 

    cout << "Vector Initiall Is : " << endl;
    printVector(vec); 

    // Now let's do the same thing using Incremental Swaps Method.
    twoPointerMethod(vec);

    cout << "Vector after Negatives on one side using 2 Pointer Method is : " << endl;
    printVector(vec); 
}

// Yep Works! 
// Now let's try the last approach using Two Pointer! 
// Works! 
// In GeeksForGeeks they have solved it as a question where they consider
// only O(1) extra space. 
// But if we see Love Babbar sheet, we have the question as - 
// Here there is nowhere mention of O(1) space and all. 
// So our first approach of sorting is also a valid one. :) 
// Thanks for watching! 

// Wait for 006! 