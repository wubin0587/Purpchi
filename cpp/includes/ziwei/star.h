#ifndef PURPCHI_ZIWEI_STAR_H
#define PURPCHI_ZIWEI_STAR_H

enum BrightnessLevel {
    BL_NOT_PRESENT = 0, // 不在此宫 (自定义)
    BL_XIAN = 1,        // 落陷
    BL_BUDE = 2,        // 不得地
    BL_PING = 3,        // 平和
    BL_LI = 4,          // 利益
    BL_DE = 5,          // 得地
    BL_WANG = 6,        // 旺
    BL_MIAO = 7         // 庙
};

// 使用 enum 定义甲级和乙级星的顺序 (行索引)
// 这样做比全局变量更安全，提供了类似的功能
enum StarA {
    // 14主星 (甲级)
    A_ZIWEI, A_TIANJI, A_TAIYANG, A_WUQU, A_TIANTONG, A_LIANZHEN,
    A_TIANFU, A_TAIYIN, A_TANLANG, A_JUMEN, A_TIANXIANG, A_TIANLIANG, A_QISHA, A_POJUN,

    // 六吉星 (甲级/乙级)
    A_ZUOFU, A_YOUBI, A_WENCHANG, A_WENQU, A_TIANKUI, A_TIANYUE,

    // 禄存、天马 (甲级/乙级)
    A_LUCUN, A_TIANMA,

    // 六煞星 (甲级/乙级)
    A_QINGYANG, A_TUOLUO, A_HUOXING, A_LINGXING, A_DIKONG, A_DIJIE,

    A_STARS_COUNT // 关键：自动计算星曜总数
};

// 使用 enum 定义丙级星的顺序 (行索引)
enum StarC {
    // 年干系
    C_TIANGUAN, C_TIANFU_GUIREN, C_TIANCHU,

    // 年支系
    C_HONGLUAN, C_TIANXI, C_TIANXING, C_TIANYAO, C_JIESHEN, C_LONGCHI, C_FENGGE,
    C_GUCHEN, C_GUASU, C_FEILIAN, C_POSUI, C_TIANCAI, C_TIANSHOU,

    // 月日时系
    C_TIANYUE_YUE, C_YINSHA, C_SANTAI, C_BAZUO, C_TAIFU, C_FENGGAO,
    
    C_STARS_COUNT // 关键：自动计算星曜总数
};

#endif // PURPCHI_ZIWEI_STAR_H