#include <Adafruit_ZeroPDM.h>
#include <Adafruit_ZeroDMA.h>
#include "utility/dma.h"

#define SAMPLERATE_HZ 16000
#define DECIMATION    64

#define  DMA_DATA_LENGTH                (DECIMATION / 16)      // 16 bits per 'I2S sample'
// a manual loop-unroller!
#define ADAPDM_REPEAT_LOOP_16(X) X X X X X X X X X X X X X X X X


#define SERIALPORT Serial

void setup_pdm();
void run_pdm();
void dma_callback(Adafruit_ZeroDMA *dma);