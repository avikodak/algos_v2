/****************************************************************************************************************************************************
 *  File Name   		: chocolatefeast.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\chocolatefeast.h
 *  Created on			: Feb 6, 2015 :: 9:06:34 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/chocolate-feast
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

#ifndef CHOCOLATEFEAST_H_
#define CHOCOLATEFEAST_H_

//Tested
void totalChocolates(){
	int testCases;
	scanf("%d",&testCases);
	long int money,cost,offer,total,activeWrappers;
	while(testCases--){
		scanf("%ld %ld %ld",&money,&cost,&offer);
		total = money/cost;
		activeWrappers = total;
		while(activeWrappers >= offer){
			total += (activeWrappers/offer);
			activeWrappers = (activeWrappers/offer) + (activeWrappers%offer);
		}
		printf("%ld\n",total);
	}
}

#endif /* CHOCOLATEFEAST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/