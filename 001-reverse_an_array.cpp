#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    In this video we will be solving the first question out of 
    the cheatsheet of Love Babbar which contains 450 questions. 
    We will try to solve as many questions as possible. 

    Question: Reverse an Array. (String and Vector included in 
    my implementation, as the implementation is nearly the same!)
*/ 

// Here we need only the vector, as the size of the vector can be 
// determined by it's size() function! 
void printVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " "; 
    }
    cout << endl; 
}

// Function to print the Array. Here we need the size parameter as 
// well inorder to know till what element do we need to continue the 
// for loop iteration. 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

void reverseArray(int arr[], int size) {
    int begin = 0; 
    int end = size - 1; 

    while (begin <= end) {
        swap(arr[begin], arr[end]);
        // Make sure to do the below two statements as well
        // Otherwise this might run into infinite loop!
        begin++; 
        end--; 
    }
}

// Here make sure that you are passing the vector via 
// reference. Otherwise if you pass it by value, then the 
// changes to the vector might not be made to the vector present in 
// the main function!
// Hence, make sure to have the & symbol to pass it by reference. 
void reverseVector(vector<int> &vec) {
    int begin = 0; 
    int end = vec.size() - 1; 

    while (begin <= end) {
        swap(vec[begin], vec[end]); 
        begin++;
        end--; 
    }
}

// Here I am taking the string by reference. 
void reverseString(string &str) {
    int begin = 0; 
    int end = str.length() - 1;

    // Same like vector you can do! 
    // Here, instead of swap you can also type the traditional 
    // way of swapping. Something like this...
    // Both works fine. swap(str[begin], str[end]) or the one 
    // shown below. 
    while (begin <= end) {
        char ch = str[begin]; 
        str[begin] = str[end]; 
        str[end] = ch; 
        begin++;
        end--;
    }
}

int main() {
    const int size = 8; 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    vector<int> vec = {10, 11, 12, 13, 14}; 
    string str = "ABCDEFG"; 

    cout << "STRING INITIALLY IS : " << str << endl; 
    reverseString(str); 
    cout << "STRING AFTER REVERSAL IS : " << str << endl; 
}

// That was the first COMMENTED video in the series. 
// And we solved the reversal of array, vector and string 
// problem. 