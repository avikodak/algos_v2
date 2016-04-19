/****************************************************************************************************************************************************
 *  File Name                   : bestbats.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/bestbats.h
 *  Created on                  : 31-Oct-2015 :: 9:24:13 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/BESTBATS
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

#ifndef BESTBATS_H_
#define BESTBATS_H_

//Tested
vector<vector<unsigned int> > generateCombinations() {
    vector<vector<unsigned int> > combinations;
    vector<unsigned int> indiComb;
    indiComb.push_back(1);
    combinations.push_back(indiComb);
    indiComb.clear();
    indiComb.push_back(1);
    indiComb.push_back(2);
    indiComb.push_back(1);
    combinations.push_back(indiComb);
    for(unsigned int outerCounter = 2; outerCounter < 11; outerCounter++) {
        indiComb.clear();
        indiComb.push_back(1);
        for(unsigned int innerCounter = 0; innerCounter < combinations[outerCounter-1].size()-1; innerCounter++) {
            indiComb.push_back(combinations[outerCounter-1][innerCounter]+combinations[outerCounter-1][innerCounter+1]);
        }
        indiComb.push_back(1);
        combinations.push_back(indiComb);
    }
    return combinations;
}

//Tested
void printResults() {
    vector<vector<unsigned int> > combinations = generateCombinations();
    unsigned int testCases,score,reqPeople;
    scanf("%u",&testCases);
    map<unsigned int,unsigned int> scoreFreq;
    map<unsigned int,unsigned int>::reverse_iterator itToScoreFreq;
    while(testCases--) {
        scoreFreq.clear();
        for(unsigned int counter = 0; counter < 11; counter++) {
            scanf("%u",&score);
            if((scoreFreq.find(score)) != scoreFreq.end()) {
                scoreFreq[score]++;
            } else {
                scoreFreq[score] = 1;
            }
        }
        scanf("%u",&reqPeople);
        if(reqPeople == 11) {
            printf("1\n");
        } else {
            for(itToScoreFreq = scoreFreq.rbegin(); itToScoreFreq != scoreFreq.rend(); ++itToScoreFreq) {
                if(itToScoreFreq->second < reqPeople) {
                    reqPeople -= itToScoreFreq->second;
                } else if(itToScoreFreq->second == reqPeople) {
                    printf("1\n");
                    break;
                } else {
                    printf("%u\n",combinations[itToScoreFreq->second-1][reqPeople]);
                    break;
                }
            }
        }
    }
}

#endif /* BESTBATS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
