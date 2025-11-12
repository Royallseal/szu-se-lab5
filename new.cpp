#include <iostream>
#include <string>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) 
		return false;
    if (num == 2) 
		return true;
    if (num % 2 == 0) 
		return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) 
			return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    while(N--) {
        string word;
        cin >> word;

        int count[26] = {0};

        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                count[c - 'A']++;
            }
        }

        int maxn = 0, minn = 1000000;

        for (int j = 0; j < 26; j++) {
            if (count[j] > maxn) {
                maxn = count[j];
            }
            if (count[j] < minn && count[j]!= 0) {
                minn = count[j];
            }
        }

        if (isPrime(maxn - minn)) {
            cout << "Lucky Word" << endl;
            cout << maxn - minn << endl;
        } else {
            cout << "No Answer" << endl;
            cout << 0 << endl;
        }
    }

    return 0;
}
