/****************************************************************************************************************************************************
 *  File Name                   : boxstacking.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\dp\page02\boxstacking.h
 *  Created on                  : Dec 15, 2014 :: 3:13:45 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/
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

#ifndef BOXSTACKING_H_
#define BOXSTACKING_H_

int bsDivideStepQuickSort(vector<dimensions *> &userInput,int startIndex,int endIndex) {
    if(startIndex > endIndex) {
        return INT_MIN;
    }
    int pivotIndex = endIndex;
    int key = userInput[pivotIndex]->depth * userInput[pivotIndex]->width;
    while(startIndex < endIndex) {
        while(userInput[startIndex]->depth * userInput[startIndex]->width > key) {
            startIndex++;
        }
        while(startIndex < endIndex && userInput[endIndex]->depth *userInput[endIndex]->width <= key) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            swap(userInput[startIndex],userInput[endIndex]);
        }
    }
    swap(userInput[endIndex],userInput[pivotIndex]);
    return endIndex;
}

void bsQuickSort(vector<dimensions *> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = bsDivideStepQuickSort(userInput,startIndex,endIndex);
    bsQuickSort(userInput,startIndex,dividingIndex-1);
    bsQuickSort(userInput,dividingIndex+1,endIndex);
}

int getMaxHeightBoxStacking(vector<dimensions *> userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    vector<dimensions *> auxSpace;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        auxSpace.push_back(userInput[counter]);
        auxSpace.push_back(new dimensions(userInput[counter]->width,min(userInput[counter]->height,userInput[counter]->depth),max(userInput[counter]->height,userInput[counter]->depth)));
        auxSpace.push_back(new dimensions(userInput[counter]->depth,min(userInput[counter]->height,userInput[counter]->width),max(userInput[counter]->height,userInput[counter]->width)));
    }
    bsQuickSort(auxSpace,0,auxSpace.size()-1);
    vector<int> maxHeights;
    maxHeights.push_back(auxSpace[0]->height);
    int height;
    for(unsigned int outerCrawler = 1; outerCrawler < auxSpace.size(); outerCrawler++) {
        height = 0;
        for(unsigned int innerCrawler = 0; innerCrawler < outerCrawler; innerCrawler++) {
            if(auxSpace[innerCrawler]->depth > auxSpace[outerCrawler]->depth && auxSpace[innerCrawler]->width > auxSpace[outerCrawler]->width) {
                height = max(height,maxHeights[innerCrawler]);
            }
        }
        maxHeights.push_back(height+auxSpace[outerCrawler]->height);
    }
    return *max(maxHeights.begin(),maxHeights.end());
}

#endif /* BOXSTACKING_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
