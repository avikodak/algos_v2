/****************************************************************************************************************************************************
 *  File Name                   : diagonaldifference.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\diagonaldifference.h
 *  Created on                  : Jun 16, 2015 :: 6:17:29 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/diagonal-difference
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

#ifndef DIAGONALDIFFERENCE_H_
#define DIAGONALDIFFERENCE_H_

//Tested
void getAbsoluteDifference() {
    unsigned int size;
    int input;
    scanf("%u",&size);
    unsigned int leftToRight = 0,rightToLeftRow = 0,rightToLeftColumn = size-1;
    int leftToRightSum = 0,rightToLeftSum = 0;
    for(unsigned int rowCounter = 0; rowCounter < size; rowCounter++) {
        for(unsigned int columnCounter = 0; columnCounter < size; columnCounter++) {
            scanf("%d",&input);
            if(leftToRight == rowCounter && leftToRight == columnCounter) {
                leftToRightSum += input;
                leftToRight++;
            }
            if(rowCounter == rightToLeftRow && columnCounter == rightToLeftColumn) {
                rightToLeftSum += input;
                rightToLeftRow++;
                rightToLeftColumn--;
            }
        }
    }
    printf("%d",abs(leftToRightSum - rightToLeftSum));
}

#endif /* DIAGONALDIFFERENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
