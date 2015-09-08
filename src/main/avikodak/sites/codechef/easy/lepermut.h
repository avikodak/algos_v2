/****************************************************************************************************************************************************
 *  File Name                   : lepermut.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\lepermut.h
 *  Created on                  : Sep 2, 2015 :: 9:01:55 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/LEPERMUT
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

#ifndef LEPERMUT_H_
#define LEPERMUT_H_

//Tested
void isGoodPermutation(vector<unsigned int> userInput){
	unsigned int inversionCount = 0,localInversionCount = 0;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size()-1;outerCounter++){
		if(userInput[outerCounter] > userInput[outerCounter+1]){
			localInversionCount++;
		}
		for(unsigned int innerCounter = outerCounter+1;innerCounter < userInput.size();innerCounter++){
			if(userInput[outerCounter] > userInput[innerCounter]){
				inversionCount++;
			}
		}
	}
	printf("%s\n",localInversionCount == inversionCount?"YES":"NO");
}

//Tested
void printResults(){
	unsigned int testCases;
	unsigned int input,size;
	vector<unsigned int> userInput;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u",&size);
		userInput.clear();
		while(size--){
			scanf("%u",&input);
			userInput.push_back(input);
		}
		isGoodPermutation(userInput);
	}
}

#endif /* LEPERMUT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
