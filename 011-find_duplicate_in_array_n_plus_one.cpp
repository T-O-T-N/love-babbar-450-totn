#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    ---------------------------------------------------------------------------------------
    Question 011:
    ---------------------------------------------------------------------------------------
    Given an array of integers nums containing n + 1 integers where each integer is in 
    the range [1, n] inclusive.
    
    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and uses only constant
    extra space.

    Note: All the integers in nums appear only once except for precisely one integer which 
    appears two or more times.

    Example - [1,3,4,2,2]
    Output - 2 
    ---------------------------------------------------------------------------------------

    So the question that is given to us is pretty straightforward. 
    The only thing that you need to know to solve this is the formula to find the sum of first N natural numbers. 
    Which is equal to N * (N + 1) / 2 

    How did we come up with that is because we have the array of size N + 1. And in this array all the numbers 
    occur once, and only one of the numbers in the array occurs twice. 

    So if we find the sum of N numbers. And we find the sum of the numbers contained in the array. And we subtract it. 
    Then we will get the number that is repeated! 

    Example in the above - We have the array of size 5. So we simply find the sum of first (5 - 1) integers. 
    That is sum of first 4 numbers. 
    So we have 4 * (4 + 1)/2 => (4 * 5) / 2 => 20/2 = 10. Let's call this A. 
    And we have the sum of all the elements in the array as -> 1 + 3 + 4 + 2 + 2 => 12. Lets call this B. 
    We subtract A from B: 
    We have (12 - 10) = 2. Which is the repeated number. 
*/

int getDuplicateFromVector(vector<int> &numbers) {
    int sum_of_vector_elements = 0; 
    for (int number : numbers) {
        sum_of_vector_elements += number; 
    }
    // Now we have the sum of the elements in the vector (this sum includes the repeated number as well!). 
    // Now let's find what is the sum of first (N - 1) natural numbers. 
    // That is, we find what is the sum of first (5 - 1) NATURAL NUMBERS. 
    int n_minus_one = numbers.size() - 1; 
    int sum_of_n_minus_one = (n_minus_one * (n_minus_one + 1)) / 2;

    // Now we just need to subtract the second one from first. 
    // Subtract (sum_of_vector_elements - sum_of_n_minus_one)
    return (sum_of_vector_elements - sum_of_n_minus_one);
}

int main() {
    // Let's declare the vector first.
    vector<int> numbers = { 1, 3, 3, 4, 2 }; 

    int duplicate_element = getDuplicateFromVector(numbers); 
    cout << "DUPLICATE ELEMENT IS : " << duplicate_element << endl;
}

// That's it! I think our program should work now! 
// I have changed the array to contain the duplicate to be 3 rather than 2. Let's see now. 
// Yep! Works. 
// Thanks for watching. 
// Wait for 012. :P 