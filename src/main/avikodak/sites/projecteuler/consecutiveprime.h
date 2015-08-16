/****************************************************************************************************************************************************
 *  File Name                   : consecutiveprime.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\consecutiveprime.h
 *  Created on                  : Aug 15, 2015 :: 7:16:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=50
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

#ifndef CONSECUTIVEPRIME_H_
#define CONSECUTIVEPRIME_H_

//Tested
map<unsigned int,bool> generatePrimeNumberMap(unsigned int limit,vector<unsigned int> &primeNumbers){
	vector<bool> flags;
	flags.assign(limit+2,true);
	map<unsigned int,bool> primeNumberMap;
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
			primeNumberMap.insert(pair<unsigned int,bool>(counter,true));
			primeNumbers.push_back(counter);
		}
	}
	return primeNumberMap;
}

//Tested
//Ans : 997651
void getLargestConsecutiveSumPrime(){
	unsigned int limit = 1000000;
	vector<unsigned int> primeNumbers;
	map<unsigned int,bool> primeNumberMap = generatePrimeNumberMap(limit,primeNumbers);
	unsigned int runningSum;
	unsigned int maxPrimeNumber,maxTerms = 0;
	unsigned int termsCount;
	for(unsigned int outerCounter = 0;outerCounter < primeNumbers.size();outerCounter++){
		runningSum = 0;
		for(unsigned int innerCounter = outerCounter;innerCounter < primeNumbers.size();innerCounter++){
			runningSum += primeNumbers[innerCounter];
			if(runningSum > 1000000){
				break;
			}
			if(primeNumberMap.find(runningSum) != primeNumberMap.end()){
				termsCount = innerCounter - outerCounter +1;
				if(termsCount > maxTerms){
					maxTerms = termsCount;
					maxPrimeNumber = runningSum;
				}else if(termsCount == maxTerms){
					maxPrimeNumber = max(maxPrimeNumber,primeNumbers[innerCounter]);
				}
			}
		}
	}
	cout << maxPrimeNumber << endl;
}

#endif /* CONSECUTIVEPRIME_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
