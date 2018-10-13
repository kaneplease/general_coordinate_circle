//
// Created by 服部篤樹 on 2018/10/12.
//

#include <cmath>
#include "SetCondition.h"
SetCondition::SetCondition(flowc& Flow, metricc& Metric)
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
}

void SetCondition::SetGrid (flowc &Flow) {

}