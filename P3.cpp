#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

int main() {
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

    return 0;
}
