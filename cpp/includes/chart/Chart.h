#include <stdbool.h>

#include "arrange/1.h"
#include "arrange/2.h"
#include "arrange/3.h"
#include "arrange/4_tf.h"
#include "arrange/5_sui.h"
#include "arrange/6_cycleYear.h"

#include "STAR.h"
#include "PALACE.h"

class Chart
{
protected:
    // 构造函数：接收所有必要的输入信息
    Chart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale);
    ~Chart();

    // 获取指定宫位（外部接口）
    const Palace& getPalace(int index) const;

    // 获取命盘的字符串表示，用于调试或简单输出
    char* getString();

private:
    // --- 输入数据 ---
    int year;
    int lunarMonth;
    int lunarDay;
    int timeBranch;
    bool isMale;

    // --- 命盘核心数据 ---
    Palace palaces[12]; // 12个宫位
    int wuXingJu;       // 五行局
    int mingPalacePos;  // 命宫位置
    int shenPalacePos;  // 身宫位置

    // --- 中间计算数据 ---
    int yearLast;       // 年干 (0-9)，0-庚，1-辛，2-壬，9-己
    int yearBranch;     // 年支 (0-11)
    int yinPalaceGan;   // 寅宫天干 (0-9)

    // --- 核心排盘逻辑 ---
    void arrange(); // 主排盘函数，调用以下所有步骤

    // 1. 计算天干地支和基本盘信息
    void calculateBaseInfo();
    // 2. 安置十二宫干和基本信息
    void arrangePalaces();
    // 3. 安置甲级主星
    void arrangeLevelAStars();
    // 4. 安置乙级星
    void arrangeLevelBStars();
    // 5. 安置生年四化
    void arrangeBornSihua();
    // 6. 安置十二宫四化
    void arrangePalaceSihua();
    // 7. 安置杂曜和神煞
    void arrangeOtherStars();
    // 8. 设置宫位名称
    void setPalaceNames();
    // 9. 计算大运流年
    void arrangeCycles();
};