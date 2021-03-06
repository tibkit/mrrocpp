// -------------------------------------------------------------------------
//                            ui_class.h
// Definicje klasy Ui
//
// Ostatnia modyfikacja: 2010
// -------------------------------------------------------------------------

#ifndef __UI_R_CONVEYOR_H
#define __UI_R_CONVEYOR_H

#include "../base/ui.h"
#include "../base/ui_r_single_motor.h"
#include "robot/conveyor/const_conveyor.h"

class wgt_single_motor_move;

namespace mrrocpp {
namespace ui {
namespace common {
class Interface;

}
namespace single_motor {
class EcpRobot;
}

namespace conveyor {

//
// KLASA UiRobotConveyor
//
//


class UiRobot : public single_motor::UiRobot
{
private:

public:

	UiRobot(common::Interface& _interface);

	int manage_interface();
	int
			process_control_window_conveyor_section_init(bool &wlacz_PtButton_wnd_processes_control_all_reader_start, bool &wlacz_PtButton_wnd_processes_control_all_reader_stop, bool &wlacz_PtButton_wnd_processes_control_all_reader_trigger);

	int synchronise();
	int synchronise_int();

	int create_ui_ecp_robot();
	int edp_create_int_extra_operations();

	int ui_get_edp_pid();
	void ui_get_controler_state(lib::controller_state_t & robot_controller_initial_state_l);

};

}
} //namespace ui
} //namespace mrrocpp

#endif

