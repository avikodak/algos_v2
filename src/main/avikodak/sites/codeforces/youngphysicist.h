/****************************************************************************************************************************************************
 *  File Name   		: youngphysicist.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\youngphysicist.h
 *  Created on			: Mar 23, 2015 :: 9:55:24 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/69/A
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

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef YOUNGPHYSICIST_H_
#define YOUNGPHYSICIST_H_

//Tested
void isBodyInEquilibriumState(){
	unsigned int testCases;
	int xCoordinate,yCoordinate,zCoordinate,xCoordinateSum = 0,yCoordinateSum = 0,zCoordinateSum = 0;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%d %d %d",&xCoordinate,&yCoordinate,&zCoordinate);
		xCoordinateSum += xCoordinate;
		yCoordinateSum += yCoordinate;
		zCoordinateSum += zCoordinate;
	}
	if(xCoordinateSum == 0 && yCoordinateSum == 0 && zCoordinateSum == 0){
		printf("YES");
	}else{
		printf("NO");
	}
}

#endif /* YOUNGPHYSICIST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
