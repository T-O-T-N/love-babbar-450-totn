#include <bits/stdc++.h>
using namespace std;
using LL = long long;

/*
    Question 004: Sort the array of 0, 1 and 2 without using sorting. 
    
    More common variant of the question asked is sorting 0s and 1s 
    which you can do via SWAPPING as well. 
*/ 

void sortZeroesOnesTwos(int zeroes_ones_twos[], int size) {
    // Here we maintain three variables called zeroes, ones, and twos. 
    // To count the number of zeroes, ones, and twos present in the array. 
    int zeroes = 0; 
    int ones = 0; 
    int twos = 0; 

    // Now we run a loop and count how many of them are present in the array. 
    for (int i = 0; i < size; i++) {
        if (zeroes_ones_twos[i] == 0) {
            zeroes++; 
        } else if (zeroes_ones_twos[i] == 1) {
            ones++;
        } else {
            // Here we put it in else block since we know that 
            // no other element apart from 0, 1, 2 would be present 
            // in the array. 
            twos++; 
        }
    }

    // Now we have the counts. We simply need to put the zeroes number 
    // of 0's in front. 
    // followed by ones 1's and twos 2's. 
    // Let's fill it. 
    // For maintaining the position to fill, we declare a variable called 
    // current_positon;
    int current_position = 0; 
    for (int i = 0; i < zeroes; i++) {
        zeroes_ones_twos[current_position] = 0; 
        current_position++; 
    }
    // Fill 1's next; 
    for (int i = 0; i < ones; i++) {
        zeroes_ones_twos[current_position] = 1; 
        current_position++; 
    }
    // Fill 2's next; 
    // You can also do the increment in the same assignmentt statement itself.
    // But make sure it's a post increment here. Not a preincrement. 
    // Postincrement means something like i++ 
    // Pre Increment means something like ++i 
    for (int i = 0; i < twos; i++) {
        zeroes_ones_twos[current_position++] = 2;
    }
}

// Note here that I am passing the vector via reference. 
// In order to reflect the changes in the main function as well. 
// If we pass by value (remove the & symbol) then the copy 
// of the vector would be modified and the one in the main function 
// would remain as it is. 
void sortVectorUsingSwapping(vector<int> &zeroes_ones) {
    // For the swapping method we maintain two pointer called 
    // left and right. 
    // The left pointer points to a 1 element. 
    // The right pointer points to a 0 element. 
    // Whenever we find a left pointer containing a 1
    // and the right pointer containing a 0. We SWAP them! 
    // We do it until the left and right pointers cross each other! 
    // (indicating no more improper positions of 1 and 0 are left)
    int left = 0; 
    int right = zeroes_ones.size() - 1; 

    // Until they cross each other! 
    while (left < right) {
        // Make left point to a valid 1 value.  
        // Here we are iterating so that until we find a 1
        // we keep moving the left pointer. 
        while (left < right and zeroes_ones[left] != 1) {
            left++; 
        }

        // Make right point to a valid 0 value. 
        // And here we are keeping on decrementing right. 
        // Until we find a 0 element. 
        while (left < right and zeroes_ones[right] != 0) {
            right--; 
        }

        // After the above two while loops. 
        // We will be having left and right pointing to valid 1's 
        // and 0's. 
        // Now we need to swap these 2 elements at left and right. 
        if (left < right) {
            swap(zeroes_ones[left], zeroes_ones[right]); 
            left++; 
            right--; 
        }
    }
}

void printArray(int arr[], int size) {
    cout << "Array is : " << endl; 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

void printVector(vector<int> &vec) {
    cout << "Vector is : " << endl; 
    for (int element : vec) {
        cout << element << " "; 
    }
    cout << endl; 
}

int main() {
    // Here we declare the array/vector of 0's and 1's. 
    // Most of the questions which involve array, I prefer using vector. 
    // Because more or less they are the same. 
    // I can show you guys how to do it using array as well. But 
    // in coding I usually advise people to use vector more and more. 

    // First I will show you the implementation using array. 
    int zeroes_ones_twos[] = {
        0, 1, 2, 0, 0, 1, 2, 2, 2, 1, 0, 0, 1
    }; 

    // We have 5 zeroes and 2 ones. 
    vector<int> zeroes_ones = {
        0, 0, 1, 0, 1, 0, 0  
    };

    // Suppose the above array is the one that we have! 
    // Let's find the size of the array. You can either count manually. 
    // Or use this formula to find the number of elements in the array.
    int size = sizeof(zeroes_ones_twos) / sizeof(int);

    // Now let's call a function which would sort our array. 
    // We pass the zeroes_ones_twos array, and the function would sort it 
    // for us. 

    cout << "Initially Array is : " << endl; 
    printArray(zeroes_ones_twos, size); 

    // I am not sure of the spelling of zeros or zeroes. 
    sortZeroesOnesTwos(zeroes_ones_twos, size); 

    // Let's print the array and see what the array looks like. 
    cout << "After Sorting (without actually sorting) : " << endl; 
    printArray(zeroes_ones_twos, size); 

    cout << "ZEROES AND ONES VECTOR before sorting is : " << endl;
    printVector(zeroes_ones); 

    // Here we need to have the function that can sort the vector
    sortVectorUsingSwapping(zeroes_ones); 

    cout << "VECTOR AFTER SORTING USING SWAPPING IS : " << endl;
    printVector(zeroes_ones); 
}

// Output looks correct. 
// Now let me show you how to sort an array of 0's and 1's using swapping. 
// Looks good. Let's run and see the output. If we run into some problem or not! 
// Oops. I guess we need to do reverse. 
// Yep, Now it looks correct. :) 
// Sorry for missing that part. I am not gonna cut this mistake of mine 
// as everyone makes silly mistakes. 

// Yep. That was it for this video. 
// Wait for 005. :P