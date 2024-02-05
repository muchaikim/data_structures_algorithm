#include <iostream>
#include <vector>

void newform(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    newform(nums, 0, n - 1);
    newform(nums, 0, k - 1);
    newform(nums, k, n - 1);
}

int main() {
    std::vector<int> nums = {78, 43, 89, 97, 43, 78, 32, 97, 89};
    int k;
    std::cout << "Enter k to rotate {78, 43, 89, 97, 43, 78, 32, 97, 89} by: ";
    std::cin >> k;

    rotate(nums, k);

    std::cout << "Rotated by " << k << " steps: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}