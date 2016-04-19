/****************************************************************************************************************************************************
 *  File Name                   : quicksortinplace.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\sorting\quicksortinplace.h
 *  Created on                  : Feb 12, 2015 :: 2:47:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
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

#ifndef QUICKSORTINPLACE_H_
#define QUICKSORTINPLACE_H_

//Tested
void printVector(vector<int> userInput) {
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        printf("%d ",userInput[counter]);
    }
    printf("\n");
}

//Tested
int partitionArray(vector<int> &userInput,int start,int end) {
    int pivotElement = end;
    int key = userInput[end];
    int frontCrawler = start,rearCrawler = start;
    while(rearCrawler <= end) {
        if(userInput[rearCrawler] < key) {
            swap(userInput[frontCrawler],userInput[rearCrawler]);
            frontCrawler++;
        }
        rearCrawler++;
    }
    swap(userInput[frontCrawler],userInput[pivotElement]);
    printVector(userInput);
    return frontCrawler;
}

//Tested
void quickSort(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return;
    }
    int dividingIndex = partitionArray(userInput,startIndex,endIndex);
    quickSort(userInput,startIndex,dividingIndex-1);
    quickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* QUICKSORTINPLACE_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
