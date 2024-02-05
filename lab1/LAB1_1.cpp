#include<iostream>

//Function for summation
int summation(const int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

//Function to find the maximum 
int maximum(const int arr[], int n) {
    if (n <= 0) {
        //Syntax error
        std::cerr << "Can't be empty bud!\n";
        return -1; 
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        max = std::max(max, arr[i]);
    }
    return max;
}

int main() {
    int n;

    // Read user expected length of array
    std::cout << "How many integers?: ";
    std::cin >> n;

     // Read inputs from user
    int arr[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Integer " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Using the user-defined summation function
    int sum = summation(arr, n);
    std::cout << "Sum of the integers entered is " << sum << "\n";

    // Use 'maximum' function 
    int max = maximum(arr, n);
    if (max != -1) {
        std::cout << "Your largest integer is " << max << "\n";
    }

    return 0;
}
