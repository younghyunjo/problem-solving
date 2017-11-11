//https://www.hackerrank.com/challenges/richie-rich/problem

#include <iostream>

using namespace std;

static int countMissMatch(const string& number) {
    int nrMissMatch = 0;
    int l=0, r = number.length()-1;
    while (l < r) {
        if (number[l++] != number[r--])
            nrMissMatch++;
    }

    return nrMissMatch;
}

static int symmetryIndex(const string& number, const int index) {
    return number.length() - index - 1;
}

static void mirroring(string& number, int& k, int index) {
    int l = index, r = symmetryIndex(number, index);
    while (k > 0 && l < r) {
        if (number[l] > number[r]) {
            number[r] = number[l];
            k--;
        }
        else if (number[r] > number[l]) {
            number[l] = number[r];
            k--;
        }

        l++, r--;
    }
}

void padWithNine(string& number, int& k, int index) {
    int left = index;
    int right = symmetryIndex(number, index);

    if (number[left] == '9' && number[right] == '9')
        return;

    if (k >=2 && number[left] != '9' && number[right] != '9') {
        number[left] = '9';
        number[right] = '9';
        k -= 2;
    }
    else if (number[left] == '9' || number[right] == '9') {
        if (number[left] != '9') {
            number[left] = '9';
            k--;
        }
        else if (number[right] != '9') {
            number[right] = '9';
            k--;
        }
    }
}

int palindrome(string& number, int k) {
    int nrMissMatch = countMissMatch(number);
    int index = 0;

    while (k != 0 && index < number.length() / 2) {
        if (nrMissMatch > k) {
            return -1;
        }
        else if (nrMissMatch == k) {
             mirroring(number, k, index);
        }
        else if (nrMissMatch == 1 && k == 2) {
            while (index < number.length() / 2) {
                if (number[index] == number[symmetryIndex(number, index)])
                    index++;
                else break;
            }
            nrMissMatch--;
            padWithNine(number, k, index++);
        }
        else { //nrMissMatch < k
            if (number[index] != number[symmetryIndex(number, index)]) {
                nrMissMatch--;
            }
            padWithNine(number, k, index++);
        }
    }

    return k;
}

void solve (string number, int k) {
    int ret = 0;

    if (number.length() % 2) {
        int middleIndex = number.size() / 2;
        char middle = number[middle];
        number.erase(number.begin() + middleIndex);

        ret = palindrome(number, k);
        if (ret >= 0) {
            if (ret > 0)
                middle = '9';
            number.insert(number.begin() + number.size()/2, middle);
        }
    }
    else {
        ret = palindrome(number, k);
    }

    if (ret < 0)
        cout << -1 << endl;
    else
        cout << number << endl;
}

int main() {
    int n, k;
    string number;

    cin >> n >> k;
    cin >> number;

    /*
    k = 3;
    number = "10101";
    solve(number, k);

    k = 10;
    number = "992289";
    */
    solve(number, k);

    return 0;
}
