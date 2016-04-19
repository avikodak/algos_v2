/****************************************************************************************************************************************************
 *  File Name   		: horses.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\horses.h
 *  Created on			: Feb 9, 2015 :: 4:14:53 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/HORSES/
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

#ifndef HORSES_H_
#define HORSES_H_

//Tested
void printMinDifference() {
    int testCases,input,size,minDiff;
    scanf("%d",&testCases);
    vector<int> userInput;
    while(testCases--) {
        scanf("%d",&size);
        userInput.clear();
        while(size--) {
            scanf("%d",&input);
            userInput.push_back(input);

        }
        sort(userInput.begin(),userInput.end());
        minDiff = INT_MAX;
        for(unsigned int counter = 0; counter < userInput.size()-1; counter++) {
            minDiff = min(minDiff,userInput[counter+1] - userInput[counter]);
        }
        printf("%d\n",minDiff);
    }
}

#endif /* HORSES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
