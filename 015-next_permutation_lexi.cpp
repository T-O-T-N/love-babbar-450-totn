#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    --------------------------------------------------------------------------------
    QUESTION 15: Next Permutation  
    --------------------------------------------------------------------------------
    Implement next permutation, which rearranges numbers into the lexicographically 
    next greater permutation of numbers.
    --------------------------------------------------------------------------------
    Input : [1,2,3]
    Output: [1,3,2]
    --------------------------------------------------------------------------------
    Input : [3,2,1]
    Output: [1,2,3]
    --------------------------------------------------------------------------------

    To be Honest! If you know the next_permutation function! Then this problem is just 
    one liner for you. 
    Before I show you how we solve it in a single line, let me give you the background 
    about the next_permutation function! 

    So the next_permutation function is responsible for getting the next lexicographically
    greater permutation of the numbers or characters present.
    Let me give you an example with an array of 3 elements with numbers {1, 2, 3} Cool! 
*/

void printVector(vector<int> &numbers) {
    // This is gonna print the numbers vector in the bracketed format. 
    // eg - {1, 2, 3} 
    cout << "{" << numbers[0] << ", " << numbers[1] << ", " << numbers[2] << "}" << endl;
}

int main() {
    // Here we declare the vector. 
    vector<int> numbers = {1, 2, 3}; 
    
    // Now, in order to find all the permutations of the numbers vector. 
    // We just need to make use of the next_permutation function! 
    do {
        // While there are still more lexicographically greater permutations available 
        // continue producing the next permutations. 
        // We can have a function that can print the elements of the vector 
        // at each iteration of the do while loop! 
        printVector(numbers); 
    } while (next_permutation(numbers.begin(), numbers.end())); 
}

// That's it for the main program! Let's see the output produced by this! 
// Generating permutations is as simple as this. :) 

// Let's take a look at the LeetCode Question! 
// The input and output are exactly what our next_permutation function is gonna produce.
// Let's directly run it on Leetcode. 

// That's it for this video. Thanks for watching. 
// Wait for 016. :P