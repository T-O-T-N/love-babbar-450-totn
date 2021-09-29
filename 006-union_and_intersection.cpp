#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 006: Find UNION and INTERSECTION of 2 Sorted Arrays/Vectors. 

    Approach - Cursor Method. 

    Input  : arr1[] = {1, 3, 4, 5, 7}
             arr2[] = {2, 3, 5, 6} 
    Output : Union : {1, 2, 3, 4, 5, 6, 7} Correct! 
             Intersection : {3, 5} // Correct! 

    // Let's try this! 
    Input  : arr1[] = {2, 5, 6}
             arr2[] = {4, 6, 8, 10} 
    Output : Union : {2, 4, 5, 6, 8, 10} 
             Intersection : {6}
*/

// Let's declare the functions now. 
// Cool! Declarations of both the functions are done now. 
// Let's focus on the INTERSECTION function first. 
/*
    Approach - Here we are gonna maintain 2 cursors (pointers, location) called
    cursor_1 and cursor_2. 
    cursor_1 points to an element in the first vector. 
    cursor_2 points to an element in the second vector. 

    For INTERSECTION, we move the cursor_1 and cursor_2 from left to right. 
    If element pointed out by cursor_1 in first vector is smaller than the element 
    pointer out by cursor_2 in second vector. Then we move cursor_1 to the right side. 
    If element point by cursor_2 is smaller than that pointed by cursor_1, then we move 
    cursor_2 to the right side (increment cursor_2 variable by one!). 
    When the element pointed by both cursor_1 and cursor_2 are same. That means that the
    element exists in both the vectors. So it should also be present in the intersection 
    vector. So we append that element to intersection_vec vector and increment both the cursors
    by 1. 
    Let's try the approach. 
*/ 
vector<int> getIntersectionVector(vector<int> &first, vector<int> &second) {
    vector<int> intersection_vec; 

    // Declare the cursors. 
    int cursor1 = 0; // points at first 
    int cursor2 = 0; // points at second 

    // Now we go through the first and second array according to the cursors. 
    while (cursor1 < first.size() and cursor2 < second.size()) {
        if (first[cursor1] == second[cursor2]) {
            // Here it means that element pointed by cursor 1 and 2 are equal. 
            // So append it to the intersection vector. 
            intersection_vec.push_back(first[cursor1]); 
            // Increment both the cursors! 
            cursor1++; 
            cursor2++; 
        } else if (first[cursor1] < second[cursor2]) {
            cursor1++; 
        } else if (first[cursor1] > second[cursor2]) {
            cursor2++; 
        }
    }

    return intersection_vec; 
}
// Looks good to me. Let's try out the intersection function! 

// Let's build our UNION FUNCTION now. 
/*
    Our Approach Here however would be to maintain 2 cursors again! 
    Let's call them cursor1 and cursor2 
    cursor1 points to element in first vector. 
    cursor2 points to element in second vector. 
    Move the cursors to the right one by one! 
    If element pointed out by cursor1 in first vector is smaller than 
    element pointed by cursor2 in second vector. We append the cursor1 element 
    to our union_vec. We incrmeent cursor1 by one. 
    For the reverse case we append the element pointed by cursor2 to our union_vec. 
    Here we increment the cursor2 by one. 
    
    If both element pointed by cursor1 and cursor2 are equals. Then we need to 
    append the element only once. And increment cursor1 and cursor2 by one.
*/ 
vector<int> getUnionVector(vector<int> &first, vector<int> &second) {
    vector<int> union_vec; 
    // Cool. So here also we follow the same cursor approach! 
    // Declare the curors. 
    int cursor1 = 0; 
    int cursor2 = 0; 

    while (cursor1 < first.size() and cursor2 < second.size()) {
        if (first[cursor1] == second[cursor2]) {
            union_vec.push_back(first[cursor1]); 
            cursor1++; 
            cursor2++; 
        } else if (first[cursor1] < second[cursor2]) {
            union_vec.push_back(first[cursor1]); 
            cursor1++; 
        } else {
            union_vec.push_back(second[cursor2]); 
            cursor2++; 
        }
    }

    // Oh! We missed to include the remaining elements in the UNION. 
    // Here, it might be so that the one of the vectors might get over soon. 
    // And there might be still elements present in the other vector. 
    // For the UNION operation, we need to include those as well. We missed it. 
    while (cursor1 < first.size()) {
        union_vec.push_back(first[cursor1]); 
        cursor1++; 
    }

    while (cursor2 < second.size()) {
        union_vec.push_back(second[cursor2]); 
        cursor2++; 
    }

    return union_vec; 
}
// Looks Good! Let's run it and see. 

void printVector(vector<int> &elements) {
    for (int element : elements) {
        cout << element << " "; 
    }
    cout << endl; 
}

int main() {
    // Todays Problem involves the SORTED ARRAYS in the Question 
    // And we need to find the INTERSECTION and UNION of the 2 Arrays/Vectors. 
    // Let's start by declaring the vector first.

    // Input  : arr1[] = {2, 5, 6}
    //          arr2[] = {4, 6, 8, 10} 
    // Output : Union : {2, 4, 5, 6, 8, 10} 
    //          Intersection : {6}
    vector<int> first =  {2, 5, 6};
    vector<int> second = {4, 6, 8, 10};

    // Now, let's have a function that can return us the UNION vector of the two 
    // vectors first and second above. 
    // And we will have a separate function that can return us the INTERSECTION of the 
    // two vectors above! 
    vector<int> intersection_vec = getIntersectionVector(first, second); 
    cout << "INTERSECTION VECTOR IS : " << endl; 
    printVector(intersection_vec); 
    
    vector<int> union_vec = getUnionVector(first, second); 
    cout << "UNION VECTOR IS : " << endl; 
    printVector(union_vec);
}

// Yep that was it for this video! 006. 
// Wait for 007. :P 
// Thanks for Watching! 