#ifndef VOTERTEST_H
#define VOTERTEST_H

#include "Voter.h"
#include "gtest/gtest.h"

using namespace std;

class VoterTest : public ::testing::Test
{

public:
    VoterTest(){};

    virtual ~VoterTest(){};

protected:
    virtual void SetUp();

    virtual void TearDown();

    c_node cn1;
    c_node cn2;
    c_node cn3;

    const unsigned short int id1 = 1;
    const unsigned short int id2 = 2;
    const unsigned short int id3 = 3;

    float resX;
    float resY;
};

#endif /* VOTERTEST_H */
