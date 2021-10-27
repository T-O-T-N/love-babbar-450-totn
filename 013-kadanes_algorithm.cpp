#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 013: KADANES Algorithm for Largest Sum Contiguous Subarray
    ----------------------------------------------------------------------------
    INPUT: 
    {-2, -3, 4, -1, -2, 1, 5, -3}
    ----------------------------------------------------------------------------
    OUTPUT: 
    Max Contiguous Subarray Sum is: 7 
    ----------------------------------------------------------------------------
    (The subarray that has the sum is - {4, -1, -2, 1, 5})
*/

/*
    If you remember, we had done the LARGEST CONTIGUOUS SUBARRAY SUM PROBLEM before in the 
    program number 008. And there I hadn't discussed about the KADANES Algorithm. 
    Today we would be discussing just that. 

    KADANES Algorithm is the most efficient way of finding the LARGEST CONTIGUOUS SUBARRAY SUM 
    in O(N) Time Complexity, where N is the size of the vector. 
    We just need to iterate once through the array, maintain 2 variables and then we are done. 
    Let's discuss the approach below while we code. 
*/ 

/*
    APPROACH for KADANES Algorithm! 

    We just need to maintain 2 variables called - 
    1. max_ending_here 
    2. max_so_far 

    max_ending_here - would be containing the maximum sum seen so far for the subarray. 
    When this value becomes -ve. We make max_ending_here = 0, indicating that we will be discarding 
    the subarray that we have been tracking so far. 
    And we would make a fresh start of the subarray starting at the current position where we are now.

    max_so_far would contain the maximum value of the maximum_ending_here seen throughout the iteration. 
    This is the variable that is gonna contain our answer of the LARGEST CONTIGUOUS SUBARRAY Sum! 

    Let's define the function now. 
*/ 

int getLargestByKadanesAlgorithm(vector<int> &numbers) {
    // As discussed, we would maintain the above 2 variables. 
    int max_so_far = 0;
    int max_ending_here = 0; 

    // Now let's iterate through the vector elements. 
    // We would add the current element to the max_ending_here sum by 
    // doing max_ending_here = max_ending_here + numbers[i]. 
    // We see if the value of the max_ending_here becomes -ve or what? 
    // If it becomes negative, then it's always better to discard the subarray as the subarray
    // is giving us -ve sum. Got it right? 
    // So when it becomes negative, we set the max_ending_here to be 0. 
    // At every addition of the current_element value to the max_ending_here we check if the 
    // max_ending_here sum becomes greater than the max_so_far. 
    // If it exceeds, then we update the max_so_far value as well. 
    // First iterate through the vector elements. 
    for (int i = 0; i < numbers.size(); i++) {
        // Update the value of max_ending_here to add the current_element (numbers[i]) 
        max_ending_here = max_ending_here + numbers[i]; 

        // Now check if the addition of the value numbers[i] made the contiguous sum even bigger or not? 
        // If it did, then we update the max_so_far variable. 
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here; 
        }

        // And we also need to see if the addition made the sum -ve. 
        // If it did, then let's start afresh by making the max_ending_here value to be 0. 
        if (max_ending_here < 0) {
            max_ending_here = 0; 
        }
        // That's it. 
    }

    // After the for loop. Our value contained in the max_so_far would be our answer. 
    // We simply need to return max_so_far. 
    return max_so_far; 
}

int main() {
    // Let's declare the vector first. 
    vector<int> numbers = {-2, -3, 4, -1, -2, 1, 5, -3}; 

    // We need to define this function called getLargestByKadanesAlgorithm. 
    int largest_subarray_sum = getLargestByKadanesAlgorithm(numbers);

    cout << "Max Contiguous Subarray Sum is: " << largest_subarray_sum << endl; 
}

// Looks good to me! 
// Let's run the program to see if we are getting the correct output or not? 
// Yep! Worked. 
// Thanks for watching. Wait for 014 :P 
