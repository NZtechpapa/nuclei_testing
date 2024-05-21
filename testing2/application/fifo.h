/*
 * jingan_fifo.h
 *
 *  Created on: 2024年4月30日
 *      Author: liuzihao
 */

#ifndef APPLICATION_JINGAN_FIFO_H_
#define APPLICATION_JINGAN_FIFO_H_

#include "config.h"

#define DSH_MAX_PEAKINFO_CHAN 2

#define DSH_FIFO_MAIN_POSITION 0x0001
#define DSH_FIFO_SECOND_POSITION 0x0002
#define DSH_FIFO_THIRD_POSITION 0x0004
// set  mean positive, else negtive
#define DSH_FIFO_MAIN_ACCURACY 0x0010
#define DSH_FIFO_SECOND_ACCURACY 0x0020
#define DSH_FIFO_THIRD_ACCURACY 0x0040

typedef enum
{
    dsh_fifo_mainpeak = 0,
    dsh_fifo_secpeak,
    dsh_fifo_thirdpeak,
    dsh_fifo_maxpeak
} dsh_fifoEnum_t;



typedef struct dsh_fifopeakinfo_s
{
    sal_uint16_t peakstatus;
    sal_uint32_t flashcount;
    sal_uint16_t peakshist[dsh_fifo_maxpeak];
    sal_uint16_t peakspos[dsh_fifo_maxpeak];
    sal_uint16_t peaksaccpos[dsh_fifo_maxpeak];
    sal_uint32_t avgHist;
    sal_uint16_t stddHist;
} dsh_fifopeakinfo_t;

typedef struct
{
    sal_uint16_t frameid;
    sal_uint32_t mp0;
    sal_uint32_t sp0;
    sal_uint32_t tp0;
    sal_uint32_t mp1;
    dsh_fifopeakinfo_t chanPeakinfo[DSH_MAX_PEAKINFO_CHAN];
    sal_uint16_t peakstatus;
    sal_uint32_t flashcount;
    sal_uint16_t peakshist[dsh_fifo_maxpeak];
    sal_uint16_t peakspos[dsh_fifo_maxpeak];
    sal_uint16_t peaksaccpos[dsh_fifo_maxpeak];
    sal_uint32_t avgHist;
    sal_uint16_t stddHist;

} dsh_output_fifo_t;

#pragma pack(2)

typedef struct dsh_jingan_pos_s
{
    sal_uint16_t pos : 9;
    sal_uint16_t valid : 1;
    sal_uint16_t reserved : 6;
} dsh_jingan_pos_t;

typedef struct dsh_jingan_acc_s
{
    sal_uint16_t accpos : 8;
    sal_uint16_t positve : 1;
    sal_uint16_t reserved : 7;
} dsh_jingan_acc_t;

typedef struct dsh_jingan_avgh_s
{
    sal_uint16_t avgR0h : 4;
    sal_uint16_t avgR1h : 4;
    sal_uint16_t reserved : 8;
} dsh_jingan_avgh_t;

typedef struct dsh_jingan_fifo_inf_s
{
    // 0th 0x400 fmID
    sal_uint16_t frameId;
    // 1st 0x401 mmxvR0 [22,7]
    // main peak
    sal_uint16_t mmxvR0;
    // 2st 0x402 smxvR0
    sal_uint16_t smxvR0;
    // 3st 0x403 tmxvR0
    sal_uint16_t tmxvR0;
    // 4th 0x404 avgQ0
    // caculate the avg after removing the three peaks
    sal_uint16_t avgQ0;
    // caculate the avg after removing the three peaks  square ()
    // 5th 0x405  stdQ0
    sal_uint16_t stdQ0;
    // the location of the bin about the main peak
    //  roimdqlf : valid / invalid
    // 6th  0x406 roimdqlf0andmmxpf0
    dsh_jingan_pos_t roimdqlf0andmmxpf0;
    // 7th  0x407 roiSDqlf0 SMXPF0
    dsh_jingan_pos_t roiSDqlf0andSMXF0;
    // 8th  0x408 roiTDqlf0 tmxpF0
    dsh_jingan_pos_t roiTDqlf0andtmxpF0;
    // 9th  0x409 hgmFlsCntR[0] [4+:16]
    // TIPS： should multiple 16
    sal_uint16_t hgmFlsCntR0;
    // 10th -x40a mmxvR1[22:7]
    sal_uint16_t mmxvR1;
    // 11th 0x40b  smxvR1[22:7]
    sal_uint16_t smxvR1;
    // 12th 0x40c  tmxvR1[22:7]
    sal_uint16_t tmxvR1;
    // 13th 0x40d  avgQ1[15:1]
    sal_uint16_t avgQ1;
    // 14th 0x40e  stdQ1[15:1]
    sal_uint16_t stdQ1;
    // 15th 0x40f  roiMDqlf1, mmxpF1[8:0]
    dsh_jingan_pos_t roiMDqlf1andmmxpF1;
    // 16th 0x410  roiSDqlf1 SMXPF1
    dsh_jingan_pos_t roiSDqlf1andSMXPF1;
    // 17th  0x411 roiTDqlf1 tmxpF1
    dsh_jingan_pos_t roiTDqlf1andtmxpF1;
    // 18th  0x412 hgmFlsCntR[1]
    sal_uint16_t hgmFlsCnt1;
    // 19th  0x413 saSgnR0[0],subAccRo[0][7:0]
    dsh_jingan_acc_t saSgnRO0andsubAccRO0;
    // 20th  0x414 saSgnR0[1],subAccRo[1][7:0]
    dsh_jingan_acc_t saSgnR01andsubAccR01;
    // 21th  0x415 saSgnR0[2],subAccR0[2][7:0]
    dsh_jingan_acc_t saSgnR02andsubAccR02;
    // 22th  0x416 saSgnR1[0],subAccR1[0][7:0]
    dsh_jingan_acc_t saSgnR10andsubAccR10;
    // 23th  0x417 saSgnR1[1],subAccR1[1][7:0]
    dsh_jingan_acc_t saSgnR11andsubAccR11;
    // 24th  0x418 saSgnR1[2],subAccR1[2][7:0]
    dsh_jingan_acc_t saSgnR12andsubAccR12;
    // 25th  0x419  padD0
    sal_uint16_t padD0;
    // 26th  0x41A  padD1
    sal_uint16_t padD1;
    // 27th  0x41B  avgR1[17+:4]  avgR0[17+:4]
    dsh_jingan_avgh_t avgR1handavgR0h;
} dsh_jingan_fifo_inf_t;

#pragma pack()

void jingan_fifo_decode(dsh_output_fifo_t *fifo_info);

#endif /* APPLICATION_JINGAN_FIFO_H_ */
