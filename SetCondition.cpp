//
// Created by 服部篤樹 on 2018/10/12.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "SetCondition.h"
SetCondition::SetCondition(flowc& Flow, metricc& Metric):
    mdx(100), mdy(100)
{

    InitialCondition(Flow, Metric);
}

void SetCondition::InitialCondition(flowc& Flow, metricc& Metric){
    //  Reynolds number
    Flow.re = 1661.0;
    //  CFL number
    Flow.cfl = 100;
    //  SOR Parameters for p
    Flow.omegap = 1.2;
    Flow.maxitp = 200;
    Flow.errorp = 1.0e-4;
    //  SOR parameters for u,v
    Flow.omegav = 1.2;
    Flow.maxitv = 20;
    Flow.errorv = 1.0e-5;
    //  No. of Time Steps
    Flow.nlast = 100000;
    Flow.nlp = 100;

    //  Set Grid Parameter
    Metric.mx = 61;
    Metric.my = 61;
    Metric.rmax = 50.0;
    Metric.drmin = 0.1/sqrt(Flow.re);

    //  x,yのサイズを確保
    Metric.x.resize(Metric.mx);
    Metric.y.resize(Metric.my);
    for(int i = 0; i<Metric.mx; i++){
        Metric.x.resize(Metric.my);
        Metric.y.resize(Metric.my);
    }
}

void SetCondition::SetGrid (flowc &Flow, metricc& Metric) {
    r.resize(mdy);
    theta.resize(mdx);
    //std::vector<std::vector<double>>* x = &Metric.x; // アドレスコピー
    //std::vector<std::vector<double>>* y = &Metric.y;

    int mx = Metric.mx;
    int my = Metric.my;
    double rmax = Metric.rmax;
    double dmin = Metric.drmin;

    //  Grid distribution in r-direction
    r[0] = 0.5;
    r[my - 1] = rmax;
    double sall = r[my - 1] - r[0];
    int no = my;
    int itemax = 50;
    double eps = 1.0e-8;

    double emin = 1.0e-5;
    double ermin = dmin * (pow(1 + emin, no - 1) - 1)/emin - sall;
    double emax = 1.0;
    double ermax = dmin * (pow(1 + emax, no - 1) - 1)/emax - sall;
    if (ermin > 0 || ermax < 0){
        std::cout << "Grid Generation error" << std::endl;
        return
    }

    //ここのeはあとで使用する
    double e;
    for(int i = 0; i<itemax; i++){
        double ehalf = (emin + emax)/2;
        double erhalf = dmin * (pow(1 + ehalf, no - 1) - 1)/ehalf - sall;
        if(abs(erhalf) < eps){
            e = ehalf;
            break;
        }
        if(erhalf > 0){
            emax = ehalf;
            ermax = erhalf;
        }else{
            emin = ehalf;
            ermin = erhalf;
        }

        //for文の制限を超えた場合にはエラーを出力
        if(i == itemax - 1){
            e = ehalf;
            std::cout << "Cluster not converged, itr = " << itemax << std::endl;
        }
    }

    double dx = 0.0;
    for(int n = 1; n<no-1; n++){
        dx = dx + dmin*pow((1 + e), n - 2);
        double t = dx/sall;
        r[n] = (1 - t)*r[0] + t * r[no - 1];
    }

    std::cout << "Grid distribution in r-direction" << std::endl;
    for (int i = 0; i<my; i++){
        std::cout << "i= " << i << ", r = r" << r[i] << std::endl;
    }

    //  Circumferential Distribution
    double dtheta = 2 * M_PI / static_cast<double>(mx - 1);
    for(int i = 0; i<mx; i++){
        theta[i] = dtheta * static_cast<double>(i);
    }

    //  Set inflow zone
    int i1 = 1 + (mx - 1)/4;
    int i2 = 1 + 3*(mx - 1)/4;

    //  2D grid definition
    for(int i = 0; i<mx; i++){
        for(int j = 0; j<my; j++){
            Metric.x[i][j] = r[j]*cos(theta[i]);
            Metric.y[i][j] = r[j]
        }
    }




};