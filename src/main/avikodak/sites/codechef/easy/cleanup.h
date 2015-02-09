/****************************************************************************************************************************************************
 *  File Name   		: cleanup.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\easy\cleanup.h
 *  Created on			: Feb 9, 2015 :: 11:16:01 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/CLEANUP
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

#ifndef CLEANUP_H_
#define CLEANUP_H_

//Tested
void printVector(vector<int> jobs){
	for(unsigned int counter = 0;counter < jobs.size();counter++){
		printf("%d ",jobs[counter]);
	}
	PRINT_NEW_LINE;
}

//Tested
void assignJobs(){
	int testCases,totalJobs,jobsCount,jobIndex;
	unsigned int finishedJobIndex;
	scanf("%d",&testCases);
	bool flag;
	vector<int> finishedJobs,chefJobs,assistantJobs;
	while(testCases--){
		finishedJobs.clear();
		chefJobs.clear();
		assistantJobs.clear();
		scanf("%d %d",totalJobs,jobsCount);
		while(jobsCount--){
			scanf("%d",jobIndex);
			finishedJobs.push_back(jobIndex);
		}
		sort(finishedJobs.begin(),finishedJobs.end());
		finishedJobIndex = 0;
		flag = true;
		int counter = 1;
		for(;counter <= totalJobs && finishedJobIndex < finishedJobs.size();counter++){
			if(counter != finishedJobs[finishedJobIndex]){
				if(flag){
					chefJobs.push_back(counter);
				}else{
					assistantJobs.push_back(counter);
				}
				flag = !flag;
			}else{
				finishedJobIndex++;
			}
		}
		for(;counter <= totalJobs;counter++){
			if(flag){
				chefJobs.push_back(counter);
			}else{
				assistantJobs.push_back(counter);
			}
			flag = !flag;
		}
		printVector(chefJobs);
		printVector(assistantJobs);
	}
}

#endif /* CLEANUP_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
