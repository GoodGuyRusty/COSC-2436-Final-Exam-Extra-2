#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// HackerRank (Medium) | Minimum Swaps 2 | https://www.hackerrank.com/challenges/minimum-swaps-2/problem

struct Element {
    int value;
    int original_index;
};

int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int swaps = 0;

    vector<Element> arrPos(n);
    for (int i = 0; i < n; i++) {
        arrPos[i] = {arr[i], i};
    }

    sort(arrPos.begin(), arrPos.end(), [](const Element& a, const Element& b) {
        return a.value < b.value;
    });

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i] || arrPos[i].original_index == i) {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;

            j = arrPos[j].original_index;

            cycle_size++;
        }
        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int main() {

    int n;
    if (!(cin >> n)) return 1;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) return 1;
    }

    int result = minimumSwaps(arr);
    cout << result << endl;

    return 0;
}
