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
