/****************************************************************************************************************************************************
 *  File Name                   : insoma3.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/insoma3.h
 *  Created on                  : 12-Sep-2015 :: 6:06:44 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/INSOMA3
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <stdint.h>
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef INSOMA3_H_
#define INSOMA3_H_

//Tested
int icMerge(vector<int> &userInput,int startIndex,int midIndex,int endIndex) {
    int firstCrawler = startIndex,secondCrawler = midIndex+1;
    vector<int> temp;
    int inversionCount = 0;
    while(firstCrawler <= midIndex || secondCrawler <= endIndex) {
        if(firstCrawler > midIndex || secondCrawler > endIndex) {
            if(firstCrawler <= midIndex) {
                temp.push_back(userInput[firstCrawler++]);
            } else {
                temp.push_back(userInput[secondCrawler++]);
            }
        } else {
            if(userInput[firstCrawler] < userInput[secondCrawler]) {
                temp.push_back(userInput[firstCrawler++]);
            } else {
                temp.push_back(userInput[secondCrawler++]);
                inversionCount += midIndex + 1 - firstCrawler;
            }
        }
    }
    for(int counter = 0; counter < temp.size(); counter++) {
        userInput[startIndex + counter] = temp[counter];
    }
    return inversionCount;
}

//Tested
int inversionCount(vector<int> &userInput,int startIndex,int endIndex) {
    if(startIndex >= endIndex) {
        return 0;
    }
    int middleIndex = (startIndex + endIndex)/2;
    int counter = inversionCount(userInput,startIndex,middleIndex);
    counter += inversionCount(userInput,middleIndex+1,endIndex);
    counter += icMerge(userInput,startIndex,middleIndex,endIndex);
    return counter;
}

//Tested
int inversionCountMerging(vector<int> userInput) {
    if(userInput.size() < 2) {
        return 0;
    }
    int counter = inversionCount(userInput,0,userInput.size()-1);
    return counter;
}

//Tested
void printDisorderlinessIndex() {
    int size,input;
    vector<int> userInput;
    scanf("%u",&size);
    for(int counter = 0; counter < size; counter++) {
        scanf("%u",&input);
        userInput.push_back(input);
    }
    cout << inversionCountMerging(userInput) << endl;
}

#endif /* INSOMA3_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
