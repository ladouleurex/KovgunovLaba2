#pragma once
#include <vector>
#include <string>
#include "structs.h"

#include <functional>
#include <chrono>

long long time(std::function<void()> func);

void readInput(const std::string& filename, std::vector<Key>& data);
void writeOutput(const std::string& filename, const std::vector<Key>& data, long long elapsed);