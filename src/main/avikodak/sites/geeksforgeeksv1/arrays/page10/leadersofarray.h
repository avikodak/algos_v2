/****************************************************************************************************************************************************
 *  File Name                   : leadersofarray.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page10\leadersofarray.h
 *  Created on                  : Nov 25, 2014 :: 12:03:29 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/leaders-in-an-array/
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

#ifndef LEADERSOFARRAY_H_
#define LEADERSOFARRAY_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printLeadersInArray(vector<int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    int maxTillNow = INT_MIN;
    for(int counter = userInput.size()-1; counter >= 0; counter--) {
        if(userInput[counter] > maxTillNow) {
            printf("%d\t",userInput[counter]);
            maxTillNow = userInput[counter];
        }
    }
}

//Tested
int printLeaders(vector<int> userInput,unsigned int counter = 0) {
    if(counter >= userInput.size()) {
        return INT_MIN;
    }
    int resultTillNow = printLeaders(userInput,counter+1);
    if(userInput[counter] > resultTillNow) {
        printf("%d\t",userInput[counter]);
        resultTillNow = userInput[counter];
    }
    return resultTillNow;
}

//Tested
void printLeadersAuxSpace(vector<int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    stack<int> auxSpace;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace.push(userInput[counter]);
    }
    int maxTillNow = INT_MIN;
    while(!auxSpace.empty()) {
        if(auxSpace.top() > maxTillNow) {
            printf("%d\t",auxSpace.top());
            maxTillNow = auxSpace.top();
        }
        auxSpace.pop();
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void printLeadersInArrayON2(vector<int> userInput) {
    if(userInput.size() == 0) {
        return;
    }
    bool isLeader;
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        isLeader = true;
        for(unsigned int innerCounter = outerCounter+1; innerCounter < userInput.size(); innerCounter++) {
            if(userInput[innerCounter] > userInput[outerCounter]) {
                isLeader = false;
            }
        }
        if(isLeader) {
            printf("%d\t",userInput[outerCounter]);
        }
    }
}

#endif /* LEADERSOFARRAY_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
