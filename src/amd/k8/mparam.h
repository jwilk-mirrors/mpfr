/* Generated by MPFR's tuneup.c, 2010-10-15, gcc 4.3.2 */
/* gcc11.fsffrance.org (Dual-Core AMD Opteron(tm) Processor 2212) with gmp 5.0.1 */


#define MPFR_MULHIGH_TAB  \
 -1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,9,11, \
 12,13,11,15,14,14,15,16,18,18,19,20,18,19,19,20, \
 22,23,23,20,26,30,28,28,32,30,30,28,32,30,32,32, \
 32,30,30,30,32,38,32,32,36,36,40,38,36,36,40,40, \
 40,40,40,40,46,44,48,48,46,46,56,48,56,56,56,56, \
 56,56,56,60,64,60,64,64,56,64,64,64,64,64,64,64, \
 72,72,72,72,72,72,72,72,72,72,72,72,80,72,80,80, \
 80,80,80,80,80,80,80,80,80,80,80,80,93,80,93,80, \
 72,76,80,93,80,93,93,90,93,93,93,93,93,93,90,93, \
 93,93,111,105,93,105,105,105,117,105,105,105,117,105,111,105, \
 117,105,117,117,117,105,117,117,117,117,111,117,117,117,117,117, \
 117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,117, \
 117,117,117,140,140,117,117,117,140,140,140,156,140,156,156,148, \
 156,156,156,156,156,155,156,156,156,155,156,156,156,156,156,156, \
 156,156,156,156,156,156,156,156,156,156,156,156,156,156,156,172, \
 172,172,172,172,180,180,180,179,180,180,188,188,180,188,188,188, \
 188,187,188,188,188,188,187,188,188,188,188,188,188,188,188,188, \
 188,188,188,188,188,188,188,188,188,188,220,220,219,220,220,219, \
 220,219,220,220,220,219,220,220,220,219,220,219,220,219,220,220, \
 220,236,219,220,220,219,220,252,252,252,236,252,252,252,252,236, \
 235,252,252,252,252,252,236,252,252,252,252,252,252,251,250,251, \
 252,252,252,252,251,252,252,252,252,252,252,252,252,252,252,252, \
 252,252,252,252,284,284,252,284,284,284,284,284,284,284,284,284, \
 284,284,284,284,284,284,284,284,284,284,284,283,284,284,284,284, \
 284,284,284,284,284,284,284,284,284,284,284,284,284,284,284,284, \
 284,316,316,316,300,316,316,284,316,316,316,316,316,316,316,316, \
 316,316,316,316,316,316,316,316,316,315,316,316,316,316,316,316, \
 316,315,316,316,316,316,316,316,315,316,315,316,316,315,316,316, \
 316,316,316,368,368,316,367,368,316,368,368,368,368,368,368,368, \
 368,368,368,368,368,368,368,368,368,368,368,368,368,367,368,368, \
 368,368,368,368,368,368,367,368,368,368,368,368,368,367,368,368, \
 368,367,368,368,367,368,368,367,368,368,368,367,368,368,367,368, \
 367,368,415,367,368,415,416,416,416,414,415,416,416,415,416,416, \
 416,416,416,416,416,415,416,416,416,415,415,416,416,416,416,415, \
 416,415,416,415,415,416,416,415,415,416,416,416,416,416,464,415, \
 415,416,464,416,415,416,415,416,416,464,416,464,464,463,464,464, \
 464,474,464,464,464,463,464,464,474,474,504,464,473,474,504,504, \
 474,474,504,504,504,502,504,504,504,504,504,504,504,504,504,504, \
 504,504,504,504,504,502,503,504,504,504,504,504,504,504,504,504, \
 504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,502, \
 503,504,504,503,504,504,503,504,503,504,504,504,504,504,503,504, \
 504,504,504,504,568,504,568,504,504,568,568,568,568,568,568,568, \
 568,567,568,568,568,567,568,568,568,568,568,568,568,568,568,568, \
 568,568,568,568,568,568,568,567,568,567,568,567,568,568,568,566, \
 567,568,568,567,568,568,565,568,567,568,567,568,568,567,568,568, \
 568,568,567,568,567,568,567,566,567,568,568,566,568,568,568,568, \
 568,568,568,568,567,568,567,568,567,568,567,568,568,568,568,568, \
 632,632,632,568,632,632,632,632,632,631,632,631,632,632,632,630, \
 631,632,630,632,632,632,631,632,631,632,631,632,632,632,632,632, \
 632,632,630,631,632,632,630,632,632,632,632,632,632,632,631,632, \
 632,632,631,632,632,632,631,632,632,632,630,632,632,632,632,632, \
 632,632,632,631,632,632,632,632,631,632,632,632,632,632,632,631, \
 632,632,632,631,632,631,632,736,736,632,632,736,632,631,632,631, \
 632,736,632,632,632,735,736,736,736,736,736,736,632,735,736,736, \
 736,734,736,736,735,736,736,734,736,736,736,736,736,736,735,736, \
 735,736,734,735,736,736,736,736,736,736,735,736,735,736,736,736, \
 736,736,736,736,736,736,736,736,735,736,735,736,736,736,735,736, \
 735,736,736,736,735,736,736,736,736,736,736,736,736,736,736,735, \
 736,736,736,735,736,736,736,735,736,736,736,832,736,736,832,735, \
 832,736,832,736,832,832,736,832,832,735,736,832,736,832,831,832, \
 832,831,832,832,832,832,832,830,832,832,832,832,832,832,831,832, \
 831,832,832,832,832,832,832,832,831,832,832,832,831,832,831,832, \
 831,832,832,832,831,832,832,832,832,832,831,832,832,832,832,832, \
 831,832,832,832,831,832,832,832,832,832,832,832,832,832,832,831 \
  
#define MPFR_SQRHIGH_TAB  \
 -1,0,0,0,0,-1,-1,-1,-1,-1,7,7,8,9,9,11, \
 11,11,11,11,13,13,14,15,17,17,18,17,17,17,18,18, \
 17,17,19,19,20,21,20,23,24,21,24,23,24,25,24,25, \
 28,27,28,29,29,31,28,29,34,34,34,34,34,34,40,34, \
 34,40,40,40,42,42,40,40,40,40,40,42,42,48,46,48, \
 42,46,48,48,46,50,46,49,54,54,56,46,54,48,56,48, \
 50,50,50,52,52,56,56,58,54,56,58,64,56,64,58,64, \
 58,64,66,58,68,68,62,72,68,66,66,72,64,72,68,72, \
 72,80,66,72,72,72,72,80,80,84,80,80,80,80,80,80, \
 80,80,80,80,84,84,92,80,84,84,92,84,96,92,92,96, \
 92,96,92,96,96,92,96,96,100,104,96,96,96,100,96,96, \
 96,96,112,96,96,96,96,96,100,100,96,112,112,112,112,112, \
 112,112,112,117,117,117,112,117,112,112,112,123,112,123,112,135, \
 112,112,112,112,112,117,112,135,141,135,141,135,141,141,141,147, \
 141,141,141,141,141,135,135,135,141,141,141,141,141,141,141,147, \
 141,141,147,141,141,147,147,147,147,147,147,147,141,141,153,159, \
 159,147,147,159,153,159,159,165,165,159,159,159,165,171,159,171, \
 165,165,171,171,165,165,171,171,165,171,171,171,165,171,171,171, \
 189,189,188,183,189,183,183,183,171,183,183,159,189,189,189,195, \
 189,165,188,195,189,171,171,171,171,188,189,188,189,189,188,189, \
 183,181,183,183,183,189,183,195,183,189,189,195,195,183,195,195, \
 195,183,183,195,195,189,189,183,183,183,189,195,183,189,189,189, \
 212,213,213,195,195,192,183,195,195,213,201,195,189,213,195,201, \
 201,213,213,213,213,213,213,213,237,213,213,213,213,213,237,213, \
 213,213,213,212,213,237,213,237,237,213,213,213,237,213,249,237, \
 237,237,237,237,249,237,237,237,237,237,249,237,249,237,237,237, \
 249,237,237,237,249,237,249,248,249,249,249,249,249,249,249,249, \
 273,273,249,273,273,249,273,285,273,285,273,273,273,273,285,285, \
 273,273,273,273,285,285,273,285,285,284,285,273,285,285,297,284, \
 285,284,285,285,285,285,297,297,297,273,297,285,297,285,297,297, \
 297,297,297,273,297,297,297,273,309,273,309,273,285,273,273,285, \
 273,273,284,285,285,333,285,285,285,285,285,285,285,297,297,297, \
 333,297,333,297,297,297,297,297,297,333,297,309,297,285,309,348, \
 348,297,309,348,309,321,320,321,297,333,320,321,321,321,321,321, \
 333,333,333,333,333,333,332,333,333,333,333,333,333,333,333,333, \
 333,333,348,333,333,345,348,348,348,348,348,348,348,332,333,348, \
 333,333,333,365,366,366,366,365,366,365,366,366,366,366,366,366, \
 333,366,366,366,333,366,333,420,420,420,420,348,420,366,365,348, \
 366,402,420,366,366,401,366,401,402,401,402,401,402,366,402,402, \
 402,366,402,366,402,402,420,419,418,419,420,420,420,419,420,420, \
 420,420,420,420,402,420,402,420,402,401,402,402,420,401,401,402, \
 420,420,420,401,402,438,402,402,420,402,420,420,420,420,420,420, \
 418,420,420,420,420,420,420,420,420,420,419,420,420,438,420,420, \
 420,420,420,420,420,438,420,420,438,438,438,420,438,438,438,437, \
 437,420,420,437,420,438,420,420,420,456,420,420,420,401,420,420, \
 420,420,420,420,420,419,420,420,420,420,420,473,420,420,438,420, \
 420,420,438,420,438,420,420,420,420,437,420,420,420,456,420,438, \
 420,437,418,419,420,419,420,420,419,419,420,420,420,420,438,420, \
 438,438,438,420,509,437,438,437,438,438,437,437,438,438,438,438, \
 438,438,437,437,437,420,438,438,456,438,455,456,473,456,456,456, \
 456,455,456,456,420,456,474,420,438,560,474,473,474,560,560,560, \
 560,560,559,474,474,474,559,560,560,560,560,510,560,490,560,492, \
 560,535,560,492,492,456,492,560,492,560,560,560,560,560,560,559, \
 559,560,510,560,560,560,560,560,535,559,560,560,560,560,560,510, \
 560,559,559,535,536,559,560,559,492,560,536,560,560,560,560,558, \
 559,559,559,560,560,560,559,560,560,560,560,560,560,560,558,559, \
 560,558,560,560,559,584,560,560,560,560,560,560,560,560,560,560, \
 560,560,560,560,560,536,579,560,584,560,584,584,560,583,584,584, \
 560,584,560,560,560,560,560,560,560,560,560,559,558,560,559,560, \
 560,560,560,560,560,560,559,560,560,584,608,560,607,560,559,584, \
 584,584,582,583,584,584,583,584,584,584,584,584,584,584,584,584, \
 560,584,728,560,728,560,584,728,560,608,728,728,560,560,696,728, \
 727,608,584,727,608,728,728,728,728,760,728,727,696,727,696,655, \
 728,759,759,760,696,728,759,726,760,632,759,760,757,760,695,727 \
  
#define MPFR_DIVHIGH_TAB  \
 0,1,2,3,2,5,6,7,8,9,10,11,12,13,14,15, \
 14,15,18,19,18,14,18,18,22,18,19,20,18,18,20,20, \
 22,22,23,22,26,26,23,26,24,30,28,28,28,28,30,30, \
 32,34,32,34,32,33,32,37,32,37,32,37,32,39,34,35, \
 39,34,34,39,39,37,39,39,39,39,37,39,39,45,39,46, \
 47,45,48,43,52,44,50,50,48,46,46,46,52,56,47,56, \
 52,60,60,56,56,64,61,60,56,64,54,63,56,64,64,60, \
 64,64,64,63,64,60,64,64,64,64,64,64,64,68,78,66, \
 68,69,78,74,78,67,67,74,78,74,74,78,79,78,78,79, \
 78,78,78,78,78,78,78,78,88,78,78,92,87,88,88,88, \
 96,92,95,91,92,94,95,96,92,96,92,96,92,112,96,112, \
 112,96,94,112,112,112,112,112,112,112,112,112,112,112,112,112, \
 128,112,112,128,112,112,112,128,112,112,112,128,112,112,128,112, \
 112,112,128,112,112,120,128,128,128,128,128,128,128,128,128,128, \
 128,128,120,128,128,128,128,128,120,128,128,128,128,128,128,128, \
 128,128,128,128,128,128,126,128,128,128,128,127,128,128,128,128, \
 148,148,144,143,140,141,140,148,148,141,136,148,148,157,156,148, \
 160,160,160,156,156,156,156,148,148,160,144,160,160,160,156,160, \
 156,157,160,156,156,156,148,156,155,156,156,156,156,160,160,156, \
 156,160,160,158,160,156,160,158,159,160,160,160,158,160,176,160, \
 160,184,180,184,184,186,184,184,184,184,186,184,184,184,184,184, \
 185,184,184,186,192,184,185,186,184,184,183,183,184,184,186,184, \
 192,184,208,184,224,186,208,186,209,192,208,184,207,208,224,210, \
 207,185,186,192,224,208,208,224,224,216,207,208,207,224,208,208, \
 224,216,216,208,224,216,224,224,216,224,224,224,224,224,224,224, \
 224,221,234,224,232,224,224,232,224,224,224,232,224,225,224,224, \
 224,224,224,224,224,224,224,224,224,256,224,256,224,232,224,224, \
 224,224,224,232,224,222,224,256,222,224,224,224,224,224,224,224, \
 224,256,232,256,240,233,240,232,248,234,233,256,240,256,256,256, \
 256,248,248,256,256,248,256,256,256,248,256,256,256,256,256,256, \
 256,256,256,256,256,256,248,256,248,256,248,248,256,256,256,256, \
 256,256,280,256,256,296,280,280,256,256,296,280,280,256,256,256, \
 296,296,280,296,280,296,296,296,280,280,312,296,280,296,312,312, \
 312,312,312,312,312,312,312,312,312,296,296,312,296,296,312,312, \
 312,296,312,312,296,311,312,312,312,312,312,312,312,312,312,296, \
 296,312,312,296,312,312,312,312,312,312,312,296,296,312,312,312, \
 312,312,312,312,312,312,312,312,296,312,312,312,312,312,312,312, \
 312,312,312,312,311,311,312,312,312,312,312,312,312,311,312,312, \
 312,312,312,312,312,312,312,312,312,312,312,312,312,312,312,312, \
 320,320,319,320,320,320,320,360,372,320,360,320,319,320,320,320, \
 368,344,368,368,369,372,368,370,372,368,352,352,360,370,376,360, \
 360,360,360,368,360,368,372,360,370,368,368,367,368,368,360,372, \
 368,368,370,372,372,372,370,368,368,368,368,368,368,368,369,372, \
 371,372,367,368,368,370,360,368,371,368,360,368,368,372,368,372, \
 372,368,368,368,360,368,372,368,368,368,371,371,368,416,368,368, \
 372,368,372,368,432,416,440,372,368,416,371,368,368,416,448,369, \
 432,416,440,416,408,448,440,448,448,448,440,448,440,440,448,448, \
 440,416,448,440,448,416,416,418,432,440,420,448,416,416,416,448, \
 448,420,448,448,448,416,432,448,416,448,448,448,440,408,416,440, \
 416,440,448,440,440,448,416,448,408,440,448,416,448,448,440,448, \
 416,420,440,420,417,448,416,440,408,432,448,448,415,432,448,432, \
 440,436,440,448,448,432,440,440,448,440,440,448,448,448,448,448, \
 448,440,448,448,448,448,448,448,448,448,448,440,445,448,448,448, \
 448,439,433,448,496,448,448,440,448,440,440,448,448,496,480,448, \
 448,448,448,468,448,496,448,448,448,468,448,496,448,467,448,448, \
 448,496,496,496,448,448,468,496,448,448,468,448,480,496,480,448, \
 468,512,496,496,512,496,496,480,496,512,496,512,496,512,496,512, \
 512,480,495,496,496,496,480,496,512,496,480,480,512,497,512,496, \
 512,512,496,496,496,512,496,496,512,512,512,496,480,560,496,496, \
 496,496,512,512,512,496,496,512,512,496,496,496,496,480,560,560, \
 512,496,496,560,576,496,496,560,560,496,560,512,496,560,560,560, \
 560,496,512,560,560,496,512,496,496,576,560,512,512,512,496,560, \
 512,560,512,512,560,512,560,512,576,512,576,575,560,560,592,512, \
 560,512,576,567,512,592,592,560,592,576,592,560,592,576,560,624 \
  
#define MPFR_MUL_THRESHOLD 28 /* limbs */
#define MPFR_SQR_THRESHOLD 66 /* limbs */
#define MPFR_EXP_2_THRESHOLD 315 /* bits */
#define MPFR_EXP_THRESHOLD 10860 /* bits */
#define MPFR_SINCOS_THRESHOLD 31385 /* bits */
#define MPFR_AI_THRESHOLD1 -10353 /* threshold for negative input of mpfr_ai */
#define MPFR_AI_THRESHOLD2 958
#define MPFR_AI_THRESHOLD3 17147
/* Tuneup completed successfully, took 954 seconds */
