#include "ziwei/arrangeChart.h"
#include <cstring>

// ======================================================================
// 辅助函数 (Helper Functions)
// ======================================================================

/**
 * @brief (静态辅助函数) 计算甲/乙级星的位置、获取其庙旺并放入图表。
 * @param chart 要修改的星盘矩阵
 * @param starId 要安放的星曜ID
 * @param starPalace 该星曜计算出的位置
 */
static void placeStarA(int** chart, StarA starId, int starPalace) {
    chart[starId][starPalace] = getStarABrightness(starId, starPalace);
}

/**
 * @brief (静态辅助函数) 计算丙级星的位置、获取其庙旺并放入图表。
 * @param chart 要修改的星盘矩阵
 * @param starId 要安放的星曜ID
 * @param starPalace 该星曜计算出的位置
 */
static void placeStarC(int** chart, StarC starId, int starPalace) {
    chart[starId][starPalace] = getStarCBrightness(starId, starPalace);
}


// ======================================================================
// 主排盘函数 (Main Arrangement Functions)
// ======================================================================

/**
 * @brief 排列甲级和乙级星曜，并将庙旺等级存入矩阵。
 */
int** arrangeGradeAStars(
    int lunarMonth, int lunarDay, int timeBranch, int yearLast, int yearBranch) 
{
    // 0. 动态分配并初始化二维数组
    const int NUM_PALACES = 12;
    int** chart = new int*[A_STARS_COUNT];
    for (int i = 0; i < A_STARS_COUNT; ++i) {
        chart[i] = new int[NUM_PALACES];
        memset(chart[i], 0, NUM_PALACES * sizeof(int));
    }

    // 1. 基础计算
    int mingPalace = calculateMingPalace(lunarMonth, timeBranch);
    int wuxingJu = calculateWuxingJu(mingPalace, yearLast);
    int ziweiPalace = calculateZiwei(wuxingJu, lunarDay);

    // 2. 使用辅助函数安放星曜
    //    现在，每一行都直接调用 placeStarA，将计算函数的结果作为参数传入。
    
    // --- 14 主星 (甲级) ---
    placeStarA(chart, A_ZIWEI,     ziweiPalace);
    placeStarA(chart, A_TIANJI,    calculateTianji(ziweiPalace));
    placeStarA(chart, A_TAIYANG,   calculateTaiyang(ziweiPalace));
    placeStarA(chart, A_WUQU,      calculateWuqu(ziweiPalace));
    placeStarA(chart, A_TIANTONG,  calculateTiantong(ziweiPalace));
    placeStarA(chart, A_LIANZHEN,  calculateLianzhen(ziweiPalace));
    placeStarA(chart, A_TIANFU,    calculateTianfu(ziweiPalace));
    placeStarA(chart, A_TAIYIN,    calculateTaiyin(ziweiPalace));
    placeStarA(chart, A_TANLANG,   calculateTanlang(ziweiPalace));
    placeStarA(chart, A_JUMEN,     calculateJumen(ziweiPalace));
    placeStarA(chart, A_TIANXIANG, calculateTianxiang(ziweiPalace));
    placeStarA(chart, A_TIANLIANG, calculateTianliang(ziweiPalace));
    placeStarA(chart, A_QISHA,     calculateQisha(ziweiPalace));
    placeStarA(chart, A_POJUN,     calculatePojun(ziweiPalace));

    // --- 六吉星 (甲级/乙级) ---
    placeStarA(chart, A_ZUOFU,     calculateZuofu(lunarMonth));
    placeStarA(chart, A_YOUBI,     calculateYoubi(lunarMonth));
    placeStarA(chart, A_WENCHANG,  calculateWenchang(timeBranch));
    placeStarA(chart, A_WENQU,     calculateWenqu(timeBranch));
    placeStarA(chart, A_TIANKUI,   calculateTiankui(yearLast));
    placeStarA(chart, A_TIANYUE,   calculateTianyue(yearLast));

    // --- 禄存、天马 (甲级/乙级) ---
    placeStarA(chart, A_LUCUN,     calculateLucun(yearLast));
    placeStarA(chart, A_TIANMA,    calculateTianma(yearBranch));

    // --- 六煞星 (甲级/乙级) ---
    placeStarA(chart, A_QINGYANG,  calculateQingyang(yearLast));
    placeStarA(chart, A_TUOLUO,    calculateTuoluo(yearLast));
    placeStarA(chart, A_HUOXING,   calculateHuoxing(yearBranch, timeBranch));
    placeStarA(chart, A_LINGXING,  calculateLingxing(yearBranch, timeBranch));
    placeStarA(chart, A_DIKONG,    calculateDikong(timeBranch));
    placeStarA(chart, A_DIJIE,     calculateDijie(timeBranch));

    return chart;
}

/**
 * @brief 排列丙级星曜，并将庙旺等级存入矩阵。
 */
int** arrangeGradeCStars(
    int lunarMonth, int lunarDay, int timeBranch, int yearLast, int yearBranch)
{
    // 0. 动态分配并初始化二维数组
    const int NUM_PALACES = 12;
    int** chart = new int*[C_STARS_COUNT];
    for (int i = 0; i < C_STARS_COUNT; ++i) {
        chart[i] = new int[NUM_PALACES];
        memset(chart[i], 0, NUM_PALACES * sizeof(int));
    }

    // 1. 基础计算
    int mingPalace = calculateMingPalace(lunarMonth, timeBranch);
    int shenPalace = calculateShenPalace(mingPalace, lunarMonth);

    // 2. 使用辅助函数安放星曜
    // --- 年干系 ---
    placeStarC(chart, C_TIANGUAN,       calculateTianguan(yearLast));
    placeStarC(chart, C_TIANFU_GUIREN,  calculateTianfu(yearLast));
    placeStarC(chart, C_TIANCHU,        calculateTianchu(yearLast));

    // --- 年支系 ---
    placeStarC(chart, C_HONGLUAN,       calculateHongluan(yearBranch));
    placeStarC(chart, C_TIANXI,         calculateTianxi(yearBranch));
    placeStarC(chart, C_TIANXING,       calculateTianxing(yearBranch));
    placeStarC(chart, C_TIANYAO,        calculateTanyao(yearBranch));
    placeStarC(chart, C_JIESHEN,        calculateJieshen(yearBranch));
    placeStarC(chart, C_LONGCHI,        calculateLongchi(yearBranch));
    placeStarC(chart, C_FENGGE,         calculateFengge(yearBranch));
    placeStarC(chart, C_GUCHEN,         calculateGuchen(yearBranch));
    placeStarC(chart, C_GUASU,          calculateGuasu(yearBranch));
    placeStarC(chart, C_FEILIAN,        calculateFeilian(yearBranch));
    placeStarC(chart, C_POSUI,          calculatePosui(yearBranch));
    placeStarC(chart, C_TIANCAI,        calculateTiancai(mingPalace, yearBranch));

    placeStarC(chart, C_TIANSHOU,       calculateTianshou(shenPalace, yearBranch));

    // --- 月日时系 ---
    placeStarC(chart, C_TIANYUE_YUE,    calculateTianyueYue(lunarMonth));
    placeStarC(chart, C_YINSHA,         calculateYinsha(lunarMonth));
    placeStarC(chart, C_SANTAI,         calculateSantai(lunarMonth, lunarDay));
    placeStarC(chart, C_BAZUO,          calculateBazuo(lunarMonth, lunarDay));
    placeStarC(chart, C_TAIFU,          calculateTaifu(timeBranch));
    placeStarC(chart, C_FENGGAO,        calculateFenggao(timeBranch));

    return chart;
}