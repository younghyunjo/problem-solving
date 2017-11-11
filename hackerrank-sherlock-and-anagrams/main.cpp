//https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define NR_ALPHABET 26

bool isAnagram(string s1, string s2) {
    int alphabetHash[NR_ALPHABET] = {0,};
    int alphabetHashZeroed[NR_ALPHABET] = {0,};

    for (int i=0; s1.length(); i++) {
        alphabetHash[s1[i]-'a']++;
        alphabetHash[s2[i]-'a']++;
    }

    if (memcmp(alphabetHash, alphabetHashZeroed, sizeof(alphabetHash)) == 0)
        return true;
    return false;
}

int solve(const string& s) {
    int nrAnagram = 0;
    for (int l=1; l<s.length(); l++) {
        map<string, int> substringMap;
        for (int i=0; i+l<=s.length(); i++) {
            string subString = s.substr(i, l);
            sort(subString.begin(), subString.end());
            if (substringMap.find(subString) != substringMap.end()) {
                substringMap[subString]++;
            }
            else {
                substringMap.insert(make_pair(subString, 1));
            }
        }

        for (auto& i : substringMap) {
            nrAnagram += i.second * (i.second-1) / 2;
        }
    }
    return nrAnagram;
}

int main() {
//
//    string s = "cccc";
//    printf("%d\n", solve(s));
//    return 0;

    int t;
    for (cin >> t; t; t--) {
        string s;
        cin >> s;
        printf("%d\n", solve(s));
    }

    return 0;
}
