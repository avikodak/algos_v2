/****************************************************************************************************************************************************
 *  File Name                   : chefdete.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/febchallenge2016/chefdete.h
 *  Created on                  : Feb 14, 2016 :: 12:15:04 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/FEB16/problems/CHEFDETE
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_FEBCHALLENGE2016_CHEFDETE_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_FEBCHALLENGE2016_CHEFDETE_H_

void solveProblem(){
	unsigned long long int testCases;
	long long int input;
	scanf("%llu",&testCases);
	vector<bool> userInput;
	userInput.assign(testCases,false);
	while(testCases--){
		scanf("%lld",&input);
		userInput[input] = true;
	}
	for(unsigned long long int counter = 0;counter < userInput.size();counter++){
		if(!userInput[counter]){
			printf("%llu\t",counter+1);
		}
	}
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_FEBCHALLENGE2016_CHEFDETE_H_ */
