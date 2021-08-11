/*
UVA1724 Solitaire
题目描述:
    Solitaire is a game played on a chessboard 8×8. The rows and columns of the chessboard are numbered
from 1 to 8, from the top to the bottom and from left to right, respectively.
There are four identical pieces on the board. In one move it is allowed to:
• move a piece to an empty neighboring field (up, down, left or right),
• jump over one neighboring piece to an empty field (up, down, left or right).
Exactly 4 moves are allowed for each piece in the figure above. As an example let’n consider a piece
placed in the row 4, column 4. It can be moved one row up, two rows down, one column left or two
columns right.
Write a program that:
• reads two chessboard configurations from the standard input,
• verifies whether the second one is reachable from the first one in at most 8 moves,
• writes the result to the standard output.

输入格式: Each of two input lines contains 8 integers a1, a2, . . . , a8 separated by single spaces and describes one
        configuration of pieces on the chessboard. Integers a2j−1 and a2j (1 ≤ j ≤ 4) describe the position of
        one piece — the row number and the column number respectively.
输出格式: The output should contain one word ‘YES’ if the configuration described in the second input line is
        reachable from the configuration described in the first input line in at most 8 moves, and one word ‘NO’
        otherwise.
难度: 提高+/省选-
历史分数--gg
*/

#ifndef PAT_UVA1724_HPP
#define PAT_UVA1724_HPP

#include <cstdio>
#include <queue>
#include <array>
#include <set>

typedef size_t piece;

inline size_t read() {
    size_t x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x-1;
}

inline piece init(size_t const &x, size_t const &y) {
    return (y<<3)+x;
}

inline size_t gy(piece const &p) {
    return p>>3;
}

inline size_t gx(piece const &p) {
    return p%8;
}

inline piece move(piece const &p, int const &dir, short const &dev) {
    switch (dir) {
        case 0:
            return p-8*dev;
            case 1:
                return p+dev;
                case 2:
                    return p+dev*8;
                    default:
                        return p-dev;
    }
}

typedef std::array<piece, 4> step;

step *move(const step& old, int const &idx, int const &dir) {
    step &ans = *new step {};
    int op[3], j{};
    for(int i=0;i!=4;++i) {if(i!=idx) op[j++] = i;}
    for(auto const &i : op) ans[i]=old[i];
    size_t x = gx(old[idx]), y = gy(old[idx]);
    switch (dir) {
        case 0:
            if(y==0) return nullptr;
            for(auto const &i:op) {
                if(x==gx(old[i])&&y==gy(old[i])+1) {
                    if(y==1) return nullptr;
                    for(auto const &w:op) {
                        if(w!=i&&x==gx(old[w])&&y==gy(old[w])+2)
                            return nullptr;
                    }
                    ans[idx]=move(old[idx], dir, 2);
                    return &ans;
                }
            }
            ans[idx]=move(old[idx], dir, 1);
            return &ans;
            case 1:
                if(x==7) return nullptr;
                for(auto const &i:op) {
                    if(y==gy(old[i])&&x+1==gx(old[i])) {
                        if(x==6) return nullptr;
                        for(auto const &w:op) {
                            if(w!=i&&y==gy(old[w])&&x+2==gx(old[w]))
                                return nullptr;
                        }
                        ans[idx]=move(old[idx], dir, 2);
                        return &ans;
                    }
                }
                ans[idx]=move(old[idx], dir, 1);
                return &ans;
                case 2:
                    if(y==7) return nullptr;
                    for(auto const &i:op) {
                        if(x==gx(old[i])&&y+1==gy(old[i])) {
                            if(y==6) return nullptr;
                            for(auto const &w:op) {
                                if(w!=i&&x==gx(old[w])&&y+2==gy(old[w]))
                                    return nullptr;
                            }
                            ans[idx]=move(old[idx], dir, 2);
                            return &ans;
                        }
                    }
                    ans[idx]=move(old[idx], dir, 1);
                    return &ans;
                    default:
                        if(x==0) return nullptr;
                        for(auto const &i:op) {
                            if(y==gy(old[i])&&x==gx(old[i])+1) {
                                if(x==1) return nullptr;
                                for(auto const &w:op) {
                                    if(w!=i&&y==gy(old[w])&&x==gx(old[w])+2)
                                        return nullptr;
                                }
                                ans[idx]=move(old[idx], dir, 2);
                                return &ans;
                            }
                        }
                        ans[idx]=move(old[idx], dir, 1);
                        return &ans;
    }
}

size_t platform(step const &method) {
    size_t bits=0;
    for (auto const &i:method) bits+=1<<i;
    return bits;
}

int main() {
    std::queue<step> prb, pob;
    std::set<size_t> prr, por;
    step pr, po;
    step ts, *tt;
    size_t x, y, bs;
    for(auto & i : pr) {
        x=read(), y=read();
        i = init(x, y);
    }
    for(auto & i : po) {
        x=read(), y=read();
        i = init(x, y);
    }
    prb.push(pr);
    for(int r=0;r!=4;++r) {
        bs=prb.size();
        for(int t=0;t!=bs;++t) {
            ts = prb.front();
            for(int p=0;p!=4;++p) {
                for(int d=0;d!=4;++d) {
                    tt = move(ts, p, d);
                    if(tt!= nullptr) prb.push(*tt);
                }
            }
            prb.pop();
        }
    }
    pob.push(po);
    for(int r=0;r!=4;++r) {
        bs=pob.size();
        for(int t=0;t!=bs;++t) {
            ts = pob.front();
            for(int p=0;p!=4;++p) {
                for(int d=0;d!=4;++d) {
                    tt= move(ts, p, d);
                    if(tt!= nullptr) pob.push(*tt);
                }
            }
            prb.pop();
        }
    }
    while(!prb.empty()) {
        prr.insert(platform(prb.front()));prb.pop();
    }
    while(!pob.empty()) {
        por.insert(platform(pob.front()));pob.pop();
    }
    for(auto const &iter:prr) {
        if(por.find(iter)!=por.end()) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

#endif //PAT_UVA1724_HPP
