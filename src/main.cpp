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

// 添加边界测试函数
void testBoundaryCases() {
    std::cout << "\n=== 边界测试 ===" << std::endl;

    // 空数组测试
    std::vector<int> empty;
    std::cout << "空数组测试: ";
    quicksort(empty, 0, -1);
    printArray(empty);

    // 单元素数组测试
    std::vector<int> single = {42};
    std::cout << "单元素测试: ";
    quicksort(single, 0, 0);
    printArray(single);

    // 已排序数组测试
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::cout << "已排序数组: ";
    quicksort(sorted, 0, sorted.size() - 1);
    printArray(sorted);

    // 逆序数组测试
    std::vector<int> reversed = {5, 4, 3, 2, 1};
    std::cout << "逆序数组: ";
    quicksort(reversed, 0, reversed.size() - 1);
    printArray(reversed);
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

    testBoundaryCases();

    return 0;
}
