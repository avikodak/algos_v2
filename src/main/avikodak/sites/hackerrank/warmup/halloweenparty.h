/****************************************************************************************************************************************************
 *  File Name   		: halloweenparty.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\warmup\halloweenparty.h
 *  Created on			: Feb 6, 2015 :: 11:37:42 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/halloween-party
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

#ifndef HALLOWEENPARTY_H_
#define HALLOWEENPARTY_H_

void getMaxCutsChocolateBar(){
	int testCases;
	scanf("%d",&testCases);
	long int userInput,temp;
	while(testCases--){
		scanf("%ld",&userInput);
		temp = userInput/2;
		if(userInput%2 == 0){
			printf("%ld\n",temp * temp);
		}else{
			printf("%ld\n",temp * (temp+1));
		}
	}
}

#endif /* HALLOWEENPARTY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/