#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(vector<int>& nums, int start, int end, int r,
                           vector<int>& data, int index) {
    // Base case: If we have selected 'r' elements, print the combination
    if (index == r) {
        for (int i = 0; i < r; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive case: Select elements and generate combinations for the rest
    for (int i = start; i <= end && end - i + 1 >= r - index; ++i) {
        data[index] = nums[i];
        generateCombinations(nums, i + 1, end, r, data, index + 1);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int r = 4; // Size of combinations
    vector<int> data(r, 0);
    generateCombinations(nums, 0, nums.size() - 1, r, data, 0);

    return 0;
}
