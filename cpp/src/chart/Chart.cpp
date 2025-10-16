#include "chart/Chart.h"
#include "global/lang_sw.h"
#include <cstring>


// 外部定义的星曜数据
// 假设 ZiweiStars 数组现在扩展到了包含所有神煞，例如 120 个
extern const Star ZiweiStars[120];

// 辅助函数：向宫位中添加星曜
void addStarToPalace(Palace& palace, int starId) {
    // 假设 ZiweiStars 数组大小足够
    if (palace.starPoint < 16 && starId > 0) {
        palace.stars[palace.starPoint] = ZiweiStars[starId - 1];
        // 初始化新增的四化标记
        palace.stars[palace.starPoint].born_siHua = 0;
        palace.stars[palace.starPoint].ming_siHua = 0;
        palace.starPoint++;
    }
}

Chart::Chart(int year, int lunarMonth, int lunarDay, int timeBranch, bool isMale)
    : year(year), lunarMonth(lunarMonth), lunarDay(lunarDay), timeBranch(timeBranch), isMale(isMale) {
    // 初始化所有宫位
    for (int i = 0; i < 12; ++i) {
        palaces[i].starPoint = 0;
        palaces[i].isShenggong = false;
        palaces[i].isLaiyingong = false;
        palaces[i].tiangan = 0;
        for(int j = 0; j < 4; ++j) {
            palaces[i].xiangXinSiHua[j] = false;
            palaces[i].liXinSiHua[j] = false;
        }
    }
    
    // 执行完整排盘
    arrange();
}

Chart::~Chart() {
    // 无动态内存，析构函数为空
}

void Chart::arrange() {
    calculateBaseInfo();
    arrangePalaces();
    arrangeLevelAStars();
    arrangeLevelBStars();
    arrangeBornSihua();
    arrangePalaceSihua();
    arrangeOtherStars();
    setPalaceNames();
    arrangeCycles();
}

void Chart::calculateBaseInfo() {
    yearLast = year % 10;

    mingPalacePos = purpchi::arrange::arrangeMingPalace(lunarMonth, timeBranch);
    shenPalacePos = purpchi::arrange::arrangeShenPalace(mingPalacePos, lunarMonth);
    palaces[shenPalacePos].isShenggong = true;

    wuXingJu = purpchi::arrange::arrangeWuxingJu(mingPalacePos, yearLast);
    
    yinPalaceGan = purpchi::arrange::arrangeYinPalaceGan(yearLast);
}

void Chart::arrangePalaces() {
    int laiyinPalacePos = purpchi::arrange::arrangeLaiyinPalace(yearLast);
    palaces[laiyinPalacePos].isLaiyingong = true;

    // 安置十二宫天干 (寅宫地支索引为2)
    for (int i = 0; i < 12; ++i) {
        int currentPalacePos = (2 + i) % 12;
        palaces[currentPalacePos].tiangan = (yinPalaceGan + i) % 10;
    }
}

void Chart::arrangeLevelAStars() {
    int ziweiPos = purpchi::arrange::arrangeZiwei(wuXingJu, lunarDay);
    addStarToPalace(palaces[ziweiPos], 1);
    addStarToPalace(palaces[purpchi::arrange::arrangeTianji(ziweiPos)], 2);
    addStarToPalace(palaces[purpchi::arrange::arrangeTaiyang(ziweiPos)], 3);
    addStarToPalace(palaces[purpchi::arrange::arrangeWuqu(ziweiPos)], 4);
    addStarToPalace(palaces[purpchi::arrange::arrangeTiantong(ziweiPos)], 5);
    addStarToPalace(palaces[purpchi::arrange::arrangeLianzhen(ziweiPos)], 6);
    
    addStarToPalace(palaces[purpchi::arrange::arrangeTianfu(ziweiPos)], 7);
    addStarToPalace(palaces[purpchi::arrange::arrangeTaiyin(ziweiPos)], 8);
    addStarToPalace(palaces[purpchi::arrange::arrangeTanlang(ziweiPos)], 9);
    addStarToPalace(palaces[purpchi::arrange::arrangeJumen(ziweiPos)], 10);
    addStarToPalace(palaces[purpchi::arrange::arrangeTianxiang(ziweiPos)], 11);
    addStarToPalace(palaces[purpchi::arrange::arrangeTianliang(ziweiPos)], 12);
    addStarToPalace(palaces[purpchi::arrange::arrangeQisha(ziweiPos)], 13);
    addStarToPalace(palaces[purpchi::arrange::arrangePojun(ziweiPos)], 14);
}

void Chart::arrangeLevelBStars() {
    addStarToPalace(palaces[purpchi::arrange::arrangeZuofu(lunarMonth)], 15);
    addStarToPalace(palaces[purpchi::arrange::arrangeYoubi(lunarMonth)], 16);
    addStarToPalace(palaces[purpchi::arrange::arrangeWenchang(timeBranch)], 17);
    addStarToPalace(palaces[purpchi::arrange::arrangeWenqu(timeBranch)], 18);
    addStarToPalace(palaces[purpchi::arrange::arrangeTiankui(yearLast)], 19);
    addStarToPalace(palaces[purpchi::arrange::arrangeTianyue(yearLast)], 20);
    addStarToPalace(palaces[purpchi::arrange::arrangeLucun(yearLast)], 21);
    addStarToPalace(palaces[purpchi::arrange::arrangeQingyang(yearLast)], 22);
    addStarToPalace(palaces[purpchi::arrange::arrangeTuoluo(yearLast)], 23);
    addStarToPalace(palaces[purpchi::arrange::arrangeHuoxing(yearBranch, timeBranch)], 24);
    addStarToPalace(palaces[purpchi::arrange::arrangeLingxing(yearBranch, timeBranch)], 25);
    addStarToPalace(palaces[purpchi::arrange::arrangeDikong(timeBranch)], 26);
    addStarToPalace(palaces[purpchi::arrange::arrangeDijie(timeBranch)], 27);
    addStarToPalace(palaces[purpchi::arrange::arrangeTianma(yearBranch)], 28);
}

void Chart::arrangeBornSihua() {
    int sihuaStarIds[] = {
        purpchi::arrange::getHuaLuStarId(yearLast),
        purpchi::arrange::getHuaQuanStarId(yearLast),
        purpchi::arrange::getHuaKeStarId(yearLast),
        purpchi::arrange::getHuaJiStarId(yearLast)
    };

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < palaces[i].starPoint; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (palaces[i].stars[j].starID == sihuaStarIds[k]) {
                    palaces[i].stars[j].born_siHua = k + 1; // 1:禄, 2:权, 3:科, 4:忌
                }
            }
        }
    }
}

void Chart::arrangePalaceSihua() {
    // 遍历十二宫，计算每个宫位飞出的四化
    for (int i = 0; i < 12; ++i) {
        int palaceGan = palaces[i].tiangan;
        
        int sihuaStarIds[] = {
            purpchi::arrange::getHuaLuStarId(palaceGan),
            purpchi::arrange::getHuaQuanStarId(palaceGan),
            purpchi::arrange::getHuaKeStarId(palaceGan),
            purpchi::arrange::getHuaJiStarId(palaceGan)
        };

        // 查找这四颗星分别落在哪一宫
        for(int k = 0; k < 4; ++k) {
            int targetStarId = sihuaStarIds[k];
            if (targetStarId == -1) continue;

            for (int targetPalaceIdx = 0; targetPalaceIdx < 12; ++targetPalaceIdx) {
                for (int starIdx = 0; starIdx < palaces[targetPalaceIdx].starPoint; ++starIdx) {
                    if (palaces[targetPalaceIdx].stars[starIdx].starID == targetStarId) {
                        // 找到了四化星的落点 targetPalaceIdx
                        
                        // 1. 分析向心(自化)和离心
                        if (i == targetPalaceIdx) {
                            // 宫干四化飞入本宫，为自化，标记为向心
                            palaces[i].xiangXinSiHua[k] = true;
                        }
                        
                        if (i == mingPalacePos) {
                            // 命宫飞出的四化，对落点宫位而言是离心
                            palaces[targetPalaceIdx].liXinSiHua[k] = true;
                        }

                        // 2. 标记命宫四化（此逻辑不变）
                        if (i == mingPalacePos) {
                            palaces[targetPalaceIdx].stars[starIdx].ming_siHua = k + 1;
                        }
                        
                        goto next_sihua; // 找到后跳到下一个四化星的查找
                    }
                }
            }
            next_sihua:;
        }
    }
}
void Chart::arrangeOtherStars() {
    // 此处安放博士、长生、岁建、将前等十二神煞
    // 你需要先在 STAR.h 和对应的语言文件中定义好这些星的ID和名称
    // 示例：假设长生十二神从ID 83开始
    int changshengStartPos = purpchi::arrange::arrangeChangsheng(mingPalacePos, wuXingJu);
    for (int i = 0; i < 12; ++i) {
        addStarToPalace(palaces[(changshengStartPos + i) % 12], 83 + i);
    }

    // 示例：假设岁建十二神从ID 95开始
    int suijianStartPos = purpchi::arrange::arrangeSuijian(yearBranch);
    for (int i = 0; i < 12; ++i) {
        addStarToPalace(palaces[(suijianStartPos + i) % 12], 95 + i);
    }
    
    // 示例：假设将前十二神从ID 107开始
    int jiangxingStartPos = purpchi::arrange::arrangeJiangxing(yearBranch);
    for (int i = 0; i < 12; ++i) {
        addStarToPalace(palaces[(jiangxingStartPos + i) % 12], 107 + i);
    }
}

void Chart::setPalaceNames() {
    const char* palaceNames[12] = {
        "命宫", "兄弟", "夫妻", "子女", "财帛", "疾厄",
        "迁移", "仆役", "官禄", "田宅", "福德", "父母"
    };

    for (int i = 0; i < 12; ++i) {
        int currentPalacePos = (mingPalacePos + i) % 12;
        strncpy(palaces[currentPalacePos].palaceName, palaceNames[i], 7);
        palaces[currentPalacePos].palaceName[7] = '\0';
    }
}

void Chart::arrangeCycles() {
    // 此处实现大运、小限、流年等计算逻辑
    // 并填充 palaces[i].dayun, liunian, xiaoxian 字段
}

const Palace& Chart::getPalace(int index) const {
    if (index >= 0 && index < 12) {
        return palaces[index];
    }
    return palaces[0]; // 默认返回第一个
}

char* Chart::getString() {
    // 待实现
    return nullptr;
}