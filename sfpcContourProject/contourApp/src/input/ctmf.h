/* see http://nomis80.org/ctmf.html */

#ifndef CTMF_H
#define CTMF_H

namespace milton {

void ctmf(
   const unsigned char* src, unsigned char* dst,
   int width, int height,
   int src_step_row, int dst_step_row,
   int r, int channels, unsigned long memsize = 1048576
);

}

#endif



//ctmf.CTMF(clip clip[, int radius=2, int memsize=1048576, int[] planes])
//clip: Clip to process. Any planar format with integer sample type of 8-16 bit depth is supported.
//
//radius: Median filter radius. The kernel will be a 2*radius+1 by 2*radius+1 square. The maximum value is 127.
//
//memsize: Maximum amount of memory to use, in bytes. Set this to the size of the L2 or L3 cache, then vary it slightly and measure the processing time to find the optimal value. For example, a 512 KB L2 cache would have memsize=512*1024 initially.
//
//planes: A list of the planes to process. By default all planes are processed.