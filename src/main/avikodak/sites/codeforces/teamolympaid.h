/****************************************************************************************************************************************************
 *  File Name                   : teamolympaid.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\teamolympaid.h
 *  Created on                  : Apr 11, 2015 :: 4:57:23 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/490/A
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TEAMOLYMPAID_H_
#define TEAMOLYMPAID_H_

void makeTeams(){
	unsigned int testCases,subject;
	scanf("%u",&testCases);
	queue<unsigned int> buckets[3];
	for(unsigned int counter = 0;counter < testCases;counter++){
		scanf("%u",&subject);
		buckets[subject-1].push(counter+1);
	}
	unsigned int minTeams = min(min(buckets[0].size(),buckets[1].size()),buckets[2].size());
	printf("%u\n",minTeams);
	while(minTeams--){
		printf("%u %u %u\n",buckets[0].front(),buckets[1].front(),buckets[2].front());
		buckets[0].pop();
		buckets[1].pop();
		buckets[2].pop();
	}
}

#endif /* TEAMOLYMPAID_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
