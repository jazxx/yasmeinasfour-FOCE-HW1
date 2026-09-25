#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

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

int main() {
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

    return 0;
}
