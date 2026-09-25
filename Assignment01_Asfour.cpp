// Assignment 1: Sorting and Algorithms
// Fundamentals of Computer Engineering (EECE 7205)
// Yasmein Asfour
//
// Single program containing all ten solutions with a menu.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

// ----------------------------------------------------------
// Shared printing helpers
// ----------------------------------------------------------

void printVector(vector<int> a) {
    cout << "[";

    for (int i = 0; i < (int)a.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << a[i];
    }

    cout << "]";
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

void printPoints(vector<vector<int>> points) {
    cout << "[";

    for (int i = 0; i < (int)points.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << "[" << points[i][0] << "," << points[i][1] << "]";
    }

    cout << "]";
}

void printArrays(vector<vector<int>> arrays) {
    cout << "[";

    for (int i = 0; i < (int)arrays.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        printVector(arrays[i]);
    }

    cout << "]";
}

void printWords(vector<string> words) {
    cout << "[";

    for (int i = 0; i < (int)words.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << words[i] << "\"";
    }

    cout << "]";
}

void printGroups(vector<vector<string>> groups) {
    cout << "[";

    for (int i = 0; i < (int)groups.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        printWords(groups[i]);
    }

    cout << "]";
}

// ----------------------------------------------------------
// Problem 1: Merge Overlapping Intervals
// ----------------------------------------------------------

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

void runProblem1() {
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
}

// ----------------------------------------------------------
// Problem 2A: Sort Colors by Counting
// ----------------------------------------------------------

void countingSort(vector<int>& a) {
    int count[3] = {0, 0, 0};

    for (int i = 0; i < (int)a.size(); i++) {
        count[a[i]] = count[a[i]] + 1;
    }

    int index = 0;

    for (int color = 0; color < 3; color++) {
        for (int j = 0; j < count[color]; j++) {
            a[index] = color;
            index++;
        }
    }
}

void runProblem2A() {
    vector<vector<int>> tests;
    tests.push_back({2, 0, 2, 1, 1, 0});
    tests.push_back({0, 0, 1, 2, 2});
    tests.push_back({});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        vector<int> a = tests[i];
        countingSort(a);

        cout << "Output: ";
        printVector(a);
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 2B: Sort Colors by Dutch National Flag
// ----------------------------------------------------------

void dutchFlag(vector<int>& a) {
    int low = 0;
    int mid = 0;
    int high = (int)a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
}

void runProblem2B() {
    vector<vector<int>> tests;
    tests.push_back({2, 0, 2, 1, 1, 0});
    tests.push_back({0, 0, 1, 2, 2});
    tests.push_back({});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        vector<int> a = tests[i];
        dutchFlag(a);

        cout << "Output: ";
        printVector(a);
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 3: Largest Number
// ----------------------------------------------------------

bool compareStrings(string x, string y) {
    return x + y > y + x;
}

string largestNumber(const vector<int>& a) {
    if (a.empty()) {
        return "";
    }

    vector<string> strings;

    for (int i = 0; i < (int)a.size(); i++) {
        strings.push_back(to_string(a[i]));
    }

    sort(strings.begin(), strings.end(), compareStrings);

    if (strings[0] == "0") {
        return "0";
    }

    string result = "";

    for (int i = 0; i < (int)strings.size(); i++) {
        result = result + strings[i];
    }

    return result;
}

void runProblem3() {
    vector<vector<int>> tests;
    tests.push_back({3, 30, 34, 5, 9});
    tests.push_back({10, 2});
    tests.push_back({0, 0, 0});
    tests.push_back({});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        string result = largestNumber(tests[i]);

        cout << "Output: \"" << result << "\"" << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 4: Group Anagrams
// ----------------------------------------------------------

vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, int> groupIndex;
    vector<vector<string>> result;

    for (int i = 0; i < (int)words.size(); i++) {
        string word = words[i];
        string key = word;
        sort(key.begin(), key.end());

        if (groupIndex.count(key) == 0) {
            groupIndex[key] = (int)result.size();
            vector<string> newGroup;
            result.push_back(newGroup);
        }

        int index = groupIndex[key];
        result[index].push_back(word);
    }

    return result;
}

void runProblem4() {
    vector<vector<string>> tests;
    tests.push_back({"eat", "tea", "tan", "ate", "nat", "bat"});
    tests.push_back({"hello"});
    tests.push_back({"", ""});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printWords(tests[i]);
        cout << endl;

        cout << "Output: ";
        printGroups(groupAnagrams(tests[i]));
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 5: Meeting Rooms
// ----------------------------------------------------------

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

void runProblem5() {
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
}

// ----------------------------------------------------------
// Problem 6: K Closest Points to Origin (shared distance)
// ----------------------------------------------------------

long long squaredDistance(const vector<int>& p) {
    long long x = p[0];
    long long y = p[1];

    return x * x + y * y;
}

// ----------------------------------------------------------
// Problem 6A: K Closest Points by Sorting
// ----------------------------------------------------------

bool compareByDistance(const vector<int>& a, const vector<int>& b) {
    return squaredDistance(a) < squaredDistance(b);
}

vector<vector<int>> kClosestSort(vector<vector<int>> points, int k) {
    sort(points.begin(), points.end(), compareByDistance);

    vector<vector<int>> result;

    for (int i = 0; i < k; i++) {
        result.push_back(points[i]);
    }

    return result;
}

void runProblem6A() {
    vector<vector<vector<int>>> testPoints;
    vector<int> testK;

    testPoints.push_back({{1, 3}, {-2, 2}, {2, 4}});
    testK.push_back(2);

    testPoints.push_back({{3, 4}});
    testK.push_back(1);

    testPoints.push_back({{1, 2}, {3, 4}});
    testK.push_back(0);

    for (int i = 0; i < (int)testPoints.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  points = ";
        printPoints(testPoints[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: ";
        printPoints(kClosestSort(testPoints[i], testK[i]));
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 6B: K Closest Points by Max Heap
// ----------------------------------------------------------

vector<vector<int>> kClosestHeap(const vector<vector<int>>& points, int k) {
    priority_queue<pair<long long, int>> heap;

    for (int i = 0; i < (int)points.size(); i++) {
        long long distance = squaredDistance(points[i]);
        heap.push(make_pair(distance, i));

        if ((int)heap.size() > k) {
            heap.pop();
        }
    }

    vector<vector<int>> result;

    while (!heap.empty()) {
        pair<long long, int> top = heap.top();
        int index = top.second;

        result.push_back(points[index]);
        heap.pop();
    }

    return result;
}

void runProblem6B() {
    vector<vector<vector<int>>> testPoints;
    vector<int> testK;

    testPoints.push_back({{1, 3}, {-2, 2}, {2, 4}});
    testK.push_back(2);

    testPoints.push_back({{3, 4}});
    testK.push_back(1);

    testPoints.push_back({{1, 2}, {3, 4}});
    testK.push_back(0);

    for (int i = 0; i < (int)testPoints.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  points = ";
        printPoints(testPoints[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: ";
        printPoints(kClosestHeap(testPoints[i], testK[i]));
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 7: Top K Frequent Elements
// ----------------------------------------------------------

bool compareFrequency(pair<int, int> x, pair<int, int> y) {
    if (x.second != y.second) {
        return x.second > y.second;
    }

    return x.first < y.first;
}

vector<int> topKFrequent(const vector<int>& a, int k) {
    if (a.empty() || k == 0)
        return {};

    unordered_map<int, int> freq;

    for (int i = 0; i < (int)a.size(); i++) {
        freq[a[i]] = freq[a[i]] + 1;
    }

    vector<pair<int, int>> pairs;

    for (pair<const int, int> item : freq) {
        pairs.push_back(make_pair(item.first, item.second));
    }

    sort(pairs.begin(), pairs.end(), compareFrequency);

    vector<int> result;

    for (int i = 0; i < k; i++) {
        result.push_back(pairs[i].first);
    }

    return result;
}

void runProblem7() {
    vector<vector<int>> testNums;
    vector<int> testK;

    testNums.push_back({1, 1, 2, 2, 3});
    testK.push_back(2);

    testNums.push_back({5, 5, 5});
    testK.push_back(1);

    testNums.push_back({4, 4, 2, 2, 1});
    testK.push_back(2);

    testNums.push_back({});
    testK.push_back(0);

    for (int i = 0; i < (int)testNums.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  nums = ";
        printVector(testNums[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: ";
        printVector(topKFrequent(testNums[i], testK[i]));
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 8: Merge K Sorted Arrays
// ----------------------------------------------------------

bool compareByFirstElement(const vector<int>& a, const vector<int>& b) {
    if (a.empty() && b.empty()) {
        return false;
    }

    if (a.empty()) {
        return true;
    }

    if (b.empty()) {
        return false;
    }

    return a[0] < b[0];
}

vector<int> mergeKArrays(vector<vector<int>> arrays) {
    vector<int> result;

    if (arrays.empty()) {
        return result;
    }

    sort(arrays.begin(), arrays.end(), compareByFirstElement);

    for (int i = 0; i < (int)arrays.size(); i++) {
        for (int j = 0; j < (int)arrays[i].size(); j++) {
            result.push_back(arrays[i][j]);
        }
    }

    sort(result.begin(), result.end());

    return result;
}

void runProblem8() {
    vector<vector<vector<int>>> tests;

    vector<vector<int>> test1;
    test1.push_back({1, 4, 5});
    test1.push_back({1, 3, 4});
    test1.push_back({2, 6});
    tests.push_back(test1);

    vector<vector<int>> test2;
    test2.push_back({});
    test2.push_back({1, 3});
    test2.push_back({});
    tests.push_back(test2);

    vector<vector<int>> test3;
    test3.push_back({});
    test3.push_back({});
    tests.push_back(test3);

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printArrays(tests[i]);
        cout << endl;

        cout << "Output: ";
        printVector(mergeKArrays(tests[i]));
        cout << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 9: Kth Largest Element
// ----------------------------------------------------------

int kthLargest(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < (int)a.size(); i++) {
        heap.push(a[i]);

        if ((int)heap.size() > k) {
            heap.pop();
        }
    }

    return heap.top();
}

void runProblem9() {
    vector<vector<int>> testNums;
    vector<int> testK;

    testNums.push_back({1, 3, 9, 8, 7, 10, 13, 12});
    testK.push_back(2);

    testNums.push_back({5, 5, 4, 3});
    testK.push_back(2);

    testNums.push_back({7});
    testK.push_back(1);

    for (int i = 0; i < (int)testNums.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  nums = ";
        printVector(testNums[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: " << kthLargest(testNums[i], testK[i]) << endl << endl;
    }
}

// ----------------------------------------------------------
// Problem 10: Count Inversions
// ----------------------------------------------------------

long long mergeAndCount(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
            count = count + (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(a[j]);
        j++;
    }

    for (int t = 0; t < (int)temp.size(); t++) {
        a[low + t] = temp[t];
    }

    return count;
}

long long mergeCount(vector<int>& a, int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    long long count = 0;
    count = count + mergeCount(a, low, mid);
    count = count + mergeCount(a, mid + 1, high);
    count = count + mergeAndCount(a, low, mid, high);

    return count;
}

long long countInversions(vector<int> a) {
    if (a.empty()) {
        return 0;
    }

    return mergeCount(a, 0, (int)a.size() - 1);
}

void runProblem10() {
    vector<vector<int>> tests;
    tests.push_back({2, 4, 1, 3, 5});
    tests.push_back({1, 2, 3, 4, 5});
    tests.push_back({5, 4, 3, 2, 1});
    tests.push_back({2, 2, 1});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        cout << "Output: " << countInversions(tests[i]) << endl << endl;
    }
}

// ----------------------------------------------------------
// Menu
// ----------------------------------------------------------

void printMenu() {
    cout << "==========================================" << endl;
    cout << " Assignment 1: Sorting and Algorithms" << endl;
    cout << " Yasmein Asfour" << endl;
    cout << "==========================================" << endl;
    cout << " 1  - Problem 1:  Merge Overlapping Intervals" << endl;
    cout << " 2  - Problem 2A: Sort Colors (Counting)" << endl;
    cout << " 3  - Problem 2B: Sort Colors (Dutch National Flag)" << endl;
    cout << " 4  - Problem 3:  Largest Number" << endl;
    cout << " 5  - Problem 4:  Group Anagrams" << endl;
    cout << " 6  - Problem 5:  Meeting Rooms" << endl;
    cout << " 7  - Problem 6A: K Closest Points (Sorting)" << endl;
    cout << " 8  - Problem 6B: K Closest Points (Max Heap)" << endl;
    cout << " 9  - Problem 7:  Top K Frequent Elements" << endl;
    cout << " 10 - Problem 8:  Merge K Sorted Arrays" << endl;
    cout << " 11 - Problem 9:  Kth Largest Element" << endl;
    cout << " 12 - Problem 10: Count Inversions" << endl;
    cout << " 0  - Exit" << endl;
    cout << "==========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice = 0;

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cout << endl << "No more input. Exiting." << endl;
            break;
        }

        cout << endl;

        if (choice == 0) {
            cout << "Exiting." << endl;
            break;
        } else if (choice == 1) {
            runProblem1();
        } else if (choice == 2) {
            runProblem2A();
        } else if (choice == 3) {
            runProblem2B();
        } else if (choice == 4) {
            runProblem3();
        } else if (choice == 5) {
            runProblem4();
        } else if (choice == 6) {
            runProblem5();
        } else if (choice == 7) {
            runProblem6A();
        } else if (choice == 8) {
            runProblem6B();
        } else if (choice == 9) {
            runProblem7();
        } else if (choice == 10) {
            runProblem8();
        } else if (choice == 11) {
            runProblem9();
        } else if (choice == 12) {
            runProblem10();
        } else {
            cout << "Invalid choice. Please enter a number from 0 to 12." << endl << endl;
        }
    }

    return 0;
}
