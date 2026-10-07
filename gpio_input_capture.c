/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"

extern volatile uint32_t interruptVectors[];

int main(void)
{
    SYSCFG_DL_init();

    /*
     * Turn OFF LED if SW is open, ON if SW is closed.
     * LED starts OFF by default.
     */

    NVIC_EnableIRQ(GPIO_SWITCHES_INT_IRQN);

    while (1) {
        __WFI();
    }
}

void GROUP1_IRQHandler(void)
{
switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
case BTN_INT_IIDX:
if (!DL_GPIO_readPins(BTN_PORT, BTN_S2_PIN)){
if (flag == 0) {
DL_TimerG_setCaptureCompareValue(
PWM_0_INST, 255, DL_TIMER_CC_0_INDEX);
flag = 1;
}
else if (flag == 1){
DL_TimerG_setCaptureCompareValue(
PWM_0_INST, 500, DL_TIMER_CC_0_INDEX);
flag = 0;
}
}
}
}
