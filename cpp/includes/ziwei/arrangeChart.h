#ifndef PURPCHI_ZIWEI_ARRANGE_CHART_H
#define PURPCHI_ZIWEI_ARRANGE_CHART_H

// 包含所有依赖的计算头文件
#include "ziwei/1.h"
#include "ziwei/2.h"
#include "ziwei/3.h"
#include "ziwei/star.h" // 包含新的星曜定义文件
#include "ziwei/bright.h"

/**
 * @brief 排列甲级和乙级星曜。
 * @warning 返回的二维数组是动态分配的，调用者必须负责释放内存！
 *          示例：
 *          int** chart = arrangeGradeAStars(...);
 *          // ...使用chart...
 *          for (int i = 0; i < A_STARS_COUNT; ++i) {
 *              delete[] chart[i];
 *          }
 *          delete[] chart;
 * 
 * @param lunarMonth 农历月 (1-12)
 * @param lunarDay 农历日 (1-30)
 * @param timeBranch 时支 (0-11)
 * @param yearLast 年份尾数 (0-9)
 * @param yearBranch 年支 (0-11)
 * @return 一个 int** 指针，指向 [A_STARS_COUNT][12] 大小的矩阵。
 */
int** arrangeGradeAStars(
    int lunarMonth, int lunarDay, int timeBranch, int yearLast, int yearBranch);

/**
 * @brief 排列丙级星曜。
 * @warning 返回的二维数组是动态分配的，调用者必须负责释放内存！
 * 
 * @param lunarMonth 农历月 (1-12)
 * @param lunarDay 农历日 (1-30)
 * @param timeBranch 时支 (0-11)
 * @param yearLast 年份尾数 (0-9)
 * @param yearBranch 年支 (0-11)
 * @return 一个 int** 指针，指向 [C_STARS_COUNT][12] 大小的矩阵。
 */
int** arrangeGradeCStars(
    int lunarMonth, int lunarDay, int timeBranch, int yearLast, int yearBranch);

#endif // PURPCHI_ZIWEI_ARRANGE_CHART_H