#include "WaveFunction.h"

int main(int argc, char *argv[])
{
    WaveFunction *a = new WaveFunction(128, 13); //每帧多少个采样点，MFCC参数的维数
    // WaveFunction *a = new WaveFunction(400, 13); //每帧多少个采样点，MFCC参数的维数

    vector<vector<float>> mfccs1 = a->getMFCCs("/app/data/audio/_tie1.wav"); //提取mfcc参数
    vector<vector<float>> mfccs2 = a->getMFCCs("/app/data/audio/casa.wav");

    // mfccs1=a->addFirstOrderDifference(mfccs1);//增加一阶差分系数,此时mfcc参数变为13+13维

    mfccs1 = a->addOrderDifference(mfccs1); //增加一阶差分和二阶差分系数，此时mfcc参数变为13*2+13维
    mfccs2 = a->addOrderDifference(mfccs2);

    cout << a->ComputeDTW(mfccs1, mfccs2) << endl; //利用动态时间规整算法，计算两个语音的相似度，越小相似度越大

    return 0;
}
