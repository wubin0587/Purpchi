#ifndef LANG_SW_H
#define LANG_SW_H

// 定义支持的语言
typedef enum {
    LANG_ZH_CN, // 简体中文
    // LANG_EN_US, // 英语（未来扩展）
    // LANG_ZH_TW  // 繁体中文（未来扩展）
} Language;

/**
 * @brief 设置当前语言
 * @param lang 要设置的语言
 */
void setCurrentLanguage(Language lang);

/**
 * @brief 获取当前设置的语言
 * @return 当前语言
 */
Language getCurrentLanguage();

/**
 * @brief 根据星曜ID获取其名称
 * @param starId 星曜的ID (1-70, 甚至更多)
 * @return 对应语言的星曜名称字符串
 */
const char* getStarName(int starId);

/**
 * @brief 根据天干ID获取其名称
 * @param ganId 天干的ID (0-9)
 * @return 对应语言的天干名称字符串
 */
const char* getGanName(int ganId);

/**
 * @brief 根据地支ID获取其名称
 * @param zhiId 地支的ID (0-11)
 * @return 对应语言的地支名称字符串
 */
const char* getZhiName(int zhiId);

// 你可以继续添加其他需要的字符串获取函数，例如：
// const char* getPalaceName(int palaceId);
// const char* getBrightnessName(int brightnessId);
// const char* getShenShaName(int shenShaId);


#endif // LANG_SW_H
