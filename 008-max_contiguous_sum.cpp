#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 008: Find Largest sum contiguous Subarray [V. IMP]

    Input  : {-2, -3, 4, -1, -2, 1, 5, -3};
    Output : Maximum contiguous sum is 7
*/

int findLargestContiguousSum(vector<int> &elements) {
    int max_sum = 0; 
    // Here we will write the logic for the problem. 
    /*
        Approach - We find the SUBARRAY Sum of all the subarrays. 
        We maintain ranges called [left, right] and find the sum of 
        subarrays defined by left and right range (inclusive). 
        We maintain the max_sum variable as well and we update the max_sum 
        as and when we see a range_sum greater than max_sum. 
        range_sum is the sum of all the elements present in the [left, right] 
        range of the elements vector. 
    */ 
    // Declare the for loop for defining left range. 
    for (int left = 0; left < elements.size(); left++) {
        // Declare the for loop for defining the right range for each left declare above. 
        for (int right = left; right < elements.size(); right++) {
            // Find the sum of all elements in left to right range. 
            // Range sum is the sum value for elements present 
            // between [left, right] 
            int range_sum = 0; 
            for (int i = left; i <= right; i++) {
                range_sum += elements[i]; 
            }

            // Update the max_sum, if the range_sum found is greater than the 
            // max_sum seen so far. 
            // You can write if statement as well. 
            if (range_sum > max_sum) {
                max_sum = range_sum; 
            }
            // Both should be fine!             
        }
    }

    return max_sum; 
}

// The above approach was a Ncube approach. As we had 3 for loops there. 
// And all of the for loops can range from 0 to n - 1. Hence O(N * N * N)
// We can easily reduce the time complexity to O(N * N) 
int findLargestContiguousSumInNSquare(vector<int> &elements) {
    int max_sum = 0; 
    // Here we will write the logic for the problem. 
    /*
        Approach - We do most of the things same as above. Only differnece 
        we make is how we calculate the inner most sum. 
        If we notice that we are unneccessarily calculating the 
        sum of [left, right] again and again if we want to calculate 
        the sum of [left, right + 1] also. 
        The difference of sum of [left, right] and [left, right + 1] 
        differ only by elements[right + 1]. Nothing else. 

        We can utilise this fact and maintain a running sum above the 2nd for 
        loop itself. 
    */ 
    // Declare the for loop for defining left range. 
    for (int left = 0; left < elements.size(); left++) {
        // Declare the for loop for defining the right range for each left declare above. 
        int running_sum = 0; 
        for (int right = left; right < elements.size(); right++) {
            // And we just add the element pointed by right to the running_sum. 
            running_sum += elements[right]; 

            // And we compare if addition of the elements[right] made the 
            // running_sum to be more than the max_sum? 
            if (running_sum > max_sum) {
                // We update the max_sum to running_sum. 
                max_sum = running_sum; 
            }
        }
    }
    // We reduced the number of loops from 3 to 2. Making the algorithm more efficient. 
    return max_sum; 
} 

// This Question is one of the most important questions in Arrays! 
// So pay attention to it. 
// I would be discussing 2 ways of doing it in the video. 
// There is a third way as well, which is the most efficient way of finding 
// Maximum SubArray Sum, and that is called KADANES Algorithm. 
// But in the DSA Cracker Sheet, there is a separate question entry
// for just KADANES algorithm, so I would discuss it at that time. :) 
// Cool. First method we have is using O(N * N * N) solution. N Cube Solution. 
int main() {
    // Before that let me declare the vector first.
    vector<int> elements = {-2, -3, 4, -1, -2, 1, 5, -3};

    int largest_contiguous_subarray_sum = findLargestContiguousSumInNSquare(elements);

    cout << "Maximum contiguous sum is " << largest_contiguous_subarray_sum << endl;
}

// Let's try to run this and see if we get correct output or not! 
// Let's run the program using the second approach! 
// Yep. Works! 
// There is the third approach of KADANES Algorithm, which we shall see later. 
// Till then wait for 009. :P 
// Thanks for Watching! 