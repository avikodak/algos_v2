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
