/****************************************************************************************************************************************************
 *  File Name                   : freecash.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\freecash.h
 *  Created on                  : Apr 8, 2015 :: 12:39:40 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/237/A
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

#ifndef FREECASH_H_
#define FREECASH_H_

//Tested
void getFreeCashCountersRequired(){
	unsigned int testCases,hour,minute;
	scanf("%u",&testCases);
	map<unsigned int,map<unsigned int,unsigned int> > timeCountersMap;
	map<unsigned int,map<unsigned int,unsigned int> >::iterator itToTimeCountersMap;
	map<unsigned int,unsigned int> existingMinuteMap;
	map<unsigned int,unsigned int>::iterator itToExistingMinuteMap;
	unsigned int maxFreeCash = 0;
	while(testCases--){
		scanf("%u %u",&hour,&minute);
		if((itToTimeCountersMap = timeCountersMap.find(hour)) != timeCountersMap.end()){
			existingMinuteMap = itToTimeCountersMap->second;
			if((itToExistingMinuteMap = existingMinuteMap.find(minute)) != existingMinuteMap.end()){
				timeCountersMap[hour][minute] = itToExistingMinuteMap->second+1;
					maxFreeCash = max(maxFreeCash,itToExistingMinuteMap->second+1);
			}else{
				timeCountersMap[hour][minute] = 1;
				maxFreeCash = max(maxFreeCash,1U);
			}
		}else{
			timeCountersMap[hour][minute] = 1;
			maxFreeCash = max(maxFreeCash,1U);
		}
	}
	printf("%u",maxFreeCash);
}
#endif /* FREECASH_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
