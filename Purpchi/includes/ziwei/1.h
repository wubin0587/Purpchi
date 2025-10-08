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

#endif // PURPCHI_ZIWEI_1_H