/****************************************************************************************************************************************************
 *  File Name                   : kiwijuiceeasy.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\kiwijuiceeasy.h
 *  Created on                  : Mar 30, 2015 :: 5:47:39 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=11020
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

#ifndef KIWIJUICEEASY_H_
#define KIWIJUICEEASY_H_

class KiwiJuiceEasy{
public:
	vector<int> thePouring(vector<int> capacities,vector<int> bottles,vector<int> fromId,vector<int> toId){
		for(unsigned int counter = 0;counter < fromId.size();counter++){
			if(bottles[fromId[counter]] > 0){
				if(bottles[toId[counter]] + bottles[fromId[counter]] <= capacities[toId[counter]]){
					bottles[toId[counter]] += bottles[fromId[counter]];
					bottles[fromId[counter]] = 0;
				}else{
					bottles[fromId[counter]] -= capacities[toId[counter]] - bottles[toId[counter]];
					bottles[toId[counter]] = capacities[toId[counter]];
				}
			}
		}
		return bottles;
	}
};

#endif /* KIWIJUICEEASY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
