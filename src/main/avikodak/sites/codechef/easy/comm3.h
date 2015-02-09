/****************************************************************************************************************************************************
 *  File Name   		: comm3.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\comm3.h
 *  Created on			: Feb 9, 2015 :: 8:24:38 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/COMM3
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

#ifndef COMM3_H_
#define COMM3_H_

double distance(int x1,int y1,int x2,int y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void isCommPossible(){
	int testCases,maxDistance;
	double chefHeadDis,chefSousDis,sousHeadDis;
	scanf("%d",&testCases);
	int chefX,chefY,headX,headY,sousX,sousY;
	while(testCases--){
		scanf("%d",&maxDistance);
		scanf("%d %d %d %d %d %d",&chefX,&chefY,&headX,&headY,&sousX,&sousY);
		chefHeadDis = distance(chefX,chefY,headX,headY);
		chefSousDis = distance(chefX,chefY,sousX,sousY);
		if(chefHeadDis <= maxDistance && chefSousDis <= maxDistance){
			printf("yes\n");
		}else if(chefHeadDis <= maxDistance || chefSousDis <= maxDistance){
			sousHeadDis = distance(sousX,sousY,headX,headY);
			if(sousHeadDis <= maxDistance){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}else{
			printf("no\n");
		}
	}
}

#endif /* COMM3_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
