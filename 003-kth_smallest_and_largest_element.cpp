#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 003: kth largest and smallest elements in an array. 
    1. Using Sorting - Done! 
    2. Using priority_queue (max and min pq) - Done! 
    3. Using map<int, int> 
*/

// Let's get the kth smallest and kth largest elements using the first method 
// using SORTING of the array! 
int kthSmallestElement(vector<int> &elements, int k) {
    // We can either sort it here, or we can pass a sorted array from the main method. 
    // A sorted array from main method would be a good choice, as for each call
    // we need not SORT the vector again and again which is O(N log N) operation 
    // where N is the size of the vector. 
    // So let's assume we get a sorted array for now. 
    return elements[k - 1]; 
}

int kthLargestElement(vector<int> &elements, int k) {
    // Here we just need to return the (size - k)the element. 
    // Here, size is the size of the vector. 
    int size = elements.size(); 

    return elements[size - k]; 
}

/*
    For the priority queue method, we need to declare a min priority queue
    and a max_priority queue. 
    For the kth smallest element, we pop (k - 1) elements from the priority queue
    then the top most  element would be kth smallest element. 
    Same way for max_priority queue. We will pop (k - 1) elements from it. Which 
    will let the kth largest element to be on the top! 
*/
int kthSmallestNumberUsingPriorityQueue(vector<int> &elements, int k) {
    priority_queue<int, vector<int>, greater<int>> minq; 
    // Return some random value if the value of k is more than 
    // the size of the vector elements. 
    if (k > elements.size()) {
        return INT_MIN; 
    } 

    // Otherwise, push elements to the min priority queue one by one; 
    for (int element : elements) {
        minq.push(element); 
    }

    // The Top Most element now will contain the smallest element in the minq. 
    // If we pop k - 1 elements from the minq, then the top most element 
    // would contain the kth smallest number on the pq.top() position. 
    for (int i = 1; i <= k - 1; i++) {
        minq.pop(); 
    }

    // Now the TOP MOST element should contain the kth smallest number.
    // Therefore simply return it.  
    return minq.top();
}

// Our kth Smallest Number is working now! Same way we do it for the kthLargest 
// as well. Here instead of min priority queue, we construct a max priority queue. 
int kthLargestNumberUsingPriorityQueue(vector<int> &elements, int k) {
    // Declare the max priority queue. 
    priority_queue<int> maxq; 

    // Push all the elements into the maxq; 
    for (int element : elements) {
        maxq.push(element); 
    }

    // Now all the elements would be present in the max priority queue. 
    // Let us now pop the top k - 1 elements from the PQ. 
    // After removing the top k - 1 elements, the top most element would 
    // contain the kth largest number. 
    for (int i = 1; i <= k - 1; i++) {
        maxq.pop(); 
    }

    // Now the top contains the kth Largest Element in the array. 
    return maxq.top(); 
}

/*
    The next method we have is using the map<int, int> STL container. 
    Here we will be storing the vector elements as the keys, and the number 
    of times a particular element is present in the vector as the values. 
    
    We would be utilising the fact that the elements in the map (the key value pairs) 
    are sorted by the increasing order of the keys! 

    We maintain a temporary variable called counter. And we increment it by the number 
    of times the given key is present. (This would be present in the value part 
    corresponding to each key). 
    We check for a condition when the variable counter becomes greater than or equal 
    to k. When this condition occurs, that means we have found our kth largest 
    or kth smallest element in the vector. 

    The only difference between kth largest and kth smallest is how we traverse the map. 
    The rest of the logic remains the same. 
    For kthSmallest Element - We traverse from mp.begin() to mp.end() 
    For kthLargest Element - We traverse from mp.rbegin() to mp.rend() 
    in the map. 
*/ 

int kthSmallestElementUsingMap(vector<int> &elements, int k) {
    // First declare a map. Note: unordered_map won't work here because 
    // the internal implementation of unordered_map is using Hash Tables 
    // which do not maintain any order in the keys. We need to strictly use 
    // map here. 
    map<int, int> map_of_vector_elements; 

    // Now let's populate the map. 
    for (int element : elements) {
        map_of_vector_elements[element]++; 
    }

    // Let's declare our counter variable. 
    int counter = 0; 

    // Now iterate over the map from begin() to end() 
    // Here it -> first : Key (elements that are present in the vector)
    // it -> second : Value (number of times the element is present in the vector)
    for (auto it = map_of_vector_elements.begin(); it != map_of_vector_elements.end(); it++) {
        // We increment the counter variable by the amount present in the value. 
        // The value contains the number of times the given key is present in the 
        // elements vector. 
        counter += it -> second;   

        // Now check if the condition (counter >= k) is true or not. 
        if (counter >= k) {
            // The key is our kth smallest element. Therefore return it -> first. 
            return it -> first; 
        }    
    }

    // Default return statement.
    return -1; 
}

// Similarly we can do it for kthLargest element using map. 
// Remember, only difference is we traverse from rbegin() to rend()

int kthLargestElementUsingMap(vector<int> &elements, int k) {
    // First declare a map. Note: unordered_map won't work here because
    // the internal implementation of unordered_map is using Hash Tables
    // which do not maintain any order in the keys. We need to strictly use
    // map here.
    map<int, int> map_of_vector_elements;

    // Now let's populate the map.
    for (int element : elements)
    {
        map_of_vector_elements[element]++;
    }

    // Let's declare our counter variable.
    int counter = 0;

    // Now iterate over the map from rbegin() to rend()
    // Here it -> first : Key (elements that are present in the vector)
    // it -> second : Value (number of times the element is present in the vector)
    for (auto it = map_of_vector_elements.rbegin(); it != map_of_vector_elements.rend(); it++)
    {
        // We increment the counter variable by the amount present in the value.
        // The value contains the number of times the given key is present in the
        // elements vector.
        counter += it->second;

        // Now check if the condition (counter >= k) is true or not.
        if (counter >= k)
        {
            // The key is our kth smallest element. Therefore return it -> first.
            return it->first;
        }
    }

    // Default return statement.
    return -1;
}
// Looks good! Let's run and see. With just putting 'r' does our program give
// proper output or not. :P 

int main() {
    // Suppose we want to return the kth largest and kth smallest 
    // elements of the vector that is shown below.
    vector<int> elements = {7, 10, 4, 3, 20, 15};

    // Let's declare the value k 
    int k = 3; // for example. 

    // Now our program should find the 2nd smallest and 
    // 2nd largest elements in the elements array. 
    // 2nd Largest Element is : 15
    // 2nd Smallest element is : 4 

    // Now the below methods would produce desired results.
    int kth_smallest = kthSmallestNumberUsingPriorityQueue(elements, k);
    int kth_largest = kthLargestNumberUsingPriorityQueue(elements, k);
    cout << "Kth Smallest Number using PQ is : " << kth_smallest << endl;
    cout << "Kth Largest Number using PQ is : " << kth_largest << endl;

    int kth_smallest_using_map = kthSmallestElementUsingMap(elements, k); 
    cout << "KTH smallest number using Map is : " << kth_smallest_using_map << endl; 

    int kth_largest_using_map = kthLargestElementUsingMap(elements, k); 
    cout << "KTH LARGEST NUMBER USING MAP IS : " << kth_largest_using_map << endl; 
}

// We are getting the correct output.
// Let's change k to 3 and see the results.
// Here we should be getting -
// kth smallest is : 7
// kth largest is : 10

// We are done with the 003 video as well. 
// Wait for 004. :P