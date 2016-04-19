/****************************************************************************************************************************************************
 *  File Name                   : comm3.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\easy\comm3.h
 *  Created on                  : Feb 9, 2015 :: 8:24:38 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/COMM3
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef COMM3_H_
#define COMM3_H_

double distance(int x1,int y1,int x2,int y2) {
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void isCommPossible() {
    int testCases,maxDistance;
    double chefHeadDis,chefSousDis,sousHeadDis;
    scanf("%d",&testCases);
    int chefX,chefY,headX,headY,sousX,sousY;
    while(testCases--) {
        scanf("%d",&maxDistance);
        scanf("%d %d %d %d %d %d",&chefX,&chefY,&headX,&headY,&sousX,&sousY);
        chefHeadDis = distance(chefX,chefY,headX,headY);
        chefSousDis = distance(chefX,chefY,sousX,sousY);
        if(chefHeadDis <= maxDistance && chefSousDis <= maxDistance) {
            printf("yes\n");
        } else if(chefHeadDis <= maxDistance || chefSousDis <= maxDistance) {
            sousHeadDis = distance(sousX,sousY,headX,headY);
            if(sousHeadDis <= maxDistance) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            printf("no\n");
        }
    }
}

#endif /* COMM3_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
