/****************************************************************************************************************************************************
 *  File Name                   : twoarrays.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\greedy\twoarrays.h
 *  Created on                  : Jul 17, 2015 :: 5:12:34 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/two-arrays
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

#ifndef TWOARRAYS_H_
#define TWOARRAYS_H_

//Tested
bool sortFunc(unsigned int first,unsigned int second){
	return first > second;
}

//Tested
void isPermutationPresentForSum(){
	unsigned int testCases;
	scanf("%u",&testCases);
	unsigned int inputSize,sum,input;
	vector<unsigned int> firstUserInput,secondUserInput;
	bool flag;
	while(testCases--){
		scanf("%u %u",&inputSize,&sum);
		firstUserInput.clear();
		secondUserInput.clear();
		for(unsigned int counter = 0;counter < inputSize;counter++){
			scanf("%u",&input);
			firstUserInput.push_back(input);
		}
		for(unsigned int counter = 0;counter < inputSize;counter++){
			scanf("%u",&input);
			secondUserInput.push_back(input);
		}
		sort(firstUserInput.begin(),firstUserInput.end());
		sort(secondUserInput.begin(),secondUserInput.end(),sortFunc);
		flag = false;
		for(unsigned int counter = 0;counter < firstUserInput.size();counter++){
			if(firstUserInput[counter] + secondUserInput[counter] < sum){
				printf("NO\n");
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("YES\n");
		}
	}
}

#endif /* TWOARRAYS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
