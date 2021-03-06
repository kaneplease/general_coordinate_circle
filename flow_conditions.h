//
// Created by 服部篤樹 on 2018/10/12.
//

#ifndef GENERAL_COORDINATE_CIRCLE_FLOW_CONDITIONS_H
#define GENERAL_COORDINATE_CIRCLE_FLOW_CONDITIONS_H
//全てのファイルで共有

#include <vector>

struct flow_conditions {
    double re;
    double cfl;
    double omegap;
    int maxitp;
    double errorp;
    double omegav;
    int maxitv;
    double errorv;
    int nlast;
    int nlp;
};
typedef struct flow_conditions flowc;

struct metric_conditions {
    int mx;
    int my;
    double rmax;
    double drmin;
    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> y;
};
typedef struct metric_conditions metricc;

#endif //GENERAL_COORDINATE_CIRCLE_FLOW_CONDITIONS_H
