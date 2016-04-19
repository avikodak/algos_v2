/****************************************************************************************************************************************************
 *  File Name                   : printmatrixinspiralorder.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page07\printmatrixinspiralorder.h
 *  Created on                  : Nov 27, 2014 :: 7:42:39 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
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
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
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

#ifndef PRINTMATRIXINSPIRALORDER_H_
#define PRINTMATRIXINSPIRALORDER_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printMatrixInSpiralOrderMain(vector<vector<int> > userInput,int startRowIndex,int endRowIndex,int startColumnIndex,int endColumnIndex) {
    if(startRowIndex > endRowIndex || startColumnIndex > endColumnIndex) {
        return;
    }
    for(int counter = startColumnIndex; counter <= endColumnIndex; counter++) {
        printf("%d\t",userInput[startRowIndex][counter]);
    }
    for(int counter = startRowIndex+1; counter <= endRowIndex; counter++) {
        printf("%d\t",userInput[counter][endColumnIndex]);
    }
    if(startRowIndex < endRowIndex) {
        for(int counter = endColumnIndex-1; counter >= startColumnIndex; counter--) {
            printf("%d\t",userInput[endRowIndex][counter]);
        }
    }
    if(startColumnIndex < endColumnIndex) {
        for(int counter = endRowIndex-1; counter > startRowIndex; counter--) {
            printf("%d\t",userInput[counter][startColumnIndex]);
        }
    }
    printMatrixInSpiralOrderMain(userInput,startRowIndex+1,endRowIndex-1,startColumnIndex+1,endColumnIndex-1);
}

//Tested
void printMatrixInSpiralOrder(vector<vector<int> > userInput) {
    printMatrixInSpiralOrderMain(userInput,0,userInput.size()-1,0,userInput[0].size()-1);
}

#endif /* PRINTMATRIXINSPIRALORDER_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
