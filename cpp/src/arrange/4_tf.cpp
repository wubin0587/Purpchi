#include "ziwei/4_tf.h"

namespace purpchi{
namespace arrange{

// yearLast (0-9) 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己

int arrangeHuaLu(int yearLast, int ziweiPalace) {
    switch (yearLast) {
        case 0: return arrangeTaiyang(ziweiPalace);   // 庚: 太阳
        case 1: return arrangeJumen(ziweiPalace);     // 辛: 巨门
        case 2: return arrangeTianliang(ziweiPalace); // 壬: 天梁
        case 3: return arrangePojun(ziweiPalace);     // 癸: 破军
        case 4: return arrangeLianzhen(ziweiPalace);  // 甲: 廉贞
        case 5: return arrangeTianji(ziweiPalace);    // 乙: 天机
        case 6: return arrangeTiantong(ziweiPalace);  // 丙: 天同
        case 7: return arrangeTaiyin(ziweiPalace);    // 丁: 太阴
        case 8: return arrangeTanlang(ziweiPalace);   // 戊: 贪狼
        case 9: return arrangeWuqu(ziweiPalace);      // 己: 武曲
        default: return -1;
    }
}

int arrangeHuaQuan(int yearLast, int ziweiPalace) {
    switch (yearLast) {
        case 0: return arrangeWuqu(ziweiPalace);      // 庚: 武曲
        case 1: return arrangeTaiyang(ziweiPalace);   // 辛: 太阳
        case 2: return ziweiPalace;                     // 壬: 紫微
        case 3: return arrangeJumen(ziweiPalace);     // 癸: 巨门
        case 4: return arrangePojun(ziweiPalace);     // 甲: 破军
        case 5: return arrangeTianliang(ziweiPalace); // 乙: 天梁
        case 6: return arrangeTianji(ziweiPalace);    // 丙: 天机
        case 7: return arrangeTiantong(ziweiPalace);  // 丁: 天同
        case 8: return arrangeTaiyin(ziweiPalace);    // 戊: 太阴
        case 9: return arrangeTanlang(ziweiPalace);   // 己: 贪狼
        default: return -1;
    }
}

int arrangeHuaKe(int yearLast, int ziweiPalace, int lunarMonth, int timeBranch) {
    switch (yearLast) {
        case 0: return arrangeTaiyin(ziweiPalace);    // 庚: 太阴
        case 1: return arrangeWenqu(timeBranch);      // 辛: 文曲
        case 2: return arrangeZuofu(lunarMonth);      // 壬: 左辅
        case 3: return arrangeTaiyin(ziweiPalace);    // 癸: 太阴
        case 4: return arrangeWuqu(ziweiPalace);      // 甲: 武曲
        case 5: return ziweiPalace;                     // 乙: 紫微
        case 6: return arrangeWenchang(timeBranch);   // 丙: 文昌
        case 7: return arrangeTianji(ziweiPalace);    // 丁: 天机
        case 8: return arrangeYoubi(lunarMonth);      // 戊: 右弼
        case 9: return arrangeTianliang(ziweiPalace); // 己: 天梁
        default: return -1;
    }
}

int arrangeHuaJi(int yearLast, int ziweiPalace, int timeBranch) {
    switch (yearLast) {
        case 0: return arrangeTiantong(ziweiPalace);  // 庚: 天同
        case 1: return arrangeWenchang(timeBranch);   // 辛: 文昌
        case 2: return arrangeWuqu(ziweiPalace);      // 壬: 武曲
        case 3: return arrangeTanlang(ziweiPalace);   // 癸: 贪狼
        case 4: return arrangeTaiyang(ziweiPalace);   // 甲: 太阳
        case 5: return arrangeTaiyin(ziweiPalace);    // 乙: 太阴
        case 6: return arrangeLianzhen(ziweiPalace);  // 丙: 廉贞
        case 7: return arrangeJumen(ziweiPalace);     // 丁: 巨门
        case 8: return arrangeTianji(ziweiPalace);    // 戊: 天机
        case 9: return arrangeWenqu(timeBranch);      // 己: 文曲
        default: return -1;
    }
}

// --- 根据年干获取四化星ID的函数 ---

int getHuaLuStarId(int yearLast) {
    // 庚日, 辛巨, 壬梁, 癸破, 甲廉, 乙机, 丙同, 丁阴, 戊贪, 己武
    const int starIds[] = {3, 10, 12, 14, 6, 2, 5, 8, 9, 4};
    return starIds[yearLast];
}

int getHuaQuanStarId(int yearLast) {
    // 庚武, 辛日, 壬紫, 癸巨, 甲破, 乙梁, 丙机, 丁同, 戊阴, 己贪
    const int starIds[] = {4, 3, 1, 10, 14, 12, 2, 5, 8, 9};
    return starIds[yearLast];
}

int getHuaKeStarId(int yearLast) {
    // 庚阴, 辛曲, 壬辅, 癸阴, 甲武, 乙紫, 丙昌, 丁机, 戊弼, 己梁
    const int starIds[] = {8, 18, 15, 8, 4, 1, 17, 2, 16, 12};
    return starIds[yearLast];
}

int getHuaJiStarId(int yearLast) {
    // 庚同, 辛昌, 壬武, 癸贪, 甲日, 乙月, 丙廉, 丁巨, 戊机, 己曲
    const int starIds[] = {5, 17, 4, 9, 3, 8, 6, 10, 2, 18};
    return starIds[yearLast];
}

}
}