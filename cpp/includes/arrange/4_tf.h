#ifndef PURPCHI_ZIWEI_4_TF_H
#define PURPCHI_ZIWEI_4_TF_H

#include "ziwei/1.h"
#include "ziwei/2.h"

namespace purpchi{
namespace arrange{

/**
 * @brief 计算化禄星的位置
 * 
 * @param yearLast 年份尾数 (0-9, 对应 0-庚, 1-辛, ..., 4-甲, ...)
 * @param ziweiPalace 紫微星的位置 (0-11)
 * @return 化禄星所在的位置 (0-11)，若无效则返回 -1
 */
int arrangeHuaLu(int yearLast, int ziweiPalace);

/**
 * @brief 计算化权星的位置
 * 
 * @param yearLast 年份尾数 (0-9, 对应 0-庚, 1-辛, ..., 4-甲, ...)
 * @param ziweiPalace 紫微星的位置 (0-11)
 * @return 化权星所在的位置 (0-11)，若无效则返回 -1
 */
int arrangeHuaQuan(int yearLast, int ziweiPalace);

/**
 * @brief 计算化科星的位置
 * 
 * @param yearLast 年份尾数 (0-9, 对应 0-庚, 1-辛, ..., 4-甲, ...)
 * @param ziweiPalace 紫微星的位置 (0-11)
 * @param lunarMonth 农历月 (1-12)，用于计算左辅右弼
 * @param timeBranch 时支 (0-11)，用于计算文昌文曲
 * @return 化科星所在的位置 (0-11)，若无效则返回 -1
 */
int arrangeHuaKe(int yearLast, int ziweiPalace, int lunarMonth, int timeBranch);

/**
 * @brief 计算化忌星的位置
 * 
 * @param yearLast 年份尾数 (0-9, 对应 0-庚, 1-辛, ..., 4-甲, ...)
 * @param ziweiPalace 紫微星的位置 (0-11)
 * @param timeBranch 时支 (0-11)，用于计算文昌文曲
 * @return 化忌星所在的位置 (0-11)，若无效则返回 -1
 */
int arrangeHuaJi(int yearLast, int ziweiPalace, int timeBranch);

}
}

#endif // PURPCHI_ZIWEI_4_TF_H