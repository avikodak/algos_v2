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
