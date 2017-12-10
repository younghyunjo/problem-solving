//https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
#include <iostream>
#include <vector>

using namespace std;


vector<int> findAnagrams(string s, string p) {
    vector<int> ss(26, 0);
    vector<int> pp(26, 0);

    for (int i=0; i<p.size(); i++) {
        ss[s[i]-'a']++;
        pp[p[i]-'a']++;
    }

    vector<int> result;

    if (ss == pp)
        result.push_back(0);

    for (int i=p.size(); i<s.size(); i++) {
        ss[s[i]-'a']++;
        ss[s[i-p.size()]-'a']--;
        if (ss == pp)
            result.push_back(i-p.size()+1);
    }

    return result;
}

int main() {
    vector<int> r = findAnagrams("abcababababcab", "abc");
    for (auto a: r)
        cout << a << endl;
    return 0;
}