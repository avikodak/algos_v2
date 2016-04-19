/****************************************************************************************************************************************************
 *  File Name                   : scoringefficiency.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\scoringefficiency.h
 *  Created on                  : Jul 18, 2015 :: 3:19:25 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=2341
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

#ifndef SCORINGEFFICIENCY_H_
#define SCORINGEFFICIENCY_H_

//Tested
class ScoringEfficiency {
public:
    double getPointsPerShot(vector<string> gameLog) {
        map<string,int> logScoreMap;
        map<string,int>::iterator itToLogScoreMap;
        logScoreMap.insert(pair<string,int>("Made 3 point field goal",3));
        logScoreMap.insert(pair<string,int>("Made 2 point field goal",2));
        logScoreMap.insert(pair<string,int>("Made free throw",1));
        logScoreMap.insert(pair<string,int>("Missed free throw",-1));
        int totalPoints = 0,freeThrowsAttempted = 0;
        for(unsigned int counter = 0; counter < gameLog.size(); counter++) {
            if((itToLogScoreMap = logScoreMap.find(gameLog[counter])) != logScoreMap.end()) {
                if(itToLogScoreMap->second == -1 || itToLogScoreMap->second == 1) {
                    freeThrowsAttempted++;
                }
                if(itToLogScoreMap->second != -1) {
                    totalPoints += itToLogScoreMap->second;
                }
            }
        }
        return (double)totalPoints/((double)(gameLog.size()-freeThrowsAttempted)+(double)(0.5*freeThrowsAttempted));
    }
};

#endif /* SCORINGEFFICIENCY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
