#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 009: Minimise the maximum difference between the heights of the towers when you are 
    given an integer k, and you either need to increase the height of a tower by k 
    or decrease the height of a tower by k compulsorily. 
    And then the difference between the tallest and the shortest tower should be as 
    minimum as possible! 

    Input:        arr[] = {1, 15, 10}, k = 6
    Output:       Maximum difference is 5.
    Explanation: Here the tower are of heights 1, 15 and 10. And the k value that is given 
    to us is 6. So we can either increase the height of the towers by 6 or decrease the height 
    of the towers by 6. 
    Therefore if we increase the height of tower with height 1, then we will have 1 + 6 = 7. 
    Tower Heights - {7, 15, 10} 
    Now the second tower we decrease the height by 6. So updated heights would be - 
    {7, 9, 10} 
    Now for the last tower it makes sense to decrease the height by 6. So the heights of the 
    towers would be - 
    {7, 9, 4} 
    Now we have the shortest tower being of height - 4 
    Tallest Tower is of height - 9 
    Difference between them is : 9 - 4 = 5. That is our answer! 

    Input : arr[] = {1, 5, 15, 10} 
            k = 3   
    Output : Maximum difference is 8
*/

int main()
{
    // In order to get the answer it would be wise to sort the array first so that we
    // can increase or decrease the height with some consistency! That is,
    // if we sort the towers, then all the shorter towers will come to the left hand side.
    // all the taller towers would go to the right hand side, the last tower being the tallest one
    // in the list.
    // Then we can start decreasing the height of the towers on the right.
    // And start increasing the heights of the towers on the left.
    // But till what tower is the question? What is the tower after which we need to decrease
    // instead of increasing? That is something we need to find out in this question.

    // Cool! There are a couple of things that we need to understand before we write the code
    // for this -

    /*
        1) For any given tower if you choose to increase it's height from Hi to Hi + K, 
        then you can also increase the height of all shorter towers as that won't affect the 
        maximum. 
        2) If you choose to decrease the height of a tower from Hi to Hi - K, then you can also
        decrease the height of all taller towers as that won't change the maxheight among the towers. 

        We are gonna make use of the above two facts. 
        We have N buildings, and we'll try to make each of the building the highest and see 
        whether making that building the highest building gives us the least range of the heights. 

        So what are the steps? 
        1) We first sort the array/vector! As mentioned before. 

        2) For every building from i = 0 to n - 2, we try to make it highest building by adding 
        K to the building, adding K to the buildings on it's left and subtracting K from the buildings
        on it's right. 

        So for example - if we are at building Hj, we've added K to it and the buildings before it 
        and subtracted K from the buildings after it. 

        So the minimum height of the buildings will now be - 
        min(H[0] + K, H[j + 1] - K) - In simple words - 
        min(1st building + K | next building on right - K) -> A 

        Same way, the maximum height of the buildings will be - 
        max(H[j] + K, H[n - 1] - K) 
        max(current_building + K, last_building_on_right - K) -> B

        Now when we have the above 2 values A and B. 
        Then Mod(A - B) should give you the answer. 
        or just B - A should give it. 

        When the current building is the last building. Then j = n - 1. 
        In this case, there are no buildings on the right of the current building. 
        And all the buildings are on the left (that is we are adding K to them). 
        Hencee all the K's actually cancel out. And the difference merely becomes 
        the height of the last building minus the height of the first building. 
        last building is the tallest 
        first building is the shortest since we sorted the buildings. 
        towers[n - 1] - tower[0]. 

        Let's write the code for this! The problem looks simple but can be confusingg 
        to understand. 
        Let's write the code now! 
    */

    // Declare the towers
    vector<int> towers = {1, 5, 15, 10};
    int k = 3;

    // Sort the array of towers now.
    sort(towers.begin(), towers.end());

    // Declare the answer to be the last case when there are no more towers
    // on the right.
    int n = towers.size();
    int answer = towers[n - 1] - towers[0];

    // Let's declare the variables smallest and largest
    int smallest = towers[0] + k;
    int largest = towers[n - 1] - k;
    // The above might not be true, just ignore. WE are anyways gonna modify these variables. 

    // Now we run a for loop from 0 to n - 2 -> [0, n - 2] or [0, n - 1) 
    // By treating every number to be the current building number who we want to make 
    // it the maximum_height and try to see if that can produce the answer for us. 

    for (int current_building = 0; current_building < n - 1; current_building++) {
        // Since the buildings are sorted, all the buildings on the right side of the current building
        // Will start to decrease by k, but we don't need to decrease all of them. 
        // We can just see what is the value to the just right building to the current_building. 
        // And we see if decreasing the height of the [current_building + 1]th building 
        // brings down the minimum or not? 
        int minimum = min(smallest, towers[current_building + 1] - k); 

        // Same way, we see if increasing the height of the current building by K
        // increases the maximum_height among all the buildings. 
        // If it does, then we make maximum to be that value.
        int maximum = max(largest, towers[current_building] + k); 

        // Here we also check if the minimum doesn't get -ve. It might be possible since 
        // we are subtracting K right. If it becomes negative, just continue. 
        // Negative height of the building is not possible. 
        if (minimum < 0) continue; 

        // Otherwise. we have got the maximum and minimum heights of the buildings 
        // if we decrease the height of all the towers/buildings to the right of the 
        // current_building and increase the height of all the towers to the left of the 
        // current_building (including the current_building). 
        answer = min(answer, maximum - minimum); 
    }

    // Print the answer outside. 
    cout << "Minimum maximum difference is : " << answer << endl; 
}

// That's it. 
// Too much commented, just to explain you guys. 
// Thanks for watching! 
// Wait for 010! :P 