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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
	double getPointsPerShot(vector<string> gameLog){
		map<string,int> logScoreMap;
		map<string,int>::iterator itToLogScoreMap;
		logScoreMap.insert(pair<string,int>("Made 3 point field goal",3));
		logScoreMap.insert(pair<string,int>("Made 2 point field goal",2));
		logScoreMap.insert(pair<string,int>("Made free throw",1));
		logScoreMap.insert(pair<string,int>("Missed free throw",-1));
		int totalPoints = 0,freeThrowsAttempted = 0;
		for(unsigned int counter = 0;counter < gameLog.size();counter++){
			if((itToLogScoreMap = logScoreMap.find(gameLog[counter])) != logScoreMap.end()){
				if(itToLogScoreMap->second == -1 || itToLogScoreMap->second == 1){
					freeThrowsAttempted++;
				}
				if(itToLogScoreMap->second != -1){
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
