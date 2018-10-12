//
// Created by 服部篤樹 on 2018/10/12.
//

#ifndef GENERAL_COORDINATE_CIRCLE_SETCONDITION_H
#define GENERAL_COORDINATE_CIRCLE_SETCONDITION_H

#include "flow_conditions.h"

class SetCondition {
public:
    SetCondition(flow& Flow);

private:
    void InitialCondition(flow& Flow);
    void SetGrid(flow& Flow);
};


#endif //GENERAL_COORDINATE_CIRCLE_SETCONDITION_H
