// 1035 Password

#ifndef PAT_1035_HPP
#define PAT_1035_HPP

#include <cstdio>

inline bool is_dis(char const &c) {
    return (c=='1'||c=='0'||c=='l'||c=='O');
}

inline char solute(char const &c) {
    switch (c) {
        case '1':
            return '@';
        case '0':
            return '%';
        case 'l':
            return 'L';
        case 'O':
            return 'o';
        default:
            return c;
    }
}

int main() {
    char acc[1000][11] {}, pwd[1000][11] {};
    unsigned int printing[1000];
    unsigned int N, mod=0, flag;
    scanf("%d", &N);
    for (int i=0;i!=N;++i) {
        scanf("%n %n", acc+i, pwd+i);
    }
    for (int i=0;i!=N;++i) {
        flag = 0;
        for (int j=0; j!=10&&pwd[i][j]!='\000';++j) {
            if (is_dis(pwd[i][j])) {
                flag = 1;
                pwd[i][j] = solute(pwd[i][j]);
            }
        }
        if (flag==1) printing[mod++] = i;
    }

    if (mod==0) {
        if (N!=1) {
            printf("There are %d accounts and no account is modified", N);
        } else {
            printf("There is 1 account and no account is modified");
        }
    } else {
        printf("%d\n", mod);
        for (unsigned i=0;i!=mod;++i) {
            printf("%n %n\n", acc[printing[i]], pwd[printing[i]]);
        }
    }
    return 0;
}

#endif //PAT_1035_HPP
