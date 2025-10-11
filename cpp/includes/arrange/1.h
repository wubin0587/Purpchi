// includes\ziwei\1.h
#ifndef PURPCHI_ZIWEI_1_H
#define PURPCHI_ZIWEI_1_H

/**
 * 定命宫位置
 * @param lunarMonth 农历月 (1-12)
 * @param timeBranch 时支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 命宫位置 (0-11, 寅=0)
 */
int calculateMingPalace(int lunarMonth, int timeBranch);

/**
 * 定身宫位置
 * @param mingPalace 命宫位置 (0-11)
 * @param lunarMonth 农历月 (1-12)
 * @return 身宫位置 (0-11)
 */
int calculateShenPalace(int mingPalace, int lunarMonth);

/**
 * 定五行局
 * @param mingPalace 命宫位置 (0-11)
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 五行局 (2-6)
 */
int calculateWuxingJu(int mingPalace, int yearLast);

/**
 * 定紫微星位置
 * @param wuxingJu 五行局 (2-6)
 * @param lunarDay 农历日 (1-30)
 * @return 紫微星位置 (0-11)
 */
int calculateZiwei(int wuxingJu, int lunarDay);

/**
 * 定天机星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 天机星位置 (0-11)
 */
int calculateTianji(int ziweiPalace);

/**
 * 定太阳星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 太阳星位置 (0-11)
 */
int calculateTaiyang(int ziweiPalace);

/**
 * 定武曲星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 武曲星位置 (0-11)
 */
int calculateWuqu(int ziweiPalace);

/**
 * 定天同星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 天同星位置 (0-11)
 */
int calculateTiantong(int ziweiPalace);

/**
 * 定廉贞星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 廉贞星位置 (0-11)
 */
int calculateLianzhen(int ziweiPalace);


// --- 天府星系 (顺时针排布) ---

/**
 * 定天府星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 天府星位置 (0-11)
 */
int calculateTianfu(int ziweiPalace);

/**
 * 定太阴星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 太阴星位置 (0-11)
 */
int calculateTaiyin(int ziweiPalace);

/**
 * 定贪狼星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 贪狼星位置 (0-11)
 */
int calculateTanlang(int ziweiPalace);

/**
 * 定巨门星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 巨门星位置 (0-11)
 */
int calculateJumen(int ziweiPalace);

/**
 * 定天相星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 天相星位置 (0-11)
 */
int calculateTianxiang(int ziweiPalace);

/**
 * 定天梁星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 天梁星位置 (0-11)
 */
int calculateTianliang(int ziweiPalace);

/**
 * 定七杀星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 七杀星位置 (0-11)
 */
int calculateQisha(int ziweiPalace);

/**
 * 定破军星位置
 * @param ziweiPalace 紫微星位置 (0-11)
 * @return 破军星位置 (0-11)
 */
int calculatePojun(int ziweiPalace);

#endif // PURPCHI_ZIWEI_1_H