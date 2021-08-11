//1148 Werewolf - Simple Version

#ifndef PAT_1148_HPP
#define PAT_1148_HPP

#include <iostream>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> v(n+1);
    for (int i=1; i<=n;++i) std::cin>>v[i];
    for (int i=1; i<=n;++i) {
        for (int j=i+1; j<=n;++j) {
            std::vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}

#endif //PAT_1148_HPP
