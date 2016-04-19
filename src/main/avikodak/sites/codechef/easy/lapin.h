/****************************************************************************************************************************************************
 *  File Name                   : lapin.h
 *  File Location               : \algos_v2\src\main\avikodak\sites\codechef\easy\lapin.h
 *  Created on                  : Feb 9, 2015 :: 10:06:30 PM
 *  Author                      : AVINASH
 *  Testing Status              : Tested
 *  URL                         : http://www.codechef.com/problems/LAPIN
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/
#define MAX_INPUT_SIZE 1001
#define ALPHABET_SIZE 26

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef LAPIN_H_
#define LAPIN_H_

//Tested
bool isStringLapindrome(char *user) {
    unsigned int length = strlen(user);
    unsigned int secondCrawler = 0,size;
    if(length&1) {
        secondCrawler = (length/2)+1;
    } else {
        secondCrawler = length/2;
    }
    size = (length/2);
    unsigned frequencies[ALPHABET_SIZE] = {0};
    for(unsigned int counter = 0; counter < size; counter++) {
        frequencies[user[counter]-'a']++;
    }
    for(unsigned int counter = secondCrawler; counter < length; counter++) {
        if(frequencies[user[counter]-'a'] == 0) {
            return false;
        }
        frequencies[user[counter]-'a']--;
    }
    for(unsigned int counter = 0; counter < ALPHABET_SIZE; counter++) {
        if(frequencies[counter] > 0) {
            return false;
        }
    }
    return true;
}

//Tested
void areStringLapindromes() {
    unsigned int testCases;
    scanf("%u",&testCases);
    char userInput[MAX_INPUT_SIZE];
    while(testCases--) {
        scanf("%s",userInput);
        if(isStringLapindrome(userInput)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

#endif /* LAPIN_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
