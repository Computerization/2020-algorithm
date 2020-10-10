#include <iostream>
#include <cmath>

using namespace std;

struct mat {
    unsigned long long a[4];
    mat operator *(mat o) {
        mat t;
        t.a[0] = (this->a[0] * o.a[0] + this->a[1] * o.a[2]) % 1000000007;
        t.a[1] = (this->a[0] * o.a[1] + this->a[1] * o.a[3]) % 1000000007;
        t.a[2] = (this->a[2] * o.a[0] + this->a[3] * o.a[2]) % 1000000007;
        t.a[3] = (this->a[2] * o.a[1] + this->a[3] * o.a[3]) % 1000000007;
        return t;
    }
};

// 预处理的矩阵 2^k 次幂
mat mat_pow[64];

int fib(unsigned long long k) {
    // 临时矩阵，每次在此上面乘以 mat_pow 中的某项
    mat tmp;
    tmp.a[0] = 1;
    tmp.a[1] = 0;
    tmp.a[2] = 0;
    tmp.a[3] = 1;
    for (int i = 0; i < 64; i++) {
        // 如果 a_i 为 1
        if (k & (1ull << i)) {
            tmp = tmp * mat_pow[i];
        }
    }
    return tmp.a[1];
}

int main() {
    mat_pow[0].a[0] = 0;
    mat_pow[0].a[1] = 1;
    mat_pow[0].a[2] = 1;
    mat_pow[0].a[3] = 1;
    for (int i = 1; i < 64; i++) {
        mat_pow[i] = mat_pow[i-1] * mat_pow[i-1];
    }
    unsigned long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
