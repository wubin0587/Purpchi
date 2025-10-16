#ifndef SANHE_H
#define SANHE_H

#include "Chart.h" // 包含核心Chart类

class SanheChart {
public:
    SanheChart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale);
    ~SanheChart();

    // 返回对核心Chart宫位的常量引用，效率最高
    const Palace& getPalace(int index) const;

private:
    Chart* fullChart; 
};

#endif // SANHE_H