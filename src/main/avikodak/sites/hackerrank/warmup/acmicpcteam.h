/****************************************************************************************************************************************************
 *  File Name                   : acmicpcteam.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\hackerrank\warmup\acmicpcteam.h
 *  Created on                  : Feb 5, 2015 :: 9:06:42 PM
 *  Author                      : AVINASH
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

#ifndef ACMICPCTEAM_H_
#define ACMICPCTEAM_H_

//Tested
void maxTopicsAndTeams() {
    long int people,topics;
    scanf("%ld %ld",&people,&topics);
    vector<string> userInput;
    string input;
    for(unsigned int counter = 0; counter < people; counter++) {
        cin >> input;
        userInput.push_back(input);
    }
    hash_map<long int,long int> topicPairsCount;
    int maxTopicsKnown = 0,topicsCount;
    for(unsigned int outerCrawler = 0; outerCrawler < userInput.size()-1; outerCrawler++) {
        for(unsigned int innerCrawler = outerCrawler+1; innerCrawler < userInput.size(); innerCrawler++) {
            topicsCount = 0;
            for(unsigned int counter = 0; counter < topics; counter++) {
                if(userInput[outerCrawler] == '1' || userInput[innerCrawler] == '1') {
                    topicsCount++;
                }
            }
            maxTopicsKnown = max(maxTopicsKnown,topicsCount);
            if(topicPairsCount.find(topicsCount) == topicPairsCount.end()) {
                topicPairsCount[topicsCount] = 1;
            } else {
                topicPairsCount[topicsCount] += 1;
            }
        }
    }
    printf("%d\n%d",maxTopicsKnown,topicPairsCount.find(maxTopicsKnown)->second);
}

#endif /* ACMICPCTEAM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
