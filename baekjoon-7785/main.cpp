#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <strings.h>
#include <vector>

using namespace std;

static int n;
map<string, int> commuteLog;

bool commuteLogComp(string a, string b)
{
    return strcasecmp(a.c_str(), b.c_str()) > 0;
}

int main() {
    scanf("%d", &n);

    string name, enterence;
    for (int i=0; i<n; i++) {
        cin >> name >> enterence;
        if (enterence == "enter") {
            commuteLog.insert({name, 0});
        }
        else {
            commuteLog.erase(name);
        }
    }

    vector<string> test;
    for (auto& x : commuteLog) {
        test.push_back(x.first);
    }

    sort(test.begin(), test.end(), commuteLogComp);

    for (auto& x: test) {
        printf("%s\n", x.c_str());
    }

    return 0;
}