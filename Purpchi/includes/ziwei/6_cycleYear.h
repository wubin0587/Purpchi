// D:\Purpchi\includes\ziwei\6_cycleYear.h
#ifndef PURPCHI_ZIWEI_6_CYCLEYEAR_H
#define PURPCHI_ZIWEI_6_CYCLEYEAR_H

// ============================================
// 大运系统
// ============================================

/**
 * 计算大运起始宫位
 * @param mingPalace 命宫位置 (0-11)
 * @param isMale 性别 (1=男, 0=女)
 * @param yearLast 年份尾数 (0-9, 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己)
 * @return 大运起始宫位 (0-11)
 * 
 * 算法:
 * 阳男阴女: 从命宫顺行，每宫10年
 * 阴男阳女: 从命宫逆行，每宫10年
 * 
 * 排盘时展开: 
 * 顺行: (起始宫 + i) % 12, i=0-11 对应 起运年龄+i*10
 * 逆行: (起始宫 - i + 12) % 12
 */
int calculateDayunStart(int mingPalace, int isMale, int yearLast);

/**
 * 判断大运方向
 * @param isMale 性别
 * @param yearLast 年份尾数
 * @return 1=顺行, 0=逆行
 */
int isDayunShun(int isMale, int yearLast);

// ============================================
// 流年系统
// ============================================

/**
 * 计算流年起始宫位（对应出生年）
 * @param mingPalace 命宫位置 (0-11)
 * @return 流年起始宫位（永远返回命宫）
 * 
 * 算法:
 * 流年永远从命宫开始顺行，每年一宫
 * 
 * 排盘时展开:
 * (命宫 + 年龄) % 12 = 该年龄对应的流年宫位
 */
int calculateLiunianStart(int mingPalace);

// ============================================
// 小限系统
// ============================================

/**
 * 计算小限起始宫位（1岁位置）
 * @param isMale 性别
 * @return 小限起始宫位 (0-11)
 * 
 * 算法:
 * 男命: 从寅宫(0)起1岁，顺行
 * 女命: 从申宫(6)起1岁，逆行
 * 
 * 排盘时展开:
 * 男: (0 + 年龄 - 1) % 12
 * 女: (6 - 年龄 + 1 + 12*100) % 12
 */
int calculateXiaoxianStart(int isMale);

/**
 * 判断小限方向
 * @param isMale 性别
 * @return 1=顺行, 0=逆行
 */
int isXiaoxianShun(int isMale);

// ============================================
// 辅助函数
// ============================================

/**
 * 判断是否为阳年
 * @param yearLast 年份尾数 (0-9)
 * @return 1=阳年, 0=阴年
 */
int isYangYear(int yearLast);

#endif // PURPCHI_ZIWEI_6_CYCLEYEAR_H