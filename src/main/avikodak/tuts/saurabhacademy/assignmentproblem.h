/****************************************************************************************************************************************************
 *  File Name   		: assignmentproblem.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\tuts\saurabhacademy\assignmentproblem.h
 *  Created on			: Dec 18, 2014 :: 8:19:06 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
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

#ifndef ASSIGNMENTPROBLEM_H_
#define ASSIGNMENTPROBLEM_H_

int assignmentProblem(vector<vector<int> > payMatrix,int jobCounter,hash_map<unsigned int,unsigned int> personJobMap){
	if(jobCounter > payMatrix[0].size()){
		return INT_MAX;
	}
	if(jobCounter == payMatrix[0].size()){
		return 0;
	}
	int minAmount = INT_MAX;
	for(unsigned int person = 0;person < payMatrix.size();person++){
		if(personJobMap.find(person) == personJobMap.end()){
			personJobMap.insert(pair<unsigned int,unsigned int>(person,jobCounter));
			minAmount = min(minAmount,payMatrix[person][jobCounter] + assignmentProblem(payMatrix,jobCounter,personJobMap));
			personJobMap.erase(person);
		}
	}
	return minAmount;
}

#endif /* ASSIGNMENTPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
