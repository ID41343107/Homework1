#include <iostream>
#include <string>
using namespace std;

// S[]:原集合 s[]:當前子集 i:目前處理到S[i] N:集合大小 n:當前子集大小
void G(string S[], string s[], int i, int N, int n) {   // 遞歸生成冪集函數
    if (i == N) {
        cout << "(";
        for (int j = 0; j < n; j++) {
            cout << s[j];
            if (j != n - 1) cout << ",";
        }
        cout << ")" << endl;
        return;
    }

    // 不加入當前元素 S[i]，繼續處理下一個元素
    G(S, s, i + 1, N, n);
    // 加入當前元素 S[i] 到子集
    s[n] = S[i];
    // 繼續處理下一個元素，子集大小 C 增加 1
    G(S, s, i + 1, N, n + 1);
}

int main() {
    int N;
    cout << "請輸入n個數 : ";
    cin >> N;

    string* S = new string[N];
    string* c = new string[N];

    cout << "請輸入集合元素 : ";
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << "集合的冪集為:" << endl;
    G(S, c, 0, N, 0);

    delete[] S;
    delete[] c;

    return 0;
}
