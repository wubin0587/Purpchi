#include "chart/Sihua.h"
#include <cstring> // for strncpy

SihuaChart::SihuaChart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale) {
    fullChart = new Chart(year, lunarMonth, lunarDay, timeBranch, isMale);
}

SihuaChart::~SihuaChart() {
    delete fullChart;
}

Palace SihuaChart::getPalace(int index) const {
    const Palace& originalPalace = fullChart->getPalace(index);
    Palace filteredPalace = {}; // 创建一个新的、空的Palace对象

    // 1. 复制所有非星曜的数据
    filteredPalace.isShenggong = originalPalace.isShenggong;
    filteredPalace.isLaiyingong = originalPalace.isLaiyingong;
    filteredPalace.tiangan = originalPalace.tiangan;
    filteredPalace.dayun = originalPalace.dayun;
    filteredPalace.liunian = originalPalace.liunian;
    filteredPalace.xiaoxian = originalPalace.xiaoxian;
    strncpy(filteredPalace.palaceName, originalPalace.palaceName, 8);
    strncpy(filteredPalace.ganzhiName, originalPalace.ganzhiName, 8);
    for(int i=0; i<4; ++i) {
        filteredPalace.xiangXinSiHua[i] = originalPalace.xiangXinSiHua[i];
        filteredPalace.liXinSiHua[i] = originalPalace.liXinSiHua[i];
    }

    // 2. 过滤星曜，只保留甲级和乙级 (level 1 和 2)
    for (int i = 0; i < originalPalace.starPoint; ++i) {
        const Star& star = originalPalace.stars[i];
        if (star.level == 1 || star.level == 2) {
            if (filteredPalace.starPoint < 16) {
                filteredPalace.stars[filteredPalace.starPoint++] = star;
            }
        }
    }

    return filteredPalace;
}