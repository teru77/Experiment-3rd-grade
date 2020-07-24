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

ofstream ofs("2-2.csv");//ファイルに書き出し λの値でファイル名を変更

double lamda;//パラメ-タλ
double myu; //パラメータμ
double Ta=0.0;//客の到着時間 Ta
double y;//客の到着時間間隔　y
double y_m;//利用時間 y_m
double Td=0.0;//利用終了時刻



cin>>lamda;
while(1){
    if(t>=END_TIME)break;//END_TIMEで終了
    y=rnd_exp(lamda);//間隔y=指数分布に従う乱数
    t += y;//最新の到着時刻を取得
    while(1){
        if(t<T){//時間区間Tの間はイベントの到着個数をカウント
             en += 1;
            break;
        }
        else{//ある区間を超えた時
            A[T-1]=en;//区間Tのイベントの数を保存
            cout<<T<<"="<<A[T-1]<<endl;//出力
            en=0;//イベントの数を初期化
            T += 1;//次の区間へ
        }
    }

}


for(int i=0;i<END_TIME;i++){
    ofs<<"A"<<i<<","<<A[i]<<endl;//保存した各区間のイベント数をファイルに出力
}



return 0;
}
