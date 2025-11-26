#pragma once

#include <vector>
#include "structs.h"

bool compareKeys(const Key& a, const Key& b);
bool compareKeysHeap(const Key& a, const Key& b);

void heapSort(std::vector<Key>& arr);
void insertionSort(std::vector<Key>& arr);
