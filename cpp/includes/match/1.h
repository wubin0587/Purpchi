#ifndef PURPCHI_MATCH_5_H
#define PURPCHI_MATCH_5_H

namespace purpchi {
namespace match {

// --- 1. 五行局 ---
bool match_wuxingju_position(int yearLast1, int lunarMonth1, int timeBranch1,
                             int yearLast2, int lunarMonth2, int timeBranch2);

// --- 2. 寅宫天干 ---
bool match_yin_palace_gan_position(int yearLast1, int yearLast2);

// --- 3. 命宫 ---
bool match_ming_palace_position(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2);
bool match_ming_palace_relative();

// --- 4. 身宫 ---
bool match_shen_palace_position(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2);
bool match_shen_palace_relative(int lunarMonth1, int timeBranch1,
                                int lunarMonth2, int timeBranch2);

// --- 5. 来因宫 ---
bool match_laiyin_palace_position(int yearLast1, int yearLast2);
bool match_laiyin_palace_relative(int yearLast1, int lunarMonth1, int timeBranch1,
                                  int yearLast2, int lunarMonth2, int timeBranch2);

// --- 6. 紫微星 ---
bool match_ziwei_position(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                          int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);
bool match_ziwei_relative(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                          int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);

// --- 7. 天府星 ---
bool match_tianfu_position(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                           int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);
bool match_tianfu_relative(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                           int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);

// --- 8. 十四主星 ---
bool match_fourteen_stars_position(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                                   int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);
bool match_fourteen_stars_relative(int yearLast1, int lunarMonth1, int lunarDay1, int timeBranch1,
                                   int yearLast2, int lunarMonth2, int lunarDay2, int timeBranch2);

} // namespace match
} // namespace purpchi

#endif //PURPCHI_MATCH_5_H