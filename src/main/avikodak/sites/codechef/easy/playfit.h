/****************************************************************************************************************************************************
 *  File Name                   : playfit.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\playfit.h
 *  Created on                  : Sep 6, 2015 :: 8:14:07 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PLAYFIT
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

#ifndef PLAYFIT_H_
#define PLAYFIT_H_

//Tested
unsigned int max(unsigned int first,unsigned int second){
	return first > second?first:second;
}

//Tested
void getMaxDifference(vector<unsigned int> userInput){
	if(userInput.size() < 2){
		printf("UNFIT\n");
		return;
	}
	unsigned int maxValue = userInput[userInput.size()-1],maxDifference = 0;
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		if(userInput[counter] > maxValue){
			maxValue = userInput[counter];
		}else{
			maxDifference = max(maxDifference,maxValue - userInput[counter]);
		}
	}
	if(maxDifference > 0){
		printf("%u\n",maxDifference);
	}else{
		printf("UNFIT\n");
	}
}

//Tested
void printResults(){
	unsigned int testCases,size,input;
	vector<unsigned int> userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		while(size--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		getMaxDifference(userInput);
	}
}

#endif /* PLAYFIT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
