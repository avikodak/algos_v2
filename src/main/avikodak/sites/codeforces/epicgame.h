/****************************************************************************************************************************************************
 *  File Name   		: epicgame.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codeforces\epicgame.h
 *  Created on			: Mar 1, 2015 :: 9:50:01 AM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://codeforces.com/problemset/problem/119/A
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef EPICGAME_H_
#define EPICGAME_H_

//Tested
int gcd(int firstNumber,int secondNumber){
	if(firstNumber == 1 || secondNumber == 1){
		return 1;
	}
	if(secondNumber % firstNumber == 0){
		return firstNumber;
	}
	return gcd(secondNumber%firstNumber,firstNumber);
}

//Tested
void epicGame(){
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	bool flag = true;
	while(n > 0){
		if(flag){
			n -= gcd(a,n);
			if(n == 0){
				printf("0");
			}
		}else{
			n -= gcd(b,n);
			if(n == 0){
				printf("1");
			}
		}
		flag = !flag;
	}
}

#endif /* EPICGAME_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
