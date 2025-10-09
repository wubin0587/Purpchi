#ifndef PURPCHI_ZIWEI_BRIGHT_H
#define PURPCHI_ZIWEI_BRIGHT_H

#include "ziwei/star.h"

// 庙旺等级定义:
// 7: 庙 (Miao)
// 6: 旺 (Wang)
// 5: 得地 (De Di)
// 4: 利益 (Li Yi)
// 3: 平和 (Ping He)
// 2: 不得地 (Bu De Di)
// 1: 落陷 (Luo Xian)
// 0: 星曜不在此宫


/**
 * @brief 获取甲级/乙级星在指定宫位的庙旺等级
 * @param star 星曜的ID (来自 StarA enum)
 * @param palace 宫位 (0-11, 寅=0)
 * @return 代表庙旺的整数 (1-7)，若不在则返回 0
 */
int getStarABrightness(StarA star, int palace);

/**
 * @brief 获取丙级星在指定宫位的庙旺等级
 * @param star 星曜的ID (来自 StarC enum)
 * @param palace 宫位 (0-11, 寅=0)
 * @return 代表庙旺的整数 (通常返回 3 代表平和)
 */
int getStarCBrightness(StarC star, int palace);

#endif // PURPCHI_ZIWEI_BRIGHT_H