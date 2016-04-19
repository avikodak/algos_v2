/****************************************************************************************************************************************************
 *  File Name   		: nextgreaterelement.h
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page08\nextgreaterelement.h
 *  Created on			: Nov 26, 2014 :: 6:27:12 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/next-greater-element/
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

#ifndef NEXTGREATERELEMENT_H_
#define NEXTGREATERELEMENT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printNextGreatestElementStack(vector<int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    stack<int> auxSpace;
    for(int counter = userInput.size()-1; counter >= 0; counter--) {
        while(!auxSpace.empty() && auxSpace.top() < userInput[counter]) {
            auxSpace.pop();
        }
        if(auxSpace.empty()) {
            printf("%d\t",INT_MAX);
        } else {
            printf("%d\t",auxSpace.top());
        }
        auxSpace.push(userInput[counter]);
    }
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void printNextGreatestElement(vector<int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    bool nextGreatestFound;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        nextGreatestFound = false;
        for(unsigned int innerCounter = outerCounter; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[innerCounter] > userInput[outerCounter]) {
                printf("%d\t",userInput[innerCounter]);
                nextGreatestFound = true;
                break;
            }
        }
        if(!nextGreatestFound) {
            printf("%d",INT_MAX);
        }
    }
}

#endif /* NEXTGREATERELEMENT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
