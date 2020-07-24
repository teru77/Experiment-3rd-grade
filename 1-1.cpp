#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>
using namespace std;

double rand_val(){ //(0,1)の一様乱数の関数
    return (rand()+0.5)/(RAND_MAX+1.0);
}

double rnd_uni(double a,double b,double y){ //(a,b)の一様乱数の関数　yにrand_valを代入
    return b-(y*(b-a));
}

double rnd_exp(double ramda,double y_e){ //指数分布の関数　yにrand_valを代入
    return (-1)*log(y_e)/ramda;
}

int  main(void){
return 0;
}
