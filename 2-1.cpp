#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

int T=1;//時間区間
int END_TIME=10000;//10000個

double rand_val(){//(0,1)の一様乱数の関数
    return (rand()+0.5)/(RAND_MAX+1.0);
}

double rnd_exp(double lamda){//指数分布の関数
    return (-1)*log(rand_val())/lamda;
}



int  main(){

ofstream ofs("2-1.csv");//ファイルに書き出し

double lamda;//パラメ-タλ
double t=0.0;//時間t
double y;//間隔y
int A[10001];//区間の個数を保存


cin>>lamda;//到着率を選択
while(1){
    if(t>=END_TIME)break;//END_TIMEで終了
    y=rnd_exp(lamda);//間隔y=指数分布に従う乱数
    t += y;//最新の到着時刻を取得
    ofs<<t<<endl;//到着時刻をファイルに出力
}






return 0;
}
