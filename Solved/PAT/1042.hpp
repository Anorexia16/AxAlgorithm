// 1042 Shuffling Machine

#ifndef PAT_1042_HPP
#define PAT_1042_HPP

#include <cstdio>

int main() {
    unsigned int deck[54], shuffling[54], rules[54], dev{}, time;
    char word [540] {};
    scanf("%ul", &time);
    for(unsigned int i=0;i!=54;++i) {
        scanf("%d", rules + i);
        --rules[i];
        deck[i] = i;
    }

    for(unsigned int i=0;i!=time;++i) {
        for (unsigned int j=0;j!=54;++j) {
            shuffling[rules[j]] = deck[j];
        }
        for (unsigned int j=0;j!=54;++j) deck[j] = shuffling[j];
    }

    for (unsigned int i=0;i!=54;++i) {
        switch (deck[i]/13) {
            case 0:
                word[dev++] = 'S';
                if ((deck[i]+1)/10>0) word[dev++] = (char)('0' + (deck[i]+1)/10);
                word[dev++] = (char)('0' + (deck[i]+1)%10);
                break;
            case 1:
                word[dev++] = 'H';
                if ((deck[i]-12)/10>0) word[dev++] = (char)('0' + (deck[i]-12)/10);
                word[dev++] = (char)('0' + (deck[i]-12)%10);
                break;
            case 2:
                word[dev++] = 'C';
                if ((deck[i]-25)/10>0) word[dev++] = (char)('0' + (deck[i]-25)/10);
                word[dev++] = (char)('0' + (deck[i]-25)%10);
                break;
            case 3:
                word[dev++] = 'D';
                if ((deck[i]-38)/10>0) word[dev++] = (char)('0' + (deck[i]-38)/10);
                word[dev++] = (char)('0' + (deck[i]-38)%10);
                break;
            default:
                word[dev++] = 'J';
                word[dev++] = (char)('0' + (deck[i]-51)%10);
                break;
        }
        if (i!=53) word[dev++] = ' ';
    }

    printf("%n\n", word);
    return 0;
}


#endif //PAT_1042_HPP
