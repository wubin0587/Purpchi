// cpp/src/match/1.cpp
#include "match/1.h"

namespace purpchi {
namespace match {

// 1. 五行局
bool match_wuxingju_position(int yearLast1, int lunarMonth1, int timeBranch1,
                             int yearLast2, int lunarMonth2, int timeBranch2) {
    int ming1 = arrange::arrangeMingPalace(lunarMonth1, timeBranch1);
    int ju1 = arrange::arrangeWuxingJu(ming1, yearLast1);
    
    int ming2 = arrange::arrangeMingPalace(lunarMonth2, timeBranch2);
    int ju2 = arrange::arrangeWuxingJu(ming2, yearLast2);

    return ju1 == ju2;
}

// 2. 寅宫天干
bool match_yin_palace_gan_position(int yearLast1, int yearLast2) {
    return (yearLast1 % 5) == (yearLast2 % 5);
}

// 3. 命宫
bool match_ming_palace_position(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2) {
    return arrange::arrangeMingPalace(lunarMonth1, timeBranch1) == 
           arrange::arrangeMingPalace(lunarMonth2, timeBranch2);
}
bool match_ming_palace_relative() { return true; }

// 4. 身宫
bool match_shen_palace_position(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2) {
    int ming1 = arrange::arrangeMingPalace(lunarMonth1, timeBranch1);
    int shen1 = (ming1 + lunarMonth1 - 1) % 12;

    int ming2 = arrange::arrangeMingPalace(lunarMonth2, timeBranch2);
    int shen2 = (ming2 + lunarMonth2 - 1) % 12;
    
    return shen1 == shen2;
}
bool match_shen_palace_relative(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2) {
    return lunarMonth1 == lunarMonth2;
}

// 5. 来因宫
bool match_laiyin_palace_position(int yearLast1, int yearLast2) {
    // 最优解：来因宫由 yearLast 唯一确定。
    return yearLast1 == yearLast2;
}
bool match_laiyin_palace_relative(int yearLast1, int lunarMonth1, int timeBranch1,
                                  int yearLast2, int lunarMonth2, int timeBranch2) {
    int laiyin1 = arrange::arrangeLaiyinPalace(yearLast1);
    int ming1 = arrange::arrangeMingPalace(lunarMonth1, timeBranch1);
    int offset1 = (laiyin1 - ming1 + 12) % 12;

    int laiyin2 = arrange::arrangeLaiyinPalace(yearLast2);
    int ming2 = arrange::arrangeMingPalace(lunarMonth2, timeBranch2);
    int offset2 = (laiyin2 - ming2 + 12) % 12;
    
    return offset1 == offset2;
}

// 6. 紫微星
bool match_ziwei_position(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    int ming1 = getMingPalace_internal(m1, t1);
    int ju1 = arrange::arrangeWuxingJu(ming1, y1);
    int ziwei1 = arrange::arrangeZiwei(ju1, d1);

    int ming2 = getMingPalace_internal(m2, t2);
    int ju2 = arrange::arrangeWuxingJu(ming2, y2);
    int ziwei2 = arrange::arrangeZiwei(ju2, d2);
    
    return ziwei1 == ziwei2;
}
bool match_ziwei_relative(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    int ming1 = getMingPalace_internal(m1, t1);
    int ju1 = arrange::arrangeWuxingJu(ming1, y1);
    int ziwei1 = arrange::arrangeZiwei(ju1, d1);
    int offset1 = (ziwei1 - ming1 + 12) % 12;

    int ming2 = getMingPalace_internal(m2, t2);
    int ju2 = arrange::arrangeWuxingJu(ming2, y2);
    int ziwei2 = arrange::arrangeZiwei(ju2, d2);
    int offset2 = (ziwei2 - ming2 + 12) % 12;
    
    return offset1 == offset2;
}

// 7. 天府星 & 8. 十四主星
// 最优解：天府和十四主星的布局由紫微唯一确定，因此它们的比较函数完全等价于紫微的比较函数。
bool match_tianfu_position(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    return match_ziwei_position(y1, m1, d1, t1, y2, m2, d2, t2);
}
bool match_tianfu_relative(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    return match_ziwei_relative(y1, m1, d1, t1, y2, m2, d2, t2);
}
bool match_fourteen_stars_position(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    return match_ziwei_position(y1, m1, d1, t1, y2, m2, d2, t2);
}
bool match_fourteen_stars_relative(int y1, int m1, int d1, int t1, int y2, int m2, int d2, int t2) {
    return match_ziwei_relative(y1, m1, d1, t1, y2, m2, d2, t2);
}

} // namespace match
} // namespace purpchi