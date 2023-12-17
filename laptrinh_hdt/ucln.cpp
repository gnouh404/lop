#include <bits/stdc++.h>
using namespace std;
 
int UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
int BCNN(int A, int B){
    return (A*B)/UCLN(A,B);
}
int main() {
    int A,B,C;
    A = 12;
    B = 20;
    cout << BCNN(A,B);
}