// includes\arrange\1.h
#ifndef PURPCHI_ARRANGE_1_H
#define PURPCHI_ARRANGE_1_H

namespace purpchi {
namespace arrange {

/**
 定命宫位置
 @param lunarMonth 农历月 (1-12)
 @param timeBranch 时支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 @return 命宫位置 (0-11, 寅=0)
*/
int arrangeMingPalace(int lunarMonth, int timeBranch);

/**
 定身宫位置
 @param mingPalace 命宫位置 (0-11)
 @param lunarMonth 农历月 (1-12)
 @return 身宫位置 (0-11)
*/
int arrangeShenPalace(int mingPalace, int lunarMonth);

/**
 定来因宫位置
 @param yearStem 年天干 (0-9: 甲乙丙丁戊己庚辛壬癸)
 @return 来因宫位置 (0-11)
*/
int arrangeLaiyinPalace(int yearLast);

/**
 定五行局
 @param mingPalace 命宫位置 (0-11)
 @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 @return 五行局 (2-6)
*/
int arrangeWuxingJu(int mingPalace, int yearLast);

/**
 定紫微星位置
 @param wuxingJu 五行局 (2-6)
 @param lunarDay 农历日 (1-30)
 @return 紫微星位置 (0-11)
*/
int arrangeZiwei(int wuxingJu, int lunarDay);

/**
 定天机星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 天机星位置 (0-11)
*/
int arrangeTianji(int ziweiPalace);

/**
 定太阳星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 太阳星位置 (0-11)
*/
int arrangeTaiyang(int ziweiPalace);

/**
 定武曲星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 武曲星位置 (0-11)
*/
int arrangeWuqu(int ziweiPalace);

/**
 定天同星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 天同星位置 (0-11)
*/
int arrangeTiantong(int ziweiPalace);

/**
 定廉贞星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 廉贞星位置 (0-11)
*/
int arrangeLianzhen(int ziweiPalace);

// --- 天府星系 (顺时针排布) ---

/**
 定天府星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 天府星位置 (0-11)
*/
int arrangeTianfu(int ziweiPalace);

/**
 定太阴星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 太阴星位置 (0-11)
*/
int arrangeTaiyin(int ziweiPalace);

/**
 定贪狼星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 贪狼星位置 (0-11)
*/
int arrangeTanlang(int ziweiPalace);

/**
 定巨门星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 巨门星位置 (0-11)
*/
int arrangeJumen(int ziweiPalace);

/**
 定天相星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 天相星位置 (0-11)
*/
int arrangeTianxiang(int ziweiPalace);

/**
 定天梁星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 天梁星位置 (0-11)
*/
int arrangeTianliang(int ziweiPalace);

/**
 定七杀星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 七杀星位置 (0-11)
*/
int arrangeQisha(int ziweiPalace);

/**
 定破军星位置
 @param ziweiPalace 紫微星位置 (0-11)
 @return 破军星位置 (0-11)
*/
int arrangePojun(int ziweiPalace);

} // namespace arrange
} // namespace purpchi

#endif // PURPCHI_ARRANGE_1_H