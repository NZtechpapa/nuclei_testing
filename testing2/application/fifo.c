/*
 * jingan_fifo.c
 *
 *  Created on: 2024年4月30日
 *      Author: liuzihao
 */

#include "fifo.h"

#define HW16_REG(ADDRESS)  (*((volatile sal_uint16_t *)(ADDRESS)))

// reg read
 __attribute__((noinline)) void dtof_ram_io_read(sal_uint16_t address, sal_uint16_t * value_p, sal_uint16_t len) {
    sal_uint16_t index = 0;
    sal_uint16_t bnk_status;
     // write the address to 0xfe
    (*((volatile sal_uint16_t *)(4))) = address;

     // read the value from 0xff
    for(index = 0; index < len ; index++) {
        value_p[index] = HW16_REG(6);
    }

    return;
}


 __attribute__((noinline)) void dtof_fifo_io_read(sal_uint16_t * value_p, sal_uint16_t len){
    dtof_ram_io_read(0, value_p, len);
 }





 __attribute__((noinline)) sal_uint32_t MergeIntegerDecimals(sal_uint16_t x, sal_uint16_t y, sal_uint16_t s)
{
    if(s == 1){
        return ((x << 9) - y);
    }else{
        return ((x << 9) + y);
    }
}

void jingan_fifo_decode(dsh_output_fifo_t * fifo_info) {
    // int ret = SAL_RET_ERROR;
    dsh_jingan_fifo_inf_t hslinfo;

    dtof_fifo_io_read((sal_uint16_t *)&hslinfo, 8);

    fifo_info->frameid  =  hslinfo.frameId;
     fifo_info->mp0 = MergeIntegerDecimals(hslinfo.roimdqlf0andmmxpf0.pos, hslinfo.saSgnRO0andsubAccRO0.accpos, hslinfo.saSgnRO0andsubAccRO0.positve);
     fifo_info->sp0 = MergeIntegerDecimals(hslinfo.roiSDqlf0andSMXF0.pos, hslinfo.saSgnR01andsubAccR01.accpos, hslinfo.saSgnR01andsubAccR01.positve);
     fifo_info->tp0 = MergeIntegerDecimals(hslinfo.roiTDqlf0andtmxpF0.pos, hslinfo.saSgnR02andsubAccR02.accpos, hslinfo.saSgnR02andsubAccR02.positve);
     fifo_info->mp1 = MergeIntegerDecimals(hslinfo.roiMDqlf1andmmxpF1.pos, hslinfo.saSgnR10andsubAccR10.accpos, hslinfo.saSgnR10andsubAccR10.positve);

    // encode hist values
    fifo_info->chanPeakinfo[0].peakshist[0] =  hslinfo.mmxvR0; // mv0
    fifo_info->chanPeakinfo[0].peakshist[1] =  hslinfo.smxvR0; // sv0
    fifo_info->chanPeakinfo[0].peakshist[2] =  hslinfo.tmxvR0; // tv0
    fifo_info->chanPeakinfo[0].flashcount  =  hslinfo.hgmFlsCntR0;
    // init flag
    fifo_info->chanPeakinfo[0].peakstatus = 0;
    // encode peakspos
    if (!!(hslinfo.roimdqlf0andmmxpf0.valid&0x01)) {
        fifo_info->chanPeakinfo[0].peakspos[0] =  hslinfo.roimdqlf0andmmxpf0.pos;
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_MAIN_POSITION;
    }

    if (!!(hslinfo.roiSDqlf0andSMXF0.valid&0x01)) {
        fifo_info->chanPeakinfo[0].peakspos[1] =  hslinfo.roiSDqlf0andSMXF0.pos;
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_SECOND_POSITION;
    }

    if (!!(hslinfo.roiTDqlf0andtmxpF0.valid&0x01)) {
        fifo_info->chanPeakinfo[0].peakspos[2] =  hslinfo.roiTDqlf0andtmxpF0.pos;
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_THIRD_POSITION;
    }

    // encode acc
    if (!!(hslinfo.saSgnRO0andsubAccRO0.positve&0x01)) {
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_MAIN_ACCURACY;
    }
    fifo_info->chanPeakinfo[0].peaksaccpos[0] =  hslinfo.saSgnRO0andsubAccRO0.accpos;

    if (!!(hslinfo.saSgnR01andsubAccR01.positve&0x01)) {
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_SECOND_ACCURACY;
    }
    fifo_info->chanPeakinfo[0].peaksaccpos[1] =  hslinfo.saSgnR01andsubAccR01.accpos;

    if (!!(hslinfo.saSgnR02andsubAccR02.positve&0x01)) {
        fifo_info->chanPeakinfo[0].peakstatus |= DSH_FIFO_THIRD_ACCURACY;
    }
    fifo_info->chanPeakinfo[0].peaksaccpos[2] =  hslinfo.saSgnR02andsubAccR02.accpos;

    fifo_info->chanPeakinfo[0].avgHist = hslinfo.avgQ0 + (hslinfo.avgR1handavgR0h.avgR0h << 16);
    // Standard Deviation
    fifo_info->chanPeakinfo[0].stddHist = hslinfo.stdQ0;

    // ref encode
    // encode hist values
    fifo_info->chanPeakinfo[1].peakshist[0] =  hslinfo.mmxvR1; // mv1
    fifo_info->chanPeakinfo[1].peakshist[1] =  hslinfo.smxvR1;
    fifo_info->chanPeakinfo[1].peakshist[2] =  hslinfo.tmxvR1;
    fifo_info->chanPeakinfo[1].flashcount  =  hslinfo.hgmFlsCnt1;
    fifo_info->chanPeakinfo[1].peakstatus = 0;
    // encode peakspos
    if (!!(hslinfo.roiMDqlf1andmmxpF1.valid&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_MAIN_POSITION;
    }
    fifo_info->chanPeakinfo[1].peakspos[0] =  hslinfo.roiMDqlf1andmmxpF1.pos;

    if (!!(hslinfo.roiSDqlf1andSMXPF1.valid&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_SECOND_POSITION;
    }
    fifo_info->chanPeakinfo[1].peakspos[1] =  hslinfo.roiSDqlf1andSMXPF1.pos;

    if (!!(hslinfo.roiTDqlf1andtmxpF1.valid&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_THIRD_POSITION;
    }
    fifo_info->chanPeakinfo[1].peakspos[2] =  hslinfo.roiTDqlf1andtmxpF1.pos;
    // encode acc
    if (!!(hslinfo.saSgnR10andsubAccR10.positve&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_MAIN_ACCURACY;
    }
    fifo_info->chanPeakinfo[1].peaksaccpos[0] =  hslinfo.saSgnR10andsubAccR10.accpos;

    if (!!(hslinfo.saSgnR11andsubAccR11.positve&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_SECOND_ACCURACY;
    }
    fifo_info->chanPeakinfo[1].peaksaccpos[1] =  hslinfo.saSgnR11andsubAccR11.accpos;

    if (!!(hslinfo.saSgnR12andsubAccR12.positve&0x01)) {
        fifo_info->chanPeakinfo[1].peakstatus |= DSH_FIFO_THIRD_ACCURACY;
    }
    fifo_info->chanPeakinfo[1].peaksaccpos[2] =  hslinfo.saSgnR12andsubAccR12.accpos;

    fifo_info->chanPeakinfo[1].avgHist = hslinfo.avgQ1 + (hslinfo.avgR1handavgR0h.avgR1h << 16);
    // Standard Deviation
    fifo_info->chanPeakinfo[1].stddHist = hslinfo.stdQ1;

    return;
}
