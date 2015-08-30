/****************************************************************************************************************************************************
 *  File Name                   : flow014.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\flow014.h
 *  Created on                  : Aug 30, 2015 :: 2:59:05 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/FLOW014
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef FLOW014_H_
#define FLOW014_H_

//Tested
void printGradeOfSteel(double hardness,double carbonContent,double tensileStrength){
	bool hardnessFlag = hardness > 50;
	bool carbonFlag = carbonContent < 0.7;
	bool tensileFlag = tensileStrength > 5600;
	if(hardnessFlag && carbonFlag && tensileFlag){
		printf("10\n");
	}else if(hardnessFlag && carbonFlag){
		printf("9\n");
	}else if(carbonFlag && tensileFlag){
		printf("8\n");
	}else if(hardnessFlag && tensileFlag){
		printf("7\n");
	}else if(hardnessFlag || carbonFlag || tensileFlag){
		printf("6\n");
	}else{
		printf("5\n");
	}

}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	double hardness,carbonContent,tensileStrength;
	while(testCases--){
		cin >> hardness >> carbonContent >> tensileStrength;
		printGradeOfSteel(hardness,carbonContent,tensileStrength);
	}
}

#endif /* FLOW014_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
