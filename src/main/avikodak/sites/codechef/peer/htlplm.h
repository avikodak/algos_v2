/****************************************************************************************************************************************************
 *  File Name                   : htlplm.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/htlplm.h
 *  Created on                  : 16-Oct-2015 :: 7:52:58 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/HTLPLM
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
#include <iomanip>
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

#ifndef HTLPLM_H_
#define HTLPLM_H_

struct interval {
public:
    long long int start;
    long long int end;
    interval(long long int start,long long int end) {
        this->start = start;
        this->end = end;
    }
};


void printResults() {
    unsigned int testCases;
    long long int size,start,end,querySize,input;
    scanf("%u",&testCases);
    vector<interval *> userInput;
    bool flag;
    while(testCases--) {
        scanf("%lld %lld",&size,&querySize);
        userInput.clear();
        while(size--) {
            scanf("%lld %lld",&start,&end);
            userInput.push_back(new interval(start,end));
        }
        while(querySize--) {
            scanf("%lld",&input);
            flag = false;
            for(unsigned int counter = 0; counter < userInput.size(); counter++) {
                if(userInput[counter]->start <= input && userInput[counter]->end >= input) {
                    flag = true;
                    break;
                }
            }
            printf("%s\n",!flag?"YES":"NO");
        }
    }
}

//Binary Search Not Working
bool sortFunc(interval *first,interval *second) {
    if(first->start == second->start) {
        return first->end <  second->end;
    }
    return first->start < second->start;
}

bool binarySearch(vector<interval *> userInput,int key,int start,int end) {
    if(start > end) {
        return true;
    }
    int middleIndex = (start+end)/2;
    if(userInput[middleIndex]->start <= key && userInput[middleIndex]->end >= key) {
        return false;
    }
    if(userInput[middleIndex]->start > key) {
        return binarySearch(userInput,key,start,middleIndex-1);
    } else {
        return binarySearch(userInput,key,middleIndex+1,end);
    }
}

void printResults2() {
    unsigned int testCases;
    long long int start,end,intervalCount,queryCount,key;
    scanf("%u",&testCases);
    vector<interval *> userInput;
    while(testCases--) {
        scanf("%lld %lld",&intervalCount,&queryCount);
        userInput.clear();
        while(intervalCount--) {
            scanf("%lld %lld",&start,&end);
            userInput.push_back(new interval(start,end));
        }
        sort(userInput.begin(),userInput.end(),sortFunc);
        while(queryCount--) {
            scanf("%lld",&key);
            printf("%s\n",binarySearch(userInput,key,0,userInput.size()-1)?"YES":"NO");
        }
    }
}

#endif /* HTLPLM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
