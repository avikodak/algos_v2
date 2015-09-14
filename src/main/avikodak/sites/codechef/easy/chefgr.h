/****************************************************************************************************************************************************
 *  File Name                   : chefgr.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/chefgr.h
 *  Created on                  : 14-Sep-2015 :: 7:29:26 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/CHEFGR
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

#ifndef CHEFGR_H_
#define CHEFGR_H_

void printResults(){
	unsigned int testCases,size,total,sum,input,maxVal;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	while(testCases--){
		scanf("%u %u",&size,&total);
		userInput.clear();
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		sum = 0;
		maxVal = *max_element(userInput.begin(),userInput.end());
		for(unsigned int counter = 0;counter < size;counter++){
			sum += (userInput[counter] - maxVal);
		}
		printf("%s\n",total >= sum?"Yes":"No");
	}
}

#endif /* CHEFGR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
