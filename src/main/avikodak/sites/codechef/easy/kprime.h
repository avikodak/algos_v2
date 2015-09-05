/****************************************************************************************************************************************************
 *  File Name                   : kprime.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\kprime.h
 *  Created on                  : Sep 4, 2015 :: 9:49:35 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/KPRIME
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
#define LIMIT 100001

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef KPRIME_H_
#define KPRIME_H_

vector<vector<unsigned int> > initialize(){
	unsigned int factorsCount[LIMIT] = {0};
	unsigned int innerCounter;
	for(unsigned int outerCounter = 2;outerCounter < LIMIT;outerCounter++){
		innerCounter = 2*outerCounter;
		if(factorsCount[outerCounter] == 0){
			factorsCount[outerCounter] = 1;
			while(innerCounter < LIMIT){
				factorsCount[innerCounter]++;
				innerCounter += outerCounter;
			}
		}
	}
	vector<vector<unsigned int> > factorsMapCount(7);
	for(unsigned int counter = 0;counter < 7;counter++){
		factorsMapCount[counter].assign(LIMIT,0);
	}
	for(unsigned int outerCounter = 1;outerCounter < 7;outerCounter++){
		for(unsigned int innerCounter = 2;innerCounter < LIMIT;innerCounter++){
			factorsMapCount[outerCounter][innerCounter] = factorsMapCount[outerCounter][innerCounter-1] + (factorsCount[innerCounter]==outerCounter?1:0);
		}
	}
	return factorsMapCount;
}

void printResults(){
	vector<vector<unsigned int> > factorsMapCount = initialize();
	unsigned int testCases;
	unsigned int A,B,N;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> A >> B >> N;
		cout << factorsMapCount[N][B] - factorsMapCount[N][A-1] << endl;
	}
}

#endif /* KPRIME_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
