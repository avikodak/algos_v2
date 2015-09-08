/****************************************************************************************************************************************************
 *  File Name                   : devusingerchurujoker.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\devusingerchurujoker.h
 *  Created on                  : Apr 11, 2015 :: 9:29:02 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/439/A
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

#ifndef DEVUSINGERCHURUJOKER_H_
#define DEVUSINGERCHURUJOKER_H_

//Tested
void printMaxJokes(){
	unsigned int totalSongs,timeTaken,input,totalTimeSongs = 0;
	scanf("%u %u",&totalSongs,&timeTaken);
	for(unsigned int counter = 0;counter < totalSongs;counter++){
		scanf("%u",&input);
		totalTimeSongs += input;
	}
	totalTimeSongs += (10*(totalSongs-1));
	if(totalTimeSongs > timeTaken){
		printf("-1");
	}else{
		printf("%u",((timeTaken - totalTimeSongs)/5 + (10*(totalSongs-1))/5));
	}
}

#endif /* DEVUSINGERCHURUJOKER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
