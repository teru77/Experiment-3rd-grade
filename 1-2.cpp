#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

double rand_val(){ //(0,1)の一様乱数の関数
    return (rand()+0.5)/(RAND_MAX+1.0);  
}

double rnd_uni(double a,double b,double y){ //(a,b)の一様乱数の関数
    return b-(y*(b-a));
}

double rnd_exp(double ramda,double y_e){ //指数分布の関数
    return (-1)*log(y_e)/ramda;
}

double squar(double v){//２乗を計算
    return v*v;
}

int  main(){
srand(18140526); //シード値の変更 
ofstream ofs("1-2.csv"); //ファイルに書き出し

int n=10000; //10000個
double a=30.0;//変数a
double b=60.0;//変数b
double ramda=3.0;//パラメタλ
double sum=0.0;//合計(一様分布)
double sum_v=0.0;//合計(一様分布の分散を求める時に使用)
double sum_e=0.0;//合計(指数分布の平均を求める時に使用)
double sum_ev=0.0;//合計(指数分布の分散を求める時に使用)
double val[10000],u[10000],e[10000]; //(0,1)の一様分布、(a,b)の一様分布、指数分布の乱数を保存

//乱数の生成
for(int i=0;i<n;i++){
    val[i]= rand_val();
    u[i]=rnd_uni(a,b,val[i]);//(a,b)の一様分布を
    e[i]=rnd_exp(ramda,val[i]);//

    sum=rnd_uni(a,b,val[i])+sum; //一様分布の乱数の合計を計算
    sum_e=rnd_exp(ramda,val[i])+sum_e; //指数分布の乱数の合計を計算
    ofs<<val[i]<<","<<u[i]<<","<<e[i]<<endl;　//ファイルに入力
}

//一様分布
double ave=sum/n;//一様分布の平均
printf("一様分布の平均:%8f\n",ave);

for(int i=0;i<n;i++){
    sum_v=squar(rnd_uni(a,b,val[i])-ave)+sum_v; //(x-平均)^2を合計に加算

}
double v=sum_v/n; //一様分布の分散
printf("一様分布の分散:%8f\n",v);

//指数分布

double ave_e=sum_e/n;//指数分布の平均
printf("指数分布の平均:%8f\n",ave_e);

for(int i=0;i<n;i++){
    sum_ev=squar(rnd_exp(ramda,val[i])-ave_e)+sum_ev; //(x-平均)^2を合計に加算
}
double v_e=sum_ev/n; //指数分布の分散
printf("指数分布の分散:%8f\n",v_e);


return 0;
}