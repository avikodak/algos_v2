/****************************************************************************************************************************************************
 *  File Name   		: arrayutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\arrayutil.h
 *  Created on			: Oct 9, 2014 :: 12:38:45 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ARRAYUTIL_H_
#define ARRAYUTIL_H_

//Tested
vector<int> generateIRandomVector(unsigned int size,int lowerLimit = INT_MIN,int upperLimit = INT_MAX){
	vector<int> randomnumbers;
	srand(time(NULL));
	for(unsigned int counter = 0;counter < size;counter++){
		randomnumbers.push_back(rand() % upperLimit + lowerLimit);
	}
	return randomnumbers;
}

bool areIVectorsEquivalent(vector<int> firstVector,vector<int> secondVector){
	if(firstVector.size() != secondVector.size()){
		return false;
	}
	for(unsigned int counter = 0;counter < firstVector.size();counter++){
		if(firstVector[counter] != secondVector[counter]){
			return false;
		}
	}
	return true;
}

#endif /* ARRAYUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
