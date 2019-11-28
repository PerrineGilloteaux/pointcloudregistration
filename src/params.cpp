

#include "main.h"
#include "params.h"

int set_params(int argc, char **argv, struct Params *params)
{
  if (argc < 2)
  {
    pcl::console::print_error ("Syntax is: %s <vtk-file> \n "
                                "--nt Disables the single cloud transform \n"
                                "-v <voxel resolution>\n-s <seed resolution>\n"
                                "-c <color weight> \n-z <spatial weight> \n"
                                "-n <normal_weight>\n"
                                "Or: %s <pcd-file> --pcd [--nt] [-v <voxel resolution>] [...]", argv[0], argv[0]);
    return (1);
  }

  params->disable_transform = pcl::console::find_switch (argc, argv, "--nt");

  params->voxel_resolution = 0.008f;
  params->voxel_res_specified = pcl::console::find_switch (argc, argv, "-v");
  if (params->voxel_res_specified)
    pcl::console::parse (argc, argv, "-v", params->voxel_resolution);

  params->seed_resolution = 0.1f;
  params->seed_res_specified = pcl::console::find_switch (argc, argv, "-s");
  if (params->seed_res_specified)
    pcl::console::parse (argc, argv, "-s", params->seed_resolution);

  params->color_importance = 0.2f;
  if (pcl::console::find_switch (argc, argv, "-c"))
    pcl::console::parse (argc, argv, "-c", params->color_importance);

  params->spatial_importance = 0.4f;
  if (pcl::console::find_switch (argc, argv, "-z"))
    pcl::console::parse (argc, argv, "-z", params->spatial_importance);

  params->normal_importance = 1.0f;
  if (pcl::console::find_switch (argc, argv, "-n"))
    pcl::console::parse (argc, argv, "-n", params->normal_importance);

  return (0);
}