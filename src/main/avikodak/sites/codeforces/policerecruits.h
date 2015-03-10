/****************************************************************************************************************************************************
 *  File Name   		: policerecruits.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\policerecruits.h
 *  Created on			: Mar 10, 2015 :: 11:06:03 AM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/427/A
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

#ifndef POLICERECRUITS_H_
#define POLICERECRUITS_H_

void getCrimesUntreated(){
	int totalEvents,crimesUntreated = 0,event,totalRecruits = 0;
	scanf("%d",&totalEvents);
	while(totalEvents--){
		scanf("%d",&event);
		if(event > 0){
			totalRecruits += event;
		}else{
			if(totalRecruits == 0){
				crimesUntreated += 1;
			}else{
				if(totalRecruits != 0){
					totalRecruits -= 1;
				}
			}
		}
	}
	printf("%d",crimesUntreated);
}

#endif /* POLICERECRUITS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
