/****************************************************************************************************************************************************
 *  File Name                   : beatbats.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\beatbats.h
 *  Created on                  : Sep 4, 2015 :: 11:12:02 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/BESTBATS
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
#define LIMIT 101

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef BEATBATS_H_
#define BEATBATS_H_

unsigned int factorial(unsigned int userInput){
	return userInput < 2?1:userInput*factorial(userInput-1);
}

unsigned int ncr(unsigned int n,unsigned int r){
	return (factorial(n)/(factorial(n-r)*factorial(r)));
}

void getTotalWays(){
	unsigned int runCount[LIMIT] = {0};
	unsigned int runs;
	for(unsigned int counter = 0;counter < 11;counter++){
		scanf("%u",&runs);
		runCount[runs]++;
	}
	unsigned int total,totalWays = 1;
	scanf("%u",&total);
	for(unsigned int counter = LIMIT-1;counter > 0 && total > 0;counter--){
		if(runCount[counter] > total){
			totalWays = ncr(runCount[counter],counter);
			break;
		}else{
			total -= runCount[counter];
		}
	}
	cout << totalWays << endl;
}

void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	while(testCases--){
		getTotalWays();
	}
}

#endif /* BEATBATS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
