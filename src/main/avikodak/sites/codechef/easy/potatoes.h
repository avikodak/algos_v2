/****************************************************************************************************************************************************
 *  File Name                   : potatoes.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\potatoes.h
 *  Created on                  : Sep 5, 2015 :: 2:37:04 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/POTATOES
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

#ifndef POTATOES_H_
#define POTATOES_H_

//Tested
vector<unsigned int> generatePrimeNumber(unsigned int limit){
	vector<bool> flags;
	vector<unsigned int> primes;
	flags.assign(limit+2,true);
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			unsigned int innerCounter = 2;
			while(counter*innerCounter <= limit){
				flags[counter*innerCounter] = false;
				innerCounter+=1;
			}
		}
	}
	for(unsigned int counter = 2;counter <= limit;counter++){
		if(flags[counter]){
			primes.push_back(counter);
		}
	}
	return primes;
}

//Tested
void printResults(){
	vector<unsigned int> primeNumbers = generatePrimeNumber(2500);
	unsigned int testCases,x,y,z;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&x,&y);
		z = primeNumbers[upper_bound(primeNumbers.begin(),primeNumbers.end(),x+y) - primeNumbers.begin()] - x -y;
		if(z != 0){
			cout << z << endl;
		}else{
			cout << primeNumbers[upper_bound(primeNumbers.begin(),primeNumbers.end(),x+y+1) - primeNumbers.begin()] - x -y << endl;
		}
	}
}

#endif /* POTATOES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
