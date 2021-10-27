#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    ----------------------------------------------------------------------------
    Question 014: Merge Overlapping Intervals 
    ----------------------------------------------------------------------------
    Input: { {1,4}, {4,5} }
    Output: { {1,5} } Correct Output! 
    Explanation: Here we can see that 2 ranges {1, 4} and {4, 5} overlap at the 
    number 4. Hence we need to combine them. 
    Net range would be -> {1, 5} 
    Hence the OUTPUT. 
    ----------------------------------------------------------------------------
    Input: { {1,3}, {8,10}, {2,6}, {15,18} }
    In this question our range isn't sorted by first element. So we need to sort it 
    first and then our algorithm will work on this! 
    Sorting becomes the prerequisite of the question, and this question can be categorised under 
    SORTING questions as well! 
    Output: { {1,6}, {8,10}, {15,18} }
    Explanation: Here we can see that the ranges {1, 3} and {2, 6} overlap at the
    number 2, 3. Hence we need to combine these two ranges. 
    Net range when we combine {1, 3} and {2, 6} would be {1, 6}. 
    And the remaining ranges are distinct on their own and do not overlap with each 
    other. 
    Hence our output is: {{1, 6}, {8, 10} {15, 18}} 


    While mergin the ranges, we observe that the NET_RANGE becomes to be 
    [lower_range_of_the_first_range, max(higher_range_of_first, higher_range_of_second_range)]
    Note: Here we are assuming that the ranges are sorted by their first element. 
    ----------------------------------------------------------------------------
*/

// This problem is pretty straightforward. 
// Here our task is to merge two ranges if at all we see that the two ranges are overlapping 
// with each other. 
// What do we mean by overlapping is - if we have a range of elements say for example 
/// RANGE_1 -> {1, 5} This simply means we have the numbers 1, 2, 3, 4, 5 in this range. 
// If we have another range called RANGE_2 -> {3, 6} 
// Then we have 3, 4, 5, 6, 7 in the RANGE_2. 
// Here we can see that the elements of RANGE_1 and RANGE_2 overlap at the numbers 3, 4, 5. 
// Hence we need to combine this range RANGE_1 and RANGE_2. 
// By combining, we get the overall range to be starting from 1 
// and ENDING at 7. 
// NET_RANGE -> {1, 7} 
// Got it? 
// Same thing we need to do it in above problem! Let's look at the INPUT and the OUTPUT. 

// Let's declare the getMergedRanges function! 
vector<pair<int, int>> getMergedRanges(vector<pair<int, int>> &ranges) {
    // Cool. Now as we know that our prerequisite of teh question was to 
    // sort the ranges array by the first element. 
    // So we simply need to call the sort function on the ranges vector. 
    // The pairs when sorted automatically get sorted on the first element
    // if we use the plain sort function on the vector. 
    sort(ranges.begin(), ranges.end()); 

    // Now the ranges would be sorted based on the first element. 
    // Cool. Now what we need to do is to declare the vector<pair<int, int>> that we
    // are going to return! 
    vector<pair<int, int>> merged_ranges; 

    // Let's push the first element of the sorted ranges into out merged_ranges
    // as we know that the merged_ranges would atleast begin with the first
    // element in the ranges now. 
    merged_ranges.push_back(ranges[0]); 

    // Right! Now we need to iterate from the second range onwards to see if the 
    // range overlap with the latest range that was pushed into the merged_range. 
    // If it does, we will modify the last pushed range to accomodate the current 
    // range as well. If it doesn't overlap with the range that was last pushed, then 
    // we push a fresh range of the current_range that we have encountered. 
    // Let me name it as current_range for better readability. 
    for (int current_range = 1; current_range < ranges.size(); current_range++) {
        // We check if the current_range DOESN'T overlap with the previous range
        // that was pushed to the merged_ranges. 
        // If the below condition is true, then the range do not overlap! 
        if (merged_ranges.back().second < ranges[current_range].first) {
            // So if it doesn't overlap, we push the new range to the merged_ranges 
            merged_ranges.push_back(ranges[current_range]); 
        } else {
            // If it OVERLAPS. We need to modify the last range that we pushed to the 
            // merged_ranges vector to accomodate the overlap. 
            // Basically we need to make the last range to be equal to the NET_RANGE 
            // after merging the last range and the current_range. 
            // Therefore, just update the last range that we pushed. 
            // We can access the last range that we pushed by using the back() function 
            // Make the upper limit to be equal to the maximum of the last range pushed 
            // to the merged_ranges vector and the current_range. 
            merged_ranges.back().second = max(ranges[current_range].second, merged_ranges.back().second); 
        }
        // That's it! 
    }
    // The merge would be taken care now! 
    // Let's try to run the program now. 
    // We forgot to return the merged_range. 
    return merged_ranges;
}

int main() {
    // Cool. Let's start by declaring the input range vector. 
    // Let's have it as a vector<pair<int, int>>
    vector<pair<int, int>> ranges = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};

    // Let's have a function that can return us the vector<pair<int, int>> 
    // which would be containing the merged ranges. 
    vector<pair<int, int>> merged_ranges = getMergedRanges(ranges); 

    cout << "Merged Range is : " << endl; 
    // Each of the range would be printed on a new line! 
    for (auto range : merged_ranges) {
        cout << "{" << range.first << ", " << range.second << "}" << endl; 
    }
}

// We will be printing in the form of { } these brackets! 
// Yep out solution is working perfect! 
// Thanks for watching! 
// Wait for 015. :P 