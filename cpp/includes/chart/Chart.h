#include <stdbool.h>

#include "arrange/1.h"
#include "arrange/2.h"
#include "arrange/3.h"
#include "arrange/4_tf.h"
#include "arrange/5_sui.h"
#include "arrange/6_cycleYear.h"

#include "STAR.h"
#include "PALACE.h"

class Chart()
{
private:
    Palace p[12];
    int wuXingJu ;

    int yearLast ;
    int timeBranch ;

    int year ;
    int lunarMonth ;
    int lunarDay ;
    char time[5];
    char[4][8] bazi;
    bool isMale ;

    Palace getPalace();
    Star getStar();

public:

    Chart();
    ~Chart();

    char* getString();

    void getyearLast() ;
    void gettimeBranch() ;
    void getbazi();
    void getTime();
    void getLunar();

    void arrange()；

}