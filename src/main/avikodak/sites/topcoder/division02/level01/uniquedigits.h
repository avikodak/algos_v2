/****************************************************************************************************************************************************
 *  File Name                   : uniquedigits.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\uniquedigits.h
 *  Created on                  : May 24, 2015 :: 2:42:41 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=5988
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
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef UNIQUEDIGITS_H_
#define UNIQUEDIGITS_H_

class UniqueDigits {
private:
	int duplicateDigits[] = {11,22,33,44,55,66,77,88,99,100,101,110,111,112,113,114,115,116,117,118,119,121,122,131,133,141,144,151,155,161,166,171,177,181,188,191,199,200,202,211,212,220,221,222,223,224,225,226,227,228,229,232,233,242,244,252,255,262,266,272,277,282,288,292,299,300,303,311,313,322,323,330,331,332,333,334,335,336,337,338,339,343,344,353,355,363,366,373,377,383,388,393,399,400,404,411,414,422,424,433,434,440,441,442,443,444,445,446,447,448,449,454,455,464,466,474,477,484,488,494,499,500,505,511,515,522,525,533,535,544,545,550,551,552,553,554,555,556,557,558,559,565,566,575,577,585,588,595,599,600,606,611,616,622,626,633,636,644,646,655,656,660,661,662,663,664,665,666,667,668,669,676,677,686,688,696,699,700,707,711,717,722,727,733,737,744,747,755,757,766,767,770,771,772,773,774,775,776,777,778,779,787,788,797,799,800,808,811,818,822,828,833,838,844,848,855,858,866,868,877,878,880,881,882,883,884,885,886,887,888,889,898,899,900,909,911,919,922,929,933,939,944,949,955,959,966,969,977,979,988,989,990,991,992,993,994,995,996,997,998,999,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020,1021,1022,1030,1031,1033,1040,1041,1044,1050,1051,1055,1060,1061,1066,1070,1071,1077,1080,1081,1088,1090,1091,1099,1100,1101,1102,1103,1104,1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118,1119,1120,1121,1122,1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138,1139,1140,1141,1142,1143,1144,1145,1146,1147,1148,1149,1150,1151,1152,1153,1154,1155,1156,1157,1158,1159,1160,1161,1162,1163,1164,1165,1166,1167,1168,1169,1170,1171,1172,1173,1174,1175,1176,1177,1178,1179,1180,1181,1182,1183,1184,1185,1186,1187,1188,1189,1190,1191,1192,1193,1194,1195,1196,1197,1198,1199,1200,1201,1202,1210,1211,1212,1213,1214,1215,1216,1217,1218,1219,1220,1221,1222,1223,1224,1225,1226,1227,1228,1229,1231,1232,1233,1241,1242,1244,1251,1252,1255,1261,1262,1266,1271,1272,1277,1281,1282,1288,1291,1292,1299,1300,1301,1303,1310,1311,1312,1313,1314,1315,1316,1317,1318,1319,1321,1322,1323,1330,1331,1332,1333,1334,1335,1336,1337,1338,1339,1341,1343,1344,1351,1353,1355,1361,1363,1366,1371,1373,1377,1381,1383,1388,1391,1393,1399,1400,1401,1404,1410,1411,1412,1413,1414,1415,1416,1417,1418,1419,1421,1422,1424,1431,1433,1434,1440,1441,1442,1443,1444,1445,1446,1447,1448,1449,1451,1454,1455,1461,1464,1466,1471,1474,1477,1481,1484,1488,1491,1494,1499,1500,1501,1505,1510,1511,1512,1513,1514,1515,1516,1517,1518,1519,1521,1522,1525,1531,1533,1535,1541,1544,1545,1550,1551,1552,1553,1554,1555,1556,1557,1558,1559,1561,1565,1566,1571,1575,1577,1581,1585,1588,1591,1595,1599,1600,1601,1606,1610,1611,1612,1613,1614,1615,1616,1617,1618,1619,1621,1622,1626,1631,1633,1636,1641,1644,1646,1651,1655,1656,1660,1661,1662,1663,1664,1665,1666,1667,1668,1669,1671,1676,1677,1681,1686,1688,1691,1696,1699,1700,1701,1707,1710,1711,1712,1713,1714,1715,1716,1717,1718,1719,1721,1722,1727,1731,1733,1737,1741,1744,1747,1751,1755,1757,1761,1766,1767,1770,1771,1772,1773,1774,1775,1776,1777,1778,1779,1781,1787,1788,1791,1797,1799,1800,1801,1808,1810,1811,1812,1813,1814,1815,1816,1817,1818,1819,1821,1822,1828,1831,1833,1838,1841,1844,1848,1851,1855,1858,1861,1866,1868,1871,1877,1878,1880,1881,1882,1883,1884,1885,1886,1887,1888,1889,1891,1898,1899,1900,1901,1909,1910,1911,1912,1913,1914,1915,1916,1917,1918,1919,1921,1922,1929,1931,1933,1939,1941,1944,1949,1951,1955,1959,1961,1966,1969,1971,1977,1979,1981,1988,1989,1990,1991,1992,1993,1994,1995,1996,1997,1998,1999,2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012,2020,2021,2022,2023,2024,2025,2026,2027,2028,2029,2030,2032,2033,2040,2042,2044,2050,2052,2055,2060,2062,2066,2070,2072,2077,2080,2082,2088,2090,2092,2099,2100,2101,2102,2110,2111,2112,2113,2114,2115,2116,2117,2118,2119,2120,2121,2122,2123,2124,2125,2126,2127,2128,2129,2131,2132,2133,2141,2142,2144,2151,2152,2155,2161,2162,2166,2171,2172,2177,2181,2182,2188,2191,2192,2199,2200,2201,2202,2203,2204,2205,2206,2207,2208,2209,2210,2211,2212,2213,2214,2215,2216,2217,2218,2219,2220,2221,2222,2223,2224,2225,2226,2227,2228,2229,2230,2231,2232,2233,2234,2235,2236,2237,2238,2239,2240,2241,2242,2243,2244,2245,2246,2247,2248,2249,2250,2251,2252,2253,2254,2255,2256,2257,2258,2259,2260,2261,2262,2263,2264,2265,2266,2267,2268,2269,2270,2271,2272,2273,2274,2275,2276,2277,2278,2279,2280,2281,2282,2283,2284,2285,2286,2287,2288,2289,2290,2291,2292,2293,2294,2295,2296,2297,2298,2299,2300,2302,2303,2311,2312,2313,2320,2321,2322,2323,2324,2325,2326,2327,2328,2329,2330,2331,2332,2333,2334,2335,2336,2337,2338,2339,2342,2343,2344,2352,2353,2355,2362,2363,2366,2372,2373,2377,2382,2383,2388,2392,2393,2399,2400,2402,2404,2411,2412,2414,2420,2421,2422,2423,2424,2425,2426,2427,2428,2429,2432,2433,2434,2440,2441,2442,2443,2444,2445,2446,2447,2448,2449,2452,2454,2455,2462,2464,2466,2472,2474,2477,2482,2484,2488,2492,2494,2499,2500,2502,2505,2511,2512,2515,2520,2521,2522,2523,2524,2525,2526,2527,2528,2529,2532,2533,2535,2542,2544,2545,2550,2551,2552,2553,2554,2555,2556,2557,2558,2559,2562,2565,2566,2572,2575,2577,2582,2585,2588,2592,2595,2599,2600,2602,2606,2611,2612,2616,2620,2621,2622,2623,2624,2625,2626,2627,2628,2629,2632,2633,2636,2642,2644,2646,2652,2655,2656,2660,2661,2662,2663,2664,2665,2666,2667,2668,2669,2672,2676,2677,2682,2686,2688,2692,2696,2699,2700,2702,2707,2711,2712,2717,2720,2721,2722,2723,2724,2725,2726,2727,2728,2729,2732,2733,2737,2742,2744,2747,2752,2755,2757,2762,2766,2767,2770,2771,2772,2773,2774,2775,2776,2777,2778,2779,2782,2787,2788,2792,2797,2799,2800,2802,2808,2811,2812,2818,2820,2821,2822,2823,2824,2825,2826,2827,2828,2829,2832,2833,2838,2842,2844,2848,2852,2855,2858,2862,2866,2868,2872,2877,2878,2880,2881,2882,2883,2884,2885,2886,2887,2888,2889,2892,2898,2899,2900,2902,2909,2911,2912,2919,2920,2921,2922,2923,2924,2925,2926,2927,2928,2929,2932,2933,2939,2942,2944,2949,2952,2955,2959,2962,2966,2969,2972,2977,2979,2982,2988,2989,2990,2991,2992,2993,2994,2995,2996,2997,2998,2999,3000,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3013,3020,3022,3023,3030,3031,3032,3033,3034,3035,3036,3037,3038,3039,3040,3043,3044,3050,3053,3055,3060,3063,3066,3070,3073,3077,3080,3083,3088,3090,3093,3099,3100,3101,3103,3110,3111,3112,3113,3114,3115,3116,3117,3118,3119,3121,3122,3123,3130,3131,3132,3133,3134,3135,3136,3137,3138,3139,3141,3143,3144,3151,3153,3155,3161,3163,3166,3171,3173,3177,3181,3183,3188,3191,3193,3199,3200,3202,3203,3211,3212,3213,3220,3221,3222,3223,3224,3225,3226,3227,3228,3229,3230,3231,3232,3233,3234,3235,3236,3237,3238,3239,3242,3243,3244,3252,3253,3255,3262,3263,3266,3272,3273,3277,3282,3283,3288,3292,3293,3299,3300,3301,3302,3303,3304,3305,3306,3307,3308,3309,3310,3311,3312,3313,3314,3315,3316,3317,3318,3319,3320,3321,3322,3323,3324,3325,3326,3327,3328,3329,3330,3331,3332,3333,3334,3335,3336,3337,3338,3339,3340,3341,3342,3343,3344,3345,3346,3347,3348,3349,3350,3351,3352,3353,3354,3355,3356,3357,3358,3359,3360,3361,3362,3363,3364,3365,3366,3367,3368,3369,3370,3371,3372,3373,3374,3375,3376,3377,3378,3379,3380,3381,3382,3383,3384,3385,3386,3387,3388,3389,3390,3391,3392,3393,3394,3395,3396,3397,3398,3399,3400,3403,3404,3411,3413,3414,3422,3423,3424,3430,3431,3432,3433,3434,3435,3436,3437,3438,3439,3440,3441,3442,3443,3444,3445,3446,3447,3448,3449,3453,3454,3455,3463,3464,3466,3473,3474,3477,3483,3484,3488,3493,3494,3499,3500,3503,3505,3511,3513,3515,3522,3523,3525,3530,3531,3532,3533,3534,3535,3536,3537,3538,3539,3543,3544,3545,3550,3551,3552,3553,3554,3555,3556,3557,3558,3559,3563,3565,3566,3573,3575,3577,3583,3585,3588,3593,3595,3599,3600,3603,3606,3611,3613,3616,3622,3623,3626,3630,3631,3632,3633,3634,3635,3636,3637,3638,3639,3643,3644,3646,3653,3655,3656,3660,3661,3662,3663,3664,3665,3666,3667,3668,3669,3673,3676,3677,3683,3686,3688,3693,3696,3699,3700,3703,3707,3711,3713,3717,3722,3723,3727,3730,3731,3732,3733,3734,3735,3736,3737,3738,3739,3743,3744,3747,3753,3755,3757,3763,3766,3767,3770,3771,3772,3773,3774,3775,3776,3777,3778,3779,3783,3787,3788,3793,3797,3799,3800,3803,3808,3811,3813,3818,3822,3823,3828,3830,3831,3832,3833,3834,3835,3836,3837,3838,3839,3843,3844,3848,3853,3855,3858,3863,3866,3868,3873,3877,3878,3880,3881,3882,3883,3884,3885,3886,3887,3888,3889,3893,3898,3899,3900,3903,3909,3911,3913,3919,3922,3923,3929,3930,3931,3932,3933,3934,3935,3936,3937,3938,3939,3943,3944,3949,3953,3955,3959,3963,3966,3969,3973,3977,3979,3983,3988,3989,3990,3991,3992,3993,3994,3995,3996,3997,3998,3999,4000,4001,4002,4003,4004,4005,4006,4007,4008,4009,4010,4011,4014,4020,4022,4024,4030,4033,4034,4040,4041,4042,4043,4044,4045,4046,4047,4048,4049,4050,4054,4055,4060,4064,4066,4070,4074,4077,4080,4084,4088,4090,4094,4099,4100,4101,4104,4110,4111,4112,4113,4114,4115,4116,4117,4118,4119,4121,4122,4124,4131,4133,4134,4140,4141,4142,4143,4144,4145,4146,4147,4148,4149,4151,4154,4155,4161,4164,4166,4171,4174,4177,4181,4184,4188,4191,4194,4199,4200,4202,4204,4211,4212,4214,4220,4221,4222,4223,4224,4225,4226,4227,4228,4229,4232,4233,4234,4240,4241,4242,4243,4244,4245,4246,4247,4248,4249,4252,4254,4255,4262,4264,4266,4272,4274,4277,4282,4284,4288,4292,4294,4299,4300,4303,4304,4311,4313,4314,4322,4323,4324,4330,4331,4332,4333,4334,4335,4336,4337,4338,4339,4340,4341,4342,4343,4344,4345,4346,4347,4348,4349,4353,4354,4355,4363,4364,4366,4373,4374,4377,4383,4384,4388,4393,4394,4399,4400,4401,4402,4403,4404,4405,4406,4407,4408,4409,4410,4411,4412,4413,4414,4415,4416,4417,4418,4419,4420,4421,4422,4423,4424,4425,4426,4427,4428,4429,4430,4431,4432,4433,4434,4435,4436,4437,4438,4439,4440,4441,4442,4443,4444,4445,4446,4447,4448,4449,4450,4451,4452,4453,4454,4455,4456,4457,4458,4459,4460,4461,4462,4463,4464,4465,4466,4467,4468,4469,4470,4471,4472,4473,4474,4475,4476,4477,4478,4479,4480,4481,4482,4483,4484,4485,4486,4487,4488,4489,4490,4491,4492,4493,4494,4495,4496,4497,4498,4499,4500,4504,4505,4511,4514,4515,4522,4524,4525,4533,4534,4535,4540,4541,4542,4543,4544,4545,4546,4547,4548,4549,4550,4551,4552,4553,4554,4555,4556,4557,4558,4559,4564,4565,4566,4574,4575,4577,4584,4585,4588,4594,4595,4599,4600,4604,4606,4611,4614,4616,4622,4624,4626,4633,4634,4636,4640,4641,4642,4643,4644,4645,4646,4647,4648,4649,4654,4655,4656,4660,4661,4662,4663,4664,4665,4666,4667,4668,4669,4674,4676,4677,4684,4686,4688,4694,4696,4699,4700,4704,4707,4711,4714,4717,4722,4724,4727,4733,4734,4737,4740,4741,4742,4743,4744,4745,4746,4747,4748,4749,4754,4755,4757,4764,4766,4767,4770,4771,4772,4773,4774,4775,4776,4777,4778,4779,4784,4787,4788,4794,4797,4799,4800,4804,4808,4811,4814,4818,4822,4824,4828,4833,4834,4838,4840,4841,4842,4843,4844,4845,4846,4847,4848,4849,4854,4855,4858,4864,4866,4868,4874,4877,4878,4880,4881,4882,4883,4884,4885,4886,4887,4888,4889,4894,4898,4899,4900,4904,4909,4911,4914,4919,4922,4924,4929,4933,4934,4939,4940,4941,4942,4943,4944,4945,4946,4947,4948,4949,4954,4955,4959,4964,4966,4969,4974,4977,4979,4984,4988,4989,4990,4991,4992,4993,4994,4995,4996,4997,4998,4999,5000,5001,5002,5003,5004,5005,5006,5007,5008,5009,5010,5011,5015,5020,5022,5025,5030,5033,5035,5040,5044,5045,5050,5051,5052,5053,5054,5055,5056,5057,5058,5059,5060,5065,5066,5070,5075,5077,5080,5085,5088,5090,5095,5099,5100,5101,5105,5110,5111,5112,5113,5114,5115,5116,5117,5118,5119,5121,5122,5125,5131,5133,5135,5141,5144,5145,5150,5151,5152,5153,5154,5155,5156,5157,5158,5159,5161,5165,5166,5171,5175,5177,5181,5185,5188,5191,5195,5199,5200,5202,5205,5211,5212,5215,5220,5221,5222,5223,5224,5225,5226,5227,5228,5229,5232,5233,5235,5242,5244,5245,5250,5251,5252,5253,5254,5255,5256,5257,5258,5259,5262,5265,5266,5272,5275,5277,5282,5285,5288,5292,5295,5299,5300,5303,5305,5311,5313,5315,5322,5323,5325,5330,5331,5332,5333,5334,5335,5336,5337,5338,5339,5343,5344,5345,5350,5351,5352,5353,5354,5355,5356,5357,5358,5359,5363,5365,5366,5373,5375,5377,5383,5385,5388,5393,5395,5399,5400,5404,5405,5411,5414,5415,5422,5424,5425,5433,5434,5435,5440,5441,5442,5443,5444,5445,5446,5447,5448,5449,5450,5451,5452,5453,5454,5455,5456,5457,5458,5459,5464,5465,5466,5474,5475,5477,5484,5485,5488,5494,5495,5499,5500,5501,5502,5503,5504,5505,5506,5507,5508,5509,5510,5511,5512,5513,5514,5515,5516,5517,5518,5519,5520,5521,5522,5523,5524,5525,5526,5527,5528,5529,5530,5531,5532,5533,5534,5535,5536,5537,5538,5539,5540,5541,5542,5543,5544,5545,5546,5547,5548,5549,5550,5551,5552,5553,5554,5555,5556,5557,5558,5559,5560,5561,5562,5563,5564,5565,5566,5567,5568,5569,5570,5571,5572,5573,5574,5575,5576,5577,5578,5579,5580,5581,5582,5583,5584,5585,5586,5587,5588,5589,5590,5591,5592,5593,5594,5595,5596,5597,5598,5599,5600,5605,5606,5611,5615,5616,5622,5625,5626,5633,5635,5636,5644,5645,5646,5650,5651,5652,5653,5654,5655,5656,5657,5658,5659,5660,5661,5662,5663,5664,5665,5666,5667,5668,5669,5675,5676,5677,5685,5686,5688,5695,5696,5699,5700,5705,5707,5711,5715,5717,5722,5725,5727,5733,5735,5737,5744,5745,5747,5750,5751,5752,5753,5754,5755,5756,5757,5758,5759,5765,5766,5767,5770,5771,5772,5773,5774,5775,5776,5777,5778,5779,5785,5787,5788,5795,5797,5799,5800,5805,5808,5811,5815,5818,5822,5825,5828,5833,5835,5838,5844,5845,5848,5850,5851,5852,5853,5854,5855,5856,5857,5858,5859,5865,5866,5868,5875,5877,5878,5880,5881,5882,5883,5884,5885,5886,5887,5888,5889,5895,5898,5899,5900,5905,5909,5911,5915,5919,5922,5925,5929,5933,5935,5939,5944,5945,5949,5950,5951,5952,5953,5954,5955,5956,5957,5958,5959,5965,5966,5969,5975,5977,5979,5985,5988,5989,5990,5991,5992,5993,5994,5995,5996,5997,5998,5999,6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6011,6016,6020,6022,6026,6030,6033,6036,6040,6044,6046,6050,6055,6056,6060,6061,6062,6063,6064,6065,6066,6067,6068,6069,6070,6076,6077,6080,6086,6088,6090,6096,6099,6100,6101,6106,6110,6111,6112,6113,6114,6115,6116,6117,6118,6119,6121,6122,6126,6131,6133,6136,6141,6144,6146,6151,6155,6156,6160,6161,6162,6163,6164,6165,6166,6167,6168,6169,6171,6176,6177,6181,6186,6188,6191,6196,6199,6200,6202,6206,6211,6212,6216,6220,6221,6222,6223,6224,6225,6226,6227,6228,6229,6232,6233,6236,6242,6244,6246,6252,6255,6256,6260,6261,6262,6263,6264,6265,6266,6267,6268,6269,6272,6276,6277,6282,6286,6288,6292,6296,6299,6300,6303,6306,6311,6313,6316,6322,6323,6326,6330,6331,6332,6333,6334,6335,6336,6337,6338,6339,6343,6344,6346,6353,6355,6356,6360,6361,6362,6363,6364,6365,6366,6367,6368,6369,6373,6376,6377,6383,6386,6388,6393,6396,6399,6400,6404,6406,6411,6414,6416,6422,6424,6426,6433,6434,6436,6440,6441,6442,6443,6444,6445,6446,6447,6448,6449,6454,6455,6456,6460,6461,6462,6463,6464,6465,6466,6467,6468,6469,6474,6476,6477,6484,6486,6488,6494,6496,6499,6500,6505,6506,6511,6515,6516,6522,6525,6526,6533,6535,6536,6544,6545,6546,6550,6551,6552,6553,6554,6555,6556,6557,6558,6559,6560,6561,6562,6563,6564,6565,6566,6567,6568,6569,6575,6576,6577,6585,6586,6588,6595,6596,6599,6600,6601,6602,6603,6604,6605,6606,6607,6608,6609,6610,6611,6612,6613,6614,6615,6616,6617,6618,6619,6620,6621,6622,6623,6624,6625,6626,6627,6628,6629,6630,6631,6632,6633,6634,6635,6636,6637,6638,6639,6640,6641,6642,6643,6644,6645,6646,6647,6648,6649,6650,6651,6652,6653,6654,6655,6656,6657,6658,6659,6660,6661,6662,6663,6664,6665,6666,6667,6668,6669,6670,6671,6672,6673,6674,6675,6676,6677,6678,6679,6680,6681,6682,6683,6684,6685,6686,6687,6688,6689,6690,6691,6692,6693,6694,6695,6696,6697,6698,6699,6700,6706,6707,6711,6716,6717,6722,6726,6727,6733,6736,6737,6744,6746,6747,6755,6756,6757,6760,6761,6762,6763,6764,6765,6766,6767,6768,6769,6770,6771,6772,6773,6774,6775,6776,6777,6778,6779,6786,6787,6788,6796,6797,6799,6800,6806,6808,6811,6816,6818,6822,6826,6828,6833,6836,6838,6844,6846,6848,6855,6856,6858,6860,6861,6862,6863,6864,6865,6866,6867,6868,6869,6876,6877,6878,6880,6881,6882,6883,6884,6885,6886,6887,6888,6889,6896,6898,6899,6900,6906,6909,6911,6916,6919,6922,6926,6929,6933,6936,6939,6944,6946,6949,6955,6956,6959,6960,6961,6962,6963,6964,6965,6966,6967,6968,6969,6976,6977,6979,6986,6988,6989,6990,6991,6992,6993,6994,6995,6996,6997,6998,6999,7000,7001,7002,7003,7004,7005,7006,7007,7008,7009,7010,7011,7017,7020,7022,7027,7030,7033,7037,7040,7044,7047,7050,7055,7057,7060,7066,7067,7070,7071,7072,7073,7074,7075,7076,7077,7078,7079,7080,7087,7088,7090,7097,7099,7100,7101,7107,7110,7111,7112,7113,7114,7115,7116,7117,7118,7119,7121,7122,7127,7131,7133,7137,7141,7144,7147,7151,7155,7157,7161,7166,7167,7170,7171,7172,7173,7174,7175,7176,7177,7178,7179,7181,7187,7188,7191,7197,7199,7200,7202,7207,7211,7212,7217,7220,7221,7222,7223,7224,7225,7226,7227,7228,7229,7232,7233,7237,7242,7244,7247,7252,7255,7257,7262,7266,7267,7270,7271,7272,7273,7274,7275,7276,7277,7278,7279,7282,7287,7288,7292,7297,7299,7300,7303,7307,7311,7313,7317,7322,7323,7327,7330,7331,7332,7333,7334,7335,7336,7337,7338,7339,7343,7344,7347,7353,7355,7357,7363,7366,7367,7370,7371,7372,7373,7374,7375,7376,7377,7378,7379,7383,7387,7388,7393,7397,7399,7400,7404,7407,7411,7414,7417,7422,7424,7427,7433,7434,7437,7440,7441,7442,7443,7444,7445,7446,7447,7448,7449,7454,7455,7457,7464,7466,7467,7470,7471,7472,7473,7474,7475,7476,7477,7478,7479,7484,7487,7488,7494,7497,7499,7500,7505,7507,7511,7515,7517,7522,7525,7527,7533,7535,7537,7544,7545,7547,7550,7551,7552,7553,7554,7555,7556,7557,7558,7559,7565,7566,7567,7570,7571,7572,7573,7574,7575,7576,7577,7578,7579,7585,7587,7588,7595,7597,7599,7600,7606,7607,7611,7616,7617,7622,7626,7627,7633,7636,7637,7644,7646,7647,7655,7656,7657,7660,7661,7662,7663,7664,7665,7666,7667,7668,7669,7670,7671,7672,7673,7674,7675,7676,7677,7678,7679,7686,7687,7688,7696,7697,7699,7700,7701,7702,7703,7704,7705,7706,7707,7708,7709,7710,7711,7712,7713,7714,7715,7716,7717,7718,7719,7720,7721,7722,7723,7724,7725,7726,7727,7728,7729,7730,7731,7732,7733,7734,7735,7736,7737,7738,7739,7740,7741,7742,7743,7744,7745,7746,7747,7748,7749,7750,7751,7752,7753,7754,7755,7756,7757,7758,7759,7760,7761,7762,7763,7764,7765,7766,7767,7768,7769,7770,7771,7772,7773,7774,7775,7776,7777,7778,7779,7780,7781,7782,7783,7784,7785,7786,7787,7788,7789,7790,7791,7792,7793,7794,7795,7796,7797,7798,7799,7800,7807,7808,7811,7817,7818,7822,7827,7828,7833,7837,7838,7844,7847,7848,7855,7857,7858,7866,7867,7868,7870,7871,7872,7873,7874,7875,7876,7877,7878,7879,7880,7881,7882,7883,7884,7885,7886,7887,7888,7889,7897,7898,7899,7900,7907,7909,7911,7917,7919,7922,7927,7929,7933,7937,7939,7944,7947,7949,7955,7957,7959,7966,7967,7969,7970,7971,7972,7973,7974,7975,7976,7977,7978,7979,7987,7988,7989,7990,7991,7992,7993,7994,7995,7996,7997,7998,7999,8000,8001,8002,8003,8004,8005,8006,8007,8008,8009,8010,8011,8018,8020,8022,8028,8030,8033,8038,8040,8044,8048,8050,8055,8058,8060,8066,8068,8070,8077,8078,8080,8081,8082,8083,8084,8085,8086,8087,8088,8089,8090,8098,8099,8100,8101,8108,8110,8111,8112,8113,8114,8115,8116,8117,8118,8119,8121,8122,8128,8131,8133,8138,8141,8144,8148,8151,8155,8158,8161,8166,8168,8171,8177,8178,8180,8181,8182,8183,8184,8185,8186,8187,8188,8189,8191,8198,8199,8200,8202,8208,8211,8212,8218,8220,8221,8222,8223,8224,8225,8226,8227,8228,8229,8232,8233,8238,8242,8244,8248,8252,8255,8258,8262,8266,8268,8272,8277,8278,8280,8281,8282,8283,8284,8285,8286,8287,8288,8289,8292,8298,8299,8300,8303,8308,8311,8313,8318,8322,8323,8328,8330,8331,8332,8333,8334,8335,8336,8337,8338,8339,8343,8344,8348,8353,8355,8358,8363,8366,8368,8373,8377,8378,8380,8381,8382,8383,8384,8385,8386,8387,8388,8389,8393,8398,8399,8400,8404,8408,8411,8414,8418,8422,8424,8428,8433,8434,8438,8440,8441,8442,8443,8444,8445,8446,8447,8448,8449,8454,8455,8458,8464,8466,8468,8474,8477,8478,8480,8481,8482,8483,8484,8485,8486,8487,8488,8489,8494,8498,8499,8500,8505,8508,8511,8515,8518,8522,8525,8528,8533,8535,8538,8544,8545,8548,8550,8551,8552,8553,8554,8555,8556,8557,8558,8559,8565,8566,8568,8575,8577,8578,8580,8581,8582,8583,8584,8585,8586,8587,8588,8589,8595,8598,8599,8600,8606,8608,8611,8616,8618,8622,8626,8628,8633,8636,8638,8644,8646,8648,8655,8656,8658,8660,8661,8662,8663,8664,8665,8666,8667,8668,8669,8676,8677,8678,8680,8681,8682,8683,8684,8685,8686,8687,8688,8689,8696,8698,8699,8700,8707,8708,8711,8717,8718,8722,8727,8728,8733,8737,8738,8744,8747,8748,8755,8757,8758,8766,8767,8768,8770,8771,8772,8773,8774,8775,8776,8777,8778,8779,8780,8781,8782,8783,8784,8785,8786,8787,8788,8789,8797,8798,8799,8800,8801,8802,8803,8804,8805,8806,8807,8808,8809,8810,8811,8812,8813,8814,8815,8816,8817,8818,8819,8820,8821,8822,8823,8824,8825,8826,8827,8828,8829,8830,8831,8832,8833,8834,8835,8836,8837,8838,8839,8840,8841,8842,8843,8844,8845,8846,8847,8848,8849,8850,8851,8852,8853,8854,8855,8856,8857,8858,8859,8860,8861,8862,8863,8864,8865,8866,8867,8868,8869,8870,8871,8872,8873,8874,8875,8876,8877,8878,8879,8880,8881,8882,8883,8884,8885,8886,8887,8888,8889,8890,8891,8892,8893,8894,8895,8896,8897,8898,8899,8900,8908,8909,8911,8918,8919,8922,8928,8929,8933,8938,8939,8944,8948,8949,8955,8958,8959,8966,8968,8969,8977,8978,8979,8980,8981,8982,8983,8984,8985,8986,8987,8988,8989,8990,8991,8992,8993,8994,8995,8996,8997,8998,8999,9000,9001,9002,9003,9004,9005,9006,9007,9008,9009,9010,9011,9019,9020,9022,9029,9030,9033,9039,9040,9044,9049,9050,9055,9059,9060,9066,9069,9070,9077,9079,9080,9088,9089,9090,9091,9092,9093,9094,9095,9096,9097,9098,9099,9100,9101,9109,9110,9111,9112,9113,9114,9115,9116,9117,9118,9119,9121,9122,9129,9131,9133,9139,9141,9144,9149,9151,9155,9159,9161,9166,9169,9171,9177,9179,9181,9188,9189,9190,9191,9192,9193,9194,9195,9196,9197,9198,9199,9200,9202,9209,9211,9212,9219,9220,9221,9222,9223,9224,9225,9226,9227,9228,9229,9232,9233,9239,9242,9244,9249,9252,9255,9259,9262,9266,9269,9272,9277,9279,9282,9288,9289,9290,9291,9292,9293,9294,9295,9296,9297,9298,9299,9300,9303,9309,9311,9313,9319,9322,9323,9329,9330,9331,9332,9333,9334,9335,9336,9337,9338,9339,9343,9344,9349,9353,9355,9359,9363,9366,9369,9373,9377,9379,9383,9388,9389,9390,9391,9392,9393,9394,9395,9396,9397,9398,9399,9400,9404,9409,9411,9414,9419,9422,9424,9429,9433,9434,9439,9440,9441,9442,9443,9444,9445,9446,9447,9448,9449,9454,9455,9459,9464,9466,9469,9474,9477,9479,9484,9488,9489,9490,9491,9492,9493,9494,9495,9496,9497,9498,9499,9500,9505,9509,9511,9515,9519,9522,9525,9529,9533,9535,9539,9544,9545,9549,9550,9551,9552,9553,9554,9555,9556,9557,9558,9559,9565,9566,9569,9575,9577,9579,9585,9588,9589,9590,9591,9592,9593,9594,9595,9596,9597,9598,9599,9600,9606,9609,9611,9616,9619,9622,9626,9629,9633,9636,9639,9644,9646,9649,9655,9656,9659,9660,9661,9662,9663,9664,9665,9666,9667,9668,9669,9676,9677,9679,9686,9688,9689,9690,9691,9692,9693,9694,9695,9696,9697,9698,9699,9700,9707,9709,9711,9717,9719,9722,9727,9729,9733,9737,9739,9744,9747,9749,9755,9757,9759,9766,9767,9769,9770,9771,9772,9773,9774,9775,9776,9777,9778,9779,9787,9788,9789,9790,9791,9792,9793,9794,9795,9796,9797,9798,9799,9800,9808,9809,9811,9818,9819,9822,9828,9829,9833,9838,9839,9844,9848,9849,9855,9858,9859,9866,9868,9869,9877,9878,9879,9880,9881,9882,9883,9884,9885,9886,9887,9888,9889,9890,9891,9892,9893,9894,9895,9896,9897,9898,9899,9900,9901,9902,9903,9904,9905,9906,9907,9908,9909,9910,9911,9912,9913,9914,9915,9916,9917,9918,9919,9920,9921,9922,9923,9924,9925,9926,9927,9928,9929,9930,9931,9932,9933,9934,9935,9936,9937,9938,9939,9940,9941,9942,9943,9944,9945,9946,9947,9948,9949,9950,9951,9952,9953,9954,9955,9956,9957,9958,9959,9960,9961,9962,9963,9964,9965,9966,9967,9968,9969,9970,9971,9972,9973,9974,9975,9976,9977,9978,9979,9980,9981,9982,9983,9984,9985,9986,9987,9988,9989,9990,9991,9992,9993,9994,9995,9996,9997,9998,9999,10000};
	bool isUnique(int number){
		bool flags[10] = {false};
		while(number > 0){
			if(flags[number%10]){
				return false;
			}
			flags[number%10] = true;
			number /= 10;
		}
		return true;
	}
public:
	int count(int n){
		int total = 0;
		for(unsigned int counter = 1;counter < n;counter++){
			if(isUnique(counter)){
				total++;
			}
		}
		return total;
	}
};

#endif /* UNIQUEDIGITS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
