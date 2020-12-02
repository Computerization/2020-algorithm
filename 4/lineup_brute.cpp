/** 
 * Adopted from official solution at 
 * http://www.usaco.org/current/data/sol_lineup_bronze_dec19.html
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
// beside_a 和 beside_b 中对应下标的奶牛表示一组约束关系
vector<string> beside_a, beside_b;
int n;

int getID(string name) {
    for (int i = 0; i < 8; i++)
        if (names[i] == name)
            return i;
    return -1;
}

bool satisfies_constraints() {
    for (int i = 0; i < n; i++)
        if (abs(getID(beside_a[i]) - getID(beside_b[i])) != 1)
            return false;
    return true;
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    fin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        fin >> a >> b >> b >> b >> b >> b;
        beside_a.push_back(a);
        beside_b.push_back(b);
    }
    // 遍历所有的8头奶牛的排列，输出第一个满足约束的解
    do {
        if (satisfies_constraints()) {
            for (int i = 0; i < 8; i++)
                fout << names[i] << endl;
            return 0;
        }
    } while (next_permutation(names.begin(), names.end()));
    return 0;
}
