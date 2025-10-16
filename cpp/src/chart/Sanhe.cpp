#include "chart/Sanhe.h"

SanheChart::SanheChart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale) {
    // 创建核心排盘对象
    fullChart = new Chart(year, lunarMonth, lunarDay, timeBranch, isMale);
}

SanheChart::~SanheChart() {
    delete fullChart;
}

const Palace& SanheChart::getPalace(int index) const {
    // 直接返回核心盘的完整宫位引用，不做任何处理
    return fullChart->getPalace(index);
}