/****************************************************************************************************************************************************
 *  File Name                   : rrcode.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/rrcode.h
 *  Created on                  : 21-Oct-2015 :: 9:54:04 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/RRCODE
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
#include <iomanip>
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

#ifndef RRCODE_H_
#define RRCODE_H_

//Tested
void printResults(){
	long long int testCases,size,kOperation,result,input;
	string operation;
	scanf("%lld",&testCases);
	vector<long long int> userInput;
	while(testCases--){
		scanf("%lld %lld %lld",&size,&kOperation,&result);
		userInput.clear();
		for(long long int counter = 0;counter < size;counter++){
			scanf("%lld",&input);
			userInput.push_back(input);
		}
		cin >> operation;
		if(operation[0] == 'X'){
			kOperation = kOperation%2;
		}else{
			kOperation = min(kOperation,1ll);
		}
		while(kOperation-- > 0){
			for(long long int counter = 0;counter < size;counter++){
				if(operation[0] == 'X'){
					result ^= userInput[counter];
				}else if(operation[0] == 'A'){
					result &= userInput[counter];
				}else{
					result |= userInput[counter];
				}
			}
		}
		printf("%lld\n",result);
	}
}

#endif /* RRCODE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
