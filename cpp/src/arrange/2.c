// src\ziwei\2.cpp
#include "ziwei/2.h"

namespace purpchi{
namespace arrange{
// ============================================
// 六吉星实现
// ============================================

int arrangeZuofu(int lunarMonth) {
    return (2 + lunarMonth - 1) % 12;
}

int arrangeYoubi(int lunarMonth) {
    return (8 - lunarMonth + 1 + 12) % 12;
}

int arrangeWenchang(int timeBranch) {
    int offset = (timeBranch >= 10) ? (timeBranch - 10) : (timeBranch + 2);
    return (2 - offset + 12) % 12;
}

int arrangeWenqu(int timeBranch) {
    int offset = (timeBranch >= 10) ? (timeBranch - 10) : (timeBranch + 2);
    return (8 + offset) % 12;
}

int arrangeTiankui(int yearLast) {
    // 天魁查表
    // 尾数对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己
    // 庚->丑, 辛->午, 壬->卯, 癸->寅, 甲->丑, 乙->子, 丙->亥, 丁->亥, 戊->丑, 己->子
    static const int kuiTable[10] = {
        11,  // 0-庚 -> 丑
        4,   // 1-辛 -> 午
        1,   // 2-壬 -> 卯
        0,   // 3-癸 -> 寅
        11,  // 4-甲 -> 丑
        10,  // 5-乙 -> 子
        9,   // 6-丙 -> 亥
        9,   // 7-丁 -> 亥
        11,  // 8-戊 -> 丑
        10   // 9-己 -> 子
    };
    return kuiTable[yearLast];
}

int arrangeTianyue(int yearLast) {
    // 天钺查表
    // 庚->未, 辛->寅, 壬->巳, 癸->卯, 甲->未, 乙->申, 丙->酉, 丁->酉, 戊->未, 己->申
    static const int yueTable[10] = {
        5,   // 0-庚 -> 未
        0,   // 1-辛 -> 寅
        3,   // 2-壬 -> 巳
        1,   // 3-癸 -> 卯
        5,   // 4-甲 -> 未
        6,   // 5-乙 -> 申
        7,   // 6-丙 -> 酉
        7,   // 7-丁 -> 酉
        5,   // 8-戊 -> 未
        6    // 9-己 -> 申
    };
    return yueTable[yearLast];
}

// ============================================
// 禄存实现
// ============================================

int arrangeLucun(int yearLast) {
    // 禄存查表
    // 庚->申, 辛->酉, 壬->亥, 癸->子, 甲->寅, 乙->卯, 丙->巳, 丁->午, 戊->巳, 己->午
    static const int lucunTable[10] = {
        6,   // 0-庚 -> 申
        7,   // 1-辛 -> 酉
        9,   // 2-壬 -> 亥
        10,  // 3-癸 -> 子
        0,   // 4-甲 -> 寅
        1,   // 5-乙 -> 卯
        3,   // 6-丙 -> 巳
        4,   // 7-丁 -> 午
        3,   // 8-戊 -> 巳
        4    // 9-己 -> 午
    };
    return lucunTable[yearLast];
}

// ============================================
// 六煞星实现
// ============================================

int arrangeQingyang(int yearLast) {
    int lucun = arrangeLucun(yearLast);
    return (lucun + 1) % 12;
}

int arrangeTuoluo(int yearLast) {
    int lucun = arrangeLucun(yearLast);
    return (lucun - 1 + 12) % 12;
}

int arrangeHuoxing(int yearBranch, int timeBranch) {
    int sanheLeiXing;
    if (yearBranch == 0 || yearBranch == 4 || yearBranch == 8) {
        sanheLeiXing = 0;
    } else if (yearBranch == 2 || yearBranch == 6 || yearBranch == 10) {
        sanheLeiXing = 1;
    } else if (yearBranch == 3 || yearBranch == 7 || yearBranch == 11) {
        sanheLeiXing = 2;
    } else {
        sanheLeiXing = 3;
    }
    
    static const int huoxingTable[4][12] = {
        {0, 1, 11, 8, 8, 5, 4, 3, 3, 0, 0, 11},
        {0, 1, 11, 8, 8, 5, 4, 3, 3, 0, 0, 11},
        {8, 9, 7, 6, 6, 3, 2, 1, 1, 8, 8, 7},
        {2, 3, 1, 0, 0, 9, 8, 7, 7, 2, 2, 1}
    };
    
    if (sanheLeiXing == 1) sanheLeiXing = 0;
    return huoxingTable[sanheLeiXing][timeBranch];
}

int arrangeLingxing(int yearBranch, int timeBranch) {
    int sanheLeiXing;
    if (yearBranch == 0 || yearBranch == 4 || yearBranch == 8) {
        sanheLeiXing = 0;
    } else if (yearBranch == 2 || yearBranch == 6 || yearBranch == 10) {
        sanheLeiXing = 1;
    } else if (yearBranch == 3 || yearBranch == 7 || yearBranch == 11) {
        sanheLeiXing = 2;
    } else {
        sanheLeiXing = 3;
    }
    
    static const int lingxingTable[4][12] = {
        {6, 2, 1, 9, 9, 6, 6, 3, 3, 9, 9, 6},
        {2, 7, 6, 3, 3, 11, 11, 8, 8, 3, 3, 11},
        {0, 5, 4, 1, 1, 9, 9, 6, 6, 1, 1, 9},
        {8, 1, 11, 9, 9, 5, 5, 2, 2, 9, 9, 5}
    };
    
    return lingxingTable[sanheLeiXing][timeBranch];
}

int arrangeDikong(int timeBranch) {
    int hourOffset = (timeBranch - 10 + 12) % 12;
    return (9 - hourOffset + 12) % 12;
}

int arrangeDijie(int timeBranch) {
    int hourOffset = (timeBranch - 10 + 12) % 12;
    return (9 + hourOffset) % 12;
}

// ============================================
// 天马实现
// ============================================

int arrangeTianma(int yearBranch) {
    if (yearBranch == 2 || yearBranch == 6 || yearBranch == 10) {
        return 0;  // 申子辰 -> 寅
    } else if (yearBranch == 0 || yearBranch == 4 || yearBranch == 8) {
        return 6;  // 寅午戌 -> 申
    } else if (yearBranch == 3 || yearBranch == 7 || yearBranch == 11) {
        return 9;  // 巳酉丑 -> 亥
    } else {
        return 3;  // 亥卯未 -> 巳
    }
}

}
}