#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*

    Question 010: Minimum number of jumps required to reach the end
    of the array/vector. 
    Problem Description - 
    We are given an array something like shown below. 
    Each element in the array shows how many jumps further we can take from 
    that index. 
    Example - Here in the arr[1] we have the value 3. So we can take 3 jumps further
    down the lane. Therefore the elements reachable from arr[1] = 3 would be -> 
    5, 8 and 9. That is arr[2], arr[3], arr[4]. The max you can reach is index = current_index 
    + the value at that index -> 1 + 3 = 4. Maximum farthest you can reach is 4th index here from 1 index.
    Our task is to find out what is the minimum number of jumps that are required 
    to reach the END. END = N - 1 (where N is the size of the Vector/Array!) 

    Got it right? The problem statement? 
    Cool. We'll start. 

    Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
    Output: 3 (1-> 3 -> 9 -> 9)
    So here we can see the above array. 
    First element is 1, and this is the place where we start the journey. 
    Since the value is 1, we can go to ONLY next index. Which contains the value 3. 
    So we started with index - 0 (value = 1) 
    Now we moved to index - 1 (value = 3) so we can move to 5, 8, 9. 
    If we move to the index containing 5, then we will end up at value 7. 
    If we move to the value 8, then we reach the destination. 
    If we move to the value 9, then also we reach/exceed the destination. 
    So it would be better to move to either 8 or 9, as it would complete our journey. 
    So total minimum jumps are - 
    1 -> 3 (1 jump) 
    3 -> 9 (1 jump) 
    9 -> 9 (1 jump) 
    So answer = 3 jumps. 

    Or this could also have been - 
    1 -> 3 (1 jump) 
    3 -> 8 (1 jump) 
    8 -> 9 (1 jump) 
    Again 3 jumps. 

    Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    Output: 10
    Explaination - For this we can clearly see that minimum jumps required is atleast the length of the 
    array. Since from every index we can move to the next index ONLY. 

    Let's write the code. 
*/

// Let's declare the function! 
int getMinimumJumpsToReachFromSourceToDestination(vector<int> &jumps, int source, int destination) {
    // Here first we will check if the source and destination are same or not! 
    if (source == destination) {
        return 0; 
    }

    // One more thing we need to check is, if the value contained at the source (the position
    // where we are currently) is 0 or some positive value. Because if it is 0, then we cannot 
    // move only. So we can just return INT_MAX from this position indicating that we just 
    // cannot reach the destination from source since there is a 0 and we can take 0 jumps 
    // (basically you cannot jump further! :/ )
    if (jumps[source] == 0) {
        return INT_MAX; 
    }

    // Cool. Now we need to see all the indices that are reachable from the source. 
    // Make a note on the for loop condition. Let me explain you that also. :) 
    // 1. i should be less than or equal to destination, if it exceeds then we should stop. 
    //    why? Because we have already reached the destination and there is nothing to check about 
    // further jumps. 
    // 2. (i <= source + jumps[source]) -> This conditon makes sure that the value of i is 
    //    within the range of the maximum jumps possible from a given index. Here, the maximum 
    //    index that you can reach is jumps[source] + current_index -> source + jumps[source]. 
    // That's it. Nothing complicated.
    
    // Declare the min_jumps variable here that would be calculated from the for loop below. 
    int min_jumps = INT_MAX; 
    for (int index = source + 1; index <= destination && index <= source + jumps[source]; index++) {
        // Inside teh for loop, the indices that populate in teh variable i, 
        // Or better let me rename the variable i to index.
        // Call the recursive function by passing the source as index, and destination remains
        // the same. 
        int jum = getMinimumJumpsToReachFromSourceToDestination(jumps, index, destination);
        
        // Here we need to check if teh value returned from the getMin... function is INT_MAX? 
        // If it's INT_MAX it indicates the conditon that we cannot move further from some subindex. 
        // And we also need to check if the value returned from the call above + 1 is < than the 
        // min_jumps? If yes, we update the min_jumps. 
        // Here we are checking for jum + 1 because we need one jump to move from the 
        // source -> index right? That's why here we have + 1 term. 
        if (jum != INT_MAX and jum + 1 < min_jumps) {
            min_jumps = jum + 1; 
        }
    }
    
    // The min_jumps would be populated now. We simply return this. 
    // Note that this min_jumps is populated for every sub problem divided in the for loop. 
    // That's how we are getting the overall result. 
    return min_jumps;
}

int main() {
    // Let's declare the vector first.
    vector<int> jumps = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // Now let's declare a variable that will get the answer. 
    // Source = 0, since we are starting from the index 0. 
    // Destination = n - 1 (where n is the size of the vector) because that is where we 
    // will end the journey! 
    int source = 0; 
    int destination = jumps.size() - 1;
    int answer = getMinimumJumpsToReachFromSourceToDestination(jumps, source, destination); 
    cout << "MINIMUM JUMPS REQUIRED IS : " << answer << endl; 
}

// Cool. Let's run the program to see if it's working! 
// That was it guys! 
// Thanks for watching. 
// Let me know if I need to put less comments. I put more comments so that you guys are 
// able to understand each and every condition that we put here. 
// Cool. Till then wait for 011. :) 