////1019. 数字黑洞 (20)
//时间限制
//100 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue
//给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，
//再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复
//这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
//
//例如，我们从6767开始，将得到
//
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//7641 - 1467 = 6174
//... ...
//现给定任意4位正整数，请编写程序演示到达黑洞的过程。
//
//输入格式：
//
//输入给出一个(0, 10000)区间内的正整数N。
//
//输出格式：
//
//如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在
//一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
//
//输入样例1：
//6767
//输出样例1：
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//输入样例2：
//2222
//输出样例2：
//2222 - 2222 = 0000

#include <iostream>
#include <algorithm>
using namespace std;

int cmp1(int a, int b) {
    return a > b;
}
int cmp2(int a, int b) {
    return a < b;
}

int main() {
    int N;
    cin >> N;
    int a[4] = {0};
    int t = 3;
    while (N != 0 && t != -1) {
        a[t--] = N % 10;
        N = N / 10;
    }
    t = 3;
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        cout << a[0] << a[1] << a[2] << a[3] << " - " << a[0] << a[1]
             << a[2] << a[3] << " = " << "0000";
        return 0;
    }
    int result = 0;
    int b[4];
    int temp;
    while (result != 6174) {
        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
        }
        sort(a, a + 4, cmp1);
        sort(b, b + 4, cmp2);
        result = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] -
        b[0] * 1000 - b[1] * 100 - b[2] * 10 - b[3];
        cout << a[0] << a[1] << a[2] << a[3] << " - " <<
                b[0] << b[1] << b[2] << b[3] << " = ";
        temp = result;
        for (int i = 0; i < 4; i++) {
            a[i] = 0;
        }
        while (temp != 0 && t != -1) {
            a[t--] = temp % 10;
            temp = temp / 10;
        }
        t = 3;
        cout << a[0] << a[1] << a[2] << a[3] << endl;
    }
    return 0;
}