// includes\ziwei\3.h
#ifndef PURPCHI_ZIWEI_3_H
#define PURPCHI_ZIWEI_3_H

namespace purpchi{
namespace arrange{

// ============================================
// 丙级星 - 年干系
// ============================================

/**
 * 定天官贵人位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 天官位置 (0-11)
 */
int arrangeTianguan(int yearLast);

/**
 * 定天福贵人位置
 * @param yearLast 年份尾数 (0-9)
 * @return 天福位置 (0-11)
 */
int arrangeTianfu(int yearLast);

/**
 * 定天厨位置
 * @param yearLast 年份尾数 (0-9)
 * @return 天厨位置 (0-11)
 */
int arrangeTianchu(int yearLast);

// ============================================
// 丙级星 - 年支系
// ============================================

/**
 * 定红鸾星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 红鸾位置 (0-11)
 */
int arrangeHongluan(int yearBranch);

/**
 * 定天喜星位置
 * @param yearBranch 年支 (0-11)
 * @return 天喜位置 (0-11)
 */
int arrangeTianxi(int yearBranch);

/**
 * 定天刑星位置
 * @param yearBranch 年支 (0-11)
 * @return 天刑位置 (0-11)
 */
int arrangeTianxing(int yearBranch);

/**
 * 定天姚星位置
 * @param yearBranch 年支 (0-11)
 * @return 天姚位置 (0-11)
 */
int arrangeTanyao(int yearBranch);

/**
 * 定解神位置
 * @param yearBranch 年支 (0-11)
 * @return 解神位置 (0-11)
 */
int arrangeJieshen(int yearBranch);

/**
 * 定龙池位置
 * @param yearBranch 年支 (0-11)
 * @return 龙池位置 (0-11)
 */
int arrangeLongchi(int yearBranch);

/**
 * 定凤阁位置
 * @param yearBranch 年支 (0-11)
 * @return 凤阁位置 (0-11)
 */
int arrangeFengge(int yearBranch);

/**
 * 定孤辰星位置
 * @param yearBranch 年支 (0-11)
 * @return 孤辰位置 (0-11)
 */
int arrangeGuchen(int yearBranch);

/**
 * 定寡宿星位置
 * @param yearBranch 年支 (0-11)
 * @return 寡宿位置 (0-11)
 */
int arrangeGuasu(int yearBranch);

/**
 * 定蜚廉位置
 * @param yearBranch 年支 (0-11)
 * @return 蜚廉位置 (0-11)
 */
int arrangeFeilian(int yearBranch);

/**
 * 定破碎位置
 * @param yearBranch 年支 (0-11)
 * @return 破碎位置 (0-11)
 */
int arrangePosui(int yearBranch);

/**
 * 定天才位置
 * 规则：安命宫，由年支起子，顺数至本命年支安之
 * @param mingPalace 命宫位置 (0-11)
 * @param yearBranch 年支 (0-11)
 * @return 天才位置 (0-11)
 */
int arrangeTiancai(int mingPalace, int yearBranch);

/**
 * 定天寿位置
 * 规则：安身宫，由年支起子，顺数至本命年支安之
 * @param shenPalace 身宫位置 (0-11)
 * @param yearBranch 年支 (0-11)
 * @return 天寿位置 (0-11)
 */
int arrangeTianshou(int shenPalace, int yearBranch);


// ============================================
// 丙级星 - 月系
// ============================================

/**
 * 定天月位置
 * @param lunarMonth 农历月 (1-12)
 * @return 天月位置 (0-11)
 */
int arrangeTianyueYue(int lunarMonth);

/**
 * 定阴煞位置
 * @param lunarMonth 农历月 (1-12)
 * @return 阴煞位置 (0-11)
 */
int arrangeYinsha(int lunarMonth);

/**
 * 定三台位置
 * 规则：由左辅起初一，顺数至生日止。
 * @param lunarMonth 农历月 (1-12)，用于安左辅星。
 * @param lunarDay 农历日 (1-30)
 * @return 三台位置 (0-11)
 */
int arrangeSantai(int lunarMonth, int lunarDay);

/**
 * 定八座位置
 * 规则：由右弼起初一，逆数至生日止。
 * @param lunarMonth 农历月 (1-12)，用于安右弼星。
 * @param lunarDay 农历日 (1-30)
 * @return 八座位置 (0-11)
 */
int arrangeBazuo(int lunarMonth, int lunarDay);

/**
 * 定台辅位置
 * 规则：由文昌起子时，顺数至生时安之。
 * @param timeBranch 时支 (0-11, 子=0)，用于安文昌星和台辅星。
 * @return 台辅位置 (0-11)
 */
int arrangeTaifu(int timeBranch);

/**
 * 定封诰位置
 * 规则：由文曲起子时，顺数至生时安之。
 * @param timeBranch 时支 (0-11, 子=0)，用于安文曲星和封诰星。
 * @return 封诰位置 (0-11)
 */
int arrangeFenggao(int timeBranch);

/**
 * 定天才位置
 * 规则：安命宫，由年支起子，顺数至本命年支安之
 * @param lunarMonth 农历月 (1-12)，用于安命宫。
 * @param timeBranch 时支 (0-11, 子=0)，用于安命宫。
 * @param yearBranch 年支 (0-11, 子=0)
 * @return 天才位置 (0-11)
 */
int arrangeTiancai(int lunarMonth, int timeBranch, int yearBranch);

/**
 * 定天寿位置
 * 规则：安身宫，由年支起子，顺数至本命年支安之
 * @param lunarMonth 农历月 (1-12)，用于安命宫和身宫。
 * @param timeBranch 时支 (0-11, 子=0)，用于安命宫。
 * @param yearBranch 年支 (0-11, 子=0)
 * @return 天寿位置 (0-11)
 */
int arrangeTianshou(int lunarMonth, int timeBranch, int yearBranch);

}
}

#endif // PURPCHI_ZIWEI_3_H