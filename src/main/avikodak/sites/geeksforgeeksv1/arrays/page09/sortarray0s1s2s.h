/****************************************************************************************************************************************************
 *  File Name                   : sortarray0s1s2s.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\sortarray0s1s2s.h
 *  Created on                  : Nov 26, 2014 :: 12:55:15 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
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

#ifndef SORTARRAY0S1S2S_H_
#define SORTARRAY0S1S2S_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Dutch national flag problem
//Tested
void sortArray0s1s2s(vector<int> &userInput) {
    int startIndex = 0,midIndex = 0,endIndex = userInput.size()-1,temp;
    while(midIndex <= endIndex) {
        switch (userInput[midIndex]) {
        case 0:
            temp = userInput[startIndex];
            userInput[startIndex] = userInput[midIndex];
            userInput[midIndex] = temp;
            startIndex++;
            midIndex++;
            break;
        case 1:
            midIndex++;
            break;
        case 2:
            temp = userInput[endIndex];
            userInput[endIndex] = userInput[midIndex];
            userInput[midIndex] = temp;
            endIndex--;
            break;
        }

    }
}

//Tested
void sortArray0s1s2sV2(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    unsigned int zeroFrequency = 0,oneFrequency = 0,twoFrequency = 0;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter] == 0) {
            zeroFrequency++;
        } else if(userInput[counter] == 1) {
            oneFrequency++;
        } else {
            twoFrequency++;
        }
    }
    int fillCounter = -1;
    while(zeroFrequency--) {
        userInput[++fillCounter] = 0;
    }
    while(oneFrequency--) {
        userInput[++fillCounter] = 1;
    }
    while(twoFrequency--) {
        userInput[++fillCounter] = 2;
    }
}

//Tested
int move2sToRightPlace(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return 0;
    }
    int startCrawler = 0,endCrawler = userInput.size()-1;
    while(startCrawler < endCrawler) {
        while(userInput[startCrawler] == 0 || userInput[startCrawler] == 1) {
            startCrawler++;
        }
        while(userInput[endCrawler] == 2) {
            endCrawler--;
        }
        if(startCrawler < endCrawler) {
            userInput[startCrawler] = userInput[endCrawler];
            userInput[endCrawler] = 2;
        }
    }
    return endCrawler;
}

//Tested
void move0s1sToRightPlace(vector<int> &userInput,int startIndex,int endIndex) {
    while(startIndex < endIndex) {
        while(userInput[startIndex] == 0) {
            startIndex++;
        }
        while(userInput[endIndex] == 1) {
            endIndex--;
        }
        if(startIndex < endIndex) {
            userInput[startIndex] = 0;
            userInput[endIndex] = 1;
        }
    }
}

//Tested
void sortArray0s1s2sQuickSortDivideSteps(vector<int> &userInput) {
    int index = move2sToRightPlace(userInput);
    move0s1sToRightPlace(userInput,0,index);
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void sortArray0s1s2sONLOGN(vector<int> &userInput) {
    sort(userInput.begin(),userInput.end());
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void sSwap(int *firstPtr,int *secondPtr) {
    int temp = *firstPtr;
    *firstPtr = *secondPtr;
    *secondPtr = temp;
}

//Tested
void sortArrayON2(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    for(unsigned int outerCounter = 0; outerCounter < userInput.size(); outerCounter++) {
        for(unsigned int innerCounter = 0; innerCounter < userInput.size()-1; innerCounter++) {
            if(userInput[innerCounter] > userInput[innerCounter+1]) {
                sSwap(&userInput[innerCounter],&userInput[innerCounter+1]);
            }
        }
    }
}

#endif /* SORTARRAY0S1S2S_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
