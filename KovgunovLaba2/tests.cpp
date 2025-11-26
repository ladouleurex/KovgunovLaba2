#include "tests.h"
#include <fstream>
#include <sstream>
#include <iostream>

long long time(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}


void readInput(const std::string& filename, std::vector<Key>& data) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не удалось открыть входной файл\n";
        return;
    }

    data.clear();
    std::string line;
    int index = 0;

    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        Key key;
        char sep;

        iss >> key.date.day >> sep >> key.date.month >> sep >> key.date.year
            >> key.fio.f >> key.fio.i >> key.fio.o;

        key.index = index;
        data.push_back(key);
        index++;
    }
}


void writeOutput(const std::string& filename, const std::vector<Key>& data, long long elapsed) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cout << "Не удалось открыть выходной файл: " << filename << std::endl;
        return;
    }
    for (const auto& key : data) {
        fout << key.date.day << '.' << key.date.month << '.' << key.date.year << '\t'
            << key.fio.f << ' ' << key.fio.i << ' ' << key.fio.o << ' ' << key.index << '\n';
    }
    fout << "time mc: " << elapsed << '\n';

}

