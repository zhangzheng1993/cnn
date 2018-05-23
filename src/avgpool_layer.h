#ifndef AVGPOOL_LAYER_H
#define AVGPOOL_LAYER_H

#include "image.h"
#include "network.h"

typedef struct {
    int h,w,c;
    int batch;
    int inputs;
    int stride;
    int out_h, out_w, out_c;
    int outputs;
    double *delta;
    double *output;
    enum LAYER_TYPE type;
} avgpool_layer;

image get_avgpool_image(avgpool_layer l);
avgpool_layer *make_avgpool_layer(int batch, int w, int h, int c);
void resize_avgpool_layer(avgpool_layer *l, int w, int h);
void forward_avgpool_layer(const avgpool_layer *l, network_state state);
void backward_avgpool_layer(const avgpool_layer *l, network_state state);

#ifdef GPU
void forward_avgpool_layer_gpu(avgpool_layer l, network_state state);
void backward_avgpool_layer_gpu(avgpool_layer l, network_state state);
#endif

#endif
