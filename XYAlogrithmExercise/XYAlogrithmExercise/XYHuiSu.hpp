//
//  XYHuiSu.hpp
//  XYAlogrithmExercise
//
//  Created by SUGAR Dev on 2020/6/15.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef XYHuiSu_hpp
#define XYHuiSu_hpp

#include <stdio.h>

/// 回溯算法
class XYHuiSu {

    // 回溯算法实现。注意：我把输入的变量都定义成了成员变量。
     int maxW = 99999; // 结果放到maxW中
     int weight[5] = {2,2,4,6,3};  // 物品重量
     int n = 5; // 物品个数
     int w = 9; // 背包承受的最大重量
     void f(int i, int cw) { // 调用f(0, 0)
      if (cw == w || i == n) { // cw==w表示装满了，i==n表示物品都考察完了
        if (cw > maxW) maxW = cw;
        return;
      }
      f(i+1, cw); // 选择不装第i个物品
      if (cw + weight[i] <= w) {
        f(i+1,cw + weight[i]); // 选择装第i个物品
      }
    }
};
#endif /* XYHuiSu_hpp */
