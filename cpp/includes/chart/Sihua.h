#ifndef SIHUA_H
#define SIHUA_H

#include "Chart.h" // 包含核心Chart类

class SihuaChart {
public:
    SihuaChart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale);
    ~SihuaChart();

    // 返回一个按值传递的、过滤后的Palace对象
    Palace getPalace(int index) const;

private:
    Chart* fullChart;
};

#endif // SIHUA_H