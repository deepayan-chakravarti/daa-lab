#include <iostream>
#include <vector>
#include <ctime>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    std::cout << "Deepayan Chakravarti\n";
    std::cout << "04714802724\n";
    int sizes[] = {50, 500, 5000};
    int iterations = 1000000;

    for (int n : sizes) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        int target = n;

        clock_t start = clock();
        for (int i = 0; i < iterations; i++) {
            linearSearch(arr, target);
        }
        clock_t end = clock();
        double linearTime = double(end - start) / CLOCKS_PER_SEC;

        start = clock();
        for (int i = 0; i < iterations; i++) {
            binarySearch(arr, target);
        }
        end = clock();
        double binaryTime = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "N = " << n << "\n";
        std::cout << "Linear Search Time: " << linearTime << " s\n";
        std::cout << "Binary Search Time: " << binaryTime << " s\n\n";
    }

    return 0;
}