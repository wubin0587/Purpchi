// includes\ziwei\2.h
#ifndef PURPCHI_ZIWEI_2_H
#define PURPCHI_ZIWEI_2_H

namespace purpchi{
namespace arrange{
// ============================================
// 六吉星
// ============================================
/**
 * 定左辅星位置
 * @param lunarMonth 农历月 (1-12)
 * @return 左辅位置 (0-11)
 */
int arrangeZuofu(int lunarMonth);

/**
 * 定右弼星位置
 * @param lunarMonth 农历月 (1-12)
 * @return 右弼位置 (0-11)
 */
int arrangeYoubi(int lunarMonth);

/**
 * 定文昌星位置
 * @param timeBranch 时支 (0-11)
 * @return 文昌位置 (0-11)
 */
int arrangeWenchang(int timeBranch);

/**
 * 定文曲星位置
 * @param timeBranch 时支 (0-11)
 * @return 文曲位置 (0-11)
 */
int arrangeWenqu(int timeBranch);

/**
 * 定天魁星位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 天魁位置 (0-11)
 */
int arrangeTiankui(int yearLast);

/**
 * 定天钺星位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 天钺位置 (0-11)
 */
int arrangeTianyue(int yearLast);

// ============================================
// 禄存
// ============================================

/**
 * 定禄存星位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 禄存位置 (0-11)
 */
int arrangeLucun(int yearLast);

// ============================================
// 六煞星
// ============================================

/**
 * 定擎羊星位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 擎羊位置 (0-11)
 */
int arrangeQingyang(int yearLast);

/**
 * 定陀罗星位置
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 陀罗位置 (0-11)
 */
int arrangeTuoluo(int yearLast);

/**
 * 定火星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @param timeBranch 时支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 火星位置 (0-11)
 */
int arrangeHuoxing(int yearBranch, int timeBranch);

/**
 * 定铃星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @param timeBranch 时支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 铃星位置 (0-11)
 */
int arrangeLingxing(int yearBranch, int timeBranch);

/**
 * 定地空星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 地空位置 (0-11)
 */
int arrangeDikong(int timeBranch);

/**
 * 定地劫星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 地劫位置 (0-11)
 */
int arrangeDijie(int timeBranch);

// ============================================
// 天马
// ============================================

/**
 * 定天马星位置
 * @param yearBranch 年支 (0-11: 寅卯辰巳午未申酉戌亥子丑)
 * @return 天马位置 (0-11)
 */
int arrangeTianma(int yearBranch);

}
}

#endif // PURPCHI_ZIWEI_2_H