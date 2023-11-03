#ifdef big_brain__msg__MainControl_hpp
#define big_brain__msg__MainControl_hpp

#include <string>
#include <vector>

#include "rclcpp/visibility_control.hpp"
#include "std_msgs/msg/header.hpp"

namespace big_brain
{
  struct ZedObject
  {
    std_msgs::msg::Header header;
    double zed_object_field;
    object self.object;
    bool self.green_buoy_detected;
	bool self.red_buoy_detected;
	bool self.nearest_green_detected;
	bool self.nearest_red_detected;
    std::vector<obj> self.green_buoys_list;
    std::vector<obj> self.red_buoys_list;


  };

  struct CenterPoint
  {
    double center_point;
  };

  struct ThrusterValues
  {
    double left_speed;
    double right_speed;
  };

}

#endif