/* Generated by MPFR's tuneup.c, 2009-02-09, gcc 4.3 */
/* achille.loria.fr with gmp-4.2.4 */

#define MPFR_TUNE_CASE "AMD K8"
#define MPFR_MULHIGH_TAB  \
 -1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,68,68,0,67,66,66, \
 65,65,64,64,67,67,64,72,65,79,68,72,67,79,72,72, \
 80,80,81,72,76,82,77,77,84,84,88,88,83,83,81,84, \
 88,88,80,80,96,96,100,97,98,89,96,84,100,97,98,98, \
 96,96,100,100,98,98,93,93,100,97,101,98,96,99,121,121, \
 104,101,108,108,112,109,110,122,111,117,115,115,122,122,123,123, \
 117,117,122,122,123,123,128,128,129,129,126,126,135,131,128,128, \
 129,129,126,126,147,143,132,132,141,137,134,134,135,147,140,140, \
 141,141,146,146,147,147,144,140,149,141,146,146,147,147,152,144, \
 153,165,146,146,147,147,152,156,165,153,162,170,167,171,168,168, \
 159,159,170,170,171,166,167,172,168,168,189,189,200,170,171,171, \
 177,167,168,168,169,199,195,200,201,201,192,192,198,198,199,189, \
 195,195,201,201,207,207,188,188,189,199,195,200,201,201,202,197, \
 198,198,189,199,210,200,196,196,197,192,213,208,219,224,225,200, \
 233,227,228,204,211,211,212,206,237,213,202,220,203,239,204,240, \
 247,211,212,212,213,243,232,232,239,215,216,222,229,235,236,224, \
 225,225,226,226,227,245,246,234,241,223,248,224,225,249,226,226, \
 227,233,234,252,247,235,236,236,237,237,250,238,239,245,246,240, \
 249,249,236,236,237,251,252,252,253,253,254,254,297,241,242,249, \
 257,257,258,251,245,245,246,267,247,261,248,248,249,249,285,278, \
 258,258,259,273,281,281,282,261,276,297,270,270,271,271,272,272, \
 273,273,288,281,282,289,290,283,284,277,285,278,286,286,287,287, \
 289,281,282,290,291,291,284,284,293,301,302,310,311,303,304,312, \
 273,297,330,282,283,299,308,348,309,285,310,366,287,327,288,288, \
 297,297,330,338,339,339,348,348,349,349,302,366,335,335,344,312, \
 297,361,330,354,355,339,348,348,341,365,342,342,359,351,360,328, \
 329,365,357,357,358,349,350,341,342,351,352,361,362,380,363,363, \
 364,364,347,347,348,348,349,367,368,341,342,342,343,343,380,380, \
 345,345,346,346,347,347,348,357,358,385,386,359,360,360,361,361, \
 362,362,363,363,364,364,365,410,411,357,358,358,359,422,414,378, \
 379,369,410,380,381,381,432,362,363,423,434,434,425,435,436,366, \
 417,437,438,438,369,399,400,440,441,441,402,382,383,393,384,384, \
 445,405,406,436,437,417,418,418,409,429,410,390,411,431,402,432, \
 423,393,414,404,445,425,436,436,417,417,438,438,399,449,450,440, \
 431,420,421,443,433,433,434,445,435,435,414,414,426,426,427,427, \
 417,417,418,418,419,430,431,442,443,443,433,433,434,434,435,501, \
 425,447,470,459,416,427,428,450,429,429,430,474,486,464,432,432, \
 455,455,489,456,468,457,469,447,459,459,438,471,472,450,462,473, \
 497,509,510,486,463,487,452,452,501,489,490,454,467,491,492,456, \
 469,469,470,470,483,447,508,508,509,509,510,510,451,499,452,452, \
 513,501,526,490,491,455,456,492,493,505,506,470,495,483,484,472, \
 473,521,510,474,535,487,488,500,501,501,502,562,563,563,528,528, \
 528,528,581,490,491,491,492,492,506,493,494,520,495,495,561,587, \
 588,510,563,589,590,499,513,513,566,566,528,515,516,516,517,569, \
 583,583,571,597,598,585,599,586,600,600,510,575,576,563,525,564, \
 578,591,527,579,567,528,594,607,556,582,583,583,558,597,598,546, \
 571,585,586,600,601,545,588,546,589,561,562,562,591,591,578,592, \
 593,593,594,594,567,595,596,596,597,597,598,598,571,599,600,572, \
 573,573,574,574,575,589,618,590,563,633,634,578,593,579,580,580, \
 581,595,596,582,597,625,626,570,571,571,600,600,601,601,602,602, \
 599,599,600,600,601,616,602,602,618,618,589,634,590,605,621,591, \
 607,607,623,623,624,609,625,595,596,596,597,597,598,628,629,599, \
 645,645,616,631,632,632,633,708,634,604,605,680,681,636,652,607, \
 608,623,624,744,670,640,641,626,627,672,673,658,659,704,630,630, \
 625,705,674,642,643,675,676,708,709,709,710,742,679,743,744,696, \
 681,633,698,682,683,699,668,732,717,669,670,670,687,703,704,704, \
 657,689,674,690,707,675,676,708,709,709,710,710,695,727,728,744, \
 713,681,682,714,715,699,700,684,701,701,702,702,703,703,704,672 \

#define MPFR_SQRHIGH_TAB  \
 -1,0,0,0,0,0,0,0,0,5,6,6,7,7,8,8, \
 9,10,10,10,11,11,12,12,13,13,14,14,15,15,16,16, \
 17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24, \
 25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32, \
 33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40, \
 41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48, \
 49,49,50,50,51,51,52,52,53,53,54,54,55,55,56,56, \
 57,57,58,58,59,59,60,60,61,61,62,62,63,63,64,64, \
 65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72, \
 73,73,74,74,75,75,76,76,77,77,78,78,79,79,80,80, \
 81,81,82,82,83,83,84,84,85,85,86,86,87,87,88,88, \
 89,89,90,90,91,91,92,92,93,93,94,94,95,95,96,96, \
 97,97,98,98,99,99,100,100,101,101,102,102,103,103,104,104, \
 105,105,106,106,107,107,108,108,109,109,110,110,111,111,112,112, \
 113,113,114,114,115,115,116,116,117,117,118,118,119,119,120,120, \
 121,121,122,122,123,123,124,124,125,125,126,126,127,127,128,128, \
 129,129,130,130,131,131,132,132,133,133,134,134,135,135,136,136, \
 137,137,138,138,139,139,140,140,141,141,142,142,143,143,144,144, \
 145,145,146,146,147,147,148,158,159,149,150,150,151,151,152,152, \
 153,153,154,154,155,155,156,156,157,157,158,158,159,159,160,160, \
 161,161,162,162,163,163,164,164,165,165,166,166,167,167,180,186, \
 199,169,170,170,171,171,172,172,173,209,198,198,205,175,176,176, \
 177,177,178,214,215,179,180,210,211,199,200,200,201,183,184,184, \
 185,185,216,186,187,211,212,212,213,189,190,190,191,191,192,192, \
 193,193,194,194,195,195,196,196,197,197,198,198,199,199,200,200, \
 201,201,202,202,203,203,204,204,205,205,206,206,207,207,208,208, \
 209,209,210,210,211,211,212,240,213,213,214,214,215,215,216,216, \
 217,217,218,218,219,219,248,248,249,221,222,222,223,223,224,224, \
 225,225,226,226,227,227,228,228,229,229,230,230,231,231,232,264, \
 273,233,234,234,267,235,236,236,237,237,238,238,239,239,240,288, \
 273,241,242,242,243,243,244,284,261,277,278,270,271,247,248,248, \
 249,249,250,250,251,251,252,252,253,253,254,254,255,255,256,256, \
 257,284,258,294,295,259,260,260,261,261,262,262,263,263,264,264, \
 265,265,266,266,267,267,268,268,269,269,270,270,271,271,272,272, \
 273,273,274,274,320,320,276,276,277,277,278,278,279,279,280,280, \
 281,281,282,282,283,283,284,284,285,285,286,286,287,287,288,288, \
 289,289,290,290,291,291,292,292,293,293,294,294,295,295,296,296, \
 297,297,298,298,299,299,300,300,301,301,302,302,303,303,304,304, \
 305,305,306,306,307,307,308,308,309,309,310,310,311,311,312,342, \
 333,313,314,314,315,315,316,316,317,317,318,318,319,319,320,320, \
 321,321,322,322,323,323,324,324,325,325,326,326,327,327,328,328, \
 329,329,330,330,331,331,332,332,333,333,334,334,335,335,336,336, \
 337,337,338,338,339,339,340,340,341,341,342,342,343,343,344,344, \
 345,345,346,401,402,402,348,414,349,349,350,350,351,351,352,418, \
 413,425,426,354,427,427,356,428,429,429,430,358,359,359,360,420, \
 361,361,362,422,423,363,364,436,437,401,402,366,367,415,416,416, \
 417,417,418,454,371,371,456,372,373,373,374,374,375,375,376,376, \
 377,377,378,378,379,379,380,380,381,381,382,382,383,383,384,384, \
 385,385,386,386,387,465,388,440,441,441,390,390,391,391,392,392, \
 393,393,394,446,447,395,396,396,397,397,398,437,438,464,465,400, \
 401,401,402,402,468,403,404,404,405,444,445,497,407,472,473,408, \
 409,409,501,410,411,411,451,438,465,465,414,492,493,415,416,416, \
 417,417,418,418,419,419,420,420,421,421,422,422,423,423,424,424, \
 425,425,426,426,427,427,428,428,429,429,486,430,431,431,432,432, \
 433,433,434,434,435,435,436,436,437,437,438,438,439,439,440,440, \
 441,441,442,498,499,443,444,528,445,445,446,446,447,447,448,448, \
 449,449,450,510,526,451,452,452,453,453,454,454,455,455,456,546, \
 487,457,458,458,459,459,460,460,461,461,462,462,463,463,464,464, \
 465,540,541,466,467,467,468,513,514,499,560,470,471,471,472,472, \
 473,473,474,474,475,535,536,476,477,582,553,478,479,599,600,585, \
 481,481,482,578,579,483,484,484,485,485,486,486,487,487,488,488, \
 489,489,490,490,491,603,620,492,493,589,590,494,495,495,496,496, \
 497,593,594,498,499,499,500,500,501,501,502,502,503,503,504,504, \
 505,505,506,506,507,507,508,508,509,509,510,510,511,511,512,608 \

#define MPFR_MUL_THRESHOLD 6 /* limbs */
#define MPFR_EXP_2_THRESHOLD 595 /* bits */
#define MPFR_EXP_THRESHOLD 10606 /* bits */
