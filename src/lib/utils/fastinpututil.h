/****************************************************************************************************************************************************
 *  File Name                   : fastinpututil.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/lib/utils/fastinpututil.h
 *  Created on                  : 19-Sep-2015 :: 12:05:57 pm
 *  Author                      : avikodak
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <stdint.h>
#include <iomanip>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef FASTINPUTUTIL_H_
#define FASTINPUTUTIL_H_

inline long long int scan() {
    long long int t=0,neg=0;
    char c;
    c=gc();
    while((c<'0' || c>'9')&& c!='-')
        c=gc();
    if(c=='-') {
        neg=1;
        c=gc();
    }
    while(c>='0' && c<='9') {
        t=(t<<3)+(t<<1)+c-'0';
        c=gc();
    }
    if(neg) t=-t;
    return(t);
}

void scanllint(long long int &x) {
    register int c = gc();
    x = 0;
    for(; (c<48 || c>57); c = gc());
    for(; c>47 && c<58; c = gc()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
}

#endif /* FASTINPUTUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
