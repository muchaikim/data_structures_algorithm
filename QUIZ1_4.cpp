#include <iostream>
#include <vector>

int TheOne(const std::vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    std::vector<int> nums = {78, 43, 89, 97, 43, 78, 32, 97, 89};

    int singleNumber = TheOne(nums);

    std::cout << "That single one is " << singleNumber << std::endl;

    return 0;
}
