#include "calculate.h"
#include "unity.h"
double temperatureDeviation = 0.12;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_adcToTemp(void)
{
  
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-55.609,adcToTemp(10));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-45.834,adcToTemp(20));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-39.719,adcToTemp(30));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-35.168,adcToTemp(40));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-31.5,adcToTemp(50));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-28.4,adcToTemp(60));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-25.699,adcToTemp(70));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-23.293,adcToTemp(80));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-21.116,adcToTemp(90));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-19.12,adcToTemp(100));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-17.27,adcToTemp(110));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-15.544233,adcToTemp(120));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-13.92,adcToTemp(130));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-12.383,adcToTemp(140));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-10.923,adcToTemp(150));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-9.528,adcToTemp(160));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-8.19,adcToTemp(170));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-6.904,adcToTemp(180));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-5.662,adcToTemp(190));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-4.461,adcToTemp(200));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-3.295,adcToTemp(210));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-2.162,adcToTemp(220));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,-1.058,adcToTemp(230));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,0.019407,adcToTemp(240));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,1.073,adcToTemp(250));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,2.106,adcToTemp(260));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,3.12,adcToTemp(270));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,4.116,adcToTemp(280));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,5.096,adcToTemp(290));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,6.061,adcToTemp(300));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,7.014,adcToTemp(310));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,7.955,adcToTemp(320));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,8.885,adcToTemp(330));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,9.806,adcToTemp(340));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,10.719535,adcToTemp(350));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,11.624763,adcToTemp(360));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,12.523,adcToTemp(370));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,13.415,adcToTemp(380));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,14.304,adcToTemp(390));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,15.188,adcToTemp(400));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,16.069,adcToTemp(410));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,16.948,adcToTemp(420));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,17.825,adcToTemp(430));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,18.7,adcToTemp(440));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,19.576,adcToTemp(450));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,20.452,adcToTemp(460));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,21.331,adcToTemp(470));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,22.209,adcToTemp(480));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,23.091,adcToTemp(490));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,23.974,adcToTemp(500));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,24.865,adcToTemp(510));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,25.756,adcToTemp(520));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,26.656,adcToTemp(530));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,27.56,adcToTemp(540));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,28.47,adcToTemp(550));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,29.391,adcToTemp(560));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,30.317,adcToTemp(570));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,31.255,adcToTemp(580));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,32.203,adcToTemp(590));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,33.157,adcToTemp(600));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,34.129,adcToTemp(610));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,35.11,adcToTemp(620));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,36.108,adcToTemp(630));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,37.122,adcToTemp(640));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,38.152,adcToTemp(650));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,39.198,adcToTemp(660));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,40.268,adcToTemp(670));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,41.353,adcToTemp(680));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,42.464,adcToTemp(690));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,43.601,adcToTemp(700));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,44.764,adcToTemp(710));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,45.954,adcToTemp(720));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,47.178,adcToTemp(730));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,48.432,adcToTemp(740));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,49.723,adcToTemp(750));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,51.06,adcToTemp(760));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,52.439,adcToTemp(770));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,53.861,adcToTemp(780));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,55.339,adcToTemp(790));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,56.876,adcToTemp(800));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,58.478,adcToTemp(810));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,60.149,adcToTemp(820));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,61.897,adcToTemp(830));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,63.74,adcToTemp(840));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,65.676,adcToTemp(850));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,67.73,adcToTemp(860));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,69.917,adcToTemp(870));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,72.237,adcToTemp(880));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,74.748,adcToTemp(890));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,77.46,adcToTemp(900));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,80.41,adcToTemp(910));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,83.642,adcToTemp(920));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,87.215,adcToTemp(930));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,91.284,adcToTemp(940));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,95.869,adcToTemp(950));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,101.222,adcToTemp(960));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,107.639,adcToTemp(970));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,115.62,adcToTemp(980));
TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation,125.99,adcToTemp(990));

}
