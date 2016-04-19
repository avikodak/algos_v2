/****************************************************************************************************************************************************
 *  File Name                   : missingnumbers.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\search\missingnumbers.h
 *  Created on                  : Feb 12, 2015 :: 12:06:39 PM
 *  Author                      : avikodak
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

#ifndef MISSINGNUMBERS_H_
#define MISSINGNUMBERS_H_

//Tested
void printMissingNumbers() {
    vector<int> firstList,secondList;
    int firstListSize,secondListSize,input;
    scanf("%d",&firstListSize);
    while(firstListSize--) {
        scanf("%d",&input);
        firstList.push_back(input);
    }
    sort(firstList.begin(),firstList.end());
    scanf("%d",&secondListSize);
    while(secondListSize--) {
        scanf("%d",&input);
        secondList.push_back(input);
    }
    sort(secondList.begin(),secondList.end());
    unsigned int firstCrawler = 0,secondCrawler = 0,prevNumber = INT_MIN;
    while(firstCrawler < firstList.size() || secondCrawler < secondList.size()) {
        if(firstCrawler > firstList.size() || secondCrawler > secondList.size()) {
            if(firstCrawler < firstList.size()) {
                break;
            } else {
                if(prevNumber != secondList[secondCrawler]) {
                    printf("%d ",secondList[secondCrawler]);
                    prevNumber = secondList[secondCrawler];
                }
                secondCrawler++;
            }
        } else {
            if(firstList[firstCrawler] == secondList[secondCrawler]) {
                firstCrawler++;
                secondCrawler++;
            } else if(firstList[firstCrawler] > secondList[secondCrawler]) {
                if(prevNumber != secondList[secondCrawler]) {
                    printf("%d ",secondList[secondCrawler]);
                    prevNumber = secondList[secondCrawler];
                }
                secondCrawler++;
            } else {
                firstCrawler++;
            }
        }
    }
}

#endif /* MISSINGNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
