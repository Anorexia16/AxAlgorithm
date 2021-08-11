// 1036 Boys vs Girls

#ifndef PAT_1036_HPP
#define PAT_1036_HPP
#include <cstdio>

int main() {
    unsigned N;
    char gender, name[100] {}, id[200] {}, fn[100] {}, mn[100] {}, fid[200] {}, mid[200] {};
    unsigned int fg=0, mg=0, g, j;
    bool fa = true, ma = true;
    scanf("%d", &N);
    for(unsigned int i=0;i!=N; ++i) {
        scanf("%n %c %n %d", &name, &gender, &id, &g);
        if (gender=='M') {
            if (ma||g<mg) {
                ma = false;
                j=0;
                for (; name[j]!='\000'; ++j) mn[j]=name[j];
                mn[j] = '\000';
                j=0;
                for (; id[j]!='\000'; ++j) mid[j]=id[j];
                mid[j] = '\000';
                mg = g;
            }
        } else {
            if (fa||g>fg) {
                fa = false;
                j = 0;
                for (; name[j]!='\000'; ++j) fn[j]=name[j];
                fn[j] = '\000';
                j=0;
                for (; id[j]!='\000'; ++j) fid[j]=id[j];
                fid[j] = '\000';
                fg = g;
            }
        }
    }

    if (!fa) {
        printf("%n %n\n", fn, fid);
    } else {
        printf("Absent\n");
    }

    if (!ma) {
        printf("%n %n\n", mn, mid);
    } else {
        printf("Absent\n");
    }

    if (fa||ma) {
        printf("NA\n");
    } else {
        printf("%d\n", fg-mg);
    }
    return 0;
}

#endif //PAT_1036_HPP
