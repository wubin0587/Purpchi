// src\ziwei\5_sui.cpp
#include "ziwei/5_sui.h"

// ============================================
// 长生十二神实现
// ============================================

int calculateChangsheng(int mingPalace, int wuxingJu) {
    // 根据五行局确定长生起始位置
    int changshengStart;
    
    switch (wuxingJu) {
        case 2:  // 水二局 -> 长生在申(6)
            changshengStart = 6;
            break;
        case 3:  // 木三局 -> 长生在亥(9)
            changshengStart = 9;
            break;
        case 4:  // 金四局 -> 长生在巳(3)
            changshengStart = 3;
            break;
        case 5:  // 土五局 -> 长生在申(6)
            changshengStart = 6;
            break;
        case 6:  // 火六局 -> 长生在申(6)
            changshengStart = 6;
            break;
        default:
            changshengStart = 6;  // 默认申宫
            break;
    }
    
    // 从长生起始位置顺数到命宫，确定命宫的长生十二神位置
    // 这里返回的是长生位在命盘中的绝对位置（从寅宫算起）
    // 长生十二神从长生起始宫位开始顺行
    
    return changshengStart;
}

// ============================================
// 岁建十二星实现
// ============================================

int calculateSuijian(int yearBranch) {
    // 岁建在年支位置
    // 岁建十二星从年支开始顺行
    return yearBranch;
}

// ============================================
// 將前十二星实现
// ============================================

int calculateJiangxing(int yearBranch) {
    // 根据年支三合局确定將星位置
    
    if (yearBranch == 0 || yearBranch == 4 || yearBranch == 8) {
        // 寅午戌年 -> 將星在午(4)
        return 4;
    } else if (yearBranch == 2 || yearBranch == 6 || yearBranch == 10) {
        // 申子辰年 -> 將星在子(10)
        return 10;
    } else if (yearBranch == 3 || yearBranch == 7 || yearBranch == 11) {
        // 巳酉丑年 -> 將星在酉(7)
        return 7;
    } else {
        // 亥卯未年 -> 將星在卯(1)
        return 1;
    }
}

// ============================================
// 流年十二星实现
// ============================================

int calculateSuiqian(int yearBranch) {
    // 岁前在年支前一位（逆行）
    return (yearBranch - 1 + 12) % 12;
}