
#ifndef __DEF_PARAMS_H__
# define __DEF_PARAMS_H__
#include "main.h"

struct Params
{
  bool disable_transform;
  float voxel_resolution;
  bool voxel_res_specified;
  float seed_resolution;
  bool seed_res_specified;
  float color_importance;
  float spatial_importance;
  float normal_importance;
};

int set_params(int argc, char **argv, struct Params *params);

#endif /* __DEF_PARAMS_H__ */