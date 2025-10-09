#include "ziwei/bright.h"

// 庙旺等级: 7庙, 6旺, 5得, 4利, 3平, 2不得, 1陷
// 甲级/乙级星庙旺查询表 [StarA][Palace]
// 宫位顺序: 寅 卯 辰 巳 午 未 申 酉 戌 亥 子 丑
static const int brightness_table_A[A_STARS_COUNT][12] = {
    // A_ZIWEI (紫微)
    {6, 3, 5, 7, 6, 7, 5, 3, 6, 3, 6, 7},
    // A_TIANJI (天机)
    {5, 6, 7, 3, 1, 5, 6, 7, 1, 3, 5, 1},
    // A_TAIYANG (太阳)
    {6, 7, 7, 7, 6, 5, 3, 1, 1, 1, 2, 2},
    // A_WUQU (武曲)
    {5, 6, 7, 3, 1, 7, 5, 6, 7, 3, 1, 7},
    // A_TIANTONG (天同)
    {5, 7, 3, 6, 1, 3, 7, 1, 3, 6, 5, 3},
    // A_LIANZHEN (廉贞)
    {3, 6, 3, 1, 3, 1, 7, 6, 5, 1, 3, 3},
    // A_TIANFU (天府)
    {7, 6, 7, 5, 6, 7, 7, 6, 7, 5, 6, 7},
    // ... 此处需要您根据权威资料继续填充 ...
    // ... 为保证能编译通过，我们用 3 (平和) 填充剩余部分作为占位符 ...
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TAIYIN
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TANLANG
    {3,3,3,3,3,3,3,3,3,3,3,3}, // JUMEN
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TIANXIANG
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TIANLIANG
    {3,3,3,3,3,3,3,3,3,3,3,3}, // QISHA
    {3,3,3,3,3,3,3,3,3,3,3,3}, // POJUN
    {3,3,3,3,3,3,3,3,3,3,3,3}, // ZUOFU
    {3,3,3,3,3,3,3,3,3,3,3,3}, // YOUBI
    {3,3,3,3,3,3,3,3,3,3,3,3}, // WENCHANG
    {3,3,3,3,3,3,3,3,3,3,3,3}, // WENQU
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TIANKUI
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TIANYUE
    {3,3,3,3,3,3,3,3,3,3,3,3}, // LUCUN
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TIANMA
    {3,3,3,3,3,3,3,3,3,3,3,3}, // QINGYANG
    {3,3,3,3,3,3,3,3,3,3,3,3}, // TUOLUO
    {3,3,3,3,3,3,3,3,3,3,3,3}, // HUOXING
    {3,3,3,3,3,3,3,3,3,3,3,3}, // LINGXING
    {1,1,1,1,1,1,1,1,1,1,1,1}, // DIKONG
    {1,1,1,1,1,1,1,1,1,1,1,1}  // DIJIE
};

int getStarABrightness(StarA star, int palace) {
    if (star >= A_STARS_COUNT || palace < 0 || palace >= 12) {
        return 0; // 安全检查，0 代表不在
    }
    // 特殊处理没有庙旺之分的星, 比如左右昌曲等
    switch(star) {
        case A_ZUOFU:
        case A_YOUBI:
        case A_WENCHANG:
        case A_WENQU:
            return 7; // 通常认为这些是吉星，在任何宫位都为庙
        default:
            return brightness_table_A[star][palace];
    }
}

int getStarCBrightness(StarC star, int palace) {
    // 丙级星通常没有庙旺之分，统一返回 3 (平和)
    return 3;
}