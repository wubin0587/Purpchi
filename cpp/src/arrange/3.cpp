// src\ziwei\3.cpp
#include "ziwei/3.h"
#include "ziwei/1.h" // 引入 1.h 以调用命宫、身宫等函数
#include "ziwei/2.h" // 引入 2.h 以调用左辅、右弼、文昌、文曲等函数

namespace purpchi{
namespace arrange{

// 宫位约定: 寅0, 卯1, 辰2, 巳3, 午4, 未5, 申6, 酉7, 戌8, 亥9, 子10, 丑11
// 地支约定: 子0, 丑1, 寅2, 卯3, 辰4, 巳5, 午6, 未7, 申8, 酉9, 戌10, 亥11
// 天干约定: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己

// ============================================
// 丙级星 - 年干系
// ============================================

int arrangeTianguan(int yearLast) {
    // 规则：甲喜羊(未), 乙龙(辰), 丙蛇(巳), 丁虎(寅), 戊兔(卯), 己鸡(酉), 庚猪(亥), 辛鸡(酉), 壬犬(戌), 癸马(午)
    static const int palaceTable[10] = {9, 7, 8, 4, 5, 2, 3, 0, 1, 7}; // 庚,辛,壬,癸,甲,乙,丙,丁,戊,己
    return palaceTable[yearLast];
}

int arrangeTianfu(int yearLast) {
    // 规则：甲鸡(酉), 乙猴(申), 丙鼠(子), 丁猪(亥), 戊兔(卯), 己虎(寅), 庚马(午), 辛蛇(巳), 壬马(午), 癸蛇(巳)
    static const int palaceTable[10] = {4, 3, 4, 3, 7, 6, 10, 9, 1, 0}; // 庚,辛,壬,癸,甲,乙,丙,丁,戊,己 -> 此实现经验证正确
    return palaceTable[yearLast];
}

int arrangeTianchu(int yearLast) {
    // 规则：甲丁食蛇口(巳), 乙戊辛马方(午), 丙从鼠口得(子), 己食于猴房(申), 庚食虎头上(寅), 壬鸡(酉), 癸猪堂(亥)
    switch(yearLast) {
        case 4: case 7: return 3;  // 甲, 丁 -> 巳
        case 5: case 8: case 1: return 4;  // 乙, 戊, 辛 -> 午
        case 6: return 10; // 丙 -> 子
        case 9: return 6;  // 己 -> 申
        case 0: return 0;  // 庚 -> 寅
        case 2: return 7;  // 壬 -> 酉
        case 3: return 9;  // 癸 -> 亥
        default: return 0;
    }
}

int arrangeJieluKongwang(int yearLast) {
    // 规则: 甲己之年申酉, 乙庚之年午未, 丙辛之年辰巳, 丁壬之年寅卯, 戊癸之年子丑 (安第一位)
    switch(yearLast) {
        case 4: case 9: return 6;  // 甲, 己 -> 申
        case 5: case 0: return 4;  // 乙, 庚 -> 午
        case 6: case 1: return 2;  // 丙, 辛 -> 辰
        case 7: case 2: return 0;  // 丁, 壬 -> 寅
        case 8: case 3: return 10; // 戊, 癸 -> 子
        default: return 0;
    }
}

// ============================================
// 丙级星 - 年支系
// ============================================

int arrangeHongluan(int yearBranch) {
    // 规则：从卯宫(1)起子(0)，逆数到生年支
    const int maoPalace = 1;
    return (maoPalace - yearBranch + 12) % 12;
}

int arrangeTianxi(int yearBranch) {
    // 规则：从酉宫(7)起子(0)，顺数到生年支
    const int youPalace = 7;
    return (youPalace + yearBranch) % 12;
}

int arrangeJieshen(int yearBranch) {
    // 规则: 年解, 从戌(8)上起子(0)，逆数至当生年太岁
    const int xuPalace = 8;
    return (xuPalace - yearBranch + 12) % 12;
}

int arrangeLongchi(int yearBranch) {
    // 规则：从辰宫(2)起子(0)，顺数到生年支
    const int chenPalace = 2;
    return (chenPalace + yearBranch) % 12;
}

int arrangeFengge(int yearBranch) {
    // 规则：从戌宫(8)起子(0)，逆数到生年支
    const int xuPalace = 8;
    return (xuPalace - yearBranch + 12) % 12;
}

int arrangeGuchen(int yearBranch) {
    // 规则：亥(11)子(0)丑(1)年在寅(0), 寅(2)卯(3)辰(4)年在巳(3)...
    if (yearBranch <= 1 || yearBranch == 11) return 0; // 亥子丑 -> 寅
    if (yearBranch <= 4) return 3; // 寅卯辰 -> 巳
    if (yearBranch <= 7) return 6; // 巳午未 -> 申
    return 9; // 申酉戌 -> 亥
}

int arrangeGuasu(int yearBranch) {
    // 规则：亥(11)子(0)丑(1)年在戌(8), 寅(2)卯(3)辰(4)年在丑(11)...
    if (yearBranch <= 1 || yearBranch == 11) return 8; // 亥子丑 -> 戌
    if (yearBranch <= 4) return 11; // 寅卯辰 -> 丑
    if (yearBranch <= 7) return 2; // 巳午未 -> 辰
    return 5; // 申酉戌 -> 未
}

int arrangeFeilian(int yearBranch) {
    // 按通用规则实现
    static const int palaceTable[12] = {6, 7, 8, 3, 4, 5, 0, 1, 2, 9, 10, 11}; // 子->申, 丑->酉...
    return palaceTable[yearBranch];
}

int arrangePosui(int yearBranch) {
    // 规则：子午卯酉年安巳宫, 寅申巳亥年安酉宫, 辰戍丑未年安丑宫
    switch (yearBranch) {
        case 0: case 6: case 3: case 9:  // 子, 午, 卯, 酉
            return 3; // 在 巳
        case 2: case 8: case 5: case 11: // 寅, 申, 巳, 亥
            return 7; // 在 酉
        case 4: case 10: case 1: case 7: // 辰, 戌, 丑, 未
            return 11; // 在 丑
        default:
            return 0;
    }
}

int arrangeHuagai(int yearBranch) {
    // 规则: 子辰申年在辰, 丑巳酉年在丑, 寅午戍年在戍, 卯未亥年在未
    switch (yearBranch) {
        case 0: case 4: case 8:  // 子, 辰, 申
            return 2; // 在 辰
        case 1: case 5: case 9: // 丑, 巳, 酉
            return 11; // 在 丑
        case 2: case 6: case 10: // 寅, 午, 戌
            return 8; // 在 戌
        case 3: case 7: case 11: // 卯, 未, 亥
            return 5; // 在 未
        default:
            return 0;
    }
}

int arrangeXianchi(int yearBranch) {
    // 规则: 子辰申年在酉, 丑巳酉年在午, 寅午戍年在卯, 卯未亥年在子
    switch (yearBranch) {
        case 0: case 4: case 8:  // 子, 辰, 申
            return 7; // 在 酉
        case 1: case 5: case 9: // 丑, 巳, 酉
            return 4; // 在 午
        case 2: case 6: case 10: // 寅, 午, 戌
            return 1; // 在 卯
        case 3: case 7: case 11: // 卯, 未, 亥
            return 10; // 在 子
        default:
            return 0;
    }
}

int arrangeTiankong(int yearBranch) {
    // 规则：生年支顺数的前一位就是 (即地支序数减一)
    return (yearBranch - 1 + 12) % 12;
}

int arrangeTianku(int yearBranch) {
    // 规则：午宫(4)起子(0), 逆行到生年
    const int wuPalace = 4;
    return (wuPalace - yearBranch + 12) % 12;
}

int arrangeTianxu(int yearBranch) {
    // 规则：午宫(4)起子(0), 顺行到生年
    const int wuPalace = 4;
    return (wuPalace + yearBranch) % 12;
}

int arrangeTiancai(int mingPalace, int yearBranch) {
    // 规则：从命宫起子(0)，顺数到生年支
    return (mingPalace + yearBranch) % 12;
}

int arrangeTianshou(int shenPalace, int yearBranch) {
    // 规则：从身宫起子(0)，顺数到生年支
    return (shenPalace + yearBranch) % 12;
}

// ============================================
// 丙级星 - 月系
// ============================================

int arrangeTianxing(int lunarMonth) {
    // 规则：天刑从酉(7)起正月，顺至生月
    const int youPalace = 7;
    return (youPalace + lunarMonth - 1) % 12;
}

int arrangeTanyao(int lunarMonth) {
    // 规则：天姚丑(11)宫起正月, 顺到生月
    const int chouPalace = 11;
    return (chouPalace + lunarMonth - 1) % 12;
}

int arrangeYuejie(int lunarMonth) {
    // 规则：正二在申, 三四在戍, 五六在子, 七八在寅, 九十在辰, 十一十二在午
    if (lunarMonth <= 2) return 6;  // 申
    if (lunarMonth <= 4) return 8;  // 戌
    if (lunarMonth <= 6) return 10; // 子
    if (lunarMonth <= 8) return 0;  // 寅
    if (lunarMonth <= 10) return 2; // 辰
    return 4; // 午
}

int arrangeTianwu(int lunarMonth) {
    // 规则: 正五九月在巳, 二六十月在申, 三七十一在寅, 四八十二在亥
    switch (lunarMonth) {
        case 1: case 5: case 9: return 3;  // 巳
        case 2: case 6: case 10: return 6; // 申
        case 3: case 7: case 11: return 0; // 寅
        case 4: case 8: case 12: return 9; // 亥
        default: return 0;
    }
}

int arrangeTianyue(int lunarMonth) {
    // 规则：一犬(戌)二蛇(巳)三在龙(辰), 四虎(寅)五羊(未)六兔(卯), 七猪(亥)八羊(未)九在虎(寅), 十马(午)冬(十一)犬(戌)腊(十二)寅(寅)中
    static const int palaceTable[12] = {8, 3, 2, 0, 5, 1, 9, 5, 0, 4, 8, 0}; // 月份-1为索引
    return palaceTable[lunarMonth - 1];
}

int arrangeYinsha(int lunarMonth) {
    // 规则：正七月在寅，二八月在子，三九月在戍...
    static const int palaceTable[12] = {0, 10, 8, 6, 4, 2, 0, 10, 8, 6, 4, 2}; // 月份-1为索引
    return palaceTable[lunarMonth - 1];
}

// ============================================
// 丙级星 - 日时系
// ============================================

int arrangeSantai(int lunarMonth, int lunarDay) {
    // 内部先安左辅
    int zuofuPalace = arrangeZuofu(lunarMonth);
    // 规则：由左辅起初一，顺数至生日止。
    return (zuofuPalace + lunarDay - 1) % 12;
}

int arrangeBazuo(int lunarMonth, int lunarDay) {
    // 内部先安右弼
    int youbiPalace = arrangeYoubi(lunarMonth);
    // 规则：由右弼起初一，逆数至生日止。
    return (youbiPalace - (lunarDay - 1) + 12 * 30) % 12; // + 12*30 避免负数
}

int arrangeEnguang(int timeBranch, int lunarDay) {
    // 内部先安文昌
    int wenchangPalace = arrangeWenchang(timeBranch);
    // 规则: 由文昌之宫位起初一, 顺行至生日再退一步
    return (wenchangPalace + lunarDay - 2 + 12) % 12;
}

int arrangeTiangui(int timeBranch, int lunarDay) {
    // 内部先安文曲
    int wenquPalace = arrangeWenqu(timeBranch);
    // 规则: 由文曲之宫位起初一, 顺行至生日再退一步
    return (wenquPalace + lunarDay - 2 + 12) % 12;
}

int arrangeTaifu(int timeBranch) {
    // 规则：台辅午(4)起子(0)顺到时
    const int wuPalace = 4;
    return (wuPalace + timeBranch) % 12;
}

int arrangeFenggao(int timeBranch) {
    // 规则：封诰寅(0)宫起子(0)逆到时
    const int yinPalace = 0;
    return (yinPalace - timeBranch + 12) % 12;
}

// ============================================
// Helper Overloads
// ============================================

int arrangeTiancai(int lunarMonth, int timeBranch, int yearBranch) {
    // 内部先安命宫
    int mingPalace = arrangeMingPalace(lunarMonth, timeBranch);
    // 再根据命宫安天才
    return arrangeTiancai(mingPalace, yearBranch);
}

int arrangeTianshou(int lunarMonth, int timeBranch, int yearBranch) {
    // 内部存在二级依赖：先安命宫，再安身宫
    int mingPalace = arrangeMingPalace(lunarMonth, timeBranch);
    int shenPalace = arrangeShenPalace(mingPalace, lunarMonth);
    // 再根据身宫安天寿
    return arrangeTianshou(shenPalace, yearBranch);
}

}
}