#include "arrange/1.h"
#include "arrange/2.h"
#include "arrange/3.h"
#include "arrange/4_tf.h"
#include "arrange/5_sui.h"
#include "arrange/6_cycleYear.h"

typedef struct{
    char name[16];
    int bright ;
    int level ;
    bool born_LU = 0 ;
    bool born_Quan = 0 ;
    bool born_Ke = 0;
    bool born_Ji = 0 ;
    bool ming_LU = 0 ;
    bool ming_Quan = 0 ;
    bool ming_Ke = 0;
    bool ming_Ji = 0 ;
}Star;

typedef struct{
    Star stars[12] ;
    int starPoint = 0 ;

    int dayun;
    int liunian;
    int xiaoxian;

    char attitude[8] ; 
    char ganzhi[8];

    char changsheng[4];
    char boshi[4]; 
    char suijian[4]; 
    char jiangqian[4];  

}Palace ;

class Chart()
{
private:
    Palace p[11];
    int wuXingJu = 1 ;

    int yearLast ;
    int timeBranch ;

public:
    int year ;
    int lunarMonth ;
    int lunarDay ;
    char time[4];
    char[3][8] bazi;
    bool isMale ;


}