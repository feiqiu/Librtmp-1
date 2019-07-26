//
// Created by kmdai on 18-4-19.
//

#ifndef LIBRTMP_PUSH_RTMP_H
#define LIBRTMP_PUSH_RTMP_H

#include "srs_librtmp.hpp"
#include "push_queue.h"
#include <jni.h>
#include <pthread.h>
#include "push_utils.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct mediaConfig {
    uint32_t framerate;
    uint32_t videodatarate;
    uint32_t width;
    uint32_t height;
    uint32_t audiodatarate;
    uint32_t audiosamplerate;
    uint32_t audiosamplesize;
    int32_t channel_count;
    uint8_t *sps;
    uint32_t sps_len;
    uint8_t *pps;
    uint32_t pps_len;
} media_config;
media_config *media_config_p;

int init_srs(const char *url);

void add_frame(char *data, int32_t size, int32_t type, uint32_t time);

void write_raw_frames(char *data, int32_t size, u_int32_t dts, u_int32_t pts);

void *push_data(void *gvm);

void rtmp_start(JavaVM *gVm);

void rtmp_destroy();

void set_framerate(uint32_t framerate);

void setVideoBitrate(uint32_t videodatarate);

void set_width(uint32_t width);

void setHeight(uint32_t height);

void setAudioBitrate(uint32_t audiodatarate);

void seChannel(int32_t channel);

void setSamplerate(uint32_t audiosamplerate);

void set_audiosamplesize(uint32_t audiosamplesize);

#ifdef __cplusplus
};
#endif
#endif //LIBRTMP_PUSH_RTMP_H