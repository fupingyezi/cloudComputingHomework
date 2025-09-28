#include "quicksort.h"
#include <iostream>
#include <vector>
#include <random>

std::vector<int> generateRandomArray(int size, int min, int max) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    std::cout << "快速排序算法测试" << std::endl;

    // 生成测试数据
    std::vector<int> arr = generateRandomArray(15, 1, 100);

    std::cout << "排序前: ";
    printArray(arr);

    // 执行快速排序
    quicksort(arr, 0, arr.size() - 1);

    std::cout << "排序后: ";
    printArray(arr);

    // 验证排序结果
    bool sorted = true;
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        std::cout << "✓ 排序验证成功!" << std::endl;
    } else {
        std::cout << "✗ 排序验证失败!" << std::endl;
    }

    return 0;
}
