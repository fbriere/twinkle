#ifndef _G711_H
#define _G711_H

// The linear PCM codes are signed 16 bit values

// G.711 A-law
unsigned char linear2alaw(int pcm_val);
int alaw2linear(unsigned char a_val);

// G.711 u-law
unsigned char linear2ulaw(int pcm_val);
int ulaw2linear(unsigned char u_val);

// A-law <-> u-law conversions
unsigned char alaw2ulaw(unsigned char aval);
unsigned char ulaw2alaw(unsigned char uval);

#endif
