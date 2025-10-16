#ifndef FEIXING_H
#define FEIXING_H

#include "Chart.h" // 包含核心Chart类

class FeixingChart {
public:
    FeixingChart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale);
    ~FeixingChart();

    // 返回一个按值传递的、过滤后的Palace对象
    Palace getPalace(int index) const;

private:
    Chart* fullChart;
};

#endif // FEIXING_H