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
