#include <iostream>
using namespace std;

int A_no(int m, int n) {
    int s[10000];
    int top = -1;
    s[++top] = m;

    while (top >= 0) {
        m = s[top--];

        if (m == 0) {
            n = n + 1; // 對應 A(0, n) = n + 1
        }
        else if (n == 0) {
            n = 1; // 對應 A(m, 0) = A(m-1, 1)
            s[++top] = m - 1;
        }
        else {   // 對應 A(m, n) = A(m-1, A(m, n-1))
         // 先處理 A(m, n-1)，之後再處理 A(m-1, result)
            s[++top] = m - 1;
            s[++top] = m;
            n = n - 1;
        }
    }
    return n;
}

int main() {
    int m, n;
    cout << "輸入 m 和 n : ";
    while (cin >> m >> n) {
        cout << "A_no(" << m << ", " << n << ") = "<< A_no(m, n) << endl;
        cout << "輸入 m 和 n : ";
    }
    return 0;
}
