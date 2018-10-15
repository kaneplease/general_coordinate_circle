
#include <iostream>
#include <vector>
#include "flow_conditions.h"
#include "SetCondition.h"

int main() {
    //流れ場のデータをインスタンス化
    flowc Flow;
    metricc Metric;
    // 初期化
    SetCondition Set(Flow, Metric);


    std::cout << Flow.cfl << std::endl;
    return 0;
}