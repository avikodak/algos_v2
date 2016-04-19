/****************************************************************************************************************************************************
 *  File Name                   : rightri.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/rightri.h
 *  Created on                  : 20-Oct-2015 :: 9:11:27 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RIGHTRI
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

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef RIGHTRI_H_
#define RIGHTRI_H_

//Tested
struct point {
public:
    unsigned int x;
    unsigned int y;
};

//Tested
unsigned int calDistance(point first,point second) {
    return (((first.x - second.x)*(first.x - second.x)) + ((first.y - second.y)*(first.y - second.y)));
}

//Tested
bool isRightTriangle(point vertices[]) {
    unsigned int distance[3];
    distance[0] = calDistance(vertices[0],vertices[1]);
    distance[1] = calDistance(vertices[1],vertices[2]);
    distance[2] = calDistance(vertices[0],vertices[2]);
    sort(distance,distance+3);
    return max(max(distance[0],distance[1]),distance[2])*2 == distance[0]+distance[1]+distance[2];
}

//Tested
void printResults() {
    unsigned int testCases,sum = 0;
    point vertices[3];
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%u %u %u %u %u %u",&vertices[0].x,&vertices[0].y,&vertices[1].x,&vertices[1].y,&vertices[2].x,&vertices[2].y);
        if(isRightTriangle(vertices)) {
            sum++;
        }
    }
    printf("%u",sum);
}

#endif /* RIGHTRI_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
