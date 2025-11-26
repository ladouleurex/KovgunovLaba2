#include "sorts.h"
#include <algorithm>

bool compareKeys(const Key& a, const Key& b) {

    if (a.date.year != b.date.year) return a.date.year > b.date.year;
    if (a.date.month != b.date.month) return a.date.month > b.date.month;
    if (a.date.day != b.date.day) return a.date.day > b.date.day;

    if (a.fio.f != b.fio.f) return a.fio.f < b.fio.f;
    if (a.fio.i != b.fio.i) return a.fio.i < b.fio.i;
    if (a.fio.o != b.fio.o) return a.fio.o < b.fio.o;

    return false;
}

bool compareKeysHeap(const Key& a, const Key& b) {

    if (a.date.year != b.date.year) return a.date.year < b.date.year;
    if (a.date.month != b.date.month) return a.date.month < b.date.month;
    if (a.date.day != b.date.day) return a.date.day < b.date.day;

    if (a.fio.f != b.fio.f) return a.fio.f > b.fio.f;
    if (a.fio.i != b.fio.i) return a.fio.i > b.fio.i;
    if (a.fio.o != b.fio.o) return a.fio.o > b.fio.o;

    return false;
}


void heapify(std::vector<Key>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compareKeysHeap(arr[left], arr[largest]))
        largest = left;
    if (right < n&& compareKeysHeap(arr[right], arr[largest]))
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<Key>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionSort(std::vector<Key>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Key temp = arr[i];
        int j = i - 1;
        while (j >= 0 && compareKeys(temp, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
