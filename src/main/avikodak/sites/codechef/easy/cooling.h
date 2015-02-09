/****************************************************************************************************************************************************
 *  File Name   		: cooling.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\cooling.h
 *  Created on			: Feb 8, 2015 :: 8:46:05 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/COOLING
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define MAX_SIZE 30

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef COOLING_H_
#define COOLING_H_

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void getMaxPiesCooled(){
	int testCases,size,input;
	int pieWeights[MAX_SIZE],maxWeights[MAX_SIZE];
	scanf("%d",&testCases);
	int maxPies,pieCounter,weightCounter;
	while(testCases--){
		scanf("%d",&size);
		for(int counter = 0;counter < size;counter++){
			scanf("%d",&input);
			pieWeights[counter] = input;
		}
		for(int counter = 0;counter < size;counter++){
			scanf("%d",&input);
			maxWeights[counter] = input;
		}
		sort(pieWeights,pieWeights+size);
		sort(maxWeights,maxWeights+size);
		maxPies = 0;
		pieCounter = 0;
		weightCounter = 0;
		while(pieCounter < size && weightCounter < size){
			while(weightCounter < size && maxWeights[weightCounter] < pieWeights[pieCounter]){
				weightCounter++;
			}
			if(weightCounter < size){
				maxPies++;
				weightCounter++;
				pieCounter++;
			}
		}
		printf("%d\n",maxPies);
	}
}

#endif /* COOLING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
