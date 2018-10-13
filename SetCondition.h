//
// Created by 服部篤樹 on 2018/10/12.
//

#ifndef GENERAL_COORDINATE_CIRCLE_SETCONDITION_H
#define GENERAL_COORDINATE_CIRCLE_SETCONDITION_H

#include "flow_conditions.h"

class SetCondition {
public:
    SetCondition(flowc& Flow, metricc& Metric);

private:
    void InitialCondition(flowc& Flow, metricc& Metric);
    void SetGrid(flowc& Flow);
};


#endif //GENERAL_COORDINATE_CIRCLE_SETCONDITION_H
