//
// Created by 服部篤樹 on 2018/10/12.
//

#include "SetCondition.h"
SetCondition::SetCondition(flow& Flow)
{
    InitialCondition(Flow);
}

void SetCondition::InitialCondition(flow& Flow){
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
}

