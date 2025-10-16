typedef struct{
    Star stars[16] ;
    int starPoint ;

    bool xiangXinSiHua[4]; // 0是否自化禄，1是否自化权，2是否自化科，3是否自化忌
    bool liXinSiHua[4]; // 0是否向心化禄，1是否向心化权，2是否向心化科，3是否向心化忌

    bool isShenggong ;
    bool isLaiyingong ;

    int tiangan ;

    char palaceName[8] ; 
    char ganzhiName[8];

    int dayun;
    int liunian;
    int xiaoxian;

    char changsheng[4];
    char boshi[4]; 
    char suijian[4]; 
    char jiangqian[4];  

}Palace ;