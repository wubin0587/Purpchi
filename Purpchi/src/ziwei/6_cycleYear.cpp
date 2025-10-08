// D:\Purpchi\src\ziwei\6_cycleYear.cpp
#include "ziwei/6_cycleYear.h"

// ============================================
// 辅助函数实现
// ============================================

int isYangYear(int yearLast) {
    // 阳年: 庚(0), 壬(2), 甲(4), 丙(6), 戊(8)
    return (yearLast == 0 || yearLast == 2 || yearLast == 4 || 
            yearLast == 6 || yearLast == 8);
}

// ============================================
// 大运系统实现
// ============================================

int isDayunShun(int isMale, int yearLast) {
    int yangYear = isYangYear(yearLast);
    // 阳男阴女顺行
    return (yangYear && isMale) || (!yangYear && !isMale);
}

int calculateDayunStart(int mingPalace, int isMale, int yearLast) {
    // 大运起点永远是命宫，方向由顺逆决定
    return mingPalace;
}

// ============================================
// 流年系统实现
// ============================================

int calculateLiunianStart(int mingPalace) {
    // 流年起点永远是命宫，顺行
    return mingPalace;
}

// ============================================
// 小限系统实现
// ============================================

int isXiaoxianShun(int isMale) {
    // 男命顺行，女命逆行
    return isMale;
}

int calculateXiaoxianStart(int isMale) {
    // 男命从寅(0)，女命从申(6)
    return isMale ? 0 : 6;
}