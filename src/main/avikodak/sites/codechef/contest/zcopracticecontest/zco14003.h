/****************************************************************************************************************************************************
 *  File Name                   : zco14003.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/zcopracticecontest/zco14003.h
 *  Created on                  : Feb 19, 2016 :: 6:57:40 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/ZCOPRAC/problems/ZCO14003
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ZCOPRACTICECONTEST_ZCO14003_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ZCOPRACTICECONTEST_ZCO14003_H_

bool sortFunc(long long int fUserInput,long long int sUserInput){
	return fUserInput > sUserInput;
}

void solveProblem(){
	long long int input,size;
	vector<long long int> userInput;
	scanf("%lld",&size);
	for(unsigned int counter = 0;counter < size;counter++){
		scanf("%lld",&input);
		userInput.push_back(input);
	}
	sort(userInput.begin(),userInput.end(),sortFunc);
	long long int maxProfit = userInput[0];
	for(unsigned int counter = 1;counter < size;counter++){
		maxProfit = max(maxProfit,(counter+1)*userInput[counter]);
	}
	printf("%lld",maxProfit);
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ZCOPRACTICECONTEST_ZCO14003_H_ */
