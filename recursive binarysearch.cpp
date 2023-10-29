#include <iostream>

// Recursive binary search
int recursiveBinarySearch(int arr[], int key, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Key found at this index
        }
        if (arr[mid] > key) {
            return recursiveBinarySearch(arr, key, left, mid - 1); // Search in the left subarray
        }
        return recursiveBinarySearch(arr, key, mid + 1, right); // Search in the right subarray
    }
    return -1; // Key not found in the array
}

// Non-recursive (iterative) binary search
int iterativeBinarySearch(int arr[], int key, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Key found at this index
        }
        if (arr[mid] > key) {
            right = mid - 1; // Search in the left subarray
        } else {
            left = mid + 1; // Search in the right subarray
        }
    }
    return -1; // Key not found in the array
}

int main() {
    int arr[] = {9, 21, 34, 45, 54, 81, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 54;

    // Recursive binary search
    int recursiveResult = recursiveBinarySearch(arr, key, 0, size - 1);
    if (recursiveResult != -1) {
        std::cout << "Key " << key << " found at index (recursive): " << recursiveResult << std::endl;
    } else {
        std::cout << "Key " << key << " not found (recursive)." << std::endl;
    }

    // Non-recursive (iterative) binary search
    int iterativeResult = iterativeBinarySearch(arr, key, size);
    if (iterativeResult != -1) {
        std::cout << "Key " << key << " found at index (iterative): " << iterativeResult << std::endl;
    } else {
        std::cout << "Key " << key << " not found (iterative)." << std::endl;
    }

    return 0;
}
