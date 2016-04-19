/****************************************************************************************************************************************************
 *  File Name                   : rotatearray.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/arrays/page04/rotatearray.h
 *  Created on                  : Jan 24, 2016 :: 2:20:38 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/array-rotation/
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_ROTATEARRAY_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_ROTATEARRAY_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void reverseArray(int userInput[],int start,int end) {
    while(start < end) {
        swap(userInput[start],userInput[end]);
        start++;
        end--;
    }
}

void rotateArrayByReversal(int userInput[],int size,int rotateBy) {
    if(size == 0) {
        return;
    }
    reverseArray(userInput,0,rotateBy-1);
    reverseArray(userInput,rotateBy,size-1);
    reverseArray(userInput,0,size-1);
}

void rotateArrayAuxSpace(int userInput[],int size,int rotateBy) {
    if(size == 0) {
        return;
    }
    int *auxSpace;
    auxSpace = (int *)malloc(size*sizeof(int));
    int fillIndex = -1;
    for(unsigned int counter = rotateBy; counter < size; counter++) {
        auxSpace[++fillIndex] = userInput[counter];
    }
    for(unsigned int counter = 0; counter < rotateBy; counter++) {
        auxSpace[++fillIndex] = userInput[counter];
    }
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/
void moveFirstValueToLast(int userInput[],int size) {
    if(size == 0) {
        return;
    }
    int temp = userInput[0];
    for(unsigned int counter = 1; counter < size; counter) {
        userInput[counter-1] = userInput[counter];
    }
    userInput[size-1] = temp;
}

void rotateArray(int userInput[],int size,int rotateBy) {
    if(rotateBy == 0 || rotateBy == size) {
        return;
    }
    for(unsigned int counter = 0; counter < rotateBy; counter++) {
        moveFirstValueToLast(userInput,size);
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE04_ROTATEARRAY_H_ */
