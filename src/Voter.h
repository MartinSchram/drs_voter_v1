#ifndef VOTER_H
#define VOTER_H

typedef struct c_node
{
    unsigned short int id;
    float x;
    float y;
    long ts;
};

const unsigned short int thLength = 6;
const long tha[thLength] = {1000, 10000, 100000, 1000000, 10000000, 100000000};
const float whp[thLength] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
const float wlp[thLength] = {0.5, 0.4, 0.3, 0.2, 0.1, 0.0};

void voteLinear(c_node const &cam1, c_node const &cam2, float *x_out, float *y_out)
{
    *x_out = (cam1.x + cam2.x) / 2;
    *y_out = (cam1.y + cam2.y) / 2;
}

void voteWeighted(c_node &cam1, c_node &cam2, float *x_out, float *y_out)
{
    long jit;
    float w1, w2;
    c_node *hpc, *lpc;

    if (cam1.ts > cam2.ts)
    {
        hpc = &cam1;
        lpc = &cam2;
        jit = cam1.ts - cam2.ts;
    }
    else
    {
        hpc = &cam2;
        lpc = &cam1;
        jit = cam2.ts - cam1.ts;
    }

    if (jit > tha[5]) // 100% / 0%
    {
        *x_out = ((hpc->x) * whp[5] + (lpc->x) * wlp[5]);
        *y_out = ((hpc->y) * whp[5] + (lpc->y) * wlp[5]);
    }
    else if (jit > tha[4]) // 90% / 10%
    {
        *x_out = ((hpc->x) * whp[4] + (lpc->x) * wlp[4]);
        *y_out = ((hpc->y) * whp[4] + (lpc->y) * wlp[4]);
    }
    else if (jit > tha[3]) // 80% / 20%
    {
        *x_out = ((hpc->x) * whp[3] + (lpc->x) * wlp[3]);
        *y_out = ((hpc->y) * whp[3] + (lpc->y) * wlp[3]);
    }
    else if (jit > tha[2]) // 70% / 30%
    {
        *x_out = ((hpc->x) * whp[2] + (lpc->x) * wlp[2]);
        *y_out = ((hpc->y) * whp[2] + (lpc->y) * wlp[2]);
    }
    else if (jit > tha[1]) // 60% / 40%
    {
        *x_out = ((hpc->x) * whp[1] + (lpc->x) * wlp[1]);
        *y_out = ((hpc->y) * whp[1] + (lpc->y) * wlp[1]);
    }
    else // 50% / 50%
    {
        *x_out = ((hpc->x) * whp[0] + (lpc->x) * wlp[0]);
        *y_out = ((hpc->y) * whp[0] + (lpc->y) * wlp[0]);
    }
}

#endif /* VOTER_H*/