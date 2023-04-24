#include<bits/stdc++.h>
using namespace std;

const int MAXN = 32;
int f[MAXN];

int main() {
    // 初始化
    f[0] = 1; f[2] = 3;
    for (int i = 4; i <= 32; i += 2) {
        f[i] = f[i-2] * 3;  // 先乘上最後兩列的長方形的方法數()
        for (int j = i-4; j >= 0; j -= 2) {
            f[i] += f[j] * 2;  // 最後四列上下翻轉 dominoes 的方法數
        }
    }

    int n;
    while (cin >> n && n != -1) {
        cout << f[n] << endl;
    }
}