#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Merge 2 sorted arrays without using Extra space.

    FIRST: {1, 7, 9, 10} 
    SECOND: {2, 3, 11} 
    OUTPUT: 
    FIRST: {1, 2, 3, 7}
    SECOND: {9, 10, 11}

    ----------------------------------------------------------------
    So, the problem that is given to us is pretty simple if we were to use EXTRA space and 
    do it. But here they have specifically mentioned not to use any EXTRA space for this 
    question is what makes the question NOT so straightforward. 
    We need to do this question in O(1) Space Complexity. :) 

    So, the approach that we are gonna discuss in this video is using INSERTION SORT. 
    We have two arrays called FIRST and SECOND. 
    What we do is we start from the LAST element in the array2 and then move towards the LEFT. 
    Let's label the element pointed at the second array by an index called j (or second_array_ptr). 

    We then see where the element that is pointed by second_array_ptr belongs to in the FIRST array. 
    That is, we try to find the SMALLEST ELEMENT that is greater than the element pointed by the SECOND
    array element. 

    Once we find the position, we SHIFT all the elements in the FIRST array, to make place for the 
    SECOND array element that is pointed by second_array_ptr in the FIRST array by shifting all the 
    elements after the SMALLEST GREATEST element to the SECOND array element. We shift all the elements
    to the RIGHT side in the FIRST element. 
    Note: Shifting all the elements to the right might make the LAST element in the FIRST array fall of 
    the edge. It might get lost. So we store the LAST element in the FIRST array to be in a variable called 
    LAST. 
    And we put this LAST variable in the place of the second_array_ptr. 

    We continue till all the elements would be at the right place. How do we get to know this? 
    This condition would be known to us when there are NO more SHIFTs of elements in the FIRST array. 
    When, there is NO greater element in the FIRST array than the element pointed by the SECOND 
    array. 

    Let me explain it to you while we code! 
*/

/*
    This function would be responsible for printing BOTH the arrays/vectors! 
    FIRST: {1, 2, 3, 7}
    SECOND: {9, 10, 11}
*/
void printVectors(vector<int> &first, vector<int> &second) {
    cout << "FIRST: " << endl; 
    for (int number : first) {
        cout << number << " "; 
    }
    cout << endl; 

    cout << "SECOND: " << endl;
    for (int number : second) {
        cout << number << " "; 
    }
    cout << endl; 
}

// Only thing and the MAIN thing need to be done is the MERGING part of the 2 Vectors.
// Let's declare the function mergeFirstAndSecond
// Make sure that you are passing the vectors via reference (including the & character).
// If you do not pass it by reference, then the changes to the vectors might not be reflected 
// in while printing the vectors using the function that is present just above! 
// So this is the function which shouldn't use any EXTRA space. 
void mergeFirstAndSecond(vector<int> &first, vector<int> &second) {
    // Cool. Let's start. 

    // 1. Iterate through all the elements of the SECOND vector starting from the LAST element. 
    //    If you see the EXPLANATION above, I have declared what is the second_array_ptr. Here, 
    //    the second_array_ptr is just the index of the elements in the SECOND array/vector. 
    //    that's it. 
    for (int second_array_ptr = second.size() - 1; second_array_ptr >= 0; second_array_ptr--) {
        // Now we need to find the smallest element in FIRST vector, that is greater than the 
        // element SECOND[second_array_ptr] 
        // Let's keep a track of the element index in the FIRST array/vector using the variable 
        // first_array_ptr. 
        int first_array_ptr; 
        // Let's also store the LAST element in the FIRST array/vector so that we can have it 
        // safe, in case the element falls of at the end. 
        int last = first.back(); // You can also write first[first.size() - 1] 

        // Now we will loop through the elements of the FIRST array, from the second last element
        // And if we find the element to be greater than the element pointed by the 
        // second[second_array_ptr], then we shift that element to the right to make space on the 
        // left side. 
        // We shift by just doing - first[first_array_ptr + 1] = first[first_array_ptr]
        // And we stop when we find that the element that is pointed by the first_array_ptr is less
        // than the one pointed by second_array_ptr in SECOND array. That means, we have found 
        // a place where the element pointed by second_array_ptr should belong in FIRST array. 
        // And what do we do with the element that was just removed from the FIRST? 
        // The REMOVED element from the FIRST vector is obviously the LAST element right which
        // fell off (lost in the FIRST vector when we were doing the SHIFTING operation!)
        // So, we put that LAST element that we stored before, in the place of second_array_ptr. 
        // That's it.   

        // Observe the condition in the middle. 
        // It is comprised of ANDing of the two conditions. 
        // 1. Move left till we reach the 0th element in the FIRST. 
        // 2. Move left till we reach an element in the FIRST such that that element
        //    is smaller than the SECOND vector element pointed by first_array_ptr and second_array_ptr
        //    respectively. 
        bool did_shift = false; 
        for (first_array_ptr = first.size() - 2; first_array_ptr >= 0 and first[first_array_ptr] > 
        second[second_array_ptr]; first_array_ptr--) {
            // Cool. So here we just need to shift the element to the right. Until we find the above 
            // condition. i.e - We find a place for the element pointed by second_array_ptr. 
            // So, we shift right using - 
            did_shift = true; 
            first[first_array_ptr + 1] = first[first_array_ptr]; 
        }

        // We see if there was shift. We can do this by a condition, or more easy by declaring a boolean 
        // variable again. 
        // So we check now, if did_shift the FIRST array, or the LAST varaible is greater 
        // than the element pointed by second[second_array_ptr]. If yes, we put the element 
        // pointed by second_array_ptr in place of the first_array_ptr. 
        // And we put the element contained in the LAST variabel in the second_array_ptr place. 
        if (did_shift || last > second[second_array_ptr]) {
            // Put the element pointed by second_array_ptr in the FIRST vector. 
            first[first_array_ptr + 1] = second[second_array_ptr]; 
            // And put the element that was present in the LAST of the FIRST vector in the 
            // place of the element that we just moved to the FIRST vector. 
            second[second_array_ptr] = last; 
        }

        // That's it. This should do the JOB! 
    }
}

// As you can see there are no other declaration of any arrays etc to store something. 
// We are just making of few variables that's it. 
// Hence our O(1) Space Complexity. :) 

int main() {
    // Let's declare the 2 VECTORS first. 
    vector<int> first = {1, 7, 9, 10}; 
    vector<int> second = {2, 3, 11}; 

    // Array before merging. 
    cout << "VECTOR/ARRAY BEFORE MERGING : " << endl; 
    printVectors(first, second); 

    // Now let's have a function that can Merge the 2 Arrays/Vectors. 
    mergeFirstAndSecond(first, second); 

    // Now let's have another function that can print the 2 vectors now as shown in the 
    // OUTPUT part of the Question.
    cout << "VECTOR/ARRAY AFTER MERGING!" << endl;
    printVectors(first, second); 
}

// Let's try to run the the program and see if we get the desired output. 
// Then probably I can run through the Space complexity to verify if we used any space anywhere. 
// The output looks correct. 
// Let's print the before array as well. 
// And see. 

// Yep Works! 
// Thanks for watching. Wait for 013. :P 