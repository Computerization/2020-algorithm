#include <iostream>
#include <fstream>

using namespace std;

struct cow {
    int adj[2];  // 需要和这头奶牛相邻的奶牛的ID
    int adjcnt;  // 这头奶牛一共有几个约束条件；决定了能否把它放在约束链的开头
    bool chosen; // 是否已经进队
} cows[8];
string names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int getID(string name) {
    for(int i = 0; i < 8; i++)
        if(names[i] == name)
            return i;
    return -1;
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    int n;
    fin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        fin >> a >> b >> b >> b >> b >> b;
        cows[getID(a)].adj[cows[getID(a)].adjcnt++] = getID(b);
        cows[getID(b)].adj[cows[getID(b)].adjcnt++] = getID(a);
    }
    int prev = -1;
    // 每次循环向队列中添加一头奶牛；如果上一头奶牛没有更多的约束条件了，则可以选择一头新的，否则选择需要和上一头相邻的奶牛
    for (int _ = 0; _ < 8; _++) {
        if (_ == 0 || cows[prev].adjcnt == 0) {
            for (int i = 0; i < 8; i++) {
                if (!cows[i].chosen && cows[i].adjcnt < 2) {
                    cows[i].chosen = true;
                    fout << names[i] << endl;
                    prev = i;
                    break;
                }
            }
        } else if (cows[prev].adjcnt == 1) {
            int i = cows[prev].adj[0];
            cows[i].chosen = true;
            // 这里的操作是在把cows[i]添加入队列的同时“删除”掉它已经满足的那条约束
            cows[i].adjcnt--;
            if(cows[i].adj[0] == prev)
                cows[i].adj[0] = cows[i].adj[1];
            fout << names[i] << endl;
            prev = i;
        }
    }
    return 0;
}
