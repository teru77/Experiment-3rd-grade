#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
#include <fstream>

using namespace std;

double rand_val(){    //(0,1)の一様乱数の関数
    return (rand()+0.5)/(RAND_MAX+1.0);
}

int  main(void){

ofstream ofs("1-3.csv"); //ファイルに書き出し


int t=50;   //時間
double p=0.5;   //確率
int sum;    //距離


for(int i=0;i<100;i++){
    sum=0;
    for(int j=1;j<=t;j++){
        double X=rand_val();
        if(0<=X && X<=p){
            sum+=1;
        }
        else{
            sum+=-1;
        }

        ofs<<sum<<",";//ファイルに入力
    }
    ofs<<endl;//改行を加える
}


return 0;
}
