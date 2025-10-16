#include "global/lang_sw.h"

// 包含所有语言的数据文件
#include "global/zh_CN/GANZHI.h"
#include "global/zh_CN/STAR.h"
// #include "global/en_US/GANZHI.h" // 未来扩展
// #include "global/en_US/STAR.h"   // 未来扩展

// 全局变量，存储当前语言，默认为简体中文
static Language currentLanguage = LANG_ZH_CN;

void setCurrentLanguage(Language lang) {
    currentLanguage = lang;
}

Language getCurrentLanguage() {
    return currentLanguage;
}

const char* getStarName(int starId) {
    // 检查ID是否在有效范围内
    int maxId = sizeof(StarNames_zh_CN) / sizeof(StarNames_zh_CN[0]) - 1;
    if (starId <= 0 || starId > maxId) {
        return "未知"; // 返回一个默认的错误提示
    }

    switch (currentLanguage) {
        case LANG_ZH_CN:
            return StarNames_zh_CN[starId];
        // case LANG_EN_US:
        //     return StarNames_en_US[starId]; // 未来扩展
        default:
            return StarNames_zh_CN[starId]; // 默认返回中文
    }
}

const char* getGanName(int ganId) {
    if (ganId < 0 || ganId > 9) return "";
    switch (currentLanguage) {
        case LANG_ZH_CN:
            return GanNames_zh_CN[ganId];
        default:
            return GanNames_zh_CN[ganId];
    }
}

const char* getZhiName(int zhiId) {
    if (zhiId < 0 || zhiId > 11) return "";
    switch (currentLanguage) {
        case LANG_ZH_CN:
            return ZhiNames_zh_CN[zhiId];
        default:
            return ZhiNames_zh_CN[zhiId];
    }
}