// src\ziwei\3.cpp
#include "ziwei/3.h"
#include "ziwei/1.h" // 引入 1.h 以调用命宫、身宫等函数
#include "ziwei/2.h" // 引入 2.h 以调用左辅、右弼、文昌、文曲等函数

// ============================================
// 丙级星 - 年干系
// ============================================

int calculateTianguan(int yearLast) {
    // 规则：甲未, 乙辰, 丙巳, 丁寅, 戊引, 己申, 庚亥, 辛酉, 壬寅, 癸卯
    // 天干: 甲4, 乙5, 丙6, 丁7, 戊8, 己9, 庚0, 辛1, 壬2, 癸3
    // 宫位: 寅0, 卯1, 辰2, 巳3, 午4, 未5, 申6, 酉7, 戌8, 亥9, 子10, 丑11
    static const int palaceTable[10] = {9, 7, 0, 1, 5, 2, 3, 0, 6, 6};
    return palaceTable[yearLast];
}

int calculateTianfu(int yearLast) {
    // 规则：甲酉, 乙申, 丙子, 丁亥, 戊卯, 己寅, 庚午, 辛巳, 壬午, 癸巳
    static const int palaceTable[10] = {4, 3, 4, 3, 7, 6, 10, 9, 1, 0};
    return palaceTable[yearLast];
}

int calculateTianchu(int yearLast) {
    // 规则：甲巳, 乙午, 丙子, 丁子, 戊申, 己申, 庚寅, 辛卯, 壬酉, 癸酉
    static const int palaceTable[10] = {0, 1, 7, 7, 3, 4, 10, 10, 6, 6};
    return palaceTable[yearLast];
}

// ============================================
// 丙级星 - 年支系
// ============================================

int calculateHongluan(int yearBranch) {
    // 规则：从卯宫(1)起子(0)，逆数到生年支
    const int maoPalace = 1;
    return (maoPalace - yearBranch + 12) % 12;
}

int calculateTianxi(int yearBranch) {
    // 规则：从酉宫(7)起子(0)，顺数到生年支
    const int youPalace = 7;
    return (youPalace + yearBranch) % 12;
}

int calculateTianxing(int yearBranch) {
    // 规则：从酉宫(7)起正月(寅)，顺数到生月(对应生年支)
    // yearBranch (子=0) -> month_num (寅=1) 映射:
    // 子0->11月, 丑1->12月, 寅2->1月, 卯3->2月...
    static const int branchToMonthNum[12] = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int youPalace = 7;
    int monthNum = branchToMonthNum[yearBranch];
    return (youPalace + monthNum - 1) % 12;
}

int calculateTanyao(int yearBranch) {
    // 规则：从丑宫(11)起子(0)，顺数到生年支
    const int chouPalace = 11;
    return (chouPalace + yearBranch) % 12;
}

int calculateJieshen(int yearBranch) {
    // 规则：年支定解神，按 子=0, 丑=1... 重新排序
    static const int palaceTable[12] = {4, 4, 6, 6, 8, 8, 10, 10, 0, 0, 2, 2};
    return palaceTable[yearBranch];
}

int calculateLongchi(int yearBranch) {
    // 规则：从辰宫(2)起子(0)，顺数到生年支
    const int chenPalace = 2;
    return (chenPalace + yearBranch) % 12;
}

int calculateFengge(int yearBranch) {
    // 规则：从戌宫(8)起子(0)，逆数到生年支
    const int xuPalace = 8;
    return (xuPalace - yearBranch + 12) % 12;
}

int calculateGuchen(int yearBranch) {
    // 规则：亥(11)子(0)丑(1)年在寅(0)，寅(2)卯(3)辰(4)年在巳(3)...
    if (yearBranch == 11 || yearBranch == 0 || yearBranch == 1) return 0; // -> 寅
    if (yearBranch >= 2 && yearBranch <= 4) return 3; // -> 巳
    if (yearBranch >= 5 && yearBranch <= 7) return 6; // -> 申
    return 9; // -> 亥
}

int calculateGuasu(int yearBranch) {
    // 规则：亥(11)子(0)丑(1)年在戌(8)，寅(2)卯(3)辰(4)年在丑(11)...
    if (yearBranch == 11 || yearBranch == 0 || yearBranch == 1) return 8; // -> 戌
    if (yearBranch >= 2 && yearBranch <= 4) return 11; // -> 丑
    if (yearBranch >= 5 && yearBranch <= 7) return 2; // -> 辰
    return 5; // -> 未
}

int calculateFeilian(int yearBranch) {
    // 规则：年支定蜚廉，按 子=0, 丑=1... 重新排序
    static const int palaceTable[12] = {10, 11, 6, 7, 8, 3, 4, 5, 0, 1, 2, 9};
    return palaceTable[yearBranch];
}

int calculatePosui(int yearBranch) {
    // 规则：巳(5)酉(9)丑(1)年在巳(3)；申(8)子(0)辰(4)年在酉(7)...
    switch (yearBranch) {
        case 5: case 9: case 1:  // 巳, 酉, 丑
            return 3; // 在 巳
        case 8: case 0: case 4:  // 申, 子, 辰
            return 7; // 在 酉
        case 11: case 3: case 7: // 亥, 卯, 未
            return 11; // 在 丑
        case 2: case 6: case 10: // 寅, 午, 戌
            return 3; // 在 巳
        default:
            return 0;
    }
}

int calculateTiancai(int mingPalace, int yearBranch) {
    // 规则：从命宫起子(0)，顺数到生年支
    return (mingPalace + yearBranch) % 12;
}

int calculateTianshou(int shenPalace, int yearBranch) {
    // 规则：从身宫起子(0)，顺数到生年支
    return (shenPalace + yearBranch) % 12;
}

// ============================================
// 丙级星 - 月系
// ============================================

int calculateTianyueYue(int lunarMonth) {
    // 规则：正月寅，二月亥，三月辰...
    static const int palaceTable[12] = {0, 9, 2, 7, 4, 1, 6, 11, 8, 5, 10, 3};
    return palaceTable[lunarMonth - 1];
}

int calculateYinsha(int lunarMonth) {
    // 规则：正月寅，二月子，三月戌...
    static const int palaceTable[12] = {0, 10, 8, 6, 4, 2, 0, 10, 8, 6, 4, 2};
    return palaceTable[lunarMonth - 1];
}

// ============================================
// 丙级星 - 日时系
// ============================================

int calculateSantai(int lunarMonth, int lunarDay) {
    // 内部先安左辅
    int zuofuPalace = calculateZuofu(lunarMonth);
    // 再根据左辅安三台
    return (zuofuPalace + lunarDay - 1) % 12;
}

int calculateBazuo(int lunarMonth, int lunarDay) {
    // 内部先安右弼
    int youbiPalace = calculateYoubi(lunarMonth);
    // 再根据右弼安八座
    return (youbiPalace - (lunarDay - 1) + 12 * 30) % 12;
}

int calculateTaifu(int timeBranch) {
    // 内部先安文昌
    int wenchangPalace = calculateWenchang(timeBranch);
    // 再根据文昌安台辅
    return (wenchangPalace + timeBranch) % 12;
}

int calculateFenggao(int timeBranch) {
    // 内部先安文曲
    int wenquPalace = calculateWenqu(timeBranch);
    // 再根据文曲安封诰
    return (wenquPalace + timeBranch) % 12;
}

int calculateTiancai(int lunarMonth, int timeBranch, int yearBranch) {
    // 内部先安命宫
    int mingPalace = calculateMingPalace(lunarMonth, timeBranch);
    // 再根据命宫安天才
    return (mingPalace + yearBranch) % 12;
}

int calculateTianshou(int lunarMonth, int timeBranch, int yearBranch) {
    // 内部存在二级依赖：先安命宫，再安身宫
    int mingPalace = calculateMingPalace(lunarMonth, timeBranch);
    int shenPalace = calculateShenPalace(mingPalace, lunarMonth);
    // 再根据身宫安天寿
    return (shenPalace + yearBranch) % 12;
}