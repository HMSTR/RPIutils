#include <stdio.h>
#include "PNG.h"



void initPNG(template *PNG,int W,int H){
    (*PNG).Header[0] = 0x89;
    (*PNG).Header[1] = 0x50;
    (*PNG).Header[2] = 0x4E;
    (*PNG).Header[3] = 0x47;
    (*PNG).Header[4] = 0x0D;
    (*PNG).Header[5] = 0x0A;
    (*PNG).Header[6] = 0x1A;
    (*PNG).Header[7] = 0x0A;
    (*PNG).IHDR_chunk.length = IHDR_CHUNK_LENGTH;
    (*PNG).IHDR_chunk.crc = 123;
    (*PNG).IHDR_chunk.H = H;
    (*PNG).IHDR_chunk.H = W;
    (*PNG).IHDR_chunk.depth = 8;
    (*PNG).IHDR_chunk.colorMode = 2;
    (*PNG).IHDR_chunk.compr = 0;
    (*PNG).IHDR_chunk.filter = 0;
    (*PNG).IHDR_chunk.interlace = 0;
    (*PNG).IHDR_chunk.name[0] = 'I';
    (*PNG).IHDR_chunk.name[0] = 'H';
    (*PNG).IHDR_chunk.name[0] = 'D';
    (*PNG).IHDR_chunk.name[0] = 'R';



    (*PNG).IEND_chunk.length=0;
    (*PNG).IEND_chunk.crc=123;
    (*PNG).IEND_chunk.name[0] = 'I';
    (*PNG).IEND_chunk.name[0] = 'E';
    (*PNG).IEND_chunk.name[0] = 'N';
    (*PNG).IEND_chunk.name[0] = 'D';
}

int main(){
template PNG;
initPNG(&PNG,1,1);
}