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
