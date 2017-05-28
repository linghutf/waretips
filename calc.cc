#include <iostream>
#include <stdlib.h>
#include <string.h>

double left(double total,double fit)
{
    return total*fit;
}
int main(int argc, char *argv[])
{
    double M = atof(argv[1]);//贷款总金额
    double fit = atof(argv[2]); // 利率
    int month = atoi(argv[3]); // 还息月份
    int month2 = atoi(argv[4]); // 还款月份
    double n = 38.04*2; //固定还息部分
    double n2 = 196.79; // 固定还息部分2

    double left = M;
    for(int i=1;i<=month;++i){
        left = left - n;
        if(i%12==0){
            left = left * fit;//年收益
        }
    }

    for(int i=1;i<=month2;++i){
        left = left - n2;
        if(i%12==0){
            left = left * fit;//年收益
        }
    }
    std::cout<<left<<std::endl;
    return 0;
}
