/****************************************************************************************************************************************************
 *  File Name                   : pandigitalproducts.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pandigitalproducts.h
 *  Created on                  : Aug 23, 2015 :: 6:32:14 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=32
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

#ifndef PANDIGITALPRODUCTS_H_
#define PANDIGITALPRODUCTS_H_

//Tested
unsigned int getLength(unsigned long long int userInput){
	unsigned int length = 0;
	while(userInput){
		length++;
		userInput /= 10;
	}
	return length;
}

//Tested
unsigned long long int concate(unsigned int first,unsigned int second){
	while(second){
		first *= 10;
		first += second%10;
		second /= 10;
	}
	return first;
}

//Tested
bool isPandigital(unsigned long long int multiplicand,unsigned long long int multiplier,unsigned long long int result){
	unsigned int userInput = concate(multiplicand,multiplier);
	userInput = concate(userInput,result);
	bool flags[10] = {false};
	while(userInput){
		if(userInput%10 == 0|| flags[userInput%10]){
			return false;
		}
		flags[userInput%10] = true;
		userInput /= 10;
	}
	for(unsigned int counter = 1;counter < 10;counter++){
		if(!flags[counter]){
			return false;
		}
	}
	return true;
}

//Tested
//Ans : 45228
void getSumPanDigitalProducts(){
	map<unsigned long long int,bool> visitedProducts;
	unsigned long long int result,sum =0;
	unsigned int length;
	for(unsigned long long int outerCounter = 1;outerCounter <= 9876;outerCounter++){
		for(unsigned long long int innerCounter = 1;innerCounter <= 9876;innerCounter++){
			result = outerCounter * innerCounter;
			length = getLength(result) + getLength(outerCounter) + getLength(innerCounter);
			if(length < 10){
				if(length == 9){
					if(visitedProducts.find(result) == visitedProducts.end()){
						if(isPandigital(outerCounter,innerCounter,result)){
							visitedProducts.insert(pair<unsigned long long int,bool>(result,true));
							sum +=result;
						}
					}
				}
			}else{
				break;
			}
		}
	}
	cout << sum << endl;
}

#endif /* PANDIGITALPRODUCTS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
