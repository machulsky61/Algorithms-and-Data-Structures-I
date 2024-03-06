#include "../ej4.h"
#include "gtest/gtest.h"



TEST(ej4TEST, ejemplo1){
    vector<vector<zona>> m = {{(10,105),(40,120)},
                              {(30,150),(500,160)}};

    int res = 25;

    EXPECT_EQ(rellenarValles(m), res);
}
