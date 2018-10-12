#include <iostream>
#include <vector>
#include "flow_conditions.h"
#include "SetCondition.h"

int main() {
    //流れ場のデータをインスタンス化
    flow Flow;
    // 初期化
    SetCondition Set(Flow);


    std::cout << Flow.cfl << std::endl;
    return 0;
}