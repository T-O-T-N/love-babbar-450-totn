#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    --------------------------------------------------------------------------------
    QUESTION 16: Count Inversions 
    --------------------------------------------------------------------------------
    Input: arr[] = {8, 4, 2, 1}
    Output: 6
    Explanation: Given array has six inversions:
    (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).
    Here we can see that for the element 8, we have 3 elements on the right of 8 which
    are smaller than 8. 
    TOTAL_INVERSIONS -> 3.
    Coming to the number 4, how many numbers to the right of 4 are smaller than 4? We have 2
    and 1 that are smaller than 4 and are right of 4. So TOTAL_INVERSIONS now would be 
    TOTAL_INVERSIONS = TOTAL_INVERSIONS + 2 => 3 + 2 => 5. 
    Now coming to the third element 2. How many elements to the right of 2 are smaller than 
    2? There is exactly one element that is smaller than 2. 
    TOTAL_INVERSIONS = TOTAL_INVERSIONS + 1 => 5 + 1 => 6. 
    Then we have the last element 1. We DONOT have any element to the right of 1. So we do
    not need to check any inversions. 
    So TOTAL_INVERSIONS are how many? We have 6. 
    --------------------------------------------------------------------------------
    Input: arr[] = {3, 1, 2}
    Output: 2
    Explanation: Given array has two inversions:
    (3, 1), (3, 2)
    Same way here. We see that TOTAL numbers less than 3 to the right of it are 2 (1, 2). 
    Total numbers smaller than 1 to the right of it are 0. 
    Total numbers smaller than 2 to the right of it are 0 (There is no element to the right of 2). 
    Hence TOTAL_INVERSIONS => 2. 
    --------------------------------------------------------------------------------
    Here we have an important term called INVERSIONS! 
    In an array, a pair of numbers having index i and j, are said to be INVERSIONS
    when we have arr[i] > arr[j] AND i < j. 
    Basically our OUTPUT of the program needs to be the value such that, for every
    index in the array, we need to tell how many elements to the right of that element
    are smaller than the element pointed by the index. 
    Eg in the above two INPUTS and OUTPUTS. Let me type there itself.

    Here I will be writing the O(N * N) solution for it. 
    You can write the Merge Sort way of counting inversions as well which works in 
    (N log N) time complexity where N is the size of the array. 
    That was a bit complex for the problem, so I am going with the easier one!  
*/

// Here the return type of the function is just an integer which will denote the 
// number of inversions! 
int getInversionCount(vector<int> &numbers) {
    // Declare the veriable called inversion_count that would be storing the 
    // overall inversion count for the numbers array. 
    int inversion_count = 0; 

    // Now let's run a for loop on the numbers array to track the element with the 
    // index i. 
    for (int i = 0; i < numbers.size(); i++) {
        // For every i, we will loop through all the elements to the right of i. 
        // To the right of i means we need to start another for loop that would 
        // be starting from (i + 1) index. 
        for (int j = i + 1; j < numbers.size(); j++) {
            // Now we just need to check if the element pointed by j is smaller than 
            // element pointed by i or not? If yes, then we increase the inversion_count 
            // variable by one! 
            if (numbers[j] < numbers[i]) {
                // Increase the inversion_count variable! 
                inversion_count++;
            }
        }
    }
    // At the end we just need to return the total count of inversions. 
    return inversion_count;
}

/*
    Now one more thing that we can do is that, instead of just displaying the count. 
    Let's display the inversion elements as well. Something like this - 
    (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1) 
    along with the INVERSION Count. 
    We can do this by storing the pairs of inversions in a vector<pair<int, int>> 
    and we can just query the size() function of the vector to find the total inversions. 
    Let's do it. 
*/

// I will be creating a new function for this task. Let's call it getInversionPairs
vector<pair<int, int>> getInversionPairs(vector<int> &numbers) {
    // Declare the vector of pair<int, int> that we need to populate and return! 
    vector<pair<int, int>> inversion_pairs; 

    // Let's iterate the same way, but the only difference is that instead of increasing
    // a variable, we would be pushing the pair of elements at index i and j {numbers[i], numbers[j]} 
    // like this. 
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            // We compare numbers[i] and numbers[j]. 
            if (numbers[j] < numbers[i]) {
                // Just push_back the pair into the inversion_pairs. 
                // You can also use make_pair function. 
                inversion_pairs.push_back({numbers[i], numbers[j]}); 
            }
        }
    }
    // At the end we just need to return the vector of inversion pairs. 
    return inversion_pairs; 
}

int main() {
    // Let's declare the vector first.
    vector<int> numbers = {8, 4, 2, 1};

    // Let's call our function here and print the TOTAL_INVERSIONS count. 
    // And the list of inversions after that. 
    // Cleared up the code a bit. 

    vector<pair<int, int>> inversions = getInversionPairs(numbers); 
    // Right! Now we just need to print the size of the inversions vector for our total
    // inversions. 
    cout << "TOTAL INVERSIONS : " << inversions.size() << endl; 
    // Let's print the pair<int, int> variables inside the inversion vector for getting the
    // inversions 
    for (pair<int, int> &p : inversions) {
        cout << "{" << p.first << ", " << p.second << "}" << endl; 
    }

}

// That's it! Our program should work. 
// Our program should print 6 right? 
// Yeah, it should print 6. Yep Works! 
// Let's try with the second one. 
// For teh second one, we need to print 2. 
// Yep! Our program is working. 
// Cool. Let's run this and test. First one was correct. Lets' try the next one.  
// Yep! Works. 
// Thanks for watching guys. Wait for 017. :P 
