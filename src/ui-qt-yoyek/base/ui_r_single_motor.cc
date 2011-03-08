/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.01  */

#include "ui_r_single_motor.h"
#include "../base/ui_ecp_robot/ui_ecp_r_single_motor.h"
#include "../base/interface.h"

#include "../base/mainwindow.h"

namespace mrrocpp {
namespace ui {
namespace single_motor {

// extern ui_state_def ui_state;

//
//
// KLASA UiRobotIrp6ot_m
//
//


UiRobot::UiRobot(common::Interface& _interface, const std::string & edp_section_name, const std::string & ecp_section_name, lib::robot_name_t _robot_name, int _number_of_servos, const std::string & _activation_string) :
			common::UiRobot(_interface, lib::conveyor::EDP_SECTION, lib::conveyor::ECP_SECTION, lib::conveyor::ROBOT_NAME, lib::conveyor::NUM_OF_SERVOS, "is_conveyor_active"),
			ui_ecp_robot(NULL)
{

}

}
}
}
