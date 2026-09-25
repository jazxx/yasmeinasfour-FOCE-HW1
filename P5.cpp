#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttendMeetings(vector<vector<int>> meetings) {
    sort(meetings.begin(), meetings.end());

    for (int i = 1; i < (int)meetings.size(); i++) {
        int currentStart = meetings[i][0];
        int previousEnd = meetings[i - 1][1];

        if (currentStart < previousEnd) {
            return false;
        }
    }

    return true;
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
    tests.push_back({{12, 13}, {2, 3}, {12, 21}});
    tests.push_back({{1, 3}, {4, 6}, {7, 9}});
    tests.push_back({{1, 3}, {3, 5}});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printIntervals(tests[i]);
        cout << endl;

        bool result = canAttendMeetings(tests[i]);

        cout << "Output: ";
        if (result) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl << endl;
    }

    return 0;
}
