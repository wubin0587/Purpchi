// src\arrange\1.cpp
#include "arrange/1.h"

namespace purpchi {
namespace arrange {

int arrangeMingPalace(int lunarMonth, int timeBranch) {
    int timeOffset = (timeBranch >= 8) ? (timeBranch - 8) : (timeBranch + 4);
    return (lunarMonth - 1 + 12 - timeOffset) % 12;
}

int arrangeShenPalace(int mingPalace, int lunarMonth) {
    return (mingPalace + lunarMonth - 1) % 12;
}

int arrangeLaiyinPalace(int yearLast) {
    return 0;
}


int arrangeWuxingJu(int mingPalace, int yearLast) {
    // 确定三合局
    int sanheLeiXing;
    if (mingPalace == 0 || mingPalace == 4 || mingPalace == 8) {
        sanheLeiXing = 0;  // 寅午戌=火局
    } else if (mingPalace == 2 || mingPalace == 6 || mingPalace == 10) {
        sanheLeiXing = 1;  // 申子辰=水局
    } else if (mingPalace == 3 || mingPalace == 7 || mingPalace == 11) {
        sanheLeiXing = 2;  // 巳酉丑=金局
    } else {
        sanheLeiXing = 3;  // 亥卯未=木局
    }

    // 年份尾数分组 (对应天干)
    // 0,4,6 -> 庚甲丙
    // 1,5 -> 辛乙
    // 2,3 -> 壬癸
    // 7 -> 丁
    // 8,9 -> 戊己
    int digitGroup;
    if (yearLast == 0 || yearLast == 4 || yearLast == 6) {
        digitGroup = 0;  // 庚甲丙
    } else if (yearLast == 1 || yearLast == 5) {
        digitGroup = 1;  // 辛乙
    } else if (yearLast == 2 || yearLast == 3) {
        digitGroup = 2;  // 壬癸
    } else if (yearLast == 7) {
        digitGroup = 3;  // 丁
    } else {
        digitGroup = 4;  // 戊己
    }

    // 纳音五行局映射 [三合局][年份尾数组]
    static const int wuxingJuTable[4][5] = {
        {6, 5, 2, 3, 4},  // 火局: 火土水木金
        {2, 6, 3, 4, 5},  // 水局: 水火木金土
        {5, 4, 6, 2, 3},  // 金局: 土金火水木
        {3, 2, 4, 5, 6}   // 木局: 木水金土火
    };

    return wuxingJuTable[sanheLeiXing][digitGroup];
}

int arrangeZiwei(int wuxingJu, int lunarDay) {
    int startPalace, step;

    switch (wuxingJu) {
        case 2: startPalace = 0; step = 2; break;  // 水二局
        case 3: startPalace = 2; step = 3; break;  // 木三局
        case 4: startPalace = 4; step = 4; break;  // 金四局
        case 5: startPalace = 6; step = 5; break;  // 土五局
        case 6: startPalace = 8; step = 6; break;  // 火六局
        default: return 0;
    }

    int offset = (lunarDay - 1) / step;
    return (startPalace + offset) % 12;
}

int arrangeTianji(int ziweiPalace) {
    // 紫微逆一为天机
    return (ziweiPalace - 1 + 12) % 12;
}

int arrangeTaiyang(int ziweiPalace) {
    // 紫微逆三为太阳
    return (ziweiPalace - 3 + 12) % 12;
}

int arrangeWuqu(int ziweiPalace) {
    // 紫微逆四为武曲
    return (ziweiPalace - 4 + 12) % 12;
}

int arrangeTiantong(int ziweiPalace) {
    // 紫微逆五为天同
    return (ziweiPalace - 5 + 12) % 12;
}

int arrangeLianzhen(int ziweiPalace) {
    // 紫微逆八为廉贞
    return (ziweiPalace - 8 + 12) % 12;
}

// --- 天府星系实现 ---

int arrangeTianfu(int ziweiPalace) {
    // 天府的位置关于“寅申线”与紫微对称
    // 在我们的坐标系中 (寅=0, 申=6), 轴线在 0 和 6 之间，可以理解为 (4 - x)
    // 寅(0) -> 巳(4)
    // 卯(1) -> 辰(3)
    // 辰(2) -> 卯(2)
    // 巳(3) -> 寅(1)
    return (4 - ziweiPalace + 12) % 12;
}

int arrangeTaiyin(int ziweiPalace) {
    // 天府顺一为太阴
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 1) % 12;
}

int arrangeTanlang(int ziweiPalace) {
    // 天府顺二为贪狼
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 2) % 12;
}

int arrangeJumen(int ziweiPalace) {
    // 天府顺三为巨门
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 3) % 12;
}

int arrangeTianxiang(int ziweiPalace) {
    // 天府顺四为天相
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 4) % 12;
}

int arrangeTianliang(int ziweiPalace) {
    // 天府顺五为天梁
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 5) % 12;
}

int arrangeQisha(int ziweiPalace) {
    // 天府顺六为七杀
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 6) % 12;
}

int arrangePojun(int ziweiPalace) {
    // 天府顺十为破军 (七杀之后空三格)
    int tianfuPalace = arrangeTianfu(ziweiPalace);
    return (tianfuPalace + 10) % 12;
}

} // namespace arrange
} // namespace purpchi