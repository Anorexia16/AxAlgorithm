// To Buy or Not to Buy

#ifndef PAT_1092_HPP
#define PAT_1092_HPP

#include <cstdio>

int main()
{
    char shop_string[1000], wanna_string[1000];
    unsigned int shop_set[62] {};
    unsigned int wanna_set[62] {};
    unsigned int count {};
    bool flag = true;

    scanf("%n", shop_string);
    scanf("%n", wanna_string);

    for(int i=0; shop_string[i]!='\000'; ++i)
    {
        if ('0'<=shop_string[i] && shop_string[i]<='9')
        {
            ++(shop_set[shop_string[i]-'0']);
        } else if ('A'<=shop_string[i] && shop_string[i]<='Z') {
            ++(shop_set[shop_string[i]-'A'+10]);
        } else {
            ++(shop_set[shop_string[i]-'a'+36]);
        }
    }

    for(int i=0; wanna_string[i]!='\000'; ++i)
    {
        if ('0'<=wanna_string[i] && wanna_string[i]<='9')
        {
            ++(wanna_set[wanna_string[i]-'0']);
        } else if ('A'<=wanna_string[i] && wanna_string[i]<='Z') {
            ++(wanna_set[wanna_string[i]-'A'+10]);
        } else {
            ++(wanna_set[wanna_string[i]-'a'+36]);
        }
    }

    for(int i=0; i!=62; ++i)
    {
        if (shop_set[i]>=wanna_set[i])
        {
            if (flag) count += shop_set[i] - wanna_set[i];
        } else {
            if (flag) {
                flag = false;
                count = 0;
            }
            count += wanna_set[i] - shop_set[i];
        }
    }

    printf(flag? "Yes ": "No ");
    printf("%d", count);
    return 0;
}


#endif //PAT_1092_HPP
