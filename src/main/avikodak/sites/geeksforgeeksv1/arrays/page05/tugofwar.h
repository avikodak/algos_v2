/****************************************************************************************************************************************************
 *  File Name                   : tugofwar.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page05\tugofwar.h
 *  Created on                  : Dec 25, 2014 :: 12:37:40 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef TUGOFWAR_H_
#define TUGOFWAR_H_

void tugOfWarMain(vector<int> userInput,int arraySum,int &minDifference,vector<int> &minSetIndices,vector<int> runningSet,int currentIndex,unsigned int kValue) {
    if(kValue > userInput.size()) {
        throw "Invalid K value";
    }
    if(kValue == 0) {
        int currentSetSum = 0;
        for(unsigned int counter = 0; counter < runningSet.size(); counter++) {
            currentSetSum += userInput[runningSet[counter]];
        }
        if(minDifference > abs(2*currentSetSum - arraySum)) {
            minSetIndices.clear();
            copy(runningSet.begin(),runningSet.end(),minSetIndices.begin());
            minDifference = abs(2*currentSetSum - arraySum);
        }
        return;
    }
    tugOfWarMain(userInput,arraySum,minDifference,minSetIndices,runningSet,currentIndex+1,kValue);
    runningSet.push_back(currentIndex);
    tugOfWarMain(userInput,arraySum,minDifference,minSetIndices,runningSet,currentIndex+1,kValue-1);
}

vector<vector<int> > tugOfWar(vector<int> userInput) {
    vector<vector<int> > sets;
    if(userInput.size() == 0) {
        return sets;
    }
    vector<int> firstSet,runningSet,secondSet;
    int minDifference = INT_MAX,arraySum = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        arraySum += userInput[counter];
    }
    tugOfWarMain(userInput,arraySum,minDifference,firstSet,runningSet,0,userInput.size()/2);
    unsigned int firstCrawler = 0,secondCrawler = 0;
    while(firstCrawler < userInput.size() || secondCrawler < firstSet.size()) {
        if(secondCrawler > firstSet.size()) {
            while(firstCrawler < userInput.size()) {
                secondSet.push_back(firstCrawler++);
            }
            break;
        } else {
            if(firstSet[secondCrawler] == (int)firstCrawler) {
                secondCrawler++;
                firstCrawler++;
            } else {
                secondSet.push_back(firstCrawler);
                firstCrawler++;
            }
        }
    }
    sets.push_back(firstSet);
    sets.push_back(secondSet);
    return sets;
}

#endif /* TUGOFWAR_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
