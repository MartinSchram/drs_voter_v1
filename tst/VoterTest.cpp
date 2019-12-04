#include "VoterTest.h"

void VoterTest::SetUp()
{
    cn1.id = id1;
    cn2.id = id2;
}

void VoterTest::TearDown()
{
}

TEST_F(VoterTest, First_Cam1_Linear)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 1000000991293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteLinear(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(25.5, resX);
    EXPECT_FLOAT_EQ(42.5, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_5050)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 1000000991293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(25.5, resX);
    EXPECT_FLOAT_EQ(42.5, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_6040)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 1000000971293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(25.2, resX);
    EXPECT_FLOAT_EQ(42.4, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_7030)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 1000000771293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(24.9, resX);
    EXPECT_FLOAT_EQ(42.3, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_8020)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 999998771293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(24.6, resX);
    EXPECT_FLOAT_EQ(42.2, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_9010)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 999988771293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(24.3, resX);
    EXPECT_FLOAT_EQ(42.1, resY);
}

TEST_F(VoterTest, First_Cam1_Weigth_100N)
{

    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    cn2.ts = 999888771293;
    cn2.x = 27.0;
    cn2.y = 43;

    voteWeighted(cn1, cn2, &resX, &resY);

    EXPECT_FLOAT_EQ(24, resX);
    EXPECT_FLOAT_EQ(42, resY);
}