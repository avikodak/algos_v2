/****************************************************************************************************************************************************
 *  File Name                   : anuarm.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/anuarm.h
 *  Created on                  : 21-Oct-2015 :: 9:01:47 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/ANUARM
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
#include <stdint.h>
#include <iomanip>
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
#define gc getchar_unlocked

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef ANUARM_H_
#define ANUARM_H_

//Tested
void scanllint(long long int &x){
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

//Tested
void printResults(){
	long long int testCases,soldiersCount,size;
	long long int index,minIndex,maxIndex;
	scanllint(testCases);
	vector<long long int> indexesFlag;
	while(testCases--){
		scanllint(soldiersCount);
		indexesFlag.assign(soldiersCount,0);
		scanllint(size);
		for(unsigned int counter = 0;counter < size;counter++){
			scanllint(index);
			if(counter == 0){
				minIndex = index;
				maxIndex = index;
			}else{
				minIndex = min(minIndex,index);
				maxIndex = max(maxIndex,index);
			}
		}
		for(unsigned int counter = 0;counter < soldiersCount;counter++){
			indexesFlag[counter] = max(abs(maxIndex-counter),abs(minIndex-counter));
		}
		for(unsigned int counter = 0;counter < soldiersCount;counter++){
			printf("%lld ",indexesFlag[counter]);
		}
		printf("\n");
	}
}

#endif /* ANUARM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
