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

 #define DEFINE_POSITION1 0x0001
 #define DEFINE_POSITION2 0x0002
 #define DEFINE_POSITION3 0x0004
 // set  mean positive, else negtive
 #define DEFINE_ACCURACY1 0x0010
 #define DEFINE_ACCURACY2 0x0020
 #define DEFINE_ACCURACY3 0x0040

 typedef enum
 {
     peak1_enum = 0,
     peak2_enum,
     peak3_enum,
     peak_maxpeak
 } peakEnum_t;



 typedef struct
 {
     sal_uint16_t peakstatus;
     sal_uint32_t flashcount;
     sal_uint16_t peakshist[peak_maxpeak];
     sal_uint16_t peakspos[peak_maxpeak];
     sal_uint16_t peaksaccpos[peak_maxpeak];
     sal_uint32_t avgHist;
     sal_uint16_t stddHist;
 } fifo_peak_info_t;

 typedef struct
 {
     sal_uint16_t frameid;
     sal_uint32_t mp0;
     sal_uint32_t sp0;
     sal_uint32_t tp0;
     sal_uint32_t mp1;
     fifo_peak_info_t chanPeakinfo[DSH_MAX_PEAKINFO_CHAN];
     sal_uint16_t peakstatus;
     sal_uint32_t flashcount;
     sal_uint16_t peakshist[peak_maxpeak];
     sal_uint16_t peakspos[peak_maxpeak];
     sal_uint16_t peaksaccpos[peak_maxpeak];
     sal_uint32_t avgHist;
     sal_uint16_t stddHist;

 } fifo_output_t;

 #pragma pack(2)

 typedef struct
 {
     sal_uint16_t pos : 9;
     sal_uint16_t valid : 1;
     sal_uint16_t reserved : 6;
 } peak_pos_t;

 typedef struct
 {
     sal_uint16_t accpos : 8;
     sal_uint16_t positve : 1;
     sal_uint16_t reserved : 7;
 } peak_acc_t;

 typedef struct
 {
     sal_uint16_t avgR0h : 4;
     sal_uint16_t avgR1h : 4;
     sal_uint16_t reserved : 8;
 } peak_avg_t;

 typedef struct
 {
     sal_uint16_t frameId;
     sal_uint16_t mmxvR0;
     sal_uint16_t smxvR0;
     sal_uint16_t tmxvR0;
     sal_uint16_t avgQ0;
     sal_uint16_t stdQ0;
     peak_pos_t roimdqlf0andmmxpf0;
     peak_pos_t roiSDqlf0andSMXF0;
     peak_pos_t roiTDqlf0andtmxpF0;
     sal_uint16_t hgmFlsCntR0;
     sal_uint16_t mmxvR1;
     sal_uint16_t smxvR1;
     sal_uint16_t tmxvR1;
     sal_uint16_t avgQ1;
     sal_uint16_t stdQ1;
     peak_pos_t roiMDqlf1andmmxpF1;
     peak_pos_t roiSDqlf1andSMXPF1;
     peak_pos_t roiTDqlf1andtmxpF1;
     sal_uint16_t hgmFlsCnt1;
     peak_acc_t saSgnRO0andsubAccRO0;
     peak_acc_t saSgnR01andsubAccR01;
     peak_acc_t saSgnR02andsubAccR02;
     peak_acc_t saSgnR10andsubAccR10;
     peak_acc_t saSgnR11andsubAccR11;
     peak_acc_t saSgnR12andsubAccR12;
     sal_uint16_t padD0;
     sal_uint16_t padD1;
     peak_avg_t avgR1handavgR0h;
 } fifo_encode_info_t;

 #pragma pack()

 void fifo_decode_f(fifo_output_t *fifo_info);

#endif /* APPLICATION_JINGAN_FIFO_H_ */
