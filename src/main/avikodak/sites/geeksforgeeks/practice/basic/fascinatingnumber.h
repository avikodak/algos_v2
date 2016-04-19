/****************************************************************************************************************************************************
 *  File Name                   : fascinatingnumber.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/practice/basic/fascinatingnumber.h
 *  Created on                  : Feb 3, 2016 :: 10:24:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=369
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_FASCINATINGNUMBER_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_FASCINATINGNUMBER_H_

//Tested
string convertToString(int userInput) {
    stringstream ss;
    ss << userInput;
    string str = ss.str();
    ss.str("");
    return str;
}

//Tested
void solveProblem() {
    unsigned int testCases = 1;
    int input = 192;
    scanf("%u",&testCases);
    while(testCases--) {
        scanf("%d",&input);
        if(input >= 100) {
            bool flags[10] = {false};
            bool isNumberFascinating = true;
            string result = convertToString(input);
            result.append(convertToString(input*2));
            result.append(convertToString(input*3));
            for(unsigned int counter = 0; counter < result.size(); counter++) {
                if(result[counter] != '0') {
                    if(flags[result[counter]-'0']) {
                        isNumberFascinating = false;
                        break;
                    }
                    flags[result[counter]-'0'] = true;
                }
            }
            for(unsigned int counter = 1; counter < 10; counter++) {
                if(!flags[counter]) {
                    isNumberFascinating = false;
                    break;
                }
            }
            printf("%s\n",isNumberFascinating?"Fascinating":"Not Fascinating");
        } else {
            printf("Number should be atleast three digits\n");
        }
    }
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_PRACTICE_BASIC_FASCINATINGNUMBER_H_ */
