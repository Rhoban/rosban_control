#include "control_config.h"

namespace rosban_control
{

ControlConfig::ControlConfig()
  : frequency(0.0)
{
}

std::string ControlConfig::class_name() const
{
  return "ControlConfig";
}

void ControlConfig::to_xml(std::ostream &out) const
{
  rosban_utils::xml_tools::write<std::string>("robot", robot, out);
  rosban_utils::xml_tools::write<double>("frequency", frequency, out);
  rosban_utils::xml_tools::write_vector<std::string>("linear_sensors", linear_sensors, out);
  rosban_utils::xml_tools::write_vector<std::string>("angular_sensors", angular_sensors, out);
  rosban_utils::xml_tools::write_vector<std::string>("effectors", effectors, out);
}

void ControlConfig::from_xml(TiXmlNode *node)
{
  robot           = rosban_utils::xml_tools::read<std::string>       (node, "robot");
  frequency       = rosban_utils::xml_tools::read<double>            (node, "frequency");
  linear_sensors  = rosban_utils::xml_tools::read_vector<std::string>(node, "linear_sensors");
  angular_sensors = rosban_utils::xml_tools::read_vector<std::string>(node, "angular_sensors");
  effectors       = rosban_utils::xml_tools::read_vector<std::string>(node, "effectors");
}

}
