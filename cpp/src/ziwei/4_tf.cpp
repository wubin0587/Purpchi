#include "ziwei/4_tf.h"

// yearLast (0-9) 对应天干: 0-庚, 1-辛, 2-壬, 3-癸, 4-甲, 5-乙, 6-丙, 7-丁, 8-戊, 9-己

int calculateHuaLu(int yearLast, int ziweiPalace) {
    switch (yearLast) {
        case 0: return calculateTaiyang(ziweiPalace);   // 庚: 太阳
        case 1: return calculateJumen(ziweiPalace);     // 辛: 巨门
        case 2: return calculateTianliang(ziweiPalace); // 壬: 天梁
        case 3: return calculatePojun(ziweiPalace);     // 癸: 破军
        case 4: return calculateLianzhen(ziweiPalace);  // 甲: 廉贞
        case 5: return calculateTianji(ziweiPalace);    // 乙: 天机
        case 6: return calculateTiantong(ziweiPalace);  // 丙: 天同
        case 7: return calculateTaiyin(ziweiPalace);    // 丁: 太阴
        case 8: return calculateTanlang(ziweiPalace);   // 戊: 贪狼
        case 9: return calculateWuqu(ziweiPalace);      // 己: 武曲
        default: return -1;
    }
}

int calculateHuaQuan(int yearLast, int ziweiPalace) {
    switch (yearLast) {
        case 0: return calculateWuqu(ziweiPalace);      // 庚: 武曲
        case 1: return calculateTaiyang(ziweiPalace);   // 辛: 太阳
        case 2: return ziweiPalace;                     // 壬: 紫微
        case 3: return calculateJumen(ziweiPalace);     // 癸: 巨门
        case 4: return calculatePojun(ziweiPalace);     // 甲: 破军
        case 5: return calculateTianliang(ziweiPalace); // 乙: 天梁
        case 6: return calculateTianji(ziweiPalace);    // 丙: 天机
        case 7: return calculateTiantong(ziweiPalace);  // 丁: 天同
        case 8: return calculateTaiyin(ziweiPalace);    // 戊: 太阴
        case 9: return calculateTanlang(ziweiPalace);   // 己: 贪狼
        default: return -1;
    }
}

int calculateHuaKe(int yearLast, int ziweiPalace, int lunarMonth, int timeBranch) {
    switch (yearLast) {
        case 0: return calculateTaiyin(ziweiPalace);    // 庚: 太阴
        case 1: return calculateWenqu(timeBranch);      // 辛: 文曲
        case 2: return calculateZuofu(lunarMonth);      // 壬: 左辅
        case 3: return calculateTaiyin(ziweiPalace);    // 癸: 太阴
        case 4: return calculateWuqu(ziweiPalace);      // 甲: 武曲
        case 5: return ziweiPalace;                     // 乙: 紫微
        case 6: return calculateWenchang(timeBranch);   // 丙: 文昌
        case 7: return calculateTianji(ziweiPalace);    // 丁: 天机
        case 8: return calculateYoubi(lunarMonth);      // 戊: 右弼
        case 9: return calculateTianliang(ziweiPalace); // 己: 天梁
        default: return -1;
    }
}

int calculateHuaJi(int yearLast, int ziweiPalace, int timeBranch) {
    switch (yearLast) {
        case 0: return calculateTiantong(ziweiPalace);  // 庚: 天同
        case 1: return calculateWenchang(timeBranch);   // 辛: 文昌
        case 2: return calculateWuqu(ziweiPalace);      // 壬: 武曲
        case 3: return calculateTanlang(ziweiPalace);   // 癸: 贪狼
        case 4: return calculateTaiyang(ziweiPalace);   // 甲: 太阳
        case 5: return calculateTaiyin(ziweiPalace);    // 乙: 太阴
        case 6: return calculateLianzhen(ziweiPalace);  // 丙: 廉贞
        case 7: return calculateJumen(ziweiPalace);     // 丁: 巨门
        case 8: return calculateTianji(ziweiPalace);    // 戊: 天机
        case 9: return calculateWenqu(timeBranch);      // 己: 文曲
        default: return -1;
    }
}