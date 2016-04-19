/****************************************************************************************************************************************************
 *  File Name                   : segregateevenoddnumbers.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\geeksforgeeks\arrays\page09\segregateevenoddnumbers.h
 *  Created on                  : Nov 26, 2014 :: 12:40:07 AM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.geeksforgeeks.org/segregate-even-and-odd-numbers/
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

#ifndef SEGREGATEEVENODDNUMBERS_H_
#define SEGREGATEEVENODDNUMBERS_H_

/****************************************************************************************************************************************************/
/*                                                                     O(N) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void segregateEvenOddNumberQuickDivideStep(vector<int> &userInput) {
    if(userInput.size() < 2) {
        return;
    }
    int startIndex = 0,rearIndex = userInput.size() - 1;
    while(startIndex < rearIndex) {
        while(userInput[startIndex]%2 == 0) {
            startIndex++;
        }
        while(userInput[rearIndex]%2 == 1) {
            rearIndex--;
        }
        if(startIndex < rearIndex) {
            swap(userInput[startIndex],userInput[rearIndex]);
        }
    }
}

//Tested
void segregateEvenOddNumbersAuxspace(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    queue<int> evenAuxspace,oddAuxspace;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(userInput[counter]%2 == 0) {
            evenAuxspace.push(userInput[counter]);
        } else {
            oddAuxspace.push(userInput[counter]);
        }
    }
    int fillCounter = -1;
    while(!evenAuxspace.empty()) {
        userInput[++fillCounter] = evenAuxspace.front();
        evenAuxspace.pop();
    }
    while(!oddAuxspace.empty()) {
        userInput[++fillCounter] = oddAuxspace.front();
        oddAuxspace.pop();
    }
}

/****************************************************************************************************************************************************/
/*                                                                 O(NLOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
bool seoSortFunc(int firstUserInput,int secondUserInput) {
    return firstUserInput%2 == 0?true:false;
}

//Tested
void segregateEvenOddNumbers(vector<int> &userInput) {
    sort(userInput.begin(),userInput.end(),seoSortFunc);
}

/****************************************************************************************************************************************************/
/*                                                                 O(N^2) Algorithm                                                                     */
/****************************************************************************************************************************************************/
//Tested
void segregateEvenOddNumbersON2(vector<int> &userInput) {
    if(userInput.size() == 0) {
        return;
    }
    unsigned int zeroInnerCrawler = 0,oneInnerCrawler;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size();) {
        oneInnerCrawler = outerCrawler;
        while(oneInnerCrawler < userInput.size() && userInput[oneInnerCrawler] % 2 == 0) {
            oneInnerCrawler++;
        }
        if(oneInnerCrawler >= userInput.size()) {
            return;
        }
        zeroInnerCrawler = oneInnerCrawler + 1;
        while(zeroInnerCrawler < userInput.size() && userInput[zeroInnerCrawler]%2 == 1) {
            zeroInnerCrawler++;
        }
        if(zeroInnerCrawler >= userInput.size()) {
            return;
        }
        swap(userInput[zeroInnerCrawler],userInput[oneInnerCrawler]);
        outerCrawler = oneInnerCrawler;
    }
}

#endif /* SEGREGATEEVENODDNUMBERS_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
