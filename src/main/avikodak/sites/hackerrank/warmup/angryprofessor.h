/****************************************************************************************************************************************************
 *  File Name   		: angryprofessor.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\warmup\angryprofessor.h
 *  Created on			: Mar 10, 2015 :: 9:59:55 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/angry-professor
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

#ifndef ANGRYPROFESSOR_H_
#define ANGRYPROFESSOR_H_

//Tested
void doesClassStarts(){
	int testCases,totalStudents,requiredStudents,timeArrival,counter;
	scanf("%d",&testCases);
	while(testCases--){
		cin >> totalStudents >> requiredStudents;
		counter = 0;
		while(totalStudents--){
			scanf("%d",&timeArrival);
			if(timeArrival <= 0){
				counter++;
			}
		}
		printf("%s\n",counter >= requiredStudents?"NO":"YES");
	}
}

#endif /* ANGRYPROFESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
