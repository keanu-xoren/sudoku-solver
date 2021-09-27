#ifndef ENCODINGS_H
#define ENCODINGS_H
/////////////////////////////
//     VALUE ENCODINGS     //
/////////////////////////////
#define ONE   0x001
#define TWO   0x002
#define THREE 0x004
#define FOUR  0x008
#define FIVE  0x010
#define SIX   0x020
#define SEVEN 0x040
#define EIGHT 0x080
#define NINE  0x100
#define VALUE_MASK 0x1FF

/////////////////////////////
//  POSSIBILITY ENCODINGS  //
/////////////////////////////
// possibility pairing
#define P_ROW_PAIR 0x00000008
#define P_COL_PAIR 0x00000080
#define P_SQR_PAIR 0x00000800

#define P_ROW_PAIRED_CELL 0x00000007
#define P_COL_PAIRED_CELL 0x00000700
#define P_SQR_PAIRED_CELL 0x00000700

// row or column limited within a square
#define P_ROW_LIMITED 0x00001000
#define P_COL_LIMITED 0x00002000

#endif // ENCODINGS_H
