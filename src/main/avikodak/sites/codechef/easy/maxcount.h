/****************************************************************************************************************************************************
 *  File Name   		: maxcount.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\maxcount.h
 *  Created on			: Feb 8, 2015 :: 7:07:41 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.codechef.com/problems/MAXCOUNT
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/
#define MAX_SIZE 10001

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef MAXCOUNT_H_
#define MAXCOUNT_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void getMaxFrequencyElement(){
	int testCases,size,number;
	vector<int> frequencyMap;
	scanf("%d",&testCases);
	int maxFrequency = 0,minElement;
	while(testCases--){
		scanf("%d",&size);
		frequencyMap.clear();
		frequencyMap.assign(MAX_SIZE,0);
		maxFrequency = 0;
		while(size--){
			scanf("%d",&number);
			frequencyMap[number] += 1;
			if(maxFrequency < frequencyMap[number]){
				maxFrequency = frequencyMap[number];
				minElement = number;
			}else if(maxFrequency == frequencyMap[number]){
				minElement = min(minElement,number);
			}
		}
		printf("%d %d\n",minElement,maxFrequency);
	}
}

#endif /* MAXCOUNT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
