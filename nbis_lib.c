//  nbis_lib.c
//  Created by ChoDongWook on 22/05/2020.
//  Copyright © 2020 digent. All rights reserved.

#include "nbis_lib.h"
#include "an2k.h"
#include "./imgtools/cwsq.c"

#define EXPORT __attribute__((visibility("default")))

EXPORT //주석처리하나 안하나 결과는 동일
int main_exe()
{
    //cout << "end" << endl;
    ANSI_NIST* an;
    alloc_ANSI_NIST(&an);

    //.B % cwsq .75 wsq finger.raw -r 500,500,8,500
    int argc = 3;
    char* mytext = "ffff";
    int ret = CWSQ_main(argc, &mytext);

    printf("라이브러리에서 오는 메세지\n");
    return 0;
}
