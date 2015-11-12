////算法训练 字串统计
//问题描述
//　　给定一个长度为n的字符串S，还有一个数字L，统计长度大于等于L的出现次数最多的子串（不同的出现可以相交），如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
//输入格式
//　　第一行一个数字L。
//　　第二行是字符串S。
//　　L大于0，且不超过S的长度。
//输出格式
//　　一行，题目要求的字符串。
//　　输入样例1：
//　　4
//　　bbaabbaaaaa
//　　输出样例1：
//　　bbaa
//　　输入样例2：
//　　2
//　　bbaabbaaaaa
//　　输出样例2：
//　　aa
//数据规模和约定
//　　n<=60
//　　S中所有字符都是小写英文字母。
//提示
//　　枚举所有可能的子串，统计出现次数，找出符合条件的那个

#include <iostream>
#include <string>
using namespace std;
int main() {
    const int MAX = 10000;
    int L;
    cin >> L;
    string s;
    cin >> s;
    const int len = s.length();
    string str[MAX];
    int t = 0;
    for (int i = L; i <= len; i++) {
        for (int j = 0; j < len - i; j++) {
            str[t++] = s.substr(j, i);
        }
    }
    
    int a[MAX] = {0};
    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < t - 1; j++) {
            if (str[i] == str[j]) {
                a[i]++;
            }
        }
    }
    
    int max = 0;
    int temp = 0;
    for (int i = 0; i < t - 1; i++) {
        if (max < a[i]) {
            max = a[i];
            temp = i;
        }
    }
    
    cout << str[temp];
    return 0;
}
