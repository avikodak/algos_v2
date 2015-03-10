/****************************************************************************************************************************************************
 *  File Name   		: iloveusername.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iloveusername.h
 *  Created on			: Mar 8, 2015 :: 12:12:33 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/155/A
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

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ILOVEUSERNAME_H_
#define ILOVEUSERNAME_H_

//Tested
void getNumberOfAmazingPerformance(){
	unsigned int testCases;
	int points,maxTillNow = INT_MIN,minTillNow = INT_MAX,noOfAmazingPerformance = 0;
	scanf("%d",&testCases);
	for(unsigned int counter = 0;counter < testCases;counter++){
		scanf("%d",&points);
		if(counter != 0){
			if(maxTillNow < points){
				noOfAmazingPerformance++;
				maxTillNow = points;
			}else if(minTillNow > points){
				noOfAmazingPerformance++;
				minTillNow = points;
			}
		}else{
			maxTillNow = points;
			minTillNow = points;
		}
	}
	printf("%d",noOfAmazingPerformance);
}

#endif /* ILOVEUSERNAME_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
