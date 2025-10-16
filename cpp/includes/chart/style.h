#ifndef STYLE_H
#define STYLE_H

#include "Chart.h"
#include <stdbool.h> // 使用C标准布尔类型
#include <stdlib.h>  // 使用 malloc, free

// 由于 Chart 是一个 C++ 类，我们需要在 C 风格的头文件中这样处理
#ifdef __cplusplus
extern "C" {
#endif

// 前向声明 Chart，但把它当作一个不透明的指针类型来处理
typedef struct Chart Chart;

// 为所有格局定义一个清晰的ID枚举
typedef enum {
    STYLE_JUN_CHEN_QING_HUI = 0,
    STYLE_ZI_FU_TONG_GONG,
    STYLE_JI_YUE_TONG_LIANG,
    STYLE_YANG_TUO_JIA_MING,
    // ... 在此添加所有其他格局的ID
    STYLE_COUNT // 用于计数
} StyleID;

// 定义返回结果的结构体
typedef struct {
    StyleID id;
    const char* name;
    const char* description;
} StyleResult;

// 定义最终分析结果的结构体，包含一个结果数组和结果数量
typedef struct {
    StyleResult* results;
    int count;
} StyleAnalysisResult;

/**
 * @brief 分析一个命盘，返回所有匹配的格局
 * @param chart 指向 Chart 对象的指针
 * @return 包含结果数组和数量的结构体。使用者需要调用 freeStyleAnalysisResult 来释放内存。
 */
StyleAnalysisResult analyseAllStyles(const Chart* chart);

/**
 * @brief 释放 analyseAllStyles 分配的内存
 * @param analysisResult 需要被释放的结果结构体
 */
void freeStyleAnalysisResult(StyleAnalysisResult* analysisResult);


// --- 单个格局判断函数声明 ---
// 这些函数在 C++ 文件中实现，但提供 C 链接，以便在纯 C 环境中调用

bool isJunChenQingHui(const Chart* chart);
bool isZiFuTongGong(const Chart* chart);
bool isJiYueTongLiang(const Chart* chart);
bool isYangTuoJiaMing(const Chart* chart);

// ... 其他格局判断函数

#ifdef __cplusplus
}
#endif

#endif // STYLE_H