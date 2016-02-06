#pragma once

#include "rosban_utils/serializable.h"

namespace rosban_control
{

class ControlConfig : public rosban_utils::Serializable
{
public:
  double frequency;
  std::vector<std::string> sensors;
  std::vector<std::string> effectors;

  virtual std::string class_name() const override;
  virtual void to_xml(std::ostream &out) const override;
  virtual void from_xml(TiXmlNode * node) override;
};

}
