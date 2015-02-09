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
