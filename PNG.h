#pragma once
#define IHDR_CHUNK_LENGTH 13
// LEN 4
// NAME 4
// CONTAINER LEN
// CRC 4

struct template{
byte Header[8];
struct IHDR_chunk_template IHDR_chunk;
struct IEND_chunk_template IEND_chunk;
};


struct IHDR_chunk_template{
    int length;
    int W,H;
    byte name[4];
    byte depth,colorMode,compr,filter,interlace;
    int crc;
};
struct IEND_chunk_template{
    int length;
    int W,H;
    byte name[4];
    byte depth,colorMode,compr,filter,interlace;
    int crc;
};



typedef struct template template;
typedef char byte;