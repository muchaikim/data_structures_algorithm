#include <iostream>

//Updates the array by moving only new integers to next position

int RemoveDupe(int nums[], int n) {
    if (n == 0) {
        return 0;
    }

    int index = 0; 

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[index]) {
            index++;
            nums[index] = nums[i];
        }
    }

    return index + 1;
}

int main() {
    int n;
    std::cout << "Enter number of integers:";
    std::cin >> n;

    int nums[n];
    
    for (int i = 0; i < n; i++) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> nums[i];
    }
    
    int updated = RemoveDupe(nums, n);

    std::cout << "New array: ";
    for (int i = 0; i < updated; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
