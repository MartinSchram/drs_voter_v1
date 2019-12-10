#ifndef VOTER_H
#define VOTER_H

#include <stdlib.h>

typedef struct c_node {
  unsigned short int id;
  float x;
  float y;
  long ts;
};

const unsigned short int thLength = 6;
const long tha[thLength] = {1000, 10000, 100000, 1000000, 10000000, 100000000};
const float whp[thLength] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
const float wlp[thLength] = {0.5, 0.4, 0.3, 0.2, 0.1, 0.0};

void voteLinear(c_node const &cam1, c_node const &cam2, float *x_out,
                float *y_out) {
  *x_out = (cam1.x + cam2.x) / 2;
  *y_out = (cam1.y + cam2.y) / 2;
}

unsigned short int getMinGapX(float const &x_1_2, float const &x_1_3,
                              float const &x_2_3) {
  float mindiv = x_1_2;
  unsigned short int minpairIt = 1;

  float gx12_13 = x_1_2 - x_1_3;
  float gx12_23 = x_1_2 - x_2_3;
  float gx13_23 = x_1_3 - x_2_3;
  if (abs(gx12_13) < mindiv) {
    mindiv = gx12_13;
    minpairIt = 1;
  }
  if (abs(gx12_23) < mindiv) {
    mindiv = gx12_23;
    minpairIt = 2;
  }
  if (abs(gx13_23) < mindiv) {
    mindiv = gx13_23;
    minpairIt = 3;
  }
  return mindiv;
}

void voteWeighted(c_node &cam1, c_node &cam2, float *x_out, float *y_out) {
  long jit;
  float w1, w2;
  c_node *hpc, *lpc;

  if (cam1.ts > cam2.ts) {
    hpc = &cam1;
    lpc = &cam2;
    jit = cam1.ts - cam2.ts;
  } else {
    hpc = &cam2;
    lpc = &cam1;
    jit = cam2.ts - cam1.ts;
  }

  if (jit > tha[5]) // 100% / 0%
  {
    *x_out = ((hpc->x) * whp[5] + (lpc->x) * wlp[5]);
    *y_out = ((hpc->y) * whp[5] + (lpc->y) * wlp[5]);
  } else if (jit > tha[4]) // 90% / 10%
  {
    *x_out = ((hpc->x) * whp[4] + (lpc->x) * wlp[4]);
    *y_out = ((hpc->y) * whp[4] + (lpc->y) * wlp[4]);
  } else if (jit > tha[3]) // 80% / 20%
  {
    *x_out = ((hpc->x) * whp[3] + (lpc->x) * wlp[3]);
    *y_out = ((hpc->y) * whp[3] + (lpc->y) * wlp[3]);
  } else if (jit > tha[2]) // 70% / 30%
  {
    *x_out = ((hpc->x) * whp[2] + (lpc->x) * wlp[2]);
    *y_out = ((hpc->y) * whp[2] + (lpc->y) * wlp[2]);
  } else if (jit > tha[1]) // 60% / 40%
  {
    *x_out = ((hpc->x) * whp[1] + (lpc->x) * wlp[1]);
    *y_out = ((hpc->y) * whp[1] + (lpc->y) * wlp[1]);
  } else // 50% / 50%
  {
    *x_out = ((hpc->x) * whp[0] + (lpc->x) * wlp[0]);
    *y_out = ((hpc->y) * whp[0] + (lpc->y) * wlp[0]);
  }
}

void voteNodesWeighted(c_node &cam1, c_node &cam2, c_node &cam3, float *x_out,
                       float *y_out) {
  // 1 & 2
  float x_1_2, y_1_2;
  voteWeighted(cam1, cam2, &x_1_2, &y_1_2);
  // 1 & 3
  float x_1_3, y_1_3;
  voteWeighted(cam1, cam3, &x_1_3, &y_1_3);
  // 2 & 3
  float x_2_3, y_2_3;
  voteWeighted(cam2, cam3, &x_2_3, &y_2_3);

  unsigned short int minGapX = getMinGapX(x_1_2, x_1_3, x_2_3);

  switch (minGapX) {
  case 1:
    *x_out = (x_1_2 + x_1_3) / 2;
    *y_out = (y_1_2 + y_1_3) / 2;
    break;
  case 2:
    *x_out = (x_1_2 + x_2_3) / 2;
    *y_out = (y_1_2 + y_2_3) / 2;
    break;
  case 3:
    *x_out = (x_1_2 - +x_1_3) / 2;
    *y_out = (y_1_2 + y_1_3) / 2;
    break;
  default:
    *x_out = (x_1_3 + x_2_3) / 2;
    *y_out = (y_1_3 + y_2_3) / 2;
    break;
  }
}

#endif /* VOTER_H*/