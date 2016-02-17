/****************************************************************************************************************************************************
 *  File Name                   : icode16b.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/icode16b/icode16b.h
 *  Created on                  : Feb 16, 2016 :: 10:26:38 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/ICOD2016/problems/ICODE16B
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

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16B_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16B_H_

//Tested
void solveProblem(){
	unsigned int testCases;
	string fUserInput,sUserInput;
	unsigned int nikeshCount,jyotiCount;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> fUserInput >> sUserInput;
		int frequency[26] = {0};
		for(unsigned int counter = 0;counter < sUserInput.size();counter++){
			frequency[sUserInput[counter]-'a']++;
		}
		nikeshCount = 0;
		jyotiCount = 0;
		for(unsigned int counter = 0;counter < fUserInput.size();counter++){
			if(counter < sUserInput.size()){
				if(fUserInput[counter] == sUserInput[counter]){
					nikeshCount++;
				}
			}
			if(frequency[fUserInput[counter]-'a'] > 0){
				jyotiCount++;
				frequency[fUserInput[counter]-'a']--;
			}
		}
		printf("%uN%uJ%uS\n",nikeshCount,jyotiCount-nikeshCount,fUserInput.size()-jyotiCount);
	}
}

#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_ICODE16B_ICODE16B_H_ */
