//1069 微博转发抽奖

#ifndef PAT_1069_HPP
#define PAT_1069_HPP

#include <iostream>
#include <map>

using namespace std;
int main() {
    map<string, bool> map;
    int m, n, s;
    string tp;
    scanf("%d%d%d", &m, &n, &s);
    if (s>=m) {
        cout << "Keep going...\n";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> tp;
        if (map[tp]) ++s;
        if (i == s && !map[tp]) {
            map[tp] = true;
            cout << tp << endl;
            s +=n;
        }
    }
    return 0;
}

#endif //PAT_1069_HPP
