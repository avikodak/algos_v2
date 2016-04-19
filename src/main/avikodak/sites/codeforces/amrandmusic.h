/****************************************************************************************************************************************************
 *  File Name                   : amrandmusic.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\amrandmusic.h
 *  Created on                  : Apr 11, 2015 :: 7:51:59 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/507/A
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

#ifndef AMRANDMUSIC_H_
#define AMRANDMUSIC_H_

//Tested
struct valIndex {
public:
    unsigned int value;
    unsigned int index;

    valIndex(unsigned int value,unsigned int index) {
        this->value = value;
        this->index = index;
    }
};

//Tested
bool compare(valIndex *first,valIndex *second) {
    return first->value < second->value;
}

//Tested
void printInstruments() {
    unsigned int totalDays,instrumentsCount,days;
    scanf("%u %u",&instrumentsCount,&totalDays);
    vector<valIndex *> userInput;
    valIndex *temp;
    for(unsigned int counter = 0; counter < instrumentsCount; counter++) {
        scanf("%u",&days);
        temp = new valIndex(days,counter+1);
        userInput.push_back(temp);
    }
    sort(userInput.begin(),userInput.end(),compare);
    queue<unsigned int> result;
    for(unsigned int counter = 0; counter < userInput.size(); counter++) {
        if(totalDays >= userInput[counter]->value) {
            result.push(userInput[counter]->index);
            totalDays -= userInput[counter]->value;
        } else {
            break;
        }
    }
    printf("%u\n",result.size());
    while(!result.empty()) {
        printf("%u ",result.front());
        result.pop();
    }
}

#endif /* AMRANDMUSIC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
