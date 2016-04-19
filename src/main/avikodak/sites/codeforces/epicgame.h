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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef EPICGAME_H_
#define EPICGAME_H_

//Tested
int gcd(int firstNumber,int secondNumber) {
    if(firstNumber == 1 || secondNumber == 1) {
        return 1;
    }
    if(secondNumber % firstNumber == 0) {
        return firstNumber;
    }
    return gcd(secondNumber%firstNumber,firstNumber);
}

//Tested
void epicGame() {
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    bool flag = true;
    while(n > 0) {
        if(flag) {
            n -= gcd(a,n);
            if(n == 0) {
                printf("0");
            }
        } else {
            n -= gcd(b,n);
            if(n == 0) {
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
