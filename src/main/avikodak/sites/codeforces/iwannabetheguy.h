/****************************************************************************************************************************************************
 *  File Name                   : iwannabetheguy.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\iwannabetheguy.h
 *  Created on                  : Apr 7, 2015 :: 11:49:25 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/469/A
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

#ifndef IWANNABETHEGUY_H_
#define IWANNABETHEGUY_H_

//Tested
void willTheyPassLevels(){
	unsigned int finalLevel;
	vector<bool> flags;
	scanf("%u",&finalLevel);
	flags.assign(finalLevel,false);
	unsigned int littleXTotalLevels,littleYTotalLevels;
	unsigned int inputLevel;
	scanf("%u",&littleXTotalLevels);
	while(littleXTotalLevels--){
		scanf("%u",&inputLevel);
		flags[inputLevel-1] = true;
	}
	scanf("%u",&littleYTotalLevels);
	while(littleYTotalLevels--){
		scanf("%u",&inputLevel);
		flags[inputLevel-1] = true;
	}
	for(unsigned int counter = 0;counter < finalLevel;counter++){
		if(!flags[counter]){
			printf("Oh, my keyboard!");
			return;
		}
	}
	printf("I become the guy.");
}

#endif /* IWANNABETHEGUY_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
