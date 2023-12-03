#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to perform QuickSort
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to partition the array for QuickSort
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform MergeSort
template <typename T>
void mergeSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to merge two halves for MergeSort
template <typename T>
void merge(std::vector<T>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<T> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform SelectionSort
template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // Generate a random vector for sorting
    std::vector<int> arr;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10000; ++i) {
        arr.push_back(rand() % 1000);
    }

    // Measure time for QuickSort
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "QuickSort time: " << duration.count() << " milliseconds\n";

    // Measure time for MergeSort
    std::random_shuffle(arr.begin(), arr.end()); // Shuffle the array before sorting
    start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "MergeSort time: " << duration.count() << " milliseconds\n";

    // Measure time for SelectionSort
    std::random_shuffle(arr.begin(), arr.end()); // Shuffle the array before sorting
    start = std::chrono::high_resolution_clock::now();
    selectionSort(arr);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "SelectionSort time: " << duration.count() << " milliseconds\n";

    return 0;
}
