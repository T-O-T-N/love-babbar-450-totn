#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 002: Find the Maximum and Minimum Elements
    in an array! 
    1. Using Linear Search
    2. Tournament Method (Divide and Conquer) 
*/

// This method will return a pair of int int - pair<int, int> 
// The first element of the pair will be the minimum element 
// present in the array. The second element in the pair will be the 
// maximum element present in the array! 
pair<int, int> getMinMaxElements(vector<int> &elements) {
    // Here we simply need to iterate over the elements. 
    // and maintain the max and min elements.
    // Let's initialise it with some valid value in the elements 
    // vector. Eg - First element - elements[0]. 
    int max_element = elements[0];
    int min_element = elements[0];

    // Iterate through all the elements! 
    for (int element : elements) {
        max_element = max(max_element, element); 
        min_element = min(min_element, element); 
    }

    // Since the return type of this function is a pair<int, int> 
    // We need to construct a pair and return it. 
    return make_pair(min_element, max_element); 
}

// Now let's solve the problem using the 2nd method called Tournament Method. 
// You can find this on GeeksForGeeks. 
// Here in this function, we divide the array into 2 halves and then find the
// min_max pairs for those halves. 
// We do this recursively and then derive the result based on the results returned
// from the return values of those recursive calls. 
// Basically we break the array and try to find minimum and maximum for smaller 
// sub problem (sub array). 
pair<int, int> tournamentMethod(vector<int> &elements, int left, int right) {
    // If there is only one element. 
    if (left == right) {
        // Also you can either return make_pair(elements[left], elements[right]) 
        // Or the shortcut of returning pairs as shown below. It's your preference. 
        return {elements[left], elements[right]}; 
    } else if (right - left == 1) {
        // This else if condition is for the case when there are 2 elements in the 
        // subarray. 
        // Therefore, for this we return the pair as {minimum_element_of_2, maximum_element_of_2}
        return {
            min(elements[left], elements[right]), 
            max(elements[left], elements[right])
        }; 
    } else {
        // There are more than 2 elements present in the array. 
        // So, what? Divide it now. 
        // And then find the min and max for those divided subarrays. 
        // For dividing, let's find the mid element. 
        int mid = (left + right) / 2; // Let's do this for understanding. :) 
        // Find min_max for left part. [left, mid]
        pair<int, int> min_max_left = tournamentMethod(elements, left, mid); 
        // Find min_max for the right part. [mid + 1, right]
        pair<int, int> min_max_right = tournamentMethod(elements, mid + 1, right); 

        // Now return the minimum of the numbers of the above two, and maximum 
        // of the numbers in above two, in a pair format. 
        return {
            min(min_max_left.first, min_max_right.first), 
            max(min_max_left.second, min_max_right.second) 
        }; 
    }
}

int main() {
    // First let us try the Linear Search Approach! 
    // Consider this random vector! 
    vector<int> elements = {10, 12, 6, 299, 678, 100, 2, 34};

    // Oops. We did not pass additional parameters. 
    pair<int, int> min_max_pair = tournamentMethod(elements, 0, elements.size() - 1);

    cout << "USING THE TOURNAMENT METHOD RESULTS ARE : " << endl; 
    cout << "MIN ELEMENT PRESENT IN THE VECTOR IS : " << min_max_pair.first << endl; 
    cout << "MAX ELEMENT PRESENT IN THE VECTOR IS : " << min_max_pair.second << endl; 
}

// Hence we solved the 002 - Maximum and Minimum Element Problem using C++. 
// Wait for video 003. :) 