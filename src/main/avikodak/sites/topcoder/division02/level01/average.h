/****************************************************************************************************************************************************
 *  File Name                   : average.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\average.h
 *  Created on                  : Jul 15, 2015 :: 11:38:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Local Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=818
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

#ifndef AVERAGE_H_
#define AVERAGE_H_

//Local Tested
class Average {
public:
	int belowAvg(vector<int> math, vector<int> verbal){
		int sum = 0;
		for(unsigned int counter = 0;counter < math.size();counter++){
			sum += math[counter];
			sum += verbal[counter];
		}
		double average = ((double)(sum)/(double)(math.size()));
		int belowAverageCount = 0;
		for(unsigned int counter = 0;counter < math.size();counter++){
			if(((double)math[counter] + (double)verbal[counter]) < average){
				belowAverageCount++;
			}
		}
		return belowAverageCount;
	}
};

#endif /* AVERAGE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
