#include "control_config.h"

namespace rosban_control
{

std::string ControlConfig::class_name() const
{
  return "ControlConfig";
}

void ControlConfig::to_xml(std::ostream &out) const
{
  rosban_utils::xml_tools::write<double>("frequency", frequency, out);
  rosban_utils::xml_tools::write_vector<std::string>("sensors", sensors, out);
  rosban_utils::xml_tools::write_vector<std::string>("effectors", effectors, out);
}

void ControlConfig::from_xml(TiXmlNode *node)
{
  frequency = rosban_utils::xml_tools::read<double>(node,"frequency");
  sensors   = rosban_utils::xml_tools::read_vector<std::string>(node, "sensors");
  effectors = rosban_utils::xml_tools::read_vector<std::string>(node, "effectors");
}

}
