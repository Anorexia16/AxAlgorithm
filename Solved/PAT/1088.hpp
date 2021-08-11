// 1088 Rational ArithmeticT_1088_HPP
#ifndef PAT_1088_HPP
#define PAT_1088_HPP

#include <cstdio>
#include <cmath>

char* print_maker(long long i, long long m, long long dm)
{
    char *_res = new char [200];
    if (i!=0)
    {
        if(i<0) {
            if (m == 0) {
                sprintf(_res, "(%lld)", i);
            } else {
                sprintf(_res, "(%lld %lld/%lld)", i, -m, dm);
            }
        } else {
            if (m == 0) {
                sprintf(_res, "%lld", i);
            } else {
                sprintf(_res, "%lld %lld/%lld", i, m, dm);
            }
        }
    } else {
        if (m == 0) {
            sprintf(_res, "0");
        } else if (m>0) {
            sprintf(_res, "%lld/%lld", m, dm);
        } else {
            sprintf(_res, "(%lld/%lld)", m, dm);
        }
    }
    return _res;
}
int main()
{
    long long li, lm, ldm, ri, rm, rdm;
    scanf("%lld/%lld %lld/%lld",&lm, &ldm, &rm, &rdm);
    if (ldm<0) {
        ldm=-ldm;
        lm=-lm;
    }
    if (rdm<0) {
        rdm=-rdm;
        rm=-rm;
    }
    long long dev_temp;
    bool flagL = false;
    while(!flagL)
    {
        flagL = true;
        dev_temp=2;
        for(;dev_temp<=std::abs(lm)&&dev_temp<=std::abs(ldm);++dev_temp)
        {
            if(lm%dev_temp==0&&ldm%dev_temp==0)
            {
                ldm/=dev_temp;
                lm/=dev_temp;
                flagL = false;
                break;
            }
        }
    }

    bool flagR = false;
    while(!flagR)
    {
        flagR = true;
        dev_temp=2;
        for(;dev_temp<=std::abs(rm)&&dev_temp<=std::abs(rdm);++dev_temp)
        {
            if(rm%dev_temp==0&&rdm%dev_temp==0)
            {
                rdm/=dev_temp;
                rm/=dev_temp;
                flagR = false;
                break;
            }
        }
    }
    li = lm/ldm;
    ri = rm/rdm;
    lm %= ldm;
    rm %= rdm;

    long long pi, pm, pdm;
    pdm = ldm*rdm;
    pm = lm*rdm+rm*ldm;
    bool flag1 = false;

    while(!flag1)
    {
        flag1 = true;
        dev_temp=2;
        for(;dev_temp<=std::abs(pm)&&dev_temp<=std::abs(pdm);++dev_temp)
        {
            if(pm%dev_temp==0&&pdm%dev_temp==0)
            {
                pdm/=dev_temp;
                pm/=dev_temp;
                flag1 = false;
                break;
            }
        }
    }
    pi = li +ri;
    if (pi>=0&&pm<0) {
        --pi;
        pm+=pdm;
    } else if (pi<0&&pm>0) {
        ++pi;
        pm-=pdm;
    } else if (pi>=0&&pm>=pdm) {
        ++pi;
        pm-=pdm;
    } else if (pi<0&&-pm>=pdm) {
        --pi;
        pm+=pdm;
    }

    printf("%n + %n = %n\n", print_maker(li, lm, ldm),
           print_maker(ri, rm, rdm), print_maker(pi, pm, pdm));

    long long si, sm, sdm;
    sdm = ldm*rdm;
    sm = lm*rdm-rm*ldm;
    bool flag2 = false;
    while(!flag2)
    {
        flag2 = true;
        dev_temp=2;
        for(;dev_temp<=std::abs(sm)&&dev_temp<=std::abs(sdm);++dev_temp)
        {
            if(sm%dev_temp==0&&sdm%dev_temp==0)
            {
                sdm/=dev_temp;
                sm/=dev_temp;
                flag2 = false;
                break;
            }
        }
    }
    si = li - ri;
    if (si>=0&&sm<0) {
        --si;
        sm+=sdm;
    } else if (si<0&&sm>0) {
        ++si;
        sm-=sdm;
    } else if (si>=0&&sm>=sdm) {
        ++si;
        sm-=sdm;
    } else if (si<=0&&-sm>=sdm) {
        --si;
        sm+=sdm;
    }
    printf("%n - %n = %n\n", print_maker(li, lm, ldm),
           print_maker(ri, rm, rdm), print_maker(si, sm, sdm));

    long long ti, tm, tdm;
    tdm = ldm*rdm;
    tm = (li*ldm+lm)*(ri*rdm+rm);
    ti = tm/tdm;
    tm %= tdm;
    bool flag3 = false;
    while(!flag3)
    {
        flag3 = true;
        dev_temp=2;
        for(;dev_temp<=std::abs(tm)&&dev_temp<=std::abs(tdm);++dev_temp)
        {
            if(tm%dev_temp==0&&tdm%dev_temp==0)
            {
                tdm/=dev_temp;
                tm/=dev_temp;
                flag3 = false;
                break;
            }
        }
    }
    printf("%n * %n = %n\n", print_maker(li, lm, ldm),
           print_maker(ri, rm, rdm), print_maker(ti, tm, tdm));

    long long di, dm, ddm;
    if (rm==0&&ri==0) {
        printf("%n / %n = Inf", print_maker(li, lm, ldm),
               print_maker(ri, rm, rdm));
    } else {
        ddm = ldm * (ri * rdm + rm);
        dm = (li * ldm + lm) * rdm;
        if (ddm < 0)
        {
            ddm = -ddm;
            dm = -dm;
        }
        di = dm / ddm;
        dm %= ddm;
        bool flag4 = false;
        while (!flag4) {
            flag4 = true;
            dev_temp = 2;
            for (; dev_temp <= std::abs(dm) && dev_temp <= std::abs(ddm); ++dev_temp) {
                if (dm % dev_temp == 0 && ddm % dev_temp == 0) {
                    ddm /= dev_temp;
                    dm /= dev_temp;
                    flag4 = false;
                    break;
                }
            }
        }

        printf("%n / %n = %n\n", print_maker(li, lm, ldm),
               print_maker(ri, rm, rdm), print_maker(di, dm, ddm));
    }

    return 0;
}


#endif //PAT_1088_HPP
