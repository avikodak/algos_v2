/****************************************************************************************************************************************************
 *  File Name                   : prgift.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\prgift.h
 *  Created on                  : Sep 7, 2015 :: 10:42:54 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PRGIFT
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

#ifndef PRGIFT_H_
#define PRGIFT_H_

//Tested
void printResults(){
	unsigned int testCases,size,input,reqEvenCount,evenCount;
	bool hasOdd;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&size,&reqEvenCount);
		evenCount = 0;
		hasOdd = false;
		for(unsigned int counter = 0;counter < size;counter++){
			scanf("%u",&input);
			if(!(input&1)){
				evenCount++;
			}else{
				hasOdd = true;
			}
		}
		if(reqEvenCount == 0){
			printf("%s\n",hasOdd?"YES":"NO");
		}else{
			printf("%s\n",evenCount < reqEvenCount?"NO":"YES");
		}
	}
}

#endif /* PRGIFT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/