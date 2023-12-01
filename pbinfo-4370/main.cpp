#include <iostream>
#include <array>
#include <algorithm>

constexpr uint32_t maxN = 1e5;

bool check_solution(const std::array<int32_t, maxN>& arr, uint32_t n, uint32_t k, uint32_t to_check)
{
    uint32_t sz = 1;
    int32_t last_element = arr[0];

    for (uint32_t i = 1; i < n; ++i) {
        if (arr[i] - last_element >= to_check) {
            last_element = arr[i];
            ++sz;
            if (sz == k) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    std::array<int32_t, maxN>arr;
    uint32_t n;
    uint32_t k;
    std::cin >> n >> k;
        
    for (uint32_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    std::sort(std::begin(arr), std::begin(arr) + n);

    uint32_t left = 0;
    uint32_t right = arr[n - 1] - arr[0];

    while (left < right - 1) {
        uint32_t mid = (left + right) / 2;

        if (check_solution(arr, n, k, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    if (check_solution(arr, n, k, right)) {
        std::cout << right << "\n";
        return 0;
    }

    std::cout << left << "\n";
    return 0;
} 