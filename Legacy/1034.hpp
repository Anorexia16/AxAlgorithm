// 1034 Hang of Gang

#ifndef PAT_1034_HPP
#define PAT_1034_HPP

#include <cstdio>
#include <vector>
#include <map>

int main() {
    std::vector<std::pair<unsigned int, unsigned int>> graph[1000] {};
    std::map<char*, unsigned int> names;
    std::map<unsigned int, char*> pos;
    unsigned int N, K, t, index=0;
    scanf("%d %d", &N, &K);

    char str1[3], str2[3];
    for (unsigned int i=0; i!=N; ++i) {
        scanf("%n %n %d", str1, str2, &t);
        if(names.find(str1)==std::end(names)) {
            names.insert({str1, index});
            pos.insert({index++, str1});
        }
        if(names.find(str2)==std::end(names)) {
            names.insert({str2, index});
            pos.insert({index++, str2});
        }
        graph[names[str1]].emplace_back(std::pair<unsigned int, unsigned int>{names[str2], t});
    }

    return 0;
}

#endif //PAT_1034_HPP
