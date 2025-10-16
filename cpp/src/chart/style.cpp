#include "chart/style.h"
#include "global/lang_sw.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C++ 文件需要包含 Chart 的完整定义
#include "chart/Chart.h" 

// 辅助函数：在指定宫位中查找星曜
static bool findStarInPalace(const Palace& palace, int starId) {
    for (int i = 0; i < palace.starPoint; ++i) {
        if (palace.stars[i].starID == starId) {
            return true;
        }
    }
    return false;
}

// --- 单个格局的实现 (函数接收 const Chart* 指针) ---

bool isJunChenQingHui(const Chart* chart) {
    const Palace& mingPalace = chart->getPalace(chart->getMingPalacePos());
    if (!findStarInPalace(mingPalace, 1)) return false;

    int sanfang[] = { chart->getMingPalacePos(), (chart->getMingPalacePos() + 4) % 12, (chart->getMingPalacePos() + 8) % 12, (chart->getMingPalacePos() + 6) % 12 };
    int jiaGong[] = { (chart->getMingPalacePos() + 1) % 12, (chart->getMingPalacePos() - 1 + 12) % 12 };
    bool hasZuoFu = false, hasYouBi = false;

    for (int i = 0; i < 4; ++i) {
        if (findStarInPalace(chart->getPalace(sanfang[i]), 15)) hasZuoFu = true;
        if (findStarInPalace(chart->getPalace(sanfang[i]), 16)) hasYouBi = true;
    }
    for (int i = 0; i < 2; ++i) {
        if (findStarInPalace(chart->getPalace(jiaGong[i]), 15)) hasZuoFu = true;
        if (findStarInPalace(chart->getPalace(jiaGong[i]), 16)) hasYouBi = true;
    }
    return hasZuoFu || hasYouBi;
}

bool isZiFuTongGong(const Chart* chart) {
    if (chart->getMingPalacePos() != 2 && chart->getMingPalacePos() != 8) return false;
    const Palace& mingPalace = chart->getPalace(chart->getMingPalacePos());
    return findStarInPalace(mingPalace, 1) && findStarInPalace(mingPalace, 7);
}

bool isJiYueTongLiang(const Chart* chart) {
    if (chart->getMingPalacePos() != 2 && chart->getMingPalacePos() != 8) return false;
    int sanfang[] = { chart->getMingPalacePos(), (chart->getMingPalacePos() + 4) % 12, (chart->getMingPalacePos() + 8) % 12, (chart->getMingPalacePos() + 6) % 12 };
    bool hasJi = false, hasYue = false, hasTong = false, hasLiang = false;
    for (int i = 0; i < 4; ++i) {
        const Palace& p = chart->getPalace(sanfang[i]);
        if (findStarInPalace(p, 2)) hasJi = true;
        if (findStarInPalace(p, 8)) hasYue = true;
        if (findStarInPalace(p, 5)) hasTong = true;
        if (findStarInPalace(p, 12)) hasLiang = true;
    }
    return hasJi && hasYue && hasTong && hasLiang;
}

bool isYangTuoJiaMing(const Chart* chart) {
    int mingPos = chart->getMingPalacePos();
    const Palace& prevPalace = chart->getPalace((mingPos - 1 + 12) % 12);
    const Palace& nextPalace = chart->getPalace((mingPos + 1) % 12);
    bool prevHasYang = findStarInPalace(prevPalace, 22);
    bool nextHasTuo = findStarInPalace(nextPalace, 23);
    bool prevHasTuo = findStarInPalace(prevPalace, 23);
    bool nextHasYang = findStarInPalace(nextPalace, 22);
    return (prevHasYang && nextHasTuo) || (prevHasTuo && nextHasYang);
}

// --- 总分析函数和内存释放函数 ---

StyleAnalysisResult analyseAllStyles(const Chart* chart) {
    StyleAnalysisResult analysisResult = { NULL, 0 };
    int capacity = 4; // 初始容量
    analysisResult.results = (StyleResult*)malloc(capacity * sizeof(StyleResult));
    if (!analysisResult.results) return analysisResult; // 内存分配失败

    // 函数指针数组
    bool (*styleChecks[STYLE_COUNT])(const Chart*) = {
        isJunChenQingHui, isZiFuTongGong, isJiYueTongLiang, isYangTuoJiaMing,
    };

    for (int i = 0; i < STYLE_COUNT; ++i) {
        if (styleChecks[i](chart)) {
            // 检查容量是否足够
            if (analysisResult.count >= capacity) {
                capacity *= 2;
                StyleResult* new_results = (StyleResult*)realloc(analysisResult.results, capacity * sizeof(StyleResult));
                if (!new_results) { // realloc 失败
                    free(analysisResult.results);
                    analysisResult.results = NULL;
                    analysisResult.count = 0;
                    return analysisResult;
                }
                analysisResult.results = new_results;
            }
            
            // 填充结果
            StyleResult* res = &analysisResult.results[analysisResult.count];
            res->id = (StyleID)i;
            res->name = getStyleName(i);
            res->description = getStyleDescription(i);
            analysisResult.count++;
        }
    }
    return analysisResult;
}

void freeStyleAnalysisResult(StyleAnalysisResult* analysisResult) {
    if (analysisResult && analysisResult->results) {
        free(analysisResult->results);
        analysisResult->results = NULL;
        analysisResult->count = 0;
    }
}