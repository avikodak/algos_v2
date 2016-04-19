/****************************************************************************************************************************************************
 *  File Name   		: rotatearray.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\rotatearray.h
 *  Created on			: Nov 25, 2014 :: 7:08:55 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/array-rotation/
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ROTATEARRAY_H_
#define ROTATEARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayAuxspace(vector<int> &userInput,unsigned int rotateBy) {
    if(userInput.size() == 0) {
        return;
    }
    vector<int> auxSpace;
    unsigned int counter;
    for(counter = 0; counter < rotateBy; counter++) {
        auxSpace.push_back(userInput[counter]);
    }
    int fillCounter = -1;
    while(counter < userInput.size()) {
        userInput[++fillCounter] = userInput[counter++];
    }
    for(counter = 0; counter < auxSpace.size(); counter++) {
        userInput[++fillCounter] = auxSpace[counter];
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayByOne(vector<int> &userInput) {
    int temp = userInput[0];
    for(unsigned int counter = 0; counter < userInput.size()-1; counter++) {
        userInput[counter] = userInput[counter+1];
    }
    userInput[userInput.size()-1] = temp;
}

//Tested
void rotateArrayON2(vector<int> &userInput,unsigned rotateBy) {
    while(rotateBy--) {
        rotateArrayByOne(userInput);
    }
}

#endif /* ROTATEARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
