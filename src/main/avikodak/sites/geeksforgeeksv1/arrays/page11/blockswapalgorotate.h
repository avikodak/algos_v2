/****************************************************************************************************************************************************
 *  File Name                   : blockswapalgorotate.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\blockswapalgorotate.h
 *  Created on                  : Nov 25, 2014 :: 7:09:37 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
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


#ifndef BLOCKSWAPALGOROTATE_H_
#define BLOCKSWAPALGOROTATE_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void blockSwap(vector<int> &userInput,int firstStartIndex,int secondStartIndex,int size) {
    while(size--) {
        swap(userInput[firstStartIndex],userInput[secondStartIndex]);
        firstStartIndex++;
        secondStartIndex++;
    }

}

//Tested
void rotateUsingBlockSwapAlgoMain(vector<int> &userInput,int rotateBy,int startIndex,int endIndex) {
    if(rotateBy == 0 || rotateBy == endIndex - startIndex + 1) {
        return;
    }
    if(endIndex - startIndex + 1== 2 * rotateBy) {
        blockSwap(userInput,startIndex,startIndex + rotateBy,rotateBy);
        return;
    } else {
        if(startIndex + rotateBy - 1 >= endIndex - rotateBy + 1) {
            int size = endIndex - (startIndex + rotateBy) + 1;
            blockSwap(userInput,startIndex,endIndex-size+1,size);
            rotateUsingBlockSwapAlgoMain(userInput,2*rotateBy-(endIndex - startIndex + 1),startIndex+size,endIndex);
        } else {
            blockSwap(userInput,startIndex,endIndex - rotateBy + 1,rotateBy);
            rotateUsingBlockSwapAlgoMain(userInput,rotateBy,startIndex,endIndex-rotateBy);
        }
    }
}

//Tested
void blockSwapRotateAlgo(vector<int> &userInput,unsigned int rotateBy) {
    if(rotateBy == 0 || rotateBy == userInput.size()) {
        return;
    }
    rotateUsingBlockSwapAlgoMain(userInput,rotateBy,0,userInput.size()-1);
}

#endif /* BLOCKSWAPALGOROTATE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
