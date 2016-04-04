// 第7题：六角填数（12）


//     如图所示六角形中，填入1~12的数字。
//     使得每条直线上的数字之和都相同。
//     图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？

// 请通过浏览器提交答案，不要填写多余的内容。

answer：
10
标记从上到下从左到右为1~12

#include <iostream>
using namespace std;
int book[13]; //标记1~12有没有被使用过
int a[13]; //标记12个位置所对应的数
int line[6];

void dfs(int x) {
    int i;
    //如果是已经填了数的那个，就直接跳过搜索下一个
    if(x == 1 || x == 2 || x == 12) {
        dfs(x + 1);
        return ;
    }
    //如果12个已经填满了，就判断是否满足每一条线上的都相等
    if(x > 12) {
        line[0] = a[1] + a[3] + a[6] + a[8];
        line[1] = a[1] + a[4] + a[7] + a[11];
        line[2] = a[8] + a[9] + a[10] + a[11];
        line[3] = a[2] + a[3] + a[4] + a[5];
        line[4] = a[2] + a[6] + a[9] + a[12];
        line[5] = a[5] + a[7] + a[10] + a[12];
        //判断是否两两相等，只要一层循环就好了
        //如果不相等，就直接return，说明这种情况不符合
        for(i = 1; i <= 5; i++) {
            if(line[i] != line[i - 1])
                return ;
        }
        //如果都满足，则输出a[6]的值
        cout << a[6] << endl;
        return ;
    }
    
    //从数字1到数字12，看有没有没填过的数字，没有填过就填入当前空格
    for(i = 1; i <= 12; i++) {
        if(book[i] == 0) {
            book[i] = 1;
            a[x] = i;
            //填入后就填下一个数字
            dfs(x + 1);
            book[i] = 0;
        }
    }
}


int main() {
    //根据题意初始化值
    book[1] = 1;
    book[3] = 1;
    book[8] = 1;
    a[1] = 1;
    a[2] = 8;
    a[12] = 3;
    
    dfs(1);
    return 0;
}

