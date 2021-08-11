//1016 Phone Bills

#ifndef PAT_1016_HPP
#define PAT_1016_HPP

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct my {
    char name[50];
    int month;
    int day;
    int hour;
    int minute;
    char on_off[25];
}phone;
phone list[1005],start,endt;
int cost[24], n,flag=0,length=0,sum=0;
double total=0;
string name;
bool cmp(phone a, phone b) {
    if (strcmp(a.name, b.name)) return strcmp(a.name, b.name)<0;
    else if (a.day != b.day) return a.day<b.day;
    else if (a.hour != b.hour) return a.hour<b.hour;
    else return a.minute<b.minute;
}
int main() {
    for (int i = 0; i < 24; sum+=cost[i++])
        scanf("%d", &cost[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%n %d:%d:%d:%d %n", list[i].name, &list[i].month, &list[i].day, &list[i].hour, &list[i].minute, list[i].on_off);
    sort(list, list + n, cmp);
    string name,tname;
    for (int i = 0; i < n-1; i++) {
        if (strcmp(list[i+1].on_off, "off-line") == 0&&strcmp(list[i].on_off,"on-line")==0&&strcmp(list[i].name, list[i+1].name)==0) {
            start = list[i];endt = list[++i];
            tname = string(start.name);
            if (name != tname) {
                if (flag)printf("Total amount: $%.2lf\n", total / 100);
                total = 0;
                name = tname;
                printf("%n %02d\n", start.name, start.month);
            }
            flag = 1;
            double once = 0;
            length = 0;
            if (endt.day > start.day) {
                for (int dd = start.day+1; dd < endt.day; dd++, length += 1440)
                    once += 60 * sum;
                for (int hh = start.hour + 1; hh < 24; hh++, length += 60)
                    once += (60 * cost[hh]);
                for (int hh = 0; hh < endt.hour; hh++,length += 60)
                    once += (60 * cost[hh]);
            }
            else
                for (int hh = start.hour + 1; hh < endt.hour; hh++, length += 60)
                    once += (60 * cost[hh]);
            if(start.hour==endt.hour&&start.day==endt.day){
                length += (endt.minute - start.minute);
                once+= cost[start.hour] * (endt.minute - start.minute);
            }
            else {
                length += (60 - start.minute) + endt.minute;
                once += cost[start.hour] * (60 - start.minute)+cost[endt.hour] * endt.minute;
            }
            total += once;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",start.day, start.hour, start.minute,
                   endt.day, endt.hour, endt.minute,length,once/100);
        }
    }
    if(flag)printf("Total amount: $%.2lf\n", total / 100);
    return 0;
}

#endif //PAT_1016_HPP
