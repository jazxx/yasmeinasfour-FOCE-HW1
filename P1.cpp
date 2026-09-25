#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> result;

    if (intervals.empty()) {
        return result;
    }

    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); i++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];
        int lastEnd = result.back()[1];

        if (currentStart <= lastEnd) {
            result.back()[1] = max(lastEnd, currentEnd);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

void printIntervals(vector<vector<int>> intervals) {
    cout << "[";

    for (int i = 0; i < (int)intervals.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
    }

    cout << "]";
}

int main() {
    vector<vector<vector<int>>> tests;
    tests.push_back({{1, 4}, {3, 8}, {9, 10}, {14, 16}});
    tests.push_back({{1, 5}, {2, 6}, {4, 8}});
    tests.push_back({});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printIntervals(tests[i]);
        cout << endl;

        cout << "Output: ";
        printIntervals(mergeIntervals(tests[i]));
        cout << endl << endl;
    }

    return 0;
}
