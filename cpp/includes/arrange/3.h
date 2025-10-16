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
 * 规则：甲羊乙龙丙蛇...
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 天官位置 (0-11, 寅-丑)
 */
int arrangeTianguan(int yearLast);

/**
 * 定天福贵人位置
 * 规则：甲鸡乙猴丙鼠...
 * @param yearLast 年份尾数 (0-9)
 * @return 天福位置 (0-11, 寅-丑)
 */
int arrangeTianfu(int yearLast);

/**
 * 定天厨位置
 * 规则：甲丁食蛇口...
 * @param yearLast 年份尾数 (0-9)
 * @return 天厨位置 (0-11, 寅-丑)
 */
int arrangeTianchu(int yearLast);

/**
 * 定截路空亡位置 (安第一位)
 * 规则：甲己申酉, 乙庚午未...
 * @param yearLast 年份尾数 (0-9)
 * @return 截路空亡位置 (0-11, 寅-丑)
 */
int arrangeJieluKongwang(int yearLast);


// ============================================
// 丙级星 - 年支系
// ============================================

/**
 * 定红鸾星位置
 * 规则：卯上起子逆数到生年支
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 红鸾位置 (0-11, 寅-丑)
 */
int arrangeHongluan(int yearBranch);

/**
 * 定天喜星位置
 * 规则：红鸾对宫
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天喜位置 (0-11, 寅-丑)
 */
int arrangeTianxi(int yearBranch);

/**
 * 定解神(年解)位置
 * 规则：从戌上起子, 逆数至生年支
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 解神位置 (0-11, 寅-丑)
 */
int arrangeJieshen(int yearBranch);

/**
 * 定龙池位置
 * 规则：从辰宫起子, 顺至本生年支
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 龙池位置 (0-11, 寅-丑)
 */
int arrangeLongchi(int yearBranch);

/**
 * 定凤阁位置
 * 规则：从戍宫起子, 逆行至本生年支
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 凤阁位置 (0-11, 寅-丑)
 */
int arrangeFengge(int yearBranch);

/**
 * 定孤辰星位置
 * 规则：寅卯辰年安巳丑...
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 孤辰位置 (0-11, 寅-丑)
 */
int arrangeGuchen(int yearBranch);

/**
 * 定寡宿星位置
 * 规则：寅卯辰年安巳丑...
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 寡宿位置 (0-11, 寅-丑)
 */
int arrangeGuasu(int yearBranch);

/**
 * 定蜚廉位置
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 蜚廉位置 (0-11, 寅-丑)
 */
int arrangeFeilian(int yearBranch);

/**
 * 定破碎位置
 * 规则：子午卯酉年安巳宫...
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 破碎位置 (0-11, 寅-丑)
 */
int arrangePosui(int yearBranch);

/**
 * 定华盖位置
 * 规则：子辰申年在辰...
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 华盖位置 (0-11, 寅-丑)
 */
int arrangeHuagai(int yearBranch);

/**
 * 定咸池(桃花)位置
 * 规则：子辰申年在酉...
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 咸池位置 (0-11, 寅-丑)
 */
int arrangeXianchi(int yearBranch);

/**
 * 定天空位置
 * 规则：生年支顺数的前一位
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天空位置 (0-11, 寅-丑)
 */
int arrangeTiankong(int yearBranch);

/**
 * 定天哭位置
 * 规则：午宫起子, 逆行到生年
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天哭位置 (0-11, 寅-丑)
 */
int arrangeTianku(int yearBranch);

/**
 * 定天虚位置
 * 规则：午宫起子, 顺行到生年
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天虚位置 (0-11, 寅-丑)
 */
int arrangeTianxu(int yearBranch);

/**
 * 定天才位置
 * 规则：由命宫起子, 顺行至本生年支
 * @param mingPalace 命宫位置 (0-11)
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天才位置 (0-11, 寅-丑)
 */
int arrangeTiancai(int mingPalace, int yearBranch);

/**
 * 定天寿位置
 * 规则：由身宫起子, 顺行至本生年支
 * @param shenPalace 身宫位置 (0-11)
 * @param yearBranch 年支 (0-11: 子-亥)
 * @return 天寿位置 (0-11, 寅-丑)
 */
int arrangeTianshou(int shenPalace, int yearBranch);


// ============================================
// 丙级星 - 月系
// ============================================

/**
 * 定天刑位置
 * 规则：天刑从酉起正月, 顺至生月
 * @param lunarMonth 农历月 (1-12)
 * @return 天刑位置 (0-11, 寅-丑)
 */
int arrangeTianxing(int lunarMonth);

/**
 * 定天姚位置
 * 规则：天姚丑宫起正月, 顺到生月
 * @param lunarMonth 农历月 (1-12)
 * @return 天姚位置 (0-11, 寅-丑)
 */
int arrangeTanyao(int lunarMonth);

/**
 * 定月解位置
 * 规则：正二在申三四在戍...
 * @param lunarMonth 农历月 (1-12)
 * @return 月解位置 (0-11, 寅-丑)
 */
int arrangeYuejie(int lunarMonth);

/**
 * 定天巫位置
 * 规则：正五九月在巳...
 * @param lunarMonth 农历月 (1-12)
 * @return 天巫位置 (0-11, 寅-丑)
 */
int arrangeTianwu(int lunarMonth);

/**
 * 定天月位置
 * 规则：一犬二蛇三在龙...
 * @param lunarMonth 农历月 (1-12)
 * @return 天月位置 (0-11, 寅-丑)
 */
int arrangeTianyue(int lunarMonth);

/**
 * 定阴煞位置
 * 规则：正七月在寅, 二八月在子...
 * @param lunarMonth 农历月 (1-12)
 * @return 阴煞位置 (0-11, 寅-丑)
 */
int arrangeYinsha(int lunarMonth);

// ============================================
// 丙级星 - 日时系
// ============================================

/**
 * 定三台位置
 * 规则：由左辅之宫位起初一, 顺行至生日
 * @param lunarMonth 农历月 (1-12)，用于安左辅星。
 * @param lunarDay 农历日 (1-30)
 * @return 三台位置 (0-11, 寅-丑)
 */
int arrangeSantai(int lunarMonth, int lunarDay);

/**
 * 定八座位置
 * 规则：由右弼之宫位起初一, 逆行至生日
 * @param lunarMonth 农历月 (1-12)，用于安右弼星。
 * @param lunarDay 农历日 (1-30)
 * @return 八座位置 (0-11, 寅-丑)
 */
int arrangeBazuo(int lunarMonth, int lunarDay);

/**
 * 定恩光位置
 * 规则：由文昌之宫位起初一, 顺行至生日再退一步
 * @param timeBranch 时支 (0-11, 子-亥)
 * @param lunarDay 农历日 (1-30)
 * @return 恩光位置 (0-11, 寅-丑)
 */
int arrangeEnguang(int timeBranch, int lunarDay);

/**
 * 定天贵位置
 * 规则：由文曲之宫位起初一, 顺行至生日再退一步
 * @param timeBranch 时支 (0-11, 子-亥)
 * @param lunarDay 农历日 (1-30)
 * @return 天贵位置 (0-11, 寅-丑)
 */
int arrangeTiangui(int timeBranch, int lunarDay);

/**
 * 定台辅位置
 * 规则：午起子顺到时
 * @param timeBranch 时支 (0-11, 子-亥)
 * @return 台辅位置 (0-11, 寅-丑)
 */
int arrangeTaifu(int timeBranch);

/**
 * 定封诰位置
 * 规则：寅宫起子逆到时
 * @param timeBranch 时支 (0-11, 子-亥)
 * @return 封诰位置 (0-11, 寅-丑)
 */
int arrangeFenggao(int timeBranch);

// ============================================
// Helper Overloads
// ============================================

/**
 * 定天才位置 (重载)
 * @param lunarMonth 农历月 (1-12)，用于安命宫。
 * @param timeBranch 时支 (0-11, 子-亥)，用于安命宫。
 * @param yearBranch 年支 (0-11, 子-亥)
 * @return 天才位置 (0-11, 寅-丑)
 */
int arrangeTiancai(int lunarMonth, int timeBranch, int yearBranch);

/**
 * 定天寿位置 (重载)
 * @param lunarMonth 农历月 (1-12)，用于安命宫和身宫。
 * @param timeBranch 时支 (0-11, 子-亥)，用于安命宫。
 * @param yearBranch 年支 (0-11, 子-亥)
 * @return 天寿位置 (0-11, 寅-丑)
 */
int arrangeTianshou(int lunarMonth, int timeBranch, int yearBranch);

}
}

#endif // PURPCHI_ZIWEI_3_H