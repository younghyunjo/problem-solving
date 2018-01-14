//https://www.acmicpc.net/problem/1620
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

static vector<string> monsterBook;
static vector<pair<string, int>> monsterDictionary[26];
static vector<string> monsters;

int bs(vector<pair<string, int>>::iterator first, vector<pair<string, int>>::iterator last, string val) {
    vector<pair<string, int>>::iterator middle = first + (last - first) / 2;
    if ((*middle).first == val) {
        return (*middle).second;
    }
    else if ((*middle).first  < val) {
        return bs(middle+1, last, val);
    }
    else {
        return bs(first, middle-1, val);
    }
};

void solve() {
    for (int i=0; i<26; i++)
        sort(monsterDictionary[i].begin(), monsterDictionary[i].end());

    int i = 0;
    for (auto m : monsters) {
        try {
            int index = stoi(m);
            printf("%s\n", monsterBook[index-1].c_str());
        }
        catch (const invalid_argument& ia) {
            int dicIndex = m[0] - 'A';
            int found = bs(monsterDictionary[dicIndex].begin(), monsterDictionary[dicIndex].end(), m);
            printf("%d\n", found + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    char name[21];
    string sname = string(name);
    for (int i=0; i<n; i++) {
        memset(name, 0, sizeof(name));
        scanf("%s", name);
        sname = string(name);
        monsterBook.push_back(sname);

        int dicIndex = name[0] -'A';
        monsterDictionary[dicIndex].push_back(make_pair(sname, i));
    };

    for (int i=0; i<m; i++) {
        memset(name, 0, sizeof(name));
        scanf("%s", name);
        sname = string(name);
        monsters.push_back(sname);
    }

    solve();

    return 0;
}