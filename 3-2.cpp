#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;


int END_TIME=10000;//10000個

double rand_val(){//(0,1)の一様乱数の関数
    return (rand()+0.5)/(RAND_MAX+1.0);
}

double rnd_exp(double lamda){//指数分布の関数
    return (-1)*log(rand_val())/lamda;
}



int  main(){

ofstream ofs("3-2.csv");//ファイルに書き出し

double lamda;//パラメ-タλ
double myu; //パラメータμ
double Ta=0.0;//客の到着時間 Ta
double y;//客の到着時間間隔　y
double y_m;//サービスの利用時間 y_m
double Td=0.0;//利用終了時刻 Td
double cus_num=0.0;//お客さんの総数
double loss_num=0.0;//ロスした人数

cin>>lamda>>myu;

while(1){
    if(Ta>=END_TIME)break;//END_TIMEで終了
    y=rnd_exp(lamda);//間隔y(指数分布に従う乱数)
    Ta += y;//最新の到着時刻を取得
    cus_num += 1.0;//お客の数をカウント

    if(Td<＝Ta){
        y_m=rnd_exp(myu);//利用予定時間を設定
        Td = Ta+y_m;//利用終了時刻を設定
    }
    else{
        loss_num += 1.0;//ロスした人数を+1
    }

}
double loss=(loss_num/cus_num)*100;//ロス率(%)

cout<<"客数＝"<<cus_num<<"ロス="<<loss_num<<"ロス率="<<loss<<"%"<<endl;

ofs<<lamda<<","<<myu<<","<<loss<<endl;
return 0;
}
