#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct wordTable {
    wordTable(long long orgIndex, long long length, string word) : orgIndex(orgIndex), word(word) {};

    long long orgIndex;
    string word;

    friend bool operator<(wordTable &w1, wordTable &w2) {
        if (w1.word.length() < w2.word.length()) {
            return true;
        }
        else if (w1.word.length() == w2.word.length()) {
            if (w1.orgIndex < w2.orgIndex)
                return true;
        }

        return false;
    }
};

vector<wordTable> split(string sentence) {
    long long index = 0;
    istringstream iss(sentence);
    vector <wordTable> words;

    do {
        string token;
        iss >> token;
        words.push_back(wordTable(index++, token.length(), token));
    } while (iss);

    words.pop_back();

    string& firstWord = words[0].word;
    firstWord[0] = tolower(firstWord[0]);

    wordTable& lastWord = words.back();
    while (lastWord.word.back() == '.') {
        lastWord.word.pop_back();
    }

    return words;
}

string arrange(string sentence) {
    vector<wordTable> words = split(sentence);
    sort(words.begin(), words.end());

    string &firstWord = words[0].word;
    firstWord[0] = toupper(firstWord[0]);

    stringstream ret;
    for (int i=0; i<words.size(); i++) {
        ret << words[i].word;
        if (i != words.size() -1) {
            ret << " ";
        }
    }
    ret << ".";

    return ret.str();
}

int main() {
//    string s(pow(10, 4), 'a');
//    cout << arrange(s) << endl;
    cout << arrange("The lines aaa are printed in reverse order.") << endl;
    return 0;
}