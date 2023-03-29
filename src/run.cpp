#include "rclcpp/rclcpp.hpp"
#include "fstream"
#include "yaml-cpp/yaml.h"

class WaypointNav2 : public rclcpp::Node {
public:
    WaypointNav2() : Node("waypoint_nav2") {}
    bool read_yaml() {
        std::ifstream fin("/home/kazuki/ros2_ws/src/waypoint_nav2/waypoints/waypoint.yaml");
        if (!fin) {
            RCLCPP_ERROR(get_logger(), "Failed to open YAML file");
            return false;
        }
        return true;
    }
private:
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointNav2>());
  rclcpp::shutdown();
  return 0;
}