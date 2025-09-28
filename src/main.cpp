// 修改main.cpp
#include "quicksort.h"
#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> parseInput(const std::string& input) {
    std::vector<int> result;
    std::stringstream ss(input);
    int number;

    while (ss >> number) {
        result.push_back(number);
        if (ss.peek() == ',' || ss.peek() == ' ') {
            ss.ignore();
        }
    }
    return result;
}

int main() {
    std::cout << "快速排序测试程序" << std::endl;

    std::string input;
    std::cout << "请输入要排序的数字(用空格或逗号分隔): ";
    std::getline(std::cin, input);

    std::vector<int> arr = parseInput(input);

    if (arr.empty()) {
        std::cout << "输入无效，使用默认测试数据..." << std::endl;
        arr = {64, 34, 25, 12, 22, 11, 90, 5};
    }

    std::cout << "排序前: ";
    printArray(arr);

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "排序后: ";
    printArray(arr);

    return 0;
}
