/****************************************************************************************************************************************************
 *  File Name   		: subsetsumproblem.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\subsetsumproblem.h
 *  Created on			: Jan 12, 2015 :: 4:10:02 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SUBSETSUMPROBLEM_H_
#define SUBSETSUMPROBLEM_H_

//Tested
bool subsetSumProblemNaive(vector<int> userInput,int sum,unsigned int currentIndex = 0) {
    if(currentIndex > userInput.size()) {
        return false;
    }
    if(currentIndex == userInput.size()) {
        return sum == 0;
    }
    return subsetSumProblemNaive(userInput,sum,currentIndex+1) || subsetSumProblemNaive(userInput,sum - userInput[currentIndex],currentIndex+1);
}

//Tested
bool subsetSumProblem(vector<int> userInput,int sum) {
    if(sum == 0) {
        return userInput.size() == 0;
    }
    if(userInput.size() == 0) {
        return false;
    }
    vector<vector<bool> > auxSpace(sum+1);
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace[counter].assign(userInput.size(),false);
    }
    for(unsigned int columnCounter = 0; columnCounter < auxSpace[0].size(); columnCounter++) {
        auxSpace[0][columnCounter] = true;
    }
    for(unsigned int rowCounter = 0; rowCounter < auxSpace.size(); rowCounter++) {
        auxSpace[rowCounter][0] = false;
    }
    auxSpace[0][0] = true;
    for(int rowCounter = 1; rowCounter < (int)auxSpace.size(); rowCounter++) {
        for(int columnCounter = 1; columnCounter < (int)auxSpace[0].size(); columnCounter++) {
            auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter-1];
            if(rowCounter - userInput[columnCounter] >= 0) {
                auxSpace[rowCounter][columnCounter] = auxSpace[rowCounter][columnCounter] || auxSpace[rowCounter - userInput[columnCounter]][columnCounter-1];
            }
        }
    }
    return auxSpace[auxSpace.size()-1][auxSpace[0].size()-1];
}

#endif /* SUBSETSUMPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
