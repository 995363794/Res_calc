#include <stdio.h>
#include <math.h>

#define uchar unsigned char
#define uint unsigned int

double resList[] = {1,1.1,1.2,1.3,1.5,1.6,1.8,2,2.2,2.4,2.7,3,3.3,3.6,3.9,4.3,4.7,5.1,5.6,6.2,6.8,7.5,8.2,9.1,10,11,12,13,15,16,18,20,22,24,27,30,33,36,39,43,47,51,56,62,68,75,82,91,100,110,120,130,150,160,180,200,220,240,270,300,330,360,390,430,470,510,560,620,680,750,820,910,1000,1100,1200,1300,1500,1600,1800,2000,2200,2400,2700,3000,3300,3600,3900,4300,4700,5100,5600,6200,6800,7500,8200,9100,10000,11000,12000,13000,15000,16000,18000,20000,22000,24000,27000,30000,33000,36000,39000,43000,47000,51000,56000,62000,68000,75000,82000,91000,100000,110000,120000,130000,150000,160000,180000,200000,220000,240000,270000,300000,330000,360000,390000,430000,470000,510000,560000,620000,680000,750000,820000,910000,1000000,1100000,1200000,1300000,1500000,1600000,1800000,2000000,2200000,2400000,2700000,3000000,3300000,3600000,3900000,4300000,4700000,5100000,5600000,6200000,6800000,7500000,8200000,9100000,};

double bili = 7.333333;

double deviation = 0.01;

//TODO:加入偏差排序
// double outBuff[100][3];
// char jisuan(double deviationBuff,double resSmall,double ResBig){
//     double outBuff_zz[3]=0;
//     if(fabs(deviationBuff)<deviation){
//         for(uchar i=0;i<sizeof(outBuff)/sizeof(outBuff[0]);i++){
//             if(outBuff[i][1]==0){
//                 outBuff[i][0]=deviationBuff;
//                 outBuff[i][1]=resSmall;
//                 outBuff[i][2]=ResBig;
//                 return 1;
//             }else if(outBuff[i][0]>fabs(deviationBuff)){

//             }
//         }
//     }
// }

int main()
{
    uchar len = sizeof(resList) / sizeof(resList[0]);
    // printf("leng:%d\r\n",len);
    // uint outBuffLen = sizeof(outBuff)/sizeof(outBuff[0]);
    // printf("outBuffleng:%d\r\n",outBuffLen);
    printf("============\r\n参数输入\r\n============\r\n");
    printf("请输入R1/R2=");
    scanf("%lf",&bili);
    printf("请输入偏差范围[0.5,0):");
    scanf("%lf",&deviation);
    printf("R1/R2=%.2f 偏差范围%.2f\r\n", bili, deviation);
    printf("============\r\n结果\r\n============\r\n");
    printf("%-13s %-17s %-13s %-7s\n", "R1", "期望阻值", "R2", "偏差");
    for (uchar i = 0; i < len; i++){
        double data_JinSi = bili * resList[i];
        double listMin = 0;
        double minGap = 0;
        double listMax = 9100000;
        double maxGap = 0;

        for (uchar j = i; j < len; j++){
            if (resList[j] >= listMin && resList[j] <= data_JinSi){
                listMin = resList[j];
            }
            if (resList[j] <= listMax && resList[j] >= data_JinSi){
                listMax = resList[j];
            }
        }
        minGap = listMin / resList[i];
        minGap = bili - minGap;
        maxGap = listMax / resList[i];
        maxGap = bili - maxGap;
        if (fabs(maxGap) < deviation){
            printf("%-13.1f %-13.1f %-13.1f %-7.2f \r\n", resList[i], data_JinSi, listMax, maxGap);
        }
        if (fabs(minGap) < deviation){
            printf("%-13.1f %-13.1f %-13.1f %-7.2f\r\n", resList[i], data_JinSi, listMin, minGap);
        }
    }
    // printf("============\r\nEND\r\n============\r\n");
    return 0;
}