/****************************************************************************************************************************************************
 *  File Name                   : cookmach.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/school/cookmach.h
 *  Created on                  : 10-Sep-2015 :: 9:14:43 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/COOKMACH
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

#ifndef COOKMACH_H_
#define COOKMACH_H_

//Tested
long long int isPowerOf2(long long int userInput){
	long long int logValue = log2(userInput);
	if(pow(2,logValue) == userInput){
		return logValue;
	}else{
		return -1;
	}
}

//Tested
void getTotalSettings(long long int userInput,long long int reqSetting){
	if(userInput == reqSetting){
		printf("0\n");
		return;
	}
	long long int totalOperations = 0;
	long long int logValue;
	while(userInput != reqSetting){
		if((logValue = isPowerOf2(userInput)) != -1 && userInput < reqSetting){
			totalOperations += ((long long int)log2(reqSetting) - logValue);
			break;
		}else if(userInput%2 == 0){
			userInput /= 2;
		}else{
			userInput = (userInput-1)/2;
		}
		totalOperations++;
	}
	cout << totalOperations << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	long long int userInput,reqSettings;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> userInput >> reqSettings;
		getTotalSettings(userInput,reqSettings);
	}
}

#endif /* COOKMACH_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
